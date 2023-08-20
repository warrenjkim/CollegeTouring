#ifndef UNORDERED_MAP_H
#define UNORDERED_MAP_H

#include <iostream>
#include <random>
#include <QDebug>
#include <vector>

namespace map {

template<typename K, typename V>
struct pair {
public:
    K first;
    V second;

public:
    pair() : first(), second() {

    }

    pair(const K& first, const V& second) : first(first), second(second) {

    }
};

template<typename K, typename V>
class unordered_map {
private:
    std::vector<map::pair<K, V>>    m_Map;
    size_t                          m_Size;

public:
    //default constructor
    unordered_map() : m_Size(0) {
        m_Map.clear();
    }

    //constructor
    unordered_map(size_t size) : m_Size(size) {
        m_Map.clear();
        m_Map.reserve(m_Size);
    }

    //copy constructor
    unordered_map(const unordered_map<K, V>& other) : m_Size(other.m_Size) {
        m_Map.clear();
        for(auto& element : other.m_Map) {
            m_Map.emplace_back(element);
        }
    }

    //destructor
    ~unordered_map() {

    }

    //empty
    bool empty() const {
        return m_Map.empty();
    }

    //size
    size_t size() const {
        return m_Map.size();
    }

    //pointer to begin
    typename std::vector<map::pair<K, V>>::iterator begin() {
        return m_Map.begin();
    }

    //pointer to end
    typename std::vector<map::pair<K, V>>::iterator end() {
        return m_Map.end();
    }

    //pointer to begin
    typename std::vector<map::pair<K, V>>::const_iterator begin() const {
        return m_Map.cbegin();
    }

    //pointer to end
    typename std::vector<map::pair<K, V>>::const_iterator end() const {
        return m_Map.cend();
    }

    typename std::vector<map::pair<K, V>>::iterator& operator++() {
        ++m_Map;
        return *m_Map;
    }

    //access operator[]
    const V operator[](const K& key) const {
        for(auto& element : m_Map) {
            if(element.first == key) {
                return element.second;
            }
        }

        return -1;
    }

    //operator[]
    V& operator[](const K& key) {
        for(size_t i = 0; i < m_Map.size(); i++) {
            if(m_Map[i].first == key) {
                return m_Map[i].second;
            }
        }

        qDebug() << "key does not exist... adding key: " << key;

        pair<K, V> item(key, 0);
        m_Map.emplace_back(item);

        return m_Map[m_Map.size() - 1].second;
    }


    //at
    V& at(const K& key) {
        return m_Map[key].second;
    }

    //erase
    void erase(const K& key) {
        size_t i = 0;
        while(i < m_Map.size()) {
            if(m_Map[i].first == key) {
                m_Map.erase(m_Map.begin() + i);
                return;
            }
            i++;
        }
    }

    //clear
    void clear() {
        m_Map.clear();
    }

    void insert(const map::pair<K, V>& element) {
        m_Map.emplace_back(element);
    }
};



/*
template<typename K, typename V>
class hash_table {
private:
    pair<K, V>** m_Elements;
    size_t m_Size;

private:
    int hash(K* key) {

        return key % m_Size;
    }

public:
    hash_table() : m_Size(0) {

    }

    hash_table(size_t size) : m_Size(size){
        m_Elements = new pair<K, V>*[m_Size];
        for(size_t i = 0; i < m_Size; i++) {
            m_Elements[i] = nullptr;
        }
    }

    ~hash_table() {
        for(size_t i = 0; i < m_Size; i++) {
            delete m_Elements[i];
        }
        delete[] m_Elements;
    }

    void insert(const K& key, const V& value) {
        K* p_Key = new K;
        p_Key = &key;

        if(!m_Elements[hash(p_Key)]) {
            return;
        }
        else {
            m_Elements[hash(p_Key)] = value;
        }
    }

    void erase(const K& key) {
        for(size_t i = 0; i < m_Size; i++) {
            if(*(m_Elements[i]) == key) {
                m_Elements[i] = nullptr;
                return;
            }
        }

        qDebug() << "key " << key << " does not exist";
    }

    V find(const K& key) {
        for(size_t i = 0; i < m_Size; i++) {
            if(*(m_Elements[i]) == key) {
                return *(m_Elements[i]);
            }
        }

        qDebug() << "key " << key << " does not exist";

        return nullptr;
    }


};

template<typename T>
class iterator {
protected:
    T* m_Ptr;

public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

public:

    iterator(T* ptr = nullptr) {
        m_Ptr = ptr;
    }

    iterator(const iterator<T>& rawIterator) = default;

    ~iterator() {

    }

    iterator<T>& operator=(const iterator<T>& rawIterator) = default;

    iterator<T>& operator=(T* ptr) {
        m_Ptr = ptr;
        return (*this);}

    operator bool() const {
        return m_Ptr;
    }

    bool operator==(const iterator<T>& rawIterator) const {
        return (m_Ptr == rawIterator.getConstPtr());
    }

    bool operator!=(const iterator<T>& rawIterator) const {
        return (m_Ptr != rawIterator.getConstPtr());
    }

    iterator<T>& operator+=(const difference_type& movement) {
        m_Ptr += movement;
        return *this;
    }

    iterator<T>& operator-=(const difference_type& movement) {
        m_Ptr -= movement;
        return *this;
    }

    iterator<T>& operator++() {
        ++m_Ptr;
        return *this;
    }

    iterator<T>& operator--() {
        --m_Ptr;
        return *this;
    }

    iterator<T> operator++(int) {
        auto temp(*this);
        ++m_Ptr;
        return temp;
    }

    iterator<T> operator--(int) {
        auto temp(*this);
        --m_Ptr;
        return temp;
    }

    iterator<T> operator+(const difference_type& movement) {
        auto oldPtr = m_Ptr;
        m_Ptr += movement;
        auto temp(*this);
        m_Ptr = oldPtr;
        return temp;
    }

    iterator<T> operator-(const difference_type& movement) {
        auto oldPtr = m_Ptr;
        m_Ptr -= movement;
        auto temp(*this);
        m_Ptr = oldPtr;
        return temp;
    }

    difference_type operator-(const iterator<T>& rawIterator) {
        return std::distance(rawIterator.getPtr(),this->getPtr());
    }

    T& operator*() {
        return *m_Ptr;
    }

    const T& operator*() const {
        return *m_Ptr;
    }

    T* operator->() {
        return m_Ptr;
    }

    T* getPtr() const {
        return m_Ptr;
    }
};


*/


}







#endif
