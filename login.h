#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QVector>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtDebug>
#include <QMessageBox>
#include "user.h"
#include "monke.h"

namespace Ui {
class login;
}

/*!
 * \brief The login class
 * \variable accounts is a vector of users
 * \variable adminLog is a boolean
 */
/*!
 * \brief The login class
 */
/*!
 * The login class contains three private data members\n
 * accounts : QVector<user>...Holds all of the accounts in the database.\n
 * db       : QSqlDatabase....Manages the connection between the program and the database.\n
 * adminLog : bool............Determines if the logged in user is an admin or not.\n\n
 */
class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);

    /*!
     * \brief addData
     * \return a boolean value
     *
     * Adds the account data to compare the user input.
     */
    void addData();

    /*!
     * \brief checkLoginInfo
     * \param email is the email of the user
     * \param pass is the password of the user
     * \return a boolean value
     *
     * If the email and password matches a user in the database
     * then return true, otherwise false.
     */
    bool checkLoginInfo(QString email, QString pass);

    /*!
     * \brief isAdmin
     * \return a boolean value
     *
     * If the user is a verified admin then return true,
     * otherwise false.
     */
    void isAdmin(QString email);

    ~login();

private slots:
    void on_pushButton_clicked();

signals:
    /*!
     * \brief userIsAdmin is a member function
     *
     * function gives new ui options such as changing data
     */
    void userIsAdmin();
    /*!
     * \brief monkie is monkie
     *
     * monkie much confused.
     */
    void monkie();

private:
    Ui::login *ui;

    QVector<user> accounts;
    QSqlDatabase db;
    bool adminLog;
};

#endif // LOGIN_H
