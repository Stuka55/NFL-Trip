#ifndef MAP_H
#define MAP_H

#include <utility>
#include <time.h>
#include <stdlib.h>
#include <QList>
#include <iostream>

//* SKIP LIST NODE:
namespace sp {

/**
     * \brief A node in the map or dictionary.
     * \tparam k Key type.
     * \tparam v Value type.
     */
    template<typename k, typename v>
    class node {
    public:
        /**
         * @brief Constructor for a node.
         */
        node()
        {
            top_bottom.first = top_bottom.second = left_right.first = left_right.second = nullptr;
        }

        /**
         * @brief Copy constructor for a node.
         * @param other Another node to be copied.
         * @param up A pointer to the node above this one.
         * @param down A pointer to the node below this one.
         * @param left A pointer to the node to the left of this one.
         * @param right A pointer to the node to the right of this one.
         */
        node(const node<k, v>& other, node* up = nullptr, node* down = nullptr, node* left = nullptr, node* right = nullptr)
        {
            top_bottom.first = up;
            top_bottom.second = down;
            left_right.first = left;
            left_right.second = right;

            _data = other._data;
            _key = other._key;
        }

        /**
         * @brief Overloaded value contstructor for a node.
         * @param data Data to be stored in the node.
         * @param key This node's key.
         * @param down Pointer to the node below this one.
         */
        node(const v data, const k key, node* down = nullptr)
            : _data{ data }, _key{ key }
        {
            top_bottom.first = left_right.first = left_right.second = nullptr;
            top_bottom.second = down;
        }

        /**
         * @brief Get the node to the left of this one.
         * @return A pointer to the node to the left of this one.
         */
        node* left() const { return left_right.first; }
        /**
         * @brief Get the node to the right of this one.
         * @return A pointer to the node to the right of this one.
         */
        node* right() const { return left_right.second; }

        /**
         * @brief Get the node above this one.
         * @return A pointer to the node abovethis one.
         */
        node* up() const { return top_bottom.first; }

        /**
         * @brief Get the node belowthis one.
         * @return A pointer to the node below this one.
         */
        node* down() const { return top_bottom.second; }

        /**
         * @brief Get the data stored in this node.
         * @return The data stored in this node.
         */
        const v data() const { return _data; }
        /**
         * @brief Get the key affiliated with this node.
         * @return The key affiliated with this node.
         */
        const k key() const { return _key; }

        /**
         * @brief Setter for the node to the left of this one.
         * @param A pointer to the node to the left of this one.
         */
        void setLeft(node* left) { left_right.first = left; }
        /**
         * @brief Setter for the node to the right of this one.
         * @param A pointer to the node to the right of this one.
         */
        void setRight(node* right) { left_right.second = right; }
        /**
         * @brief Setter for the node above this one.
         * @param A pointer to the node above this one.
         */
        void setUp(node* up) { top_bottom.first = up; }
        /**
         * @brief Setter for the node below this one.
         * @param A pointer to the node below this one.
         */
        void setDown(node* down) { top_bottom.second = down; }

        /**
         * @brief Setter for the data.
         * @param The data to be stored.
         */
        void setData(const v data) { _data = data; }
        /**
         * @brief Setter for the key.
         * @param The key to be set.
         */
        void setKey(const k key) { _key = key; }



    private:
        v _data;
        k _key;

        std::pair<node*, node*> top_bottom;
        std::pair<node*, node*> left_right;
    };

    //* MAP:
    /**
     * \brief A sorted map data structure.
     * \tparam v Value type.
     * \tparam k Key type.
     */
    template<typename v, typename k>
    class map
    {
    public:
        /**
         * @brief Default constructor with optional overloads.
         * @param p The probablility of a new tower being generated.
         * @param H The random distribution maximum.
         * @param M The max size of the tower.
         */
        map(float p = .5f, int H = 100, int M = 10)
            : p{ p }, H{ H }, first{ nullptr }, n{ 0 }, MAX_h{ M }, rows{ new node<k,v>*[M] } {}

        ~map() {
            if (n) {

                for (int i = 0; i < MAX_h; i++) {
                    node<k, v>* temp = rows[i];
                    while (temp->right() != nullptr) {
                        node<k, v>* next = temp->right();
                        delete temp;
                        temp = next;
                    }

                    delete temp;

                }
            }

            delete[] rows;
        }

        /**
         * @brief Return the size of the map (horizontal width).
         * @return The number of unique nodes in the map.
         */
        int size() const { return n; }

        /**
         * @brief Test whether or not the map is empty.
         * @return A boolean value whether or not the map is empty.
         */
        bool empty() const { return !n; }

        /**
         * @brief Get the data in the first node.
         * @return The data in the first node.
         */
        v firstVal() const { return first->data(); }
        /**
         * @brief Get the key in the first node.
         * @return The key in the first node.
         */
        k firstKey() const { return first->key(); }

        /**
         * @brief Get the value at the node accociated with the specified key.
         * @param sKey The key to search for.
         * @return The value at the node accociated with the specififed key.
         */
        v value(k sKey) { return private_search(sKey)->data(); }

        /**
         * @brief Get the value at the node accociated with the specified key.
         * @param sKey The key to search for.
         * @return The value at the node accociated with the specififed key.
         */
        v operator[](k sKey) { return private_search(sKey)->data(); }

        /**
         * @brief Get the value at the specified index (for enumerating the data in order).
         * @param i The index.
         * @return The data at the specified index.
         */
        v at_index(int i) const{
            node<k, v>* temp = first;
            while(temp->down() != nullptr)
                temp = temp->down();

            for(int j = 0; j < i; j++)
                temp = temp->right();

            return temp->data();
        }


        /**
         * @brief Insert the specified data at the specified key.
         * @param data Data to insert.
         * @param key Key to insert.
         */
        void insert(v data, k key) {
            if (first == nullptr) {

                first = new node<k, v>(data, key);

                for (int i = 0; i < MAX_h; i++) {

                    rows[i] = first;
                    first->setUp(new node<k, v>(data, key, first));

                    first = first->up();
                }

                n++;
            }
            else if (key < first->key()) {

                if (n == 1) {
                    node<k, v> temp = *first;
                    clear();
                    n++;
                    insert(data, key);
                    insert(temp.data(), temp.key());
                    return;
                }

                node<k, v>* temp_first = first;

                node<k, v>** new_rows = new node<k, v>*[MAX_h];

                for (int i = 0; i < MAX_h; i++) {
                    new_rows[i] = rows[i]->right();
                }


                node<k, v>* killroy = new node<k, v>(first->data(), first->key());
                killroy->setRight(new_rows[0]);
                killroy->right()->setLeft(killroy);
                new_rows[0] = killroy;

                for (int j = 1; toss(p, H) == true && j < MAX_h; j++) {
                    killroy->setUp(new node<k, v>(killroy->data(), killroy->key(), killroy));
                    killroy = killroy->up();
                    killroy->setRight(new_rows[j]);
                    if (killroy->right() != nullptr) killroy->right()->setLeft(killroy);

                    new_rows[j] = killroy;
                }

                node<k, v>* billroy = new node<k, v>(data, key);
                billroy->setRight(new_rows[0]);
                billroy->right()->setLeft(billroy);
                rows[0] = billroy;

                for (int h = 1; h < MAX_h; h++) {

                    billroy->setUp(new node<k, v>(data, key, billroy));

                    billroy = billroy->up();
                    billroy->setRight(new_rows[h]);
                    if (billroy->right() != nullptr) billroy->right()->setLeft(billroy);

                    rows[h] = billroy;
                    first = billroy;
                }

                for (int g = 0; g < MAX_h; g++) {
                    node<k, v>* temp_first_down = temp_first->down();
                    delete temp_first;
                    temp_first = temp_first_down;
                }

                delete temp_first;

                delete[] new_rows;

                n++;
                return;
            }
            else {
                node<k, v>* killroy = private_search(key);

                if (key == killroy->key()) {

                    while (killroy->up() != nullptr) {
                        killroy->setData(data);
                        killroy = killroy->up();
                    }

                    return;
                }

                node<k, v>* temp = killroy->right();

                killroy->setRight(new node<k, v>(data, key));

                killroy->right()->setLeft(killroy);
                killroy->right()->setRight(temp);

                if (temp != nullptr) temp->setLeft(killroy->right());

                node<k, v>* ascend = killroy->right();


                for (int i = 1; toss(p,H) == true && i < MAX_h; i++) {
                    node<k, v>* last_item = layer_search(key, i);
                    node<k, v>* next_item = last_item->right();
                    ascend->setUp(new node<k, v>(data, key, ascend));

                    ascend = ascend->up();

                    if (next_item != nullptr) {
                        ascend->setRight(next_item);
                        next_item->setLeft(ascend);
                    }
                    ascend->setLeft(last_item);
                    last_item->setRight(ascend);

                }

                n++;
            }

        }

        /**
         * @brief Clear the map.
         * @return Whether or not the map was cleared. Returns false if first was nullptr.
         */
        bool clear() {
            if (first == nullptr)
                return false;

            if (n) {

                for (int i = 0; i < MAX_h; i++) {
                    node<k, v>* temp = rows[i];
                    while (temp->right() != nullptr) {
                        node<k, v>* next = temp->right();
                        delete temp;
                        temp = next;
                    }

                    delete temp;

                }
            }

            delete[] rows;

            first = nullptr;
            n = 0;
            rows = new node<k, v> * [MAX_h];
            return true;
        }

        /**
         * @brief Erase the data at the specified key.
         * @param key The key to erase the data associated with.
         * @return Returns true if the erase was successful.
         */
        bool erase(k key) {
            if (first == nullptr)
                return false;

            if (key == first->key()) {
                node<k, v>** temp = new node<k, v> * [MAX_h];

                node<k, v>* find = private_search(key)->right();
                node<k, v>* find2 = find;

                for (int i = 0; i < MAX_h; i++) {
                    if(find2 == nullptr) temp[i] = rows[i]->right();
                    if (find2 != nullptr) {
                        temp[i] = find2->right();
                        find2 = find2->up();
                    }

                }

                for (int j = 0; j < MAX_h; j++) {
                    rows[j] = find;

                    if (find->up() == nullptr)
                        find->setUp(new node<k, v>(find->data(), find->key(), find));

                    find->setLeft(nullptr);
                    find->setRight(temp[j]);
                    if(temp[j] != nullptr) temp[j]->setLeft(find);

                    find = find->up();
                }

                node<k, v>* temp_first = first;
                for (int l = 0; l < MAX_h; l++) {
                    temp_first = first->down();
                    delete first;
                    first = temp_first;
                }
                delete first;

                first = find;

                n--;

                return true;

            }
            else {
                node<k, v>* find = private_search(key);
                for (int i = 0; i < MAX_h && find != nullptr; i++) {
                    node<k, v>* bridge = find->right();
                    find->left()->setRight(bridge);
                    if(bridge != nullptr) bridge->setLeft(find->left());

                    bridge = find->up();
                    delete find;
                    find = bridge;
                }

                n--;
                return true;
            }

            return false;
        }

        /**
         * @brief Test print function.
         */
        void testPrint() {
            node<k, v>* temp = first;

            while (temp->down() != nullptr)
                temp = temp->down();

            for (int i = 0; i < n; i++) {
                std::cout << "Node: " << temp->data() << ", key( " << temp->key() << " )\n";
                temp = temp->right();
            }

            std::cout << '\n';
        }

        /**
         * @brief Test print by level function.
         */
        void testPrint_level() {
            for (int i = 0; i < MAX_h; i++) {
                node<k, v>* temp = rows[i];

                std::cout << "Level " << i + 1 << ":\n\n";

                while (temp->right() != nullptr) {
                    std::cout << "Node: " << temp->data() << ", key( " << temp->key() << ")\n";
                    temp = temp->right();
                }

                std::cout << "Node: " << temp->data() << ", key( " << temp->key() << ")\n----------------------------------------------------------------------\n\n";

            }
        }


    private:
        const int MAX_h;

        node<k, v>* first;
        node<k, v>** rows;

        int n;

        float p;
        int H;

        node<k, v>* layer_search(k key, int layer) {
            node<k, v>* row = rows[layer];

            while (row->right() != nullptr && key >= row->right()->key())
                row = row->right();

            return row;
        }

        node<k, v>* private_search(k key) {
            node<k, v>* p = first;
            while (p->down() != nullptr) {
                p = p->down();
                while (p->right() != nullptr && key >= p->right()->key()) {
                    p = p->right();
                }
            }

            return p;
        }

        bool toss(float p, int H) {
            srand(time(NULL) + rand());
            return (rand() % H + 1) <= p * H;
        }

    };

    // DICTIONARY (ADAPTED FROM THIS MAP)

    /**
     * \brief A sorted dictionary implementation.
     * \tparam v The value type to use.
     * \tparam k The key type to use.
     */
    template<typename v, typename k>
    class dictionary
    {
    public:
        /**
         * @brief Default constructor with optional overloads.
         * @param p The probablility of a new tower being generated.
         * @param H The random distribution maximum.
         * @param M The max size of the tower.
         */
        dictionary(float p = .5f, int H = 100, int M = 10)
            : p{ p }, H{ H }, first{ nullptr }, n{ 0 }, MAX_h{ M }, rows{ new node<k,v>*[M] } {}

        ~dictionary() {
            if (n) {

                for (int i = 0; i < MAX_h; i++) {
                    node<k, v>* temp = rows[i];
                    while (temp->right() != nullptr) {
                        node<k, v>* next = temp->right();
                        delete temp;
                        temp = next;
                    }

                    delete temp;

                }
            }

            delete[] rows;
        }

        /**
         * @brief Return the size of the dictionary (horizontal width).
         * @return The number of unique nodes in the dictionary.
         */
        int size() const { return n; }

        /**
         * @brief Test whether or not the dictionary is empty.
         * @return A boolean value whether or not the dictionary is empty.
         */
        bool empty() const { return !n; }

        /**
         * @brief Get the data in the first node.
         * @return The data in the first node.
         */
        v firstVal() const { return first->data(); }
        /**
         * @brief Get the key in the first node.
         * @return The key in the first node.
         */
        k firstKey() const { return first->key(); }

        /**
         * @brief Get the value at the node accociated with the specified key.
         * @param sKey The key to search for.
         * @return The value at the node accociated with the specififed key.
         */
        v value(k sKey) { return private_search(sKey)->data(); }

        /**
         * @brief Return all of the values associated with a key.
         * @param sKey They key to associated to node.
         * @return A Qlist of the values associated to the key.
         */
        QList<v> values(k sKey) {
            QList<v> list;
            node<k, v>* temp = private_search(sKey);
            k tKey = temp->key();

            while(temp->right() != nullptr && temp->right()->key() == tKey){
                list.insert(temp->data());
                temp = temp->right();
            }

            return list;

        }

        /**
         * @brief Get the value at the node accociated with the specified key.
         * @param sKey The key to search for.
         * @return The value at the node accociated with the specififed key.
         */
        v operator[](k sKey) { return private_search(sKey)->data(); }

        /**
         * @brief Get the value at the specified index (for enumerating the data in order).
         * @param i The index.
         * @return The data at the specified index.
         */
        v at_index(int i) const{
            node<k, v>* temp = first;
            while(temp->down() != nullptr)
                temp = temp->down();

            for(int j = 0; j < i; j++)
                temp = temp->right();

            return temp->data();
        }


        /**
         * @brief Insert the specified data at the specified key.
         * @param data Data to insert.
         * @param key Key to insert.
         */
        void insert(v data, k key) {
            if (first == nullptr) {

                first = new node<k, v>(data, key);

                for (int i = 0; i < MAX_h; i++) {

                    rows[i] = first;
                    first->setUp(new node<k, v>(data, key, first));

                    first = first->up();
                }

                n++;
            }
            else if (key < first->key()) {

                if (n == 1) {
                    node<k, v> temp = *first;
                    clear();

                    insert(data, key);
                    insert(temp.data(), temp.key());
                    n++;
                    return;
                }

                node<k, v>* temp_first = first;

                node<k, v>** new_rows = new node<k, v>*[MAX_h];

                for (int i = 0; i < MAX_h; i++) {
                    new_rows[i] = rows[i]->right();
                }


                node<k, v>* killroy = new node<k, v>(first->data(), first->key());
                killroy->setRight(new_rows[0]);
                killroy->right()->setLeft(killroy);
                new_rows[0] = killroy;

                for (int j = 1; toss(p, H) == true && j < MAX_h; j++) {
                    killroy->setUp(new node<k, v>(killroy->data(), killroy->key(), killroy));
                    killroy = killroy->up();
                    killroy->setRight(new_rows[j]);
                    if (killroy->right() != nullptr) killroy->right()->setLeft(killroy);

                    new_rows[j] = killroy;
                }

                node<k, v>* billroy = new node<k, v>(data, key);
                billroy->setRight(new_rows[0]);
                billroy->right()->setLeft(billroy);
                rows[0] = billroy;

                for (int h = 1; h < MAX_h; h++) {

                    billroy->setUp(new node<k, v>(data, key, billroy));

                    billroy = billroy->up();
                    billroy->setRight(new_rows[h]);
                    if (billroy->right() != nullptr) billroy->right()->setLeft(billroy);

                    rows[h] = billroy;
                    first = billroy;
                }

                for (int g = 0; g < MAX_h; g++) {
                    node<k, v>* temp_first_down = temp_first->down();
                    delete temp_first;
                    temp_first = temp_first_down;
                }

                delete temp_first;

                delete[] new_rows;

                n++;
                return;
            }
            else {
                node<k, v>* killroy = private_search(key);

                node<k, v>* temp = killroy->right();

                killroy->setRight(new node<k, v>(data, key));

                killroy->right()->setLeft(killroy);
                killroy->right()->setRight(temp);

                if (temp != nullptr) temp->setLeft(killroy->right());

                node<k, v>* ascend = killroy->right();


                for (int i = 1; toss(p,H) == true && i < MAX_h; i++) {
                    node<k, v>* last_item = layer_search(key, i);
                    node<k, v>* next_item = last_item->right();
                    ascend->setUp(new node<k, v>(data, key, ascend));

                    ascend = ascend->up();

                    if (next_item != nullptr) {
                        ascend->setRight(next_item);
                        next_item->setLeft(ascend);
                    }
                    ascend->setLeft(last_item);
                    last_item->setRight(ascend);

                }

                n++;
            }

        }

        /**
         * @brief Clear the map.
         * @return Whether or not the map was cleared. Returns false if first was nullptr.
         */
        bool clear() {
            if (first == nullptr)
                return false;

            if (n) {

                for (int i = 0; i < MAX_h; i++) {
                    node<k, v>* temp = rows[i];
                    while (temp->right() != nullptr) {
                        node<k, v>* next = temp->right();
                        delete temp;
                        temp = next;
                    }

                    delete temp;

                }
            }

            delete[] rows;

            first = nullptr;
            n = 0;
            rows = new node<k, v> * [MAX_h];
        }

        /**
         * @brief Erase the data at the specified key.
         * @param key The key to erase the data associated with.
         * @return Returns true if the erase was successful.
         */
        bool erase(k key) {
            if (first == nullptr)
                return false;

            if (key == first->key()) {
                node<k, v>** temp = new node<k, v> * [MAX_h];

                node<k, v>* find = private_search(key)->right();
                node<k, v>* find2 = find;

                for (int i = 0; i < MAX_h; i++) {
                    if(find2 == nullptr) temp[i] = rows[i]->right();
                    if (find2 != nullptr) {
                        temp[i] = find2->right();
                        find2 = find2->up();
                    }

                }

                for (int j = 0; j < MAX_h; j++) {
                    rows[j] = find;

                    if (find->up() == nullptr)
                        find->setUp(new node<k, v>(find->data(), find->key(), find));

                    find->setLeft(nullptr);
                    find->setRight(temp[j]);
                    if(temp[j] != nullptr) temp[j]->setLeft(find);

                    find = find->up();
                }

                node<k, v>* temp_first = first;
                for (int l = 0; l < MAX_h; l++) {
                    temp_first = first->down();
                    delete first;
                    first = temp_first;
                }
                delete first;

                first = find;

                n--;

                return true;

            }
            else {
                node<k, v>* find = private_search(key);
                for (int i = 0; i < MAX_h && find != nullptr; i++) {
                    node<k, v>* bridge = find->right();
                    find->left()->setRight(bridge);
                    if(bridge != nullptr) bridge->setLeft(find->left());

                    bridge = find->up();
                    delete find;
                    find = bridge;
                }

                n--;
                return true;
            }

            return false;
        }

        /**
         * @brief Test print function.
         */
        void testPrint() {
            node<k, v>* temp = first;

            while (temp->down() != nullptr)
                temp = temp->down();

            for (int i = 0; i < n; i++) {
                std::cout << "Node: " << temp->data() << ", key( " << temp->key() << " )\n";
                temp = temp->right();
            }

            std::cout << '\n';
        }

        /**
         * @brief Test print by level function.
         */
        void testPrint_level() {
            for (int i = 0; i < MAX_h; i++) {
                node<k, v>* temp = rows[i];

                std::cout << "Level " << i + 1 << ":\n\n";

                while (temp->right() != nullptr) {
                    std::cout << "Node: " << temp->data() << ", key( " << temp->key() << ")\n";
                    temp = temp->right();
                }

                std::cout << "Node: " << temp->data() << ", key( " << temp->key() << ")\n----------------------------------------------------------------------\n\n";

            }
        }


    private:
        const int MAX_h;

        node<k, v>* first;
        node<k, v>** rows;

        int n;

        float p;
        int H;

        node<k, v>* layer_search(k key, int layer) {
            node<k, v>* row = rows[layer];

            while (row->right() != nullptr && key >= row->right()->key())
                row = row->right();

            return row;
        }

        node<k, v>* private_search(k key) {
            node<k, v>* p = first;
            while (p->down() != nullptr) {
                p = p->down();
                while (p->right() != nullptr && key >= p->right()->key()) {
                    p = p->right();
                }
            }

            return p;
        }

        bool toss(float p, int H) {
            srand(time(NULL) + rand());
            return (rand() % H + 1) <= p * H;
        }

    };
}

#endif // MAP_H
