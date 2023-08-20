#include "database.h"

// Author: Danny Cowles

database::database(const QString& path)
{
    //Gives the database object a name and adds a path to the .db file which will be "college.db"
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    //Ensure that the database connection was successfully opened
    if (!db.open())
    {
        qDebug() << "Connection with database unsuccessful";
    }
    else
    {
        qDebug() << "Connection with database successful";
    }

}

database::~database()
{
    //closes the database connection when database object is deleted
//    db.close(); Riley commented this out as a temporary fix, I will remove it once my problem is fixed

    qDebug() << "Database connection closed";
}

bool database::addCollege(const College& newCollege)
{
    //retrieve information from college object so it can be sent into the database
    QString name = newCollege.name();
    QString state = newCollege.state();
    int undergrads = newCollege.undergrads();
    QString souvenirsText = getSouvenirText(newCollege.souvenirs());
    QString distanceText = getDistanceText(newCollege.distances());

    qDebug() << distanceText;

    int id = newCollege.id();

    //create an insert query with the parameters to load the table
    QSqlQuery query;
    query.prepare("INSERT INTO COLLEGES VALUES (:ID, :NAME, :STATE, :UNDERGRADS, :DISTANCES, :SOUVENIRS)");

    //bind college information to their respective columns
    query.bindValue(":ID", id);
    query.bindValue(":NAME", name);
    query.bindValue(":STATE", state);
    query.bindValue(":UNDERGRADS", undergrads);
    query.bindValue(":DISTANCES", distanceText);
    query.bindValue(":SOUVENIRS", souvenirsText);

    //ensure that the college was successfully added to the database
    if (query.exec())
    {
        qDebug() << "College successfully added to database";

        return true;
    }
    else
    {
        qDebug() << "Error: Could not add college to database";

        //debugging tools for determining the possible errors for why the college wasn't added to the database
        qDebug() << query.lastError().text();
        qDebug() << query.lastQuery();

        return false;
    }

}

void database::deleteAllColleges()
{
    //deletes all rows from the colleges table in the database
    QSqlQuery query("DELETE FROM COLLEGES");

    //ensure that all colleges were deleted from the database
    if (query.exec())
    {
        qDebug() << "Database: All colleges successfully deleted!";
    }
    else
    {
        qDebug() << "Error: Could not remove all colleges from the database";
    }
}

int database::getCollegeCount() const
{
    QSqlQuery query("SELECT * FROM COLLEGES");

    int numRows = 0;

    //calculates how many colleges are in the database
    if (query.last())
    {
        numRows = query.at() + 1;
    }

    return numRows;
}

College database::getCollegeByName(const QString name) const
{
    //create college object
    College newCollege;

    //create a query that adds a bind value to the desired name
    QSqlQuery query;
    query.prepare("SELECT * FROM COLLEGES WHERE NAME = ?");
    query.addBindValue(name);
    query.exec();
    query.next();

    //retrieve a record
    auto rec = query.record();

    //add error checking here for if name does not exist
    newCollege = getCollegeFromRecord(rec);

    return newCollege;
}

College database::getCollegeFromRecord(const QSqlRecord &record) const
{
    //create college object
    College newCollege;

    //retrieve name and set college object's name
    QString name = record.value("NAME").toString();
    newCollege.setName(name);

    //retrieve state and set college object's state
    QString state = record.value("STATE").toString();
    newCollege.setState(state);

    //retrive undergrads and set college object's undergrads
    int undergrads = record.value("UNDERGRADS").toInt();
    newCollege.setUndergrads(undergrads);

    //retrieve ID and set college object's ID
    int id = record.value("ID").toInt();
    newCollege.setId(id);

    //retrieve distances from the database
    auto distanceText = record.value("DISTANCES").toString().split(" : ");

    //retrieves souvenirs from the database
    auto souvenirsText = record.value("SOUVENIRS").toString();

    //splits the distanceText string by commas
    for (unsigned i = 0, n = distanceText.size(); i < n; ++i)
    {
        QString pair = distanceText[i];
        int gap = pair.indexOf('-');

        //retrieves ID before - character
        QString ID = pair.mid(0, gap);

        //retrieves distance after space character
        float distance = pair.mid(gap + 1).toFloat();

        //for debugging and testing making sure the distances are correct
        qDebug() << "getCollegeFromRecord() id and distance:";
        qDebug() << ID;
        qDebug() << distance;

        //sets the distances in the distance map (ID, distance)
        newCollege.addDistance(ID, distance);
    }

    auto items = souvenirsText.split(", ");

    for (const QString& x: items)
    {
        int index = x.indexOf('$');

        //gets souvenirs name which is the text before the dollar sign, removes the space
        QString souvenirName = x.mid(0, index - 1);

        //gets souvenirs price which is the text after the dollar sign, and converts that text to float
        float souvenirPrice = x.mid(index + 1).toFloat();

        newCollege.addSouvenir(souvenirName, souvenirPrice);
    }

    qDebug() << "Printing college data in getCollegeFromRecord()";
    //newCollege.print();

    return newCollege;
}

map::unordered_map<int, College> database::getColleges() const
{
    //holds the college object that is currently being taken from the database
    College currentCollege;

    //map to hold (college name, college object)
    map::unordered_map<int, College> collegeMap;

    //select all columns of all rows of the COLLEGES table
    QSqlQuery query("SELECT * FROM COLLEGES");

    //converts each record in the database into a college object and add it to the college map
    while (query.next()){
        currentCollege = getCollegeFromRecord(query.record());

        collegeMap.insert(map::pair(currentCollege.id(), currentCollege));
    }

    //returns the college map
    return collegeMap;

}

bool database::updateCollege(const College& college)
{
    //retrieves information from the college object
    QString name = college.name();
    QString state = college.state();
    int undergrads = college.undergrads();
    QString souvenirsText = getSouvenirText(college.souvenirs());
    QString distanceText = getDistanceText(college.distances());
    int id = college.id();

    //creates a query to update colleges in the row where name is the name of the college object being updated
    QSqlQuery query;
    query.prepare("UPDATE COLLEGES SET ID = :ID, NAME = :NAME, STATE = :STATE, UNDERGRADS = :UNDERGRADS, DISTANCES = :DISTANCES, "
                  "SOUVENIRS = :SOUVENIRS WHERE NAME = :NAME");

    query.bindValue(":ID", id);
    query.bindValue(":NAME", name);
    query.bindValue(":STATE", state);
    query.bindValue(":UNDERGRADS", undergrads);
    query.bindValue(":DISTANCES", distanceText);
    query.bindValue(":SOUVENIRS", souvenirsText);

    //ensure that the college was successfully updated to the database
    if (query.exec())
    {
        qDebug() << "College successfully updated to database";

        return true;
    }
    else
    {
        qDebug() << "Error: Could not update college";

        //debugging tools for determining the possible errors for why the college wasn't added to the database
        qDebug() << query.lastError().text();
        qDebug() << query.lastQuery();

        return false;
    }
}

void database::resetWithFile()
{
    //first clear the database
    deleteAllColleges();

    std::vector<College> collegeVec;
    parser parse;

    //reads in the initial files for the 11 colleges
    parse.read(collegeVec, "inputfile.csv", "souvenirs.csv");

    for (int i = 0; i < 11; i++)
    {
        //assigns college an ID and a distance to itself of 0
        collegeVec[i].setId(i+1);
        collegeVec[i].addDistance(collegeVec[i].name(), 0);

        //prints relevant college information
        collegeVec[i].print();

        //adds college to the database
        addCollege(collegeVec[i]);
    }

}

void database::addAdminColleges()
{
    std::vector<College> newCollegeVec;
    parser parse;

    //reads in the files for the new data
    parse.read(newCollegeVec, "newinputfile.csv", "newsouvenirs.csv");

    for (int i = 0; i < 2; i++)
    {
        //sets ID of the college to values past 11 and adds the distance to itself of 0
        newCollegeVec[i].setId(i+12);
        newCollegeVec[i].addDistance(newCollegeVec[i].name(), 0);

        //retrieves the new colleges distances to all other colleges
        auto newDistances = newCollegeVec[i].distances();

        //retrieves the map of colleges in the database
        auto colleges = getColleges();

        //loops through colleges map, in order to add distances from the initial 11 colleges, to the new college
        for (auto& x: colleges)
        {
            float foundDistance = 0.0;

            //determines the distance from 1 -> 2 so we can also set 2 -> 1 example
            for (auto itr = newDistances.begin(); itr != newDistances.end(); itr++)
            {
                if (itr->first == x.second.name())
                {
                    foundDistance = itr->second;
                }
            }

            //adds distance from the initial college to the new college
            x.second.addDistance(newCollegeVec[i].name(),foundDistance);

            //updates the modified college
            updateCollege(x.second);
        }

        //adds the new college to the database
        addCollege(newCollegeVec[i]);
    }
}

QString database::getSouvenirText(const std::vector<Souvenir>& souvenirs) const
{
    QString souvenirsText = "";

    for (unsigned i = 0; i < souvenirs.size(); i++)
    {
        //adds souvenir name (first = name, second = price)
        souvenirsText += souvenirs[i].name() + " ";

        //adds dollar sign and souvenir price to the string
        souvenirsText += "$" + QString::number(souvenirs[i].price());

        //adds a comma unless you reach the last souvenir in the vector
        if (i != souvenirs.size() - 1)
        {
            souvenirsText += ", ";
        }
    }

    return souvenirsText;
}

QString database::getDistanceText(const map::unordered_map<QString, float> &distances) const
{
    //this will hold the formatted distance information for the college
    QString distanceText = "";

    unsigned i = 0;
    for (auto x: distances)
    {
        //converts float distance to a QString and adds it to the distance text for the database
        distanceText += x.first + "-" + QString::number(x.second);

        //adds a comma unless you reach the last distance in the map
        if (i != distances.size() - 1)
        {
            distanceText += " : ";
        }

        i++;

    }

    return distanceText;
}






