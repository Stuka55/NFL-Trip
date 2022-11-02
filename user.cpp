#include "user.h"

user::user()
{
    firstName  = ' ';
    lastName   = ' ';
    email      = ' ';
    password   = ' ';
    permission = 0;
}

user::user(QString fName, QString lName, QString mail, QString pass, int permis)
{
    firstName  = fName;
    lastName   = lName;
    email      = mail;
    password   = pass;
    permission = permis;
}

void user::setFirstName(QString fName)
{
    firstName = fName;
}

void user::setLastName(QString lName)
{
    lastName = lName;
}

void user::setEmail(QString mail)
{
    email = mail;
}

void user::setPassword(QString pass)
{
    password = pass;
}

void user::setPermission(int permis)
{
    permission = permis;
}

QString user::getFirstName()
{
    return firstName;
}

QString user::getLastName()
{
    return lastName;
}

QString user::getEmail()
{
    return email;
}

QString user::getPassword()
{
    return password;
}

int user::getPermission()
{
    return permission;
}
