#include "team_souvenir.h"

Team_Souvenir::Team_Souvenir(const QString& name, const double price, const int id, const int team_id) :
    id{ id },
    name{ name },
    price{ price },
    team_id{ team_id }
{}


// Getters

int Team_Souvenir::getID() const
{
    return id;
}

QString Team_Souvenir::getName() const
{
    return name;
}
double Team_Souvenir::getPrice() const
{
    return price;
}

int Team_Souvenir::getTeamId() const
{
    return team_id;
}

// Setters

void Team_Souvenir::setID(const int id)
{
    this->id = id;
    return;
}

void Team_Souvenir::setName(const QString& name)
{
    this->name = name;
    return;
}

void Team_Souvenir::setPrice(const double price)
{
    this->price = price;
    return;
}

void Team_Souvenir::setTeamID(const int team_id)
{
    this->team_id = team_id;
    return;
}
