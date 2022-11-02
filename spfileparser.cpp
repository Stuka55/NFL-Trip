#include "spfileparser.h"

SPFileParser::SPFileParser(class data& dat)
    :
      dat(dat)
{

}


bool SPFileParser::read(const QString& filedir, QStringList& ErrorMessage) const {
    ErrorMessage.clear();

    QFile file(filedir);
    QTextStream c(&file);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        ErrorMessage.clear();
        ErrorMessage << "Error opening file.";
        return false;
    }
    else{
        QVector<Stadium> tempStad;
        QVector<team> tempTeam;
        QVector<QPair<QPair<int,int>,int>> tempDistances;

        int stad_offset = -1;

        while (!c.atEnd()){
            QString currentLine = c.readLine();

            currentLine = currentLine.simplified().replace(' ', "");

            if(currentLine.isEmpty()){
                continue;
            }
            if(currentLine[0] == '@'){
                continue;
            }
            if(currentLine == "newStadium{"){
                stad_offset++;
                QString stadLine = c.readLine();
                QString copyStad = stadLine;
                copyStad = copyStad.simplified().replace(' ', "");

                Stadium tempStadium;
                int thisID = dat.getStadium_ID(INT32_MAX).getID() + 1 + stad_offset;
                tempStadium.setID(thisID);

                while(copyStad != '}'){

                    if(copyStad.isEmpty()){

                    }
                    else{
                        QString l = stadLine.left(stadLine.indexOf('='));
                        QString r = stadLine.right(stadLine.size() - stadLine.indexOf('=') - 1);
                        l = l.simplified().replace(' ', "");
                        r = r.simplified();

                        if(l == "name"){
                            tempStadium.setstadiumName(r);
                        }
                        else if(l == "seating"){
                            bool isNum;
                            int s = r.toInt(&isNum);
                            if(!isNum)
                                tempStadium.setcapacity(0);
                            else
                                tempStadium.setcapacity(s);
                        }
                        else if(l == "location"){
                            tempStadium.setlocation(r);
                        }
                        else if(l == "conference"){
                            tempStadium.setConference(r);
                        }
                        else if(l == "division"){
                            tempStadium.setdivision(r);
                        }
                        else if(l == "surface"){
                            bool isNum;
                            int s = r.toInt(&isNum);
                            if(s >= SurfaceTypes.size() || !isNum)
                                tempStadium.setsurfaceType(SurfaceTypes[0]);
                            else
                                tempStadium.setsurfaceType(SurfaceTypes[s]);
                        }
                        else if(l == "roof"){
                            bool isNum;
                            int s = r.toInt(&isNum);
                            if(s >= RoofTypes.size() || !isNum)
                                tempStadium.setsurfaceRoofType(RoofTypes[0]);
                            else
                                tempStadium.setsurfaceRoofType(RoofTypes[s]);
                        }
                        else if(l == "date"){
                            bool isNum;
                            int s = r.toInt(&isNum);
                            if(!isNum)
                                tempStadium.setdateOpened(0);
                            else
                                tempStadium.setdateOpened(s);
                        }
                        else if(l == "teams+"){
                            if(tempStadium.getstadiumName().isEmpty()){
                                ErrorMessage.clear();
                                ErrorMessage << "Error: Teams delcared before stadium given a name.";
                                ErrorMessage << "Line: " + stadLine;
                                return false;
                            }
                            else{
                                QString teamLine;
                                if(r.isEmpty()){
                                    ErrorMessage.clear();
                                    ErrorMessage << "Invalid team syntax.";
                                    ErrorMessage << "Line: " + stadLine;
                                    return false;
                                }
                                else if(!r.contains('\\')){
                                    tempTeam.push_back(team{r, dat.getTeam_ID(INT32_MAX).getId() + 1, thisID});
                                }
                                else {
                                    teamLine = c.readLine();
                                    tempTeam.push_back(team{r.replace('\\', "").simplified(), dat.getTeam_ID(INT32_MAX).getId() + 1 + tempTeam.size(), thisID});
                                    while(teamLine.contains('\\')){
                                        tempTeam.push_back(team{teamLine.replace('\\', "").simplified(), dat.getTeam_ID(INT32_MAX).getId() + 1 + tempTeam.size(), thisID});
                                        teamLine = c.readLine();
                                    }
                                    if(teamLine.isEmpty() || teamLine.contains('}') || teamLine.contains('=') || c.atEnd()){
                                        ErrorMessage.clear();
                                        ErrorMessage << "Invalid team syntax.";
                                        ErrorMessage << "Check if your team list\'s final item contains the '\\' character. It should not.";
                                        return false;
                                    }
                                    tempTeam.push_back(team{teamLine.simplified(), dat.getTeam_ID(INT32_MAX).getId() + 1 + tempTeam.size(), thisID});

                                }
                            }

                        }
                        else if(l == "distances+"){
                            QString  distLine;
                            if(r.isEmpty()){
                                ErrorMessage.clear();
                                ErrorMessage << "Invalid distance syntax.";
                                ErrorMessage << "Line: " + stadLine.simplified();
                                return false;
                            }
                            else if(!r.contains('\\')){
                                tempDistances.push_back({{thisID, r.left(r.indexOf(':')).simplified().toInt()}, (r.right(r.size() - distLine.indexOf(':') - 1)).simplified().toInt()});
                            }
                            else {
                                distLine = c.readLine();
                                tempDistances.push_back({{thisID, r.left(r.indexOf(':')).toInt()}, (r.right(distLine.size() - distLine.indexOf(':') - 1)).replace('\\',"").simplified().toInt()});
                                while(distLine.contains('\\')){
                                    tempDistances.push_back({{thisID, distLine.left(distLine.indexOf(':')).simplified().toInt()}, (distLine.right(distLine.replace('\\',"").simplified().size() - distLine.replace('\\',"").simplified().indexOf(':') - 1)).replace('\\',"").simplified().toInt()});
                                    distLine = c.readLine();
                                }
                                if(distLine.isEmpty() || distLine.contains('}')|| distLine.contains('=') || c.atEnd()){
                                    ErrorMessage.clear();
                                    ErrorMessage << "Invalid distance syntax.";
                                    ErrorMessage << "Check if your distance list\'s final item contains the '\\' character.";
                                    return false;
                                }
                                tempDistances.push_back({{thisID, distLine.left(distLine.indexOf(':')).simplified().toInt()}, (distLine.right(distLine.simplified().size() - distLine.simplified().indexOf(':') - 1)).simplified().toInt()});
                            }
                        }
                        else{
                            ErrorMessage.clear();
                            ErrorMessage << "Error: Unreadable line decected.";
                            ErrorMessage << "Line: " + stadLine.simplified();
                            return false;
                        }
                    }
                    stadLine = c.readLine();
                    copyStad = stadLine.simplified();
                    copyStad.replace(' ', "");

                }
                tempStad.push_back(tempStadium);

            }
            else{
                ErrorMessage.clear();
                ErrorMessage << "Error: Unreadable line detectected.";
                ErrorMessage << "Line: " + currentLine.simplified();
                return false;
            }
        }
        for(auto e : tempStad)
            dat.addStadium(new Stadium(e));
        for(auto e : tempTeam)
            dat.addTeam(new team(e));
        for(auto p : tempDistances){

            dat.addDistance(p.first.first, p.first.second, p.second);
            dat.addDistance(p.first.second, p.first.first, p.second);
        }
    }
    return true;
}
