#include "college.h"

//author: Warren Kim

//default constructor
College::College() : m_Name(""), m_State(""), m_Undergrads(0) {
    m_Distances.clear();
    m_Souvenirs.clear();
}

//overloaded constructor
College::College(const QString& name, const QString& state, const int& undergrads) : m_Name(name), m_State(state), m_Undergrads(undergrads) {
    m_Distances.clear();
    m_Souvenirs.clear();
}

//========================================ACCESSORS========================================

//name
QString College::name() const {
    return this->m_Name;
}

//state
QString College::state() const {
    return this->m_State;
}

//undergrads
int College::undergrads() const {
    return this->m_Undergrads;
}

//souvenirs
std::vector<Souvenir> College::souvenirs() const {
    return this->m_Souvenirs;
}

//distances
map::unordered_map<QString, float> College::distances() const {
    return this->m_Distances;
}

//id
int College::id() const {
    return this->m_Id;
}

void College::print() const
{
    qDebug() << "NAME: " << m_Name;
    qDebug() << "STATE: " << m_State;
    qDebug() << "UNDERGRADS: " << m_Undergrads;
    qDebug() << "DISTANCES: ";

    for (const auto& x : m_Distances)
    {
        qDebug() << x.first << " - " << x.second;
    }

    qDebug() << "SOUVENIRS: ";

    for (auto& x : m_Souvenirs)
    {
        qDebug() << x.name() << " - $" << x.price();
    }
}

//=========================================================================================

//========================================MUTATORS=========================================

//setName
void College::setName(const QString& name) {
    this->m_Name = name;
}

//setState
void College::setState(const QString& state) {
    this->m_State = state;
}

//setUndergrads
void College::setUndergrads(const int& undergrads) {
    this->m_Undergrads = undergrads;
}

//addDistance
void College::addDistance(const QString& key, const float& value) {
    this->m_Distances[key] = value;
}

//removeDistance
void College::removeDistance(const QString& key) {
    this->m_Distances.erase(key);
}

//setId
void College::setId(const int& id) {
    this->m_Id = id;
}

//addSouvenir
bool College::addSouvenir(const QString& name, const float& price) {
    Souvenir temp(name, price);

    for(auto& item : this->m_Souvenirs) {
        //if item already exists
        if(item.name() == name) {

            //item not added
            return false;
        }
    }

    this->m_Souvenirs.push_back(temp);

    //item added
    return true;
}

//deleteSouvenir
bool College::deleteSouvenir(const QString& name) {
        int count = 0;
        for(auto& x : this->m_Souvenirs) {
            if(x.name() == name)
            {
                this->m_Souvenirs.erase(this->m_Souvenirs.begin() + count);
                //souvenir deleted
                return true;
            }
            count++;
    }

    //souvenir doesn't exist
    return false;
}

//setPrice
bool College::setPrice(const QString& name, const float& price) {
    //iterates to find key
    for(auto& x : this->m_Souvenirs) {
        //if found, modify price
        if(x.name() == name) {
            x.setPrice(price);
            //price modified: return true
            return true;
        }
    }

    //souvenir not found: return false
    return false;
}

//resetSouvenirs
void College::resetSouvenirs(std::vector<Souvenir>& souvenirs) {
   souvenirs.clear();
}

//reset
void College::reset() {
    this->m_Name = "";
    this->m_State = "";
    this->m_Undergrads = 0;
    this->m_Distances.clear();
    this->m_Souvenirs.clear();
}

//=========================================================================================
