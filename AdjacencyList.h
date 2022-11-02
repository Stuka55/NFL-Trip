#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

// AdjacencyList.h

// I KNOW THE DOCUMENTATION ON THIS SUCKS! I WILL DO IT LAST MINUTE! SORRY :)
// Also don't use this for anything other than value == Stadium* until I find a more general solution than what is here! :)))

#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <queue>
#include <QStringList>
#include <QPair>
#include "stadium.h"

// Forward Declaration of EDGE
template<typename value, typename dist>
struct adjEdge;

// Forward Declaration of NODE
template<typename value, typename dist>
struct adjNode;

// Forward Declaration of DFS class
template<typename G, typename value, typename dist>
class DFS;


// Compare two nodes for sort algorithm.
/**
 * @brief Compare two pointers to nodes.
 * \tparam value The dataype of the value stored in a Vertex.
 * \tparam dist The Datatype of the edge weight stored in and Edge.
 */
template<typename value, typename dist>
bool comparePtrToNode(adjEdge<value, dist>* a, adjEdge<value, dist>* b) { return (a->weight < b->weight); }

// Comparator for two nodes for priority_queue stored in MST search.
/**
 * @brief Compare two pointers to nodes.
 * \tparam value The dataype of the value stored in a Vertex.
 * \tparam dist The Datatype of the edge weight stored in and Edge.
 */
template<typename value, typename dist>
class adjGreater {
public:
    bool operator ()(adjEdge<value, dist>* a, adjEdge<value, dist>* b) { return (a->weight > b->weight); }
};



// NODE
/**
 * @brief A Vertex on the graph.
 * \tparam value The dataype of the value stored in a Vertex.
 * \tparam dist The Datatype of the edge weight stored in and Edge.
 */
template <typename value, typename dist>
struct adjNode {

    /**
     * @brief Default Constructor, takes the value to be stored in the vertex and it's position in the vector.
     * @param x The value to store in this node.
     * @param pos The position in the vector.
     */
    adjNode(const value x = value(NULL), int pos = -1) : name{ x }, pos{ pos }, visited{ false } {}

    value name; /**< The data stored in the node. */
    std::vector<adjEdge<value, dist>*> incidentEdges; /**< All adjacent edges. */
    int pos; /**< The position in the graph's vector. */

    adjNode<value, dist>* parent{ nullptr }; /** A pointer to the node's parent (for MST). */

    bool visited; /**< A boolean value telling if the node has been visited (for traversals). */

public:
    /**
     * @brief Check if a node is adjacent to node v.
     * @param v The node to check.
     * @return A boolean value as to whether or not the node is adjacent to v.
     */
    bool isAdjacentTo(const adjNode<value, dist>* v) {

        if (incidentEdges.size() <= v->incidentEdges.size()) {
            std::cout << "WENT INTO FIRST";
            for (auto e : incidentEdges) {
                if (e->endpoints.first == v || e->endpoints.second == v)
                    return true;
            }
        }
        else if (incidentEdges.size() > v->incidentEdges.size()) {
            std::cout << "WENT INTO SECOND";
            for (auto e : v->incidentEdges) {
                if (e->endpoints.first == this || e->endpoints.second == this)
                    return true;
            }
        }

        return false;
    }
};

// EDGE
/**
 * @brief An edge on the graph.
 * \tparam value The dataype of the value stored in a Vertex.
 * \tparam dist The Datatype of the edge weight stored in and Edge.
 */
template<typename value, typename dist>
struct adjEdge {

    /**
     * @brief Default constructor.
     * @param w The weight of this edge.
     * @param Ep The position of this edge in the graph's edge list.
     */
    adjEdge(const dist& w = dist(NULL), const int Ep = -1) : weight{ w }, Epos{ Ep }, visited{ false }
    {}



    dist weight; /**< The weight of this edge. */
    int Epos; /** The position of this edge in the graph's edge list. */
    std::vector<int> Ipos; /**< Positions in an edge incidence collection. */

    bool visited; /**< Whether or not this edge has been visited */

    std::pair<adjNode<value, dist>*, adjNode<value, dist>*> endpoints; /**< Pointers to the nodes on either endpoint of the edge. */


public:
    /**
     * @brief Test whether or not this edge is incident upon vertex v.
     * @param v Vertex v.
     * @return Whether or not this edge is incident on vertex v.
     */
    bool isIncidentOn(const adjNode<value, dist>* v) {
        if (endpoints.first == v)
            return true;
        else if (endpoints.second == v)
            return true;

        return false;
    }

    /**
     * @brief Get the node opposit to v. If v is not incident, returns nullptr.
     * @param v The node to get the opposite of.
     * @return The node (w) opposite of v.
     */
    adjNode<value, dist>* opposite(const adjNode<value, dist>* v) {
        if (!isIncidentOn(v))
            return nullptr;

        if (endpoints.first == v)
            return endpoints.second;
        else if (endpoints.second == v)
            return endpoints.first;
    }

};

// ADJACENCY LIST
/**
 * @brief A graph implementing the adjacency list.
 * \tparam value The dataype of the value stored in a Vertex.
 * \tparam dist The Datatype of the edge weight stored in and Edge.
 */
template<typename value, typename dist>
class adjGraph {
public:
    typedef adjNode<value, dist>* Vertex;
    typedef adjEdge<value, dist>* Edge;

    /**
     * @brief Default constructor, initializes size to 0 and points the DFS search to itself.
     */
    adjGraph() : _size{ 0 }, dfs{ *this } {}

    /**
     * @brief Copy constructor. Copies size and vectors.
     * @param other Other graph.
     */
    adjGraph(const adjGraph& other) : dfs{ *this } {
        _size = other._size;
        Vc = other.Vc;
        Ec = other.Ec;
    }

    ~adjGraph() {
        if (_size > 0) {
            for (auto e : Vc)
                delete e;
            for (auto e : Ec)
                delete e;
        }
    }

    /**
     * @brief Erase the edge that connects u and v;
     * @param u Vertex u.
     * @param v Vertex v.
     * @return A bool representing a successful erasure.
     */
    bool eraseEdge(adjNode<value, dist>* u, adjNode<value, dist>* v){
        adjEdge<value, dist>* temp = getEdge(u, v);

        if (temp == nullptr)
            return false;

        int index = 0;
        for(auto e : u->incidentEdges){
            if(e == temp){
                u->incidentEdges.erase(u->incidentEdges.begin() + index);
            }
            index++;
        }
        index = 0;
        for(auto e : v->incidentEdges){
            if(e == temp){
                v->incidentEdges.erase(v->incidentEdges.begin() + index);
            }
            index++;
        }
        index = 0;
        for(auto e: Ec){
            if(e == temp){
                Ec.erase(Ec.begin() + index);
            }
            index++;
        }

        delete temp;

        return true;

    }

    /**
     * @brief Erase the given vertex.
     * @param val A vertex in the graph.
     * @return Whether or not a successful erasure occured.
     */
    bool eraseVertex(const adjNode<value,dist>* val){
        if (val == nullptr)
            return false;
        if(!std::find(Vc.begin(), Vc.end(), val)){
            return false;
        }

        for(auto Edge : val->incidentEdges)
            eraseEdge(Edge);

        for(int i = 0; i < Vc.size(); i++){
            if(Vc[i] == val){
                Vc.erase(Vc.begin() + i);
                break;
            }
        }

        for(int i = 0; i < Vc.size(); i++){
            Vc[i]->pos = i;
        }

        _size--;

        delete val;

    }

    /**
     * @brief Get the given vertex in the graph at index i.
     * @param i Index to return.
     * @return Vertex at i.
     */
    adjNode<value, dist>* operator [](const int i) { return Vc[i]; }
    /**
     * @brief Get the given edge in the graph at index i.
     * @param i Index to return.
     * @return Edge at i.
     */
    adjEdge<value, dist>* operator ()(const int i) { return Ec[i]; }

    /**
     * @brief Get the edge containing verticies u and v.
     * @param u The first vertex.
     * @param v The second vertex.
     * @return An edge containing the specified connection. Returns nullptr if there is none.
     */
    adjEdge<value, dist>* operator () (adjNode<value,dist>* u, adjNode<value,dist>* v){
        for(auto e : Ec){
            if(e->endpoints.first == u && e->endpoints.second == v)
                return e;
        }

        return nullptr;
    }
    /**
     * @brief Get the edge containing verticies u and v.
     * @param u The first vertex.
     * @param v The second vertex.
     * @return An edge containing the specified connection. Returns nullptr if there is none.
     */
    adjEdge<value, dist>* getEdge(adjNode<value, dist>* u, adjNode<value,dist>* v){
        for(auto e : Ec){
            if(e->endpoints.first == u && e->endpoints.second == v)
                return e;
        }

        return nullptr;
    }

    /**
     * @brief Get the vertex containing the name "val."
     * @param val The name to search for.
     * @return The vertex containing name. If name does not exist, returns nullptr.
     */
    adjNode<value, dist>* operator [](const value& val) {
        for(auto e : Vc){
            if (e->name == val){
                return e;
                break;
            }

        }

        return nullptr;
    }

    /**
     * @brief Test if the graph is empty.
     * @return Whether or not the graph is empty.
     */
    bool empty() { return !_size; }
    /**
     * @brief Get the size of the graph.
     * @return The size of the graph.
     */
    int size() { return _size; }

    /**
     * @brief Get a list of all the verticies in the graph.
     * @return The list of verticies in the graph.
     */
    std::vector<adjNode<value, dist>*> verticies() const { return Vc; }
    /**
     * @brief Get the list of edges in the graph.
     * @return The list of edges in the graph.
     */
    std::vector<adjEdge<value, dist>*> edges() const { return Ec; }

    /**
     * @brief Insert a vertex containing the name "x."
     * @param x The value to insert in the new vertex.
     */
    void insertVertex(const value& x) {
        Vc.push_back(new adjNode<value, dist>(x, Vc.size()));
        _size++;
    }

    /**
     * @brief Insert an edge between verticies u & v.
     * @param u First vertex.
     * @param v Second Vertex.
     * @param d Weight of the edge.
     */
    void insertEdge(adjNode<value, dist>* u, adjNode<value, dist>* v, const dist& d) {

        adjEdge<value, dist>* temp = new adjEdge<value, dist>(d, Ec.size());

        temp->endpoints.first = u;
        temp->endpoints.second = v;

        u->incidentEdges.push_back(temp);
        v->incidentEdges.push_back(temp);

        temp->Ipos.push_back(index_of(u, temp));
        temp->Ipos.push_back(index_of(v, temp));

        Ec.push_back(temp);
    }

    /**
     * @brief Insert an edge by name.
     * @param u Name of vertex u.
     * @param v Name of vertex v.
     * @param d Distance between u & v.
     */
    bool insertEdge(const value& u, const value& v, const dist& d){
        adjNode<value, dist>* uN = nullptr;
        adjNode<value, dist>* vN = nullptr;

        for(auto Verts : Vc) {
            if(Verts->name == u) uN = Verts;
            if(Verts->name == v) vN = Verts;
        }

        if(uN == nullptr || vN == nullptr)
            return false;

        insertEdge(uN, vN, d);
        return true;
    }

    /**
     * @brief Print the depth first traversal to the console.
     * @param starting_city Vertex to start in.
     */
    void dfs_print(adjNode<value, dist>* starting_city) {
        dfs.dfsTraversal(starting_city);

        std::cout << '\n';

        dfs.outputMiles();
    }

    /**
     * @brief Preform a BFS search.
     * @param starting_city The Vertex to start in.
     * @return A QStringList containing the "Output" as if the BFS was logged on the console.
     */
    QStringList getBFS(adjNode<value, dist>* starting_city){
        QStringList output;

        int sum = 0;

        for(auto v : Vc){
            v->visited = false;
        }
        for(auto e : Ec){
            e->visited = false;
        }

        starting_city->visited = true;

        output << "Level 0:\n";

        output << "Started at: " + starting_city->name->getstadiumName() + '\n';

        std::vector<std::vector<adjNode<value, dist>*>> L;

        L.push_back(std::vector<adjNode<value, dist>*>()); // Vector literal... wtf!
        L.at(0).push_back(starting_city);

        for(int i = 0; !L[i].empty(); i++){
            output << "Level " + QString::number(i + 1) + ":\n";
            L.push_back(std::vector<adjNode<value, dist>*>());
            for(auto Verts : L[i]){
                if(!L[i].empty()){
                    for(auto Edges : Verts->incidentEdges){
                        if(!Edges->visited){
                            adjNode<value, dist>* w = Edges->opposite(Verts);
                            if(!w->visited){
                                output << "Discovery Edge: " + w->name->getstadiumName() + '\n';
                                w->visited = true;
                                sum += Edges->weight;
                                L.at(i + 1).push_back(w);
                            }
                            else{
                                output << "Cross Edge: " + w->name->getstadiumName() + '\n';
                            }
                            Edges->visited = true;
                        }
                    }
                }
            }
        }
        output << "Total Distance: " + QString::number(sum);

        dfs.reset();

        return output;
    }

    /**
     * @brief Preform a DFS search.
     * @param starting_city The Vertex to start in.
     * @return A QStringList containing the "Output" as if the dfs was logged on the console.
     */
    QStringList getDFS(adjNode<value, dist>* starting_city){
        QStringList d = dfs.dfsTraversal(starting_city);
        d << dfs.outputMiles();

        dfs.reset();
        return d;
    }

    /**
     * @brief Preform a BFS search.
     * @param val The Vertex to start in.
     * @return A QStringList containing the "Output" as if the BFS was logged on the console.
     */
    QStringList getDFS(const value& val){
        adjNode<value, dist>* temp = nullptr;

        for(auto Verts : Vc){
            if (Verts->name == val){
                temp = Verts;
                break;
            }
        }

        if(temp == nullptr)
            throw "NOT_IN_VECTOR_ERROR";

        return getDFS(temp);
    }

    /**
     * @brief Helper for the MST. Find a node that has not yet been given a parent.
     * @param u Node begin the find on.
     * @return A node without a parent.
     */
    adjNode<value, dist>* find(adjNode<value, dist>* u) {
        if (u == u->parent)
            return u;
        else
            return find(u->parent);
    }

    /**
     * @brief Give a node a parent, or "unify" them.
     * @param u Node u.
     * @param v Node v.
     */
    void unify(adjNode<value, dist>* u, adjNode<value, dist>* v) {
        u->parent = v;
        return;
    }

    /**
     * @brief Preform a MST search.
     * @return A QStringList containing the "Output" as if the MST was logged on the console.
     */
    QStringList getMST() {

        QStringList temp;

        int sum = 0;

        for (auto e : Vc)
            e->parent = e;

        std::priority_queue<adjEdge<value, dist>*, std::vector<adjEdge<value, dist>*>, adjGreater<value, dist>> pQ;

        for (auto e : Ec)
            pQ.push(e);

        std::vector<adjEdge<value, dist>*> T;

        int found = 0;

        while (found < _size - 1) {
            adjNode<value, dist>* u = find(pQ.top()->endpoints.first);
            adjNode<value, dist>* v = find(pQ.top()->endpoints.second);

            if (u != v) {
                /* normally, this is where you would make it add the edje to the tree */
                std::clog << "Edge " << found + 1 << ": " << pQ.top()->endpoints.first->name << " to " << pQ.top()->endpoints.second->name
                    << ", " << pQ.top()->weight << " miles\n";

                temp << "Edge " + QString::number(found + 1) + ": " + pQ.top()->endpoints.first->name->getstadiumName() + " to " + pQ.top()->endpoints.second->name->getstadiumName()
                               + ", " + QString::number(pQ.top()->weight) + " miles\n";

                unify(u, v);

                sum += pQ.top()->weight;

                found++;
            }

            pQ.pop();

        }

        //std::clog << "\nTotal trip: " << sum << " miles.\n";
        temp << "Total trip: " + QString::number(sum) + " miles.\n";


        return temp;
    }

    /**
     * @brief Erase the contents of the graph, and reset it to base state.
     */
    void clear(){
        _size = 0;
        for(auto V : Vc)
            delete V;
        for(auto E : Ec)
            delete E;

        Vc.clear();
        Ec.clear();
    }

    /**
    * @brief Comparator for a QPair containing a node and an int to compare the djikstra's distance.
    * @param lhs The QPair on the left hand side of the comparator.
    * @param rhs The QPair on the right hand side of the omparator.
    * @return Whether or not the > test condtion yeilded.
    */
   class pairGreater{
   public:
       bool operator() (const QPair<adjNode<value, dist>*, int>& lhs, const QPair<adjNode<value, dist>*, int>& rhs){
           return lhs.second > rhs.second;
       }
    };

   /**
    * @brief Get the distances from vertex u to all other verticies on the graph.
    * @param u The vertex to check.
    * @return The distances from u to all other verticies on the graph.
    */
   std::vector<int> djikstras(adjNode<value, dist>* u) {

       typedef QPair<adjNode<value, dist>*, int> vpair;

        for(auto v : Vc)
            v->visited = false;
        for(auto e : Ec)
            e->visited = false;

        std::priority_queue<vpair, std::vector<vpair>, pairGreater> pq;


        std::vector<int> distance(Vc.size(), INT32_MAX);

        pq.push(vpair(u, 0));
        distance[u->pos] = 0;

        while(!pq.empty()){
            adjNode<value, dist>* w = pq.top().first;
            pq.pop();

            for(auto e : w->incidentEdges){
                adjNode<value, dist>* v = e->opposite(w);
                int wt = e->weight;

                if(distance[v->pos] > distance[w->pos] + wt){
                    distance[v->pos] = distance[w->pos] + wt;
                    pq.push(vpair(v, distance[v->pos]));
                }

            }
        }

        dfs.reset();

        return distance;
    }

private:
    int _size;

    std::vector<adjNode<value, dist>*> Vc;
    std::vector<adjEdge<value, dist>*> Ec;


    DFS<adjGraph, value, dist> dfs;


    // Helper:
    int index_of(adjNode<value, dist>* u, adjEdge<value, dist>* x) {
        return std::distance(u->incidentEdges.begin(), std::find(u->incidentEdges.begin(), u->incidentEdges.end(), x));
    }
};



// DFS class (author's implementaion but less general)
/**
 * \brief DFS class. Handles a slightly-less-than general DFS traversal.
 * \tparam G A Graph of any kind.
 * \tparam value The value contained in graph G's verticies.
 * \tparam dist The weight contained in graph G's edges.
 */
template <typename G, typename value, typename dist>
class DFS {
public:
    /**
     * @brief Default constructor Initializes graph and sum of DFS.
     * @param g The graph to be traversed.
     */
    DFS(const G& g) : graph{ g }, sum{ 0 } {}

    /**
     * @brief Preform a DFS search.
     * @param v The Vertex to start in.
     * @return A QStringList containing the "Output" as if the dfs was logged on the console.
     */
    QStringList dfsTraversal(adjNode<value, dist>* v) {

        QStringList temp;

        temp << startVisit(v);	visit(v);
        std::vector<adjEdge<value, dist>*> incident = v->incidentEdges;
        std::sort(incident.begin(), incident.end(), comparePtrToNode<value, dist>);

        auto pe = incident.begin();
        while (!isDone() && pe != incident.end()) {
            adjEdge<value, dist>* e = *pe++;
            if (!isVisited(e)) {
                visit(e);
                adjNode<value, dist>* w = e->opposite(v);
                if (!isVisited(w)) {
                    temp << traverseDiscover(e, v);
                    if(!isDone())
                        temp << dfsTraversal(w);
                }
                else temp << traverseBack(e, v);
            }
        }
        if (!isDone()) finishVisit(v);

        return temp;
    }

    /**
     * @brief Reset the DFS's internal state.
     */
    void reset(){
        initialize();
    }

    /**
     * @brief Get the sum of the discovery edges discovered in the last traversal.
     * @return The sum of the discovery edges in the last traversal.
     */
    QString outputMiles() {
        std::cout << "Total distance along discovery edges: " << sum << " miles.";
        return "Total distance along discovery edges: " + QString::number(sum) + " miles.";
    }
private:


    const G& graph;
    adjNode<value, dist>* start;

    int sum;


    void visit(adjNode<value, dist>* v) { v->visited = true; }
    void visit(adjEdge<value, dist>* e) { e->visited = true; }
    void unvisit(adjNode<value, dist>* v) { v->visited = false; }
    void unvisit(adjEdge<value, dist>* e) { e->visited = false; }
    bool isVisited(adjNode<value, dist>* v) { return v->visited; }
    bool isVisited(adjEdge<value, dist>* e) { return e->visited; }


    void initialize() {
        start = nullptr;
        sum = 0;

        std::vector<adjNode<value, dist>*> verts = graph.verticies();
        for (auto pv = verts.begin(); pv != verts.end(); pv++)
            unvisit(*pv);
        std::vector<adjEdge<value, dist>*> edges = graph.edges();
        for (auto pe = edges.begin(); pe != edges.end(); pe++)
            unvisit(*pe);
    }

    QString startVisit(adjNode<value, dist>* v) {
        //std::cout << "Visited: " << v->name->getstadiumName() << '\n';
        start = v;

        return "Visited: " + v->name->getstadiumName() + '\n';
    }
    virtual QString traverseDiscover(adjEdge<value, dist>* e, adjNode<value, dist>* v) {
        QString temp = "";

        if(e->endpoints.second->name == v->name){
            //std::cout << "Discovered edge: " << e->endpoints.first->name->getstadiumName() << ", " << e->weight << " miles from " << v->name->getstadiumName() << ".\n";
            temp += "Discovered edge: " + e->endpoints.first->name->getstadiumName() + ", " + QString::number(e->weight) + " miles from " + v->name->getstadiumName() + ".\n";
        }
        else{
            //std::cout << "Discovered edge: " << e->endpoints.second->name->getstadiumName() << ", " << e->weight << " miles from " << v->name->getstadiumName() << ".\n";
            temp += "Discovered edge: " + e->endpoints.second->name->getstadiumName() + ", " + QString::number(e->weight) + " miles from " + v->name->getstadiumName() + ".\n";
        }
        sum += e->weight;

        return temp;
    }

    virtual QString traverseBack(adjEdge<value, dist>* e, adjNode<value, dist>* from) {
        QString temp = "";

        if(e->endpoints.first->name == from->name){
            //std::cout << "Back edge: " << e->endpoints.second->name->getstadiumName() << " from " << from->name->getstadiumName() << " (" << e->weight << " miles)\n";
            temp += ("Back edge: " + e->endpoints.second->name->getstadiumName() + " from " + from->name->getstadiumName() + " (" + QString::number(e->weight) + " miles)\n");
        }
        else{
            //std::cout << "Back edge: " << e->endpoints.first->name->getstadiumName() << " to " << from->name->getstadiumName() << " (" << e->weight << " miles)\n";
            temp += "Back edge: " + e->endpoints.first->name->getstadiumName() + " to " + from->name->getstadiumName() + " (" + QString::number(e->weight) + " miles)\n";
        }

        return temp;
    }

    virtual void finishVisit(const adjNode<value, dist>* v) {
        // std::cout << "Completed a visit to " << v->name << ". Total distance traveled so far: " << sum << " miles\n";
    }

    bool isDone() const { return false; }
};

#endif // ADJACENCYLIST_H
