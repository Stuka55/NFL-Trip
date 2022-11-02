#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

void login::addData()
{
    user account;

    QSqlQuery q(db);

    q.exec("SELECT * FROM users");

    int FName      = q.record().indexOf("FName");
    int LName      = q.record().indexOf("LName");
    int Email      = q.record().indexOf("Email");
    int Password   = q.record().indexOf("Password");
    int Permission = q.record().indexOf("Permission");

    while(q.next())
    {
        account.setFirstName(q.value(FName).toString());
        account.setLastName(q.value(LName).toString());
        account.setEmail(q.value(Email).toString());
        account.setPassword(q.value(Password).toString());
        account.setPermission(q.value(Permission).toString().toInt());

        accounts.push_back(account);
    }

    q.finish();

}

bool login::checkLoginInfo(QString email, QString pass)
{
    bool validUser = false;
    int loop = 0;

    while(!validUser && loop != accounts.size())
    {
        if(accounts[loop].getEmail() == email && accounts[loop].getPassword() == pass)
        {
            validUser = true;
        }
        loop++;
    }

    return validUser;
}

void login::isAdmin(QString email)
{
    bool validAdmin = false;
    int loop = 0;

    while(!validAdmin && loop != accounts.size())
    {
        if(accounts[loop].getEmail() == email && accounts[loop].getPermission() == 1)
        {
            validAdmin = true;
        }
        loop++;
    }

    if(validAdmin)
    {
        emit userIsAdmin();

        this->close();

        if(email == "monkey")
            emit monkie();
    }
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    QString email;
    QString password;
    bool validUser;

    email = ui->userEdit->text();
    password = ui->passEdit->text();

    validUser = checkLoginInfo(email,password);

    if(validUser)
    {
        isAdmin(email);
    }
    else
    {
        QMessageBox::information(this, "Error", "Username and Password is not Correct");
    }
}
