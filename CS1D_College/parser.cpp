#include "parser.h"

//author: Warren Kim

//========================================PRIVATE MEMBER FUNCTIONS========================================

//addCollege
void parser::addCollege(const QString& name, const QString& key, const float& value, const QString& state, const int& undergrads, std::vector<College>& colleges) {
    for(auto& currCollege : colleges) {
        if(currCollege.name() == name) {
            currCollege.addDistance(key, value);
            return;
        }
    }

    //college doesn't exist yet
    College temp(name, state, undergrads);

    //push new college to vector
    temp.addDistance(key, value);

    colleges.push_back(temp);
}

//addSouvenir
void parser::addSouvenir(const QString& collegeName, const QString& itemName, const float& itemPrice, std::vector<College>& colleges) {
    for(auto& currCollege : colleges) {
        if(currCollege.name() == collegeName) {
            currCollege.addSouvenir(itemName, itemPrice);
        }
    }
}

//readColleges
bool parser::readColleges(std::vector<College>& colleges, const QString& path) {
    //read member file
    QString file = PATH + path;
    QFile inFile(file);
    //QFile inFile(CAMPUSES_PATH);

    //check to see if file opens correctly
    if(!inFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "error reading file\n";
        return false;
    }

    QString line;
    QStringList temp;

    //read and ignore first line
    inFile.readLine();

    //starting college, destination college, state
    QString name, key, state;
    //distance between colleges
    float value;
    //number of undergrads
    int undergrads;

    while(!inFile.atEnd()) {

        line = inFile.readLine();
        temp = line.split(",");
        int index = 0;

        for(int i = 0; i < 6; i++) {

            /* switch case format
             * 0: starting college
             * 1: destination college
             * 2: distance between colleges
             * 3: state
             * 4: undergrads
             * 5: assign
             */
            switch(i) {
            // starting college
            case 0:
                //if name starts with quotes, remove quotes
                if(temp[index].startsWith('"')) {
                    std::string tempName = temp[index].toStdString() + "," + temp[index + 1].toStdString();
                    name = tempName.substr(1, tempName.length() - 2).c_str();
                    index++;
                }
                else {
                    name = temp[index];
                }

                break;

            // destination college
            case 1:
                //if name starts with quotes, remove quotes
                if(temp[index].startsWith('"')) {
                    std::string tempKey = temp[index].toStdString() + "," + temp[index + 1].toStdString();
                    key = tempKey.substr(1, tempKey.length() - 2).c_str();
                    index++;
                }
                else {
                    key = temp[index];
                }

                break;

            // distance between colleges
            case 2:
                value = temp[index].toFloat();
                break;

            // state
            case 3:
                if(temp[index] == "") {
                    break;
                }
                state = temp[index];
                break;

            // undergrads
            case 4:
                if(temp[index] == "" || temp[index] == "\n") {
                    break;
                }
                undergrads = temp[index].toInt();
                break;

            // assign
            case 5:
                this->addCollege(name, key, value, state, undergrads, colleges);
                break;
            default:
                break;
            }

            index++;
        }

        line = "";
    }

    //file parsed correctly
    return true;
}

//readSouvenirs
bool parser::readSouvenirs(std::vector<College>& colleges, const QString& path) {
    //read member file
    QString file = PATH + path;
    QFile inFile(file);
    //QFile inFile(SOUVENIRS_PATH);

    //check to see if file opens correctly
    if(!inFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "error reading file\n";
        return false;
    }

    QString line;
    QStringList temp;

    //read and ignore first line
    inFile.readLine();

    //college name, item name, item price string
    QString collegeName, itemName;
    //item price
    std::string tempPrice;
    float itemPrice;

    while(!inFile.atEnd()) {

        line = inFile.readLine();
        temp = line.split(",");
        int index = 1;

        if(temp[0] != "") {
            //if name starts with quotes, remove quotes
            if(temp[0].startsWith('"')) {
                std::string tempName = temp[0].toStdString() + "," + temp[1].toStdString();
                collegeName = tempName.substr(1, tempName.length() - 2).c_str();
                index++;
            }
            else {
                collegeName = temp[0];
            }
            continue;
        }

        for(int i = 0; i < 3; i++) {

            /* switch case format
             * 0: item name
             * 1: item price
             * 2: assign
             */
            switch(i) {
            // item name
            case 0:
                itemName = temp[index];
                break;

            // item price
            case 1:
                //round to 2 decimal places
                tempPrice = temp[index].toStdString();
                itemPrice = atof(tempPrice.substr(1, tempPrice.length()).c_str());
                this->round(itemPrice);
                break;

            // assign
            case 2:
                this->addSouvenir(collegeName, itemName, itemPrice, colleges);
                break;
            default:
                break;
            }

            index++;
        }

        line = "";
    }

    //file parsed correctly
    return true;


}

//round
void parser::round(float& price) const {
    int temp = price * 100;
    price = temp / 100.0;
}

//========================================================================================================

//========================================PUBLIC MEMBER FUNCTIONS=========================================

//constructor
parser::parser() {

}

//read
bool parser::read(std::vector<College>& colleges, const QString& campuses, const QString& souvenirs) {
    //std::vector<College> colleges;
    bool bColleges, bSouvenirs;

     bColleges = readColleges(colleges, campuses);
     bSouvenirs = readSouvenirs(colleges, souvenirs);
     debug(colleges);

     return (bColleges && bSouvenirs);
}

//debug
void parser::debug(const std::vector<College>& colleges) const {
    QDebug debug = qDebug();
    debug.noquote().nospace();

    for(const auto& temp : colleges) {
        debug << "\n\nname: " << temp.name();
        debug << "\nstate: " << temp.state();
        debug << "\nundergrads: " << temp.undergrads() << "\n";

        debug << "\ndistances:\n";
        for(const auto& dist : temp.distances()) {
            debug << temp.name() << " to " << dist.first << ": " << dist.second << "\n";
        }

        debug << "\nsouvenirs:\n";

        for(const auto& souv : temp.souvenirs()) {
            debug << souv.name() << ", $" << souv.price() << "\n";
        }
    }
}

//========================================================================================================
