#ifndef DATABASE_H
#define DATABASE_H

#include <QDebug>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QtSql>
#include <QSqlDatabase>
#include <QString>
#include <unordered_map>

#include "college.h"
#include "unordered_map"
#include "parser.h"

// Author: Danny Cowles

///
/// \brief The database class includes methods used to modify / add / delete / and retrieve college and souvenir information from the SQLite database
///
class database
{
public:
    ///
    /// \brief sets the database to the .db file
    /// \param path: location of the .db file in the folder
    ///
    database(const QString& path);

    ///
    /// \brief destructor closes the database
    ///
    ~database();

    ///
    /// \brief used to add a college object to the database
    /// \param newCollege: populated college object
    /// \return returns true if the college was successfully added to the database, else false
    ///
    bool addCollege(const College& newCollege);

    ///
    /// \brief used to remove all information from the database, clears all rows
    ///
    void deleteAllColleges();

    ///
    /// \brief retrieves the amount of colleges currently stored in the database
    /// \return returns the number of colleges
    ///
    int getCollegeCount() const;

    ///
    /// \brief given a name, it will retrieve the associated college object
    /// \param name: name of the college you would like to retrieve
    /// \return retusn the associated college object with the searched name
    ///
    College getCollegeByName(const QString name) const;

    ///
    /// \brief will retrieve all information from the database and create objects for each college, adding them to an unordered_map
    /// \return returns the map holding the colleges
    ///
    map::unordered_map<int, College> getColleges() const;

    ///
    /// \brief after any modifications are made in the program, use this method to update the database
    /// \param college: college object that changes were made on
    /// \return returns true if the college was updated, else false
    ///
    bool updateCollege(const College& college);

    ///
    /// \brief resets the database with the initial given data (the file)
    ///
    void resetWithFile();

    ///
    /// \brief called with the user selects the add colleges button in maintenance, will read the new files with the new college and souvenir data and add to the database
    ///
    void addAdminColleges();

private:
    QSqlDatabase db; /*!< database object */

    ///
    /// \brief method used by getColleges() to get each record from the database and store that data in a college object (this method should NOT be called by user or admin directly)
    /// \param rec: SQlRecord
    /// \return returns the populated college object
    ///
    College getCollegeFromRecord(const QSqlRecord &rec) const;

    ///
    /// \brief method used to take a vector of souvenirs and turn it into a QString of the form ( name $price, ...) so the database can store it
    /// \param souvenirs: vector of souvenirs that holds all of a colleges respective souvenirs
    /// \return returns the resulting QString that contains all names and prices of all souvenirs
    ///
    QString getSouvenirText(const std::vector<Souvenir>& souvenirs) const;

    ///
    /// \brief method used to take an unordered map, and turn it into a QString of the form ( ID# distance to that ID, ...) so the database can store it
    /// \param distanceMap: unordered map (int, float) that holds all distances from the current college to the others
    /// \return returns the resulting QString that contains all IDs and distances
    ///
    QString getDistanceText(const map::unordered_map<QString, float>& distanceMap) const;
};

#endif // DATABASE_H
