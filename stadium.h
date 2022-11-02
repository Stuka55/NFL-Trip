#ifndef STADIUM_H
#define STADIUM_H
#include <QString>

/**
 * @brief A class to represent a stadium.
 */
/*!
 * The stadium data class contains eight(8) private data members:\n
 * id               :   int.........................An ID to represent a particular stadium item within a container.\n
 * stadiumName      :   QString.....................A name for the stadium object.\n
 * capacity         :   int.........................A number of available seats in a stadium.\n
 * location         :   QString.....................The location of where the stadium is based.\n
 * division         :   QString.....................The division of where the stadium is based.\n
 * surfaceType      :   QString.....................The type of grass that the field is composed of.\n
 * surfaceRoofType  :   QString.....................The type of roofing that the ceiling is composed of.\n
 * dateOpened       :   int.........................The year that the stadium opened.\n\n
 * Getters and setter functions all exist. A constructor with default values exists, and takes an\n
 * It is not reccomended to use Default values for any reason except to create a temporary food item.
 */


class Stadium
{
private:
    int     id;              /**< An ID to represent a particular stadium item within a container. */
    QString stadiumName;     /**< A name for the stadium object. */
    int     capacity;        /**< A number of available seats in a stadium. */
    QString location;        /**< The location of where the stadium is based. */
    QString division;        /**< The division of where the stadium is based. */
    QString conference;      /**< The conference of where the stadium is based. */
    QString surfaceType;     /**< The type of grass that the field is composed of. */
    QString surfaceRoofType; /**< The type of roofing that the ceiling is composed of. */
    int     dateOpened;      /**< The year that the stadium opened. */
public:

    Stadium();
    /**
     * @brief Overloaded constructor.
     * @param id A constant reference to an int to set said data member.
     * @param stadiumName A constant QString to set said data member.
     * @param capacity A constant int to set said data member.
     * @param location A constant QString to set said data member.
     * @param division A constant QString to set said data member.
     * @param surfaceType A constant QString to set said data member.
     * @param surfaceRoofType A constant QString to set said data member.
     * @param dateOpened a constant int to set said data member.
     */
    Stadium(int id, QString stadiumName,int capacity,
            QString location, QString division, QString conference, QString surfaceType,
            QString surfaceRoofType,int dateOpened);

    /**
     * @brief Stadium copy constructor.
     */
    Stadium(const Stadium& other);

    /**
     * @brief ~Stadium destructor
     */
    ~Stadium();

    //getters

    /**
     * @brief Getter for "id" data member.
     * @return The  of the stadium.
     */
    int getID() const;
    /**
     * @brief Getter for "stadiumName" data member.
     * @return The stadiumName of the stadium.
     */
    QString getstadiumName() const;
    /**
     * @brief Getter for "capacity" data member.
     * @return The capacity of the stadium.
     */
    int getcapacity() const;
    /**
     * @brief Getter for "location" data member.
     * @return The location of the stadium.
     */
    QString getlocation() const;
    /**
     * @brief Getter for "division" data member.
     * @return The division of the stadium.
     */
    QString getdivision() const;
    /**
     * @brief Getter for "conference" data member.
     * @return The conference of the stadium.
     */
    QString getConference() const;
    /**
     * @brief Getter for "surfaceType" data member.
     * @return The surfaceType of the stadium.
     */
    QString getsurfaceType() const;
    /**
     * @brief Getter for "surfaceRoofType" data member.
     * @return The surfaceRoofType of the stadium.
     */
    QString getsurfaceRoofType() const;
    /**
     * @brief Getter for "dateOpened" data member.
     * @return The dateOpened of the stadium.
     */
    int getdateOpened() const;

    //setters
    /**
     * @brief Setter for the "id" data member.
     * @param id A constant reference to an int to set said data member.
     */
    void setID(const int& id);
    /**
     * @brief Setter for the "stadiumName" data member.
     * @param stadiumName A constant QString to set said data member.
     */
    void setstadiumName(const QString& stadName);
    /**
     * @brief Setter for the "capacity" data member.
     * @param capacity A constant int to set said data member.
     */
    void setcapacity(const int& capacity);
    /**
     * @brief Setter for the "location" data member.
     * @param location A constant QString to set said data member.
     */
    void setlocation(const QString& location);
    /**
     * @brief Setter for the "division" data member.
     * @param division A constant QString to set said data member.
     */
    void setdivision(const QString& division);

    /**
     * @brief setConference
     * @param conference a constant to set said data member.
     */
    void setConference(const QString& conference);

    /**
     * @brief Setter for the "surfaceRoofType" data member.
     * @param surfaceRoofType A constant QString to set said data member.
     */
    void setsurfaceRoofType(const QString& surfaceRoofType);
    /**
     * @brief Setter for the "surfaceType" data member.
     * @param surfaceType A constant QString to set said data member.
     */
    void setsurfaceType(const QString& surfaceType);

    /**
     * @brief Setter for the "dateOpened" data member.
     * @param dateOpened a constant int to set said data member.
     */
    void setdateOpened(const int& dateOpened);
    // end of getters and setters
};

#endif // STADIUM_H
