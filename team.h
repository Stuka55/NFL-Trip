#ifndef TEAM_H
#define TEAM_H

#include <QString>
#include <QVector>
#include "team_souvenir.h"


class team
{
public:
   /*!
    * \brief team is the default constructor
    *
    * This function initializes all the team's information.
    */
   team();

   /*!
    * \brief team is an alternate constructor
    * \param teamN is the name of the team
    * \param teamId is the id of the team
    * \param stadID is the id of the stadium
    *
    * This function initializes all the team's information to the values passed into the
    * alternate constructor.
    */
   team(QString teamN, int teamId, int stadID);

   /**
    * @brief Copy constructor.
    * @param other A team to copy.
    */
   team( const team& other);

   /**
    * @brief Overloaded assignment copy operator.
    * @param other A team to copy.
    * @return A reference to this team for cascading assignment.
    */
   team& operator=(const team& other);

   ~team();

   /*!
    * \brief getTeamName is a public member function
    * \return a QString variable is returned (team name)
    *
    * This function returns the team name of the team
    */
   QString getTeamName();

   /*!
    * \brief getId is a public member function
    * \return an int variable is returned (team id)
    *
    * This function returns the id of the team
    */
   int getId();

   /*!
    * \brief getStadiumId is a public member function
    * \return an int variable is returned (stadium Id)
    *
    * This function returns the stadium id of the team
    */
    int getStadium();

   /*!
    * \brief getSouvenirs is a public member function
    * \return a  QVector<Team_Souvenir> reference is returned (souvenirs)
    *
    * This function returns the reference to the vector conatining all the souvenirs of the team
    */
   QVector<Team_Souvenir*> getSouvenirs();

   /**
    * @brief Setter for the teamName data member.
    * @param name is a QString used to set teamName.
    */
   void setTeamName(QString name);

   /**
    * @brief Setter for the id data member.
    * @param iD is an int used to set id.
    */
   void setId(int iD);

   /**
    * @brief Setter for the stadiumId data member.
    * @param iD is an int used to set stadiumId.
    */
   void setStadium(int sta);

   /**
    * @brief Add a souvenier to the team. The team does not own the souvenir.
    * @param s A pointer to a team's souvenir.
    */
   void addSouvenir(Team_Souvenir* s);

   /**
    * @brief Clear all the souvenirs in the team. Does not deallocate their memory.
    */
   void clearSouvenir();

  private:
   QString teamName;  /**< The team's name */
   int id;  /**< The team's id. Each team has a unique id */
   int teamStadium;  /**< The team's stadium id. Each stadium id is unique */

   QVector<Team_Souvenir*> souvenirs;  /**< The total list of souvenirs each team has */

};

#endif // TEAM_H
