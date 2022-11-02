#include "team.h"

team::team()
{
    teamName = "NO NAME";  /**< The team's name */
    id = 0;  /**< The team's id. Each team has a unique id */
}


team::team(QString teamN, int teamId, int stadID)
{
    teamName = teamN;  /**< The team's name */
    id = teamId;  /**< The team's id. Each team has a unique id */
    teamStadium = stadID;
}

team::team( const team& other){
    teamName = other.teamName;
    id = other.id;
    teamStadium = other.teamStadium;

    for(int i = 0; i < other.souvenirs.size(); i++)
        souvenirs.push_back(new Team_Souvenir(other.souvenirs[i]->getName(), other.souvenirs[i]->getPrice(), other.souvenirs[i]->getID(), id));
}

team& team::operator=(const team& other){
    teamName = other.teamName;
    id = other.id;
    teamStadium = other.teamStadium;

    if(!souvenirs.empty()){
        for(auto e : souvenirs)
            delete e;
        souvenirs.clear();

        for(int i = 0; i < other.souvenirs.size(); i++)
            souvenirs.push_back(new Team_Souvenir(other.souvenirs[i]->getName(), other.souvenirs[i]->getPrice(), other.souvenirs[i]->getID(), id));
    }

    return *this;
}

team::~team(){
}

/*!
 * \brief getTeamName is a public member function
 * \return a QString variable is returned (team name)
 *
 * This function returns the team name of the team
 */
QString team::getTeamName()
{
    return teamName;
}

/*!
 * \brief getId is a public member function
 * \return an int variable is returned (team id)
 *
 * This function returns the id of the team
 */
int team::getId()
{
    return id;
}

/*!
 * \brief getStadiumId is a public member function
 * \return an int variable is returned (stadium Id)
 *
 * This function returns the stadium id of the team
 */
int team::getStadium()
{
    return teamStadium;
}

/*!
 * \brief getSouvenirs is a public member function
 * \return a  QVector<Team_Souvenir> reference is returned (souvenirs)
 *
 * This function returns the reference to the vector conatining all the souvenirs of the team
 */
QVector<Team_Souvenir*> team::getSouvenirs()
{
    return souvenirs;
}

/**
 * @brief Setter for the teamName data member.
 * @param name is a QString used to set teamName.
 */
void team::setTeamName(QString name)
{
    teamName = name;
}

/**
 * @brief Setter for the id data member.
 * @param iD is an int used to set id.
 */
void team::setId(int iD)
{
    id = iD;
}

/**
 * @brief Setter for the stadiumId data member.
 * @param iD is an int used to set stadiumId.
 */
void team::setStadium(int iD)
{
    teamStadium = iD;
}

void team::addSouvenir(Team_Souvenir* s){
    souvenirs.push_back(s);
}

void team::clearSouvenir(){
    souvenirs.clear();
}
