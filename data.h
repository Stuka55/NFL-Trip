#ifndef DATA_H
#define DATA_H

#include <vector>
#include "map.h"
#include "stadium.h"
#include "team.h"
#include "team_souvenir.h"
#include "AdjacencyList.h"


#include <QDebug>

/*!
 * \brief SurfaceTypes is a QStringList of the various kinds of Turfs for a stadium
 */
const QStringList SurfaceTypes = {
    "A-Turf Titan 50",
    "Bermuda Grass",
    "Desso GrassMaster",
    "FieldTurf™Classic HD",
    "FieldTurf™Revolution",
    "Hellas Matrix Turf",
    "Kentucky Bluegrass",
    "Platinum TE Paspalum",
    "UBU Speed Series S5-M Synthetic Turf",
    "UBU Sports Speed Series S5-M Synthetic Turf"
};

/*!
 * \brief RoofTypes is a QStringList of the various kinds of Roofs for a stadium
 */
const QStringList RoofTypes = {
    "Fixed",
    "Open",
    "Retractable"
};

/*!
 * \brief The data class:
 * This class is used to store all the data from the SQLite database.
 *
 * Public Members:
 *      data  : constructor
 *      ~data : destructor
 *      empty : checks to see if teams vector is empty
 *      addStadium : adds a Stadium to the data class
 *      addTeam : adds a team to the data class
 *      addSouvenir : adds a souvenir to the data class
 *      addDistance : adds a distance to the data class
 *      eraseDistance : deletes a specified edge
 *      renameStadium : renames a stadium
 *      getEdges : returns a vector of edges
 *      getStadiums : returns a vector of stadiums
 *      getTeams : returns a vector of teams
 *      getSouvenirs : returns a vector of souvenirs
 *
 *      getTeamsSize : returns the number of teams
 *      getStadiumsSize : returns the number of stadiums
 *      getSouvenirSize : returns the number of souvenirs
 *
 *      getTeam_Alphabet (index) : returns a team given an index
 *      getTeam_Alphabet (string) : returns a team given a string
 *      getTeam_Stadium (int) : returns a stadium given an index
 *      getTeam_Stadium (string) : returns a stadium given a string
 *      getTeam_Date(index) : returns a team given an index
 *      getTeam_Date(string) : returns a team given a string
 *
 *      getTeam_ID : returns a team reference by passing in an id
 *      getTeam_Capacity : returns a team by passing in a capacity
 *      getTeam_Conference : returns a team by passing in a conference
 *
 *      getStadium_ID : get a stadium by passing in an id
 *      getStadium_Alphabet : get a stadium by passing in a string
 *
 *      getDistance : returns distance between adjacent neighbors (pass in strings)
 *      getDistance : returns distace between adjacent neighbors (pass in int)
 *
 *      getStadium_index : returns a stadium given an index
 *
 *      getDFS : returns a QStringList of stadiums visited in via a Depth First Search (edges are later printed into a dialog box)
 *
 *      getBFS : returns a QStringList of stadiums visited in via a Breadth First Search (edges are later printed into a dialog box)
 *
 *      getMST : returns a QStringList of stadiums (a Minimum Spanning Tree)
 *
 *      printTeams : prints all the teams to the console (used for debugging)
 *
 *      clear : deletes all data in the object
 *      clearSouvenirs : deletes souvenirs given a team id
 *
 *      getDjikstra : gets the entire Dijkstra's distance between all the cities
 *
 *      getDistance : returns the shortest distance between two stadiums
 *
 *      teamExists : verifies that a team exists
 *      getStadiumByPosInGraph : gets the stadium at the postion in the vertex list in the graph
 *      getStadium_ptrID : gets the stadium from the map of stadiums sorted by id.
 *      getPosOfTeamInGraph : finds the position of the stadium that the team plays at in the graph's vertex list.
 *      getPosOfStadiumInGraph : finds the position of the stadium in graph
 *
 */
class data
{
public:

    /*!
     * \brief data is a default constructor.
     */
    data();

    /*!
     * \brief ~data is a destructor.
     *
     * This destructor destroys the object.
     */
    ~data(){
        for(auto e : stadiums)
            delete e;

        for(auto e : teams)
            delete e;

        for(auto e : souvenirs)
            delete e;
    }

    /*!
     * \brief empty checks to see if teams vector is empty.
     *  \return A boolean is returned (whether or not teams vector is empty).
     */
    bool empty();

    /*!
     * \brief addStadium adds a Stadium to the data class.
     * @param stadium object to be added
     *  \return void (no return)
     */

    void addStadium(Stadium* s);

    /*!
     * \brief addTeam adds a team to the data class.
     * @param team object to be added
     *  \return void (no return)
     */
    void addTeam(team* t);

    /*!
     * \brief addSouvenir adds a souvenir to the data class.
     * @param teamID: team id
     * @param s: souvenir object to be added
     *  \return void (no return)
     */
    void addSouvenir(const int teamID, Team_Souvenir* s);

    /*!
     * \brief addDistance adds a distance to the data class.
     * @param stadium1: stadium id
     * @param stadium2: stadium id
     * @param distance: distance between stadium1 and stadium2
     *  \return void (no return)
     */
    void addDistance(const int stadium1, const int stadium2, const int distance);

    /*!
     * \brief eraseDistance deletes a specified edge
     * @param stadFrom: string identifying the start stadium
     * @param stadTo: string identifying the ending stadium
     *  \return returns a bool
     */
    bool eraseDistance(const QString& stadFrom, const QString& stadTo);

    /*!
     * \brief rename_Stadium renames a stadium
     * @param oldName: string identifying which stadium you want to change
     * @param newName: new name of stadium
     *  \return void (no return)
     */
    void rename_Stadium(const QString& oldName, const QString& newName);

    /*!
     * \brief getEdges returns a vector of edges
     *  \return returns a vector of type adjEdge<Stadium*, int>
     */
    std::vector<adjEdge<Stadium*, int>*> getEdges();

    /*!
     * \brief getStadiums returns a vector of stadiums
     *  \return returns a vector of type Stadium* (a stadium pointer)
     */
    std::vector<Stadium*> getStadiums();

    /*!
     * \brief getTeams returns a vector of teams
     * \return returns a vector of type team* (team pointer)
     */
    std::vector<team*> getTeams();

    /*!
     * \brief getSouvenirs returns a vector of souvenirs
     * \return returns a vector of type  Team_Souvenir* (souvenir pointer)
     */
    std::vector<Team_Souvenir*> getSouvenirs();

    /*!
     * \brief getTeamsSize returns the number of teams
     * \return returns an integer
     */
    int getTeamsSize() const;

    /*!
     * \brief getStadiumsSize returns the number of stadiums
     * \return returns an integer
     */
    int getStadiumsSize() const;

    /*!
     * \brief getSouvenirSize returns the number of souvenirs
     * \return returns an integer
     */
    int getSouvenirSize() const;

    /*!
     * \brief getTeam_Alphabet returns a team given an index.
     * @param index: index identifying the team you want to access
     * \return returns a team object
     */
    team getTeam_Alphabet(int index) const;      // O(n)... use only when listing everything

    /*!
     * \brief getTeam_Alphabet returns a team given a string.
     * @param name: string identifying the team you want to access
     * \return returns a team object
     */
    team getTeam_Alphabet(const QString& name);  // O(logn)... use when you need to find a specific team.

    /*!
     * \brief getTeam_Stadium returns a stadium given an index.
     * @param index: index identifying the stadium you want to access
     * \return returns a stadium object
     */
    team getTeam_Stadium(int index) const;

    /*!
     * \brief getTeam_Stadium returns a stadium given a string.
     * @param name: string identifying the stadium you want to access
     * \return returns a stadium object
     */
    team getTeam_Stadium(const QString& name);

    /*!
     * \brief getTeam_Date returns a team given an index.
     * @param index: index identifying the stadium
     * \return returns a team object
     */
    team getTeam_Date(int index) const;

    /*!
     * \brief getTeam_Date returns a team given an date (string).
     * @param date: string identifying the stadium
     * \return returns a team object
     */
    team getTeam_Date(const QString& date);

    /*!
     * \brief getTeam_ID returns a team by passing in an id
     * @param id: index identifying the stadium
     * \return returns a team object reference
     */
    team& getTeam_ID(const int id);

    /*!
     * \brief getTeam_Capacity returns a team by passing in a capacity
     * @param index: the capacity of a stadium
     * \return returns a team object
     */
    team getTeam_Capacity(int index) const;

    /*!
     * \brief getTeam_Conference returns a team by passing in a conference
     * @param index: the conference the team is in
     * \return returns a team object
     */
    team getTeam_Conference(int index) const;

    /*!
     * \brief getStadium_ID get a stadium by passing in an id
     * @param id: the stadium id
     * \return returns a Stadium object reference
     */
    Stadium& getStadium_ID(const int id);

    /*!
     * \brief getStadium_Alphabet get a stadium by passing in an a string
     * @param name: the name of the stadium
     * \return returns a Stadium object reference
     */
    Stadium& getStadium_Alphabet(const QString& name);


    /*!
     * \brief getStadium_index returns a stadium given an index
     * @param id: the index of the stadium
     * \return returns a stadium pointer.
     */
    Stadium* getStadium_index(const int id) const;

    /*!
     * \brief getDFS returns a QStringList of stadiums visited in via a Depth First Search (edges are later printed into a dialog box)
     * @param stadium1: the start stadium of the DFS
     * \return returns a QStringList.
     */
    QStringList getDFS(const QString& stadium1);

    /*!
     * \brief getBFS returns a QStringList of stadiums visited in via a Breadth First Search (edges are later printed into a dialog box)
     * @param stadium1: the start stadium of the BFS
     * \return returns a QStringList.
     */
    QStringList getBFS(const QString& stadium1);

    /*!
     * \brief getMST returns a QStringList of stadiums (a Minimum Spanning Tree)
     * \return returns a QStringList.
     */
    QStringList getMST();

    /*!
     * \brief getDjikstra gets the entire Dijkstra's distance between all the cities
     * @param stadium1: the starting stadium
     * \return returns a vector of type int.
     */
    std::vector<int> getDjikstra(const QString& stadium1);

    /*!
     * \brief getDistance returns the shortest distance between two stadiums
     * @param stadium1: the starting stadium
     * @param stadium2: the ending stadium
     * \return returns an integer value (the distance between the two stadiums)
     */
    int getDistance(const QString& stadium1, const QString& stadium2);

    /*!
     * \brief printTeams prints all the teams to the console (used for debugging)
     * \return void (no return value)
     */
    void printTeams(){
        for(auto e : teams){
            qDebug() << e->getTeamName() << ",";
        }
    }

    /*!
     * \brief clear deletes all data in the object
     * \return void (no return value)
     */
    void clear();


    /*!
     * \brief teamExists verifies that a team exists
     * @param teamName : a QString that is passed in to identify the team
     * \return returns a boolean (true or false)
     */
    bool teamExists(const QString& teamName);


    /*!
     * \brief clearSouvenirs deletes souvenirs given a team id
     * @param teamID : int passed in to identify the given team
     * \return void (no return value)
     */

    void clearSouvenirs(const QString& teamName);

    /*!
     * \brief getStadiumByPosInGraph gets the stadium at the postion in the vertex list in the graph
     * @param pos : int passed in to identify the given stadium
     * \return returns a stadium pointer
     */
    Stadium* getStadiumByPosInGraph(const int pos);

    /*!
     * \brief getStadium_ptrID gets the stadium from the map of stadiums sorted by id.
     * @param id : int passed in to identify the given stadium
     * \return returns a stadium pointer
     */
    Stadium* getStadium_ptrID(const int id);

    /*!
     * \brief getPosOfTeamInGraph finds the position of the stadium that the team plays at in the graph's vertex list.
     * @param team : QString passed in to identify the given team
     * \return returns an int
     */
    int getPosOfTeamInGraph(const QString& team);

    /*!
     * \brief getPosOfStadiumInGraph finds the position of the stadium in graph
     * @param stadium1 : QString passed in to identify the given stadium.
     * \return returns an int
     */
    int getPosOfStadiumInGraph(const QString& stadium1);

private:


    std::vector<Stadium*> stadiums;
    std::vector<team*> teams;
    std::vector<Team_Souvenir*> souvenirs;

    sp::map<team*, QString> teams_alphabet;
    sp::map<team*, int> teams_id;
    sp::dictionary<team*, int> teams_date;
    sp::dictionary<team*, int> teams_capacity;
    sp::dictionary<team*, QString> teams_conf;

    sp::dictionary<team*, QString> teams_stadium;

    adjGraph<Stadium*, int> stadiums_graph;

    sp::map<Stadium*, int> stadiums_id;
    sp::map<Stadium*, QString> stadiums_alphabet;
};

#endif // DATA_H
