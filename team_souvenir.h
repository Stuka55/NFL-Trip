#ifndef TEAM_SOUVENIR_H
#define TEAM_SOUVENIR_H

#include <QString>

/**
 * @brief A class to represent a souvenir.
 */
/*!
 * The souvenir data class contains four private data members:\n
 * id       :   int.....................An ID to represent a particular food item within a container.\n
 * name     :   QString.................A name for the food item.\n
 * price    :   double..................A price for the food item.\n
 * team_id  :   int.....................The ID of the team a given food item belongs to (see team.h).\n\n
 * Getters and setter functions all exist. A constructor with default values exists, and takes an\n
 * int (id), QString& (name), double (price), and finally an int (team_id).\n
 * It is not reccomended to use Default values for any reason except to create a temporary food item.
 */
class Team_Souvenir
{
public:
    /**
     * @brief Default constructor.
     * @param name A constant reference to a QString to set the name to.
     * @param price A constant double to set the price to.
     * @param id A constant int to set the id to.
     * @param team_id a constant int to set the team id to.
     */
    Team_Souvenir(const QString& name = "", const double price = 0.f, const int id = 0, const int team_id = 0);

    ~Team_Souvenir() {}

    // Getters

    /**
     * @brief Getter for "id" data member.
     * @return The ID of the souvenir.
     */
    int getID() const;

    /**
     * @brief Getter for the "name" data member.
     * @return The name of the city.
     */
    QString getName() const;

    /**
     * @brief Getter for the "price" data member.
     * @return The price of the souvenir.
     */
    double getPrice() const;

    /**
     * @brief Getter for the "team_id" data member.
     * @return The ID of the team associated to this souvenir.
     */
    int getTeamId() const;

    // Setters

    /**
     * @brief Setter for the "id" data member.
     * @param id A constant int to set the ID to.
     */
    void setID(const int id);

    /**
     * @brief Setter for the "name" data member.
     * @param name A constant reference to a QString to set the name to.
     */
    void setName(const QString& name);

    /**
     * @brief Setter for the "price" data member.
     * @param price A constant double to set the price to.
     */
    void setPrice(const double price);

    /**
     * @brief Setter for the "team_id" data member.
     * @param team_id A constant int to set the team ID to.
     */
    void setTeamID(const int team_id);

private:

    int id;             /**< An id for this individual type of souvenir. Each food item within the program should have it's own id. */
    QString name;       /**< A name for this individual type of souvenir. */
    double price;       /**< A price for the souvenir. */

    int team_id;        /**< The id of the Team this Souvenir is associated with. */

};

#endif // TEAM_SOUVENIR_H
