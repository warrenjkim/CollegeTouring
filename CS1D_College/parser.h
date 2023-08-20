#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <QFile>
#include <vector>
#include <unordered_map>
#include <QDebug>

//#include "unordered_map.h"
#include "college.h"

//author: Warren Kim

//define member path for different OS
#if __APPLE__ && TARGET_OS_MAC
    #define PATH "../../../../CS1D_College/"
#elif __linux__
    #define PATH "../CS1D_College/"
#else
    #define PATH  "..\\CS1D_College\\"
#endif

class parser {
private:
    ///
    /// \brief helper function that constructs a college object and adds it to the vector of colleges
    ///
    void addCollege(const QString&, const QString&, const float&, const QString&, const int&, std::vector<College>&);

    ///
    /// \brief helper function that constructs a souvenir object and adds it to the vector of souvenirs
    ///
    void addSouvenir(const QString&, const QString&, const float&, std::vector<College>&);

    ///
    /// \brief helper function that reads all the colleges and stores it into a vector of colleges
    /// \return true if parsed correctly, false otherwise
    ///
    bool readColleges(std::vector<College>&, const QString& path);

    ///
    /// \brief helper function that reads all the souvenirs and stores it into a vector of souvenirs
    /// \return true if parsed correctly, false otherwise
    ///
    bool readSouvenirs(std::vector<College>&, const QString& path);

    ///
    /// \brief helper function that rounds a number to 2 decimal places
    ///
    void round(float&) const;

public:
    ///
    /// \brief default constructor
    ///
    parser();

    ///
    /// \brief reads all colleges and all souvenirs
    /// \return true if everything parsed correctly, false otherwise
    ///
    bool read(std::vector<College>& colleges, const QString& campuses, const QString& souvenirs);

    ///
    /// \brief for debug purposes: prints all parsed information
    ///
    void debug(const std::vector<College>&) const;
};

#endif // PARSER_H
