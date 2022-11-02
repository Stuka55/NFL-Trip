#include "stadium.h"

Stadium::Stadium()
{
    id = 0;
    stadiumName     = "NO NAME";
    capacity        = 0;
    location        = "NO LOCATION";
    division        = "NO DIVISION";
    surfaceType     = "NO SURFACE TYPE";
    surfaceRoofType = "NO ROOF TYPE";
    dateOpened      = 0;
}
Stadium::Stadium(int id, QString stadiumName,int capacity,
                 QString location, QString division, QString conference, QString surfaceType,
                 QString surfaceRoofType,int dateOpened)
{
    this->id              = id;
    this->stadiumName     = stadiumName;
    this->capacity        = capacity;
    this->location        = location;
    this->division        = division;
    this->conference      = conference;
    this-> surfaceType    = surfaceType;
    this->surfaceRoofType = surfaceRoofType;
    this->dateOpened      = dateOpened;
}

Stadium::Stadium(const Stadium& other)
    :
      id(other.id),
      stadiumName(other.stadiumName),
      capacity(other.capacity),
      location(other.location),
      division(other.division),
      conference(other.conference),
      surfaceType(other.surfaceType),
      surfaceRoofType(other.surfaceRoofType),
      dateOpened(other.dateOpened)
{}

Stadium::~Stadium() {} // default destructor

// ------------------- All getters--------------------------
int Stadium::getID() const                  {return id;}
QString Stadium::getstadiumName() const     {return stadiumName;}
int Stadium::getcapacity() const            {return capacity;}
QString Stadium::getlocation() const        {return location;}
QString Stadium::getdivision() const        {return division;}
QString Stadium::getConference() const      {return conference;}
QString Stadium::getsurfaceType() const     {return surfaceType;}
QString Stadium::getsurfaceRoofType() const {return surfaceRoofType;}
int Stadium::getdateOpened() const          {return dateOpened;}
// ------------------- end of getters------------------------


// ------------------- all setters --------------------------
void Stadium::setID(const int& id)                               {this->id              = id ;}
void Stadium::setstadiumName(const QString& stadName)            {this->stadiumName     = stadName;}
void Stadium::setcapacity(const int& capacity)                   {this->capacity        = capacity;}
void Stadium::setlocation(const QString& location)               {this->location        = location;}
void Stadium::setdivision(const QString& division)               {this->division        = division;}
void Stadium::setConference(const QString& conference)           {this->conference      = conference;}
void Stadium::setsurfaceRoofType(const QString& surfaceRoofType) {this->surfaceRoofType = surfaceRoofType;}
void Stadium::setsurfaceType(const QString& surfaceType)         {this->surfaceType     = surfaceType;}
void Stadium::setdateOpened(const int& dateOpened)               {this->dateOpened      = dateOpened;}
// ------------------- end of getters------------------------
// end of getters and setters
