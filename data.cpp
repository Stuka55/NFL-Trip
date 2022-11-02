#include "data.h"

data::data()
{
}

bool data::empty() { return teams.empty(); }

team data::getTeam_Alphabet(int index) const{
    return *teams_alphabet.at_index(index);
}

team data::getTeam_Alphabet(const QString& name) {
    return *teams_alphabet[name];
}

team data::getTeam_Stadium(int index) const{
    return *teams_stadium.at_index(index);
}
team data::getTeam_Stadium(const QString& name){
    return *teams_stadium[name];
}

team data::getTeam_Date(int index) const{
    return *teams_date.at_index(index);
}
team data::getTeam_Date(const QString& date){
    return *teams_alphabet[date];
}

team& data::getTeam_ID(const int id){
    return *teams_id[id];
}


team data::getTeam_Capacity(int index) const{
    return *teams_capacity.at_index(index);
}

team data::getTeam_Conference(int index) const{
    return *teams_conf.at_index(index);
}

Stadium& data::getStadium_ID(const int id) {
    return *stadiums_id[id];
}

Stadium* data::getStadium_index(const int index) const{
    return stadiums[index];
}

int data::getTeamsSize() const{
    return teams.size();
}

int data::getStadiumsSize() const{
    return stadiums.size();
}

int data::getSouvenirSize() const{
    return souvenirs.size();
}

void data::addTeam(team* t)
{
    teams.push_back(t);
    teams_alphabet.insert(t, t->getTeamName());
    teams_date.insert(t, getStadium_ID(t->getStadium()).getdateOpened());
    teams_stadium.insert(t, getStadium_ID(t->getStadium()).getstadiumName());
    teams_capacity.insert(t, getStadium_ID(t->getStadium()).getcapacity());
    teams_conf.insert(t, getStadium_ID(t->getStadium()).getConference());
    teams_id.insert(t, t->getId());
    return;
}

void data::addSouvenir(const int teamID, Team_Souvenir *s){
    getTeam_ID(teamID).addSouvenir(s);
    souvenirs.push_back(s);
}

void data::addStadium(Stadium* s)
{
    stadiums.push_back(s);
    stadiums_id.insert(s, s->getID());
    stadiums_alphabet.insert(s, s->getstadiumName());
    stadiums_graph.insertVertex(s);
    return;
}

void data::addDistance(const int stadium1, const int stadium2, const int distance){
    stadiums_graph.insertEdge(stadiums_id[stadium1], stadiums_id[stadium2], distance);
    return;
}

QStringList data::getDFS(const QString& stadium1){
    QStringList temp = stadiums_graph.getDFS(stadiums_alphabet[stadium1]);
    return temp;
}

QStringList data::getBFS(const QString& stadium1){
    return stadiums_graph.getBFS(stadiums_graph[stadiums_alphabet[stadium1]]);
}

QStringList data::getMST(){
    return stadiums_graph.getMST();
}


std::vector<int> data::getDjikstra(const QString& stadium1){
    return stadiums_graph.djikstras(stadiums_graph[stadiums_alphabet[stadium1]]);
}

int data::getDistance(const QString& stadium1, const QString& stadium2){
    int stad2IPos = getPosOfStadiumInGraph(stadium2);

    return getDjikstra(stadium1).at(stad2IPos);
}

Stadium& data::getStadium_Alphabet(const QString& name){
    return *stadiums_alphabet[name];
}

std::vector<adjEdge<Stadium*, int>*> data::getEdges(){
    return stadiums_graph.edges();
}

std::vector<Stadium*> data::getStadiums(){
    return stadiums;
}
std::vector<team*> data::getTeams(){
    return teams;
}
std::vector<Team_Souvenir*> data::getSouvenirs(){
    return souvenirs;
}

bool data::eraseDistance(const QString& stadFrom, const QString& stadTo){
    return stadiums_graph.eraseEdge(stadiums_graph[stadiums_alphabet[stadFrom]], stadiums_graph[stadiums_alphabet[stadTo]]);
}

void data::rename_Stadium(const QString& oldName, const QString& newName){
    Stadium* stad;
    for(auto e : stadiums){
        if(e->getstadiumName() == oldName){
            e->setstadiumName(newName);
            stad = e;
            break;
        }
    }

    stadiums_alphabet.erase(oldName);
    stadiums_alphabet.insert(stad, newName);
}

void data::clear(){
    teams_alphabet.clear();
    teams_date.clear();
    teams_stadium.clear();
    teams_capacity.clear();
    teams_conf.clear();
    teams_id.clear();
    stadiums_alphabet.clear();
    stadiums_id.clear();
    stadiums_graph.clear();

    for(auto e : stadiums)
        delete e;

    for(auto e : teams)
        delete e;

    for(auto e : souvenirs)
        delete e;


    stadiums.clear();
    teams.clear();
    souvenirs.clear();
}

void data::clearSouvenirs(const QString& teamName){
    team* t = teams_alphabet[teamName];

    for(int i = 0; i < t->getSouvenirs().size(); i++){
        souvenirs.erase(std::find(souvenirs.begin(), souvenirs.end(), t->getSouvenirs()[i]));
        delete t->getSouvenirs()[i];
    }



    t->clearSouvenir();
}

Stadium* data::getStadiumByPosInGraph(const int pos){
    return stadiums_graph[pos]->name;
}

Stadium* data::getStadium_ptrID(const int id){
    return stadiums_id[id];
}

int data::getPosOfTeamInGraph(const QString& team){
    return stadiums_graph[getStadium_ptrID(teams_alphabet[team]->getStadium())]->pos;
}

int data::getPosOfStadiumInGraph(const QString& stadium1){
    return stadiums_graph[&getStadium_Alphabet(stadium1)]->pos;
}

bool data::teamExists(const QString &teamName){
    return teams_alphabet[teamName]->getTeamName() == teamName;
}
