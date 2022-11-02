#ifndef USER_H
#define USER_H
#include <QString>

/**
 * @brief A class to represent a user.
 */
/*!
 * The stadium data class contains eight(8) private data members:\n
 * firstName       :   Qstring.........................the first name of the user.\n
 * lastName        :   Qstring.....................the last name of the user.\n
 * email           :   Qstring.........................the email of the user.\n
 * password        :   Qstring.....................the password of the user.\n
 * permission      :   int.....................determine the status and permissions of user\n\n
 * Getters and setter functions all exist. A constructor with default values exists, and takes an\n
 * It is not reccomended to use Default values for any reason except to create a temporary food item.
*/

class user
{
public:
    /*!
     * \brief user is a default constructor
     */
    user();

    /*!
     * \brief user is a alternate constructor
     * \param fName is the first name of the user
     * \param lName is the last name of the user
     * \param mail is the email of the user
     * \param pass is the password of the user
     * \param permis is the permission of the user
     *
     * This function sets all the user's information
     */
    user(QString fName, QString lName, QString mail, QString pass, int permis);

    /*!
     * \brief setFirstName is a member function with a perameter
     * \param fName is the first name of the user
     *
     * This function sets the first name of the user
     */
    void setFirstName(QString fName);

    /*!
     * \brief setLastName is a member function
     * \param lName is the last name of the user
     *
     * This function sets the last name of the user
     */
    void setLastName(QString lName);

    /*!
     * \brief setEmail is a member function
     * \param mail is the email of the user
     *
     * This function sets the email of the user
     */
    void setEmail(QString mail);

    /*!
     * \brief setPassword is a member function
     * \param pass is the password of the user
     *
     * This function sets the password of the user
     */
    void setPassword(QString pass);

    /*!
     * \brief setPermission is a member function
     * \param permis is the permission setting of the user
     *
     * This function sets the permission setting of the user
     */
    void setPermission(int permis);

    /*!
     * \brief getFirstName is a member function
     * \return a QString variable with first name
     *
     * This function returns the first name of the user
     */
    QString getFirstName();

    /*!
     * \brief getLastName is a member function
     * \return a QString variable with last name
     *
     * This function returns the last name of the user
     */
    QString getLastName();

    /*!
     * \brief getEmail is a member function
     * \return a QString variable with email
     *
     * This function returns the email of the user
     */
    QString getEmail();

    /*!
     * \brief getPassword is a member function
     * \return  a QString variable with password
     *
     * This function returns the password of the user
     */
    QString getPassword();

    /*!
     * \brief getPermission is a member function
     * \return  a QString variable with permission
     *
     * This function returns the permission id of the user
     */
    int getPermission();

private:
    QString firstName;/**< the first name of the user*/
    QString lastName;/**< the last name of the user*/
    QString email;/**< the email of the user*/
    QString password;/**< the password of the user*/
    int permission;/**< determine the status and permissions of user*/

};

#endif // USER_H
