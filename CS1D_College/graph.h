#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iomanip>
#include <stack>
#include <QString>
#include <QDebug>
#include <algorithm>

#include "database.h"

//vertex struct
struct vertex {
    //vertex id(0-11)
    //0: seattle
    //1: san francisco
    //2: denver
    //3: chicago
    //4: boston
    //5: new york
    //6: los angeles
    //7: kansas city
    //8: atlanta
    //9: dallas
    //10: houston
    //11: miami
    int id;
    //city name
    QString city;
    //visited flag
    bool visited;

    vertex() : id(-1), city(""), visited(false) {

    }
};

//edge struct
struct edge {
    //start city, end city: vertex
    vertex start, end;
    //weight: int
    float weight;
    edge() : start(), end(), weight(0.0) {

    }

    edge(const vertex& start, const vertex& end, const float& weight) : start(start), end(end), weight(weight) {

    }
};

//graph class: uses adjacency matrix
class graph {
private:
    //array of cities
    std::vector<QString> cities;
    //QString cities[12] = { "Seattle", "San Francisco", "Denver", "Chicago", "Boston", "New York", "Los Angeles", "Kansas City", "Atlanta", "Dallas", "Houston", "Miami" };

    //number of vertices
    size_t n;

    //adjacency matrix
    //index of vertex(0-9): int
    //type of edge: int
    //-1: undiscovered (UN)
    //0: cross edge (CR)
    //1: discovered edge (DI)
    std::pair<float, int>** adjMat;

    //dynamic array of vertices
    //0: seattle
    //1: san francisco
    //2: denver
    //3: chicago
    //4: boston
    //5: new york
    //6: los angeles
    //7: kansas city
    //8: atlanta
    //9: dallas
    //10: houston
    //11: miami
    vertex* v;


    //vector of all discovered edges in order
    std::vector<edge> discoveredEdges;

    //distance info of total distance string, and total distance
    std::pair<QString, int> distanceInfo;

    //DFS VARS *****
    float totalDist;

    float total;

    int* count;

private:
    database* db;
    //size of matrix (v^2)
    int size() const;

    //returns id given city name
    int at(const QString&) const;

    //returns if the adjacency matrix at [start][end] is nonzero
    bool hasBFSPath(const int&, const int&);

    //compares two edge weights (for std::sort())
    friend bool compare(const edge&, const edge&);

    //compares two distances (for std::sort())
    friend bool sortByDist(const std::pair<vertex, int>&, const std::pair<vertex, int>&);

public:
    //constructor
    graph(const int& x);

    //destructor
    ~graph();

    //adds edge
    //params: start, end, distance
    void addEdge(const int&, const int&, const float&);

    //BFS algo
    std::vector<edge> BFS(const QString&);

    //prints adjacency matrix
    //format:
    //[distance, edge type (UN, CR, DI)]
    void printAdjMatrix();

    //prints order vector (cities)
    void printOrder();

    //prints all discovered edge distances
    void printDiscoveredEdges();

    //prints all cross edges
    void printCrossEdges();

    //prints order by level (cities)
    void printLvlOrder();

    //prints total distance and total distance string
    void printTotalDist();

    //ASSIGNMENT 12
    //helper min functino
    int minDistance(int[], bool[]);

    //djikstra's algo
    void djikstra(const QString&);

    //print djikstra
    void printDjikstra(const int[], const QString&, int[]);

    //print path
    void printPath(int[], int, QString&);

    // MST algo
    void MST(const QString& name, std::queue<QString>& queue);

    // print MST
    void printMST(int x, int y);

    //DFS METHODS *****
    void DFS(std::vector<bool> visited, QString startVisit, bool printFirst, std::stack<int> stack, bool backtrack, std::queue<QString>& queue);

    float getTotalDistDFS() const;

    float getTotalDistMST() const;
public:

    //vector of city order
    std::vector<std::pair<vertex, int>> order;
};

#endif
