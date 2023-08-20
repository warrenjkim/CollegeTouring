#ifndef COLLEGE_H
#define COLLEGE_H

#include <QDebug>
#include <QString>
#include "unordered_map.h"

//author: Warren Kim

class Souvenir {
private:
    //first = item name: QString
    //second = item price: float
    map::pair<QString, float> m_Item; /// \var item in the format: { Key, Value } = { [item name], [item price] }

public:
    ///
    /// \brief default constructor
    ///
    Souvenir() : m_Item({"", 0}){

    }

    ///
    /// \brief overloaded constructor
    /// \param name
    /// \param price
    ///
    Souvenir(const QString& name, const float& price) : m_Item({name, price}) {

    }

    ///
    /// \brief item name
    /// \return name: QString
    ///
    QString name() const {
        return this->m_Item.first;
    }

    ///
    /// \brief item price
    /// \return price: float
    ///
    float price() const {

        return this->m_Item.second;
    }

    ///
    /// \brief set item price
    /// \param price: float
    ///
    void setPrice(const float& price) {
        this->m_Item.second = price;
    }
};

class College {
private:
    QString m_Name, /// \var college name
            m_State; /// \var college state
    map::unordered_map<QString, float> m_Distances; /// \var distance to other colleges in the format: { Key, Value } = { [college name], [distance] }
    int m_Undergrads; /// \var number of undergrads
    std::vector<Souvenir> m_Souvenirs; /// \var vector of souvenirs

    int m_Id; /// \var college id

public:
    ///
    /// \brief default constructor, intializes everything to default values
    ///
    College();

    ///
    /// \brief overloaded constructor, initializes name, state, and number of undergrads
    /// \param name: QString
    /// \param state: QString
    /// \param undergrads: int
    ///
    College(const QString&, const QString&, const int&);

                                                            /// accessors ///
    ///
    ///
    /// \brief returns name
    /// \return name: QString
    ///
    QString name() const;

    ///
    /// \brief returns state
    /// \return state: QString
    ///
    QString state() const;

    ///
    /// \brief returns undergrads
    /// \return undergrads: int
    ///
    int undergrads() const;

    ///
    /// \brief returns souvenirs
    /// \return souvenirs: map::vector<souvenir>
    ///
    std::vector<Souvenir> souvenirs() const;

    ///
    /// \brief returns distances
    /// \paragraph distance map is in the format: { Key, Value } = { [destination college id], [distance to destination college] }
    /// \return distances: unordered_map<map::string, float>
    ///
    map::unordered_map<QString, float> distances() const;

    ///
    /// \brief college id
    /// \return id: int
    ///
    int id() const;

    ///
    /// \brief prints college information
    ///
    void print() const;

                                                            /// mutators ///

    ///
    /// \brief sets college name
    /// \param name: QString
    ///
    void setName(const QString&);

    ///
    /// \brief sets college state
    /// \param state: QString
    ///
    void setState(const QString&);

    ///
    /// \brief sets undergrads
    /// \param undergrads: int
    ///
    void setUndergrads(const int&);

    ///
    /// \brief adds a distance to a college when valid
    /// \param key: int
    /// \param value: float
    /// \paragraph when setting the distance, key = id of the destination college and value = distance to the destination college
    ///
    void addDistance(const QString&, const float&);

    ///
    /// \brief removeDistance
    /// \param key: int
    ///
    void removeDistance(const QString&);

    ///
    /// \brief sets college id
    /// \param id: int
    ///
    void setId(const int&);

    ///
    /// \brief adds a souvenir object
    /// \param itemName: QString
    /// \param itemPrice: float
    /// \return true if added successfully, false otherwise
    ///
    bool addSouvenir(const QString&, const float&);

    ///
    /// \brief deletes a souvenir object
    /// \param item: souvenir
    /// \return true if deleted successfully, false otherwise
    ///
    bool deleteSouvenir(const QString&);

    ///
    /// \brief modifies the price of a souvenir
    /// \param itemName: QString
    /// \param itemPrice: float
    /// \return true if modified successfully, false otherwise
    ///
    bool setPrice(const QString&, const float&);

    ///
    /// \brief resetSouvenirs
    /// \param souvenirs: map::vector<souvenir>
    ///
    void resetSouvenirs(std::vector<Souvenir>&);

    ///
    /// \brief reset college to default values (NIL)
    ///
    void reset();
};

#endif // COLLEGE_H
