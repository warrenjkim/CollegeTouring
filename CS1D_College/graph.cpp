#include "graph.h"

// private methods (ends on line 38)
int graph::size() const {
  // return size of matrix
  return this->n * this->n;
}

int graph::at(const QString &name) const {
  // search for id given city name
  for (size_t i = 0; i < this->n; i++) {
    // if curr name matches city name
    if (this->v[i].city == name) {
      return this->v[i].id;
    }
  }

  // if not found, return -1
  return -1;
}

bool graph::hasBFSPath(const int &start, const int &end) {
  // true: nonzero value at [start][end]
  // false: zero at [start][end]
  return (this->adjMat[start][end]).first != 0;
}

bool compare(const edge &e1, const edge &e2) {
  // true: weight 1 < weight 2
  // false: weight 1 >= weight 2
  return (e1.weight < e2.weight);
}

bool sortByDist(const std::pair<vertex, int> &d1,
                const std::pair<vertex, int> &d2) {
  // true: dist 1 < dist 2
  // false: dist 1 >= dist 2
  return (d1.second < d2.second);
}
// end of private methods

// constructor
graph::graph(const int &n) : n(n) {
  // new array of <distance, edge type> pointers
  this->adjMat = new std::pair<float, int> *[this->n];

  // new 2d array(matrix) of <distance, edge type>
  for (size_t i = 0; i < this->n; i++) {
    this->adjMat[i] = new std::pair<float, int>[n];
    for (size_t j = 0; j < this->n; j++) {
      // mark all edges as undiscovered(UN)
      (this->adjMat[i][j]).second = -1;
    }
  }

  //set up cities array and database
  cities.push_back("");

  QString path;

#if __APPLE__ && TARGET_OS_MAC
      path = "../../../../CS1D_College/college.db";
#elif __linux__
      path = "../CS1D_College/college.db";
#else
      path = "..\\CS1D_College\\college.db";
#endif

  db = new database(path);

  auto colleges = db->getColleges();

  qDebug() << "CITIES OUTPUT: ";
  for (auto &x : colleges)
  {
      cities.push_back(x.second.name());

      qDebug() << x.second.id() << x.second.name();
  }

  //flip the cities
  //std::reverse(cities.begin() + 1,cities.end());

  for (size_t i = 0; i < cities.size(); i++)
  {
      qDebug() << cities[i];
  }


  // new array of vertices
  this->v = new vertex[n];

  qDebug() << "V OUTPUT: ";

  for (int i = 0; i < n; i++) {
    this->v[i].id = i;
    this->v[i].city = this->cities[i];
    this->v[i].visited = false;

    qDebug() << v[i].id << v[i].city;
  }


  count = new int[n] {0};

  //setting up edge weights
  for (auto &x : colleges)
  {
    auto distances = x.second.distances();

    for (auto &y : distances)
    {
        qDebug() << "ADDING EDGES: ";
        qDebug() << x.second.name() << " to " << y.first << " = " << y.second;

        qDebug() << "INDEX: " << x.second.id() << " to " << at(y.first);

        addEdge(x.first, at(y.first), y.second);

    }
  }

  //DFS STUFF
  totalDist = 0.0;

}
// end of constructor

// destructor
graph::~graph() {
  // delete matrix
  for (size_t i = 0; i < this->n; i++) {
    delete[] this->adjMat[i];
  }

  // delete array of pointers
  delete[] this->adjMat;

  // delete vertex array
  delete[] this->v;

  delete db;

}
// end of destructor

// addEdge()
void graph::addEdge(const int &start, const int &end, const float &weight) {
  // add weight to both [start][end] and [end][start]
  (this->adjMat[start][end]).first = weight;
  (this->adjMat[end][start]).first = weight;

    //DFS STUFF
    //for some reason it crashes on count, dont know why, worked before, says count has 0 items, but in constructor i set 12 values
    count[start]++;
    count[end]++;

    qDebug() << "adding to edge fn: " << start << " to " << end << " = " << adjMat[start][end].first;
}
// end of addEdge()

// BFS
std::vector<edge> graph::BFS(const QString &name) {
  // start id
  int start = this->at(name);

  // visited vector to keep track of edges that have been visited
  std::vector<bool> visited(this->size(), false);

  // vector of edges: stores all discovered edges in BFS order
  std::vector<edge> info;

  // set start vertex to visited
  visited[start] = true;
  this->v[start].visited = true;

  // push back start vertex with distance 0
  this->order.push_back(std::make_pair(this->v[start], 0));

  // number of vertices in previous levels
  size_t size = 0;

  // iterate through each vertex at a given level
  int j = 0;

  // while all cities haven't been visited
  while (this->order.size() < this->n - 1) {
    // set current vertex to first element in the order vector
    int curr = this->order[j].first.id;

    // for all adjacent edges to vertex curr
    for (size_t i = 0; i < this->n; i++) {
      // if curr has an edge connecting curr and i
      if (hasBFSPath(curr, i) != 0) {
        // the vertex hasn't been visited
        if (!(visited[i])) {
          // add edge to info vector
          info.push_back(edge(this->v[curr], this->v[i], (this->adjMat[curr][i]).first));

          // add vertex and distance to order vector
          this->order.push_back(std::make_pair(this->v[i], (this->adjMat[curr][i]).first));

          // set current vertex to visited
          this->v[curr].visited = true;

          // set edge at [curr][i] to discovered(DI)
          (this->adjMat[curr][i]).second = (this->adjMat[i][curr]).second = 1;

          // set i'th visited vector to true
          visited[i] = true;
        }
      }
    }

    // sort info vector excluding start distance (0)
    if (size == 0) {
      std::sort(info.begin(), info.end(), compare);
    } else {
      std::sort(info.begin() + (size - 1), info.end(), compare);
    }

    // sort the current "level" of the order vector
    std::sort(this->order.begin() + size, this->order.end(), sortByDist);

    // add current vertices to size to "skip" to the next level on the next sort
    size = this->order.size();

    // iterate j to BFS visit all vertices in the next "level"
    j++;
  }

  // all nonzero edges that were undiscovered are cross edges
  for (size_t i = 0; i < this->n; i++) {
    for (size_t j = 0; j < this->n; j++) {
      if ((this->adjMat[i][j]).first != 0 &&
          (this->adjMat[i][j]).second == -1) {
        (this->adjMat[j][i]).second = (this->adjMat[i][j]).second = 0;
      }
    }
  }

  // set discoveredEdges to point to info
  this->discoveredEdges = info;

  // return info vector
  return info;
}
// end of BFS

// printAdjMatrix()
void graph::printAdjMatrix() {
  // for each element in the adjacency matrix
  for (size_t i = 0; i < this->n; i++) {
    for (size_t j = 0; j < this->n; j++) {

      // set edgeType
      QString edgeType;
      switch ((adjMat[i][j]).second) {
      // undiscovered
      case -1:
        edgeType = "UN";
        break;
      // cross
      case 0:
        edgeType = "CR";
        break;
      // discovered
      case 1:
        edgeType = "DI";
        break;
      // error
      default:
        edgeType = "error";
        break;
      }
      // print in format [distance, edge type]
      // setw(4) to make matrix uniform: left justified
      qDebug().nospace() << "[ " << (adjMat[i][j]).first << ", " << edgeType << " ] ";
    }
    // 2 lines of space between rows
    qDebug() << "\n" << "\n";
  }
}
// end of printAdjMatrix()

// prints order of cities to visit using BFS
void graph::printOrder() {
  // order
  int i = 1;
  // print order vector (cities)
  for (auto &x : this->order) {
    qDebug() << i << ": " << x.first.city << "\n";
    i++;
  }

  qDebug() << "\n";
}
// end of printOrder()

// printDiscoveredEdges()
void graph::printDiscoveredEdges() {
    //adding distances string
    QString addition = "";
    //total distance traveled
    int sum = 0;
    //iterate through dists vector
    for(const auto& x : this->discoveredEdges) {
        //print distance between start and end city
        qDebug() << x.start.city << " and " << x.end.city << ": " << x.weight
<< " mi" << "\n";
        //add weight to total distance
        sum += x.weight;
        //add weight to total distance string
        addition += QString::number(x.weight) + " + ";
    }
    //omit extraneous " + "
    //addition = addition.substr(0, addition.length() - 3);
    //set distanceInfo to addition string and total distance
    this->distanceInfo = std::pair(addition, sum);
    qDebug() << "\n";
}
//end of printDiscoveredEdges()

// printCrossEdges()
void graph::printCrossEdges() {
  // map of cross edges
  std::vector<int> visited;
  for (size_t i = 0; i < this->n; i++) {
    for (size_t j = 0; j < this->n; j++) {
      if (((this->adjMat[i][j]).second == 0) &&
          (std::find(visited.begin(), visited.end(),
                     (this->adjMat[i][j]).first) == visited.end())) {
        visited.push_back((this->adjMat[i][j]).first);
        qDebug() << (this->v[i]).city << " and " << (this->v[j]).city << ": "
                  << (this->adjMat[i][j]).first << " mi" << "\n";
      }
    }
  }

  qDebug() << "\n";
}
// end of printCrossEdges()

// printLvlOrder()
void graph::printLvlOrder() {
  // lvl
  int lvl = 0;
  for (size_t i = 0; i < this->order.size(); i++) {
    qDebug() << "level " << lvl << ": " << this->order[i].first.city
              << "\n";
    if (this->order[i].first.city == "Dallas" ||
        this->order[i].first.city == "Los Angeles" ||
        this->order[i].first.city == "New York") {
      lvl++;
    }
  }
  qDebug() << "\n";
}
// end of printLvlOrder()

// printTotalDist()
void graph::printTotalDist() {
  // print addition string and total distance taveled
  qDebug() << this->distanceInfo.first << "\n";
  qDebug() << "total distance traveled: " << this->distanceInfo.second << " mi"
            << "\n";

  this->totalDist = this->distanceInfo.second;
}
// end of printTotalDist()

// ASSIGNMENT 12
// minDistance()
int graph::minDistance(int dist[], bool sptSet[]) {
  int min = INT_MAX;
  int minIndex = -1;

  for (size_t i = 0; i < this->n; i++) {
    if ((sptSet[i] == false) && dist[i] <= min) {
      min = dist[i];
      minIndex = this->v[i].id;
    }
  }

  return minIndex;
}
// end of minDistance()

// djikstra()
void graph::djikstra(const QString &name) {
  int start = this->at(name);

  // distance from start to vertex i
  int dist[this->n];

  // true if vertex is in shortest path tree, false otherwise
  bool sptSet[this->n];

  // array to store djikstra path
  int path[this->n];

  // initialize arrays to infinity and false respectively
  for (size_t i = 0; i < this->n; i++) {
    dist[i] = INT_MAX;
    sptSet[i] = false;
    path[i] = -1;
  }

  // distance from start to itself is 0
  dist[start] = 0;

  // shortest path for all vertices
  for (size_t i = 0; i < this->n - 1; i++) {
    // minimum distance vertex by calling helper function minDistance()
    int temp = this->minDistance(dist, sptSet);

    // set picked vertex as true
    sptSet[temp] = true;

    // update distance value of adjacent vertices of the picked vertex
    for (size_t j = 0; j < this->n; j++) {
      // update dist[j] if:
      // it's not in stpSet
      // there's an edge from temp to j
      // the total weight of the path from temp to j is shorter than the current
      // dist[j]
      if (!(sptSet[j]) && (this->adjMat[temp][j]).first &&
          (dist[temp] != INT_MAX) &&
          (dist[temp] + (this->adjMat[temp][j]).first < dist[j])) {
        // add vertex id to path
        path[j] = this->v[temp].id;

        // add distance to current
        dist[j] = dist[temp] + (this->adjMat[temp][j]).first;
      }
    }
  }

  // print djikstra order and path starting at [start city]
  printDjikstra(dist, name, path);
}
// end of djikstra()

// printDjikstra()
void graph::printDjikstra(const int dist[], const QString &name,
                          int path[]) {
  // iterate through dist array
  for (size_t i = 0; i < this->n; i++) {
    // reset path string
    QString pathStr = "";

    // format: [start city] to [end city]: [shortest distance] mi
    qDebug() << name << " to " << this->v[i].city << ": " << dist[i] << " mi"
              << "\n";

    // recursively build path from [start city] to [end city]
    printPath(path, i, pathStr);

    // format: path from [start city] to [end city]:
    // [start->next->next->...->end]
    std::string temp = pathStr.toStdString();
    temp.substr(0, temp.length() - 2);
    pathStr = temp.c_str();
    qDebug() << "path from " << name << " to " << this->v[i].city << ": "
              << pathStr << "\n"
              << "\n";
  }
}

void graph::printPath(int path[], int i, QString &pathStr) {
  // BASE CASE
  // if id is start city
  if (i == -1) {
    return;
  }
  // RECURSIVE CASE
  else {
    // recursively build path
    printPath(path, path[i], pathStr);
    // add to path string
    // format: [start]->[next]->...->[end]
    pathStr += (this->v[i].city + "->");
  }
  return;
}

// MST
void graph::MST(const QString& name, std::queue<QString>& queue){
  // start city
  int start = this->at(name);

  // variable to cycle through each edge
  int edge;

  // keeps track of what cities have been visited
  bool visit[n];

  // initialize all cities to not visited
  for (int i = 0; i < n; i++)
    visit[i] = false;

  // initialize edge
  edge = 0;

  // start city has already been visited
  visit[start] = true;

  // variables to track minimum mileage while cycling through each possible edge
  int x;
  int y;

  // stores minimum mileage to compare with other edges
  int min;

  //cycles through each possible edge
  while (edge < n - 1) {

    // initializes minimum edge to largest possible value
    min = INT_MAX;

    // initialize cycling variables
    x = 0;
    y = 0;

    // cycle through all adjacent verices and find the least distance for a
    // city that has not been visited and store it in min
    for (int i = 0; i < n; i++) {
      if (visit[i]) {
        for (int j = 0; j < n; j++) {
          if (!visit[j] && adjMat[i][j].first != 0) {
            if (min > adjMat[i][j].first) {
              min = adjMat[i][j].first;
              x = i;
              y = j;
            }
          }
        }
      }
    }

    // print the MST as the loop happens
    QString temp = this->v[x].city + "--->" + this->v[y].city + " : " + QString::number(adjMat[x][y].first) + " mi";

    queue.push(temp);

    // mark city visited
    visit[y] = true;

    // update total mileage
    total += adjMat[x][y].first;

    // traverse to next edge
    edge++;
  }
  qDebug() << "Total mileage: " << total << " mi";

}
// print MST as while loop happens
void graph::printMST(int x, int y)
{
          qDebug() << this->v[x].city << "--->" << this->v[y].city << " : "
              << adjMat[x][y].first << " mi";
    qDebug() << "\n" << "\n";
}


// DFS METHODS ****
void graph::DFS(std::vector<bool> visited, QString startVisit, bool printFirst, std::stack<int> stack, bool backtrack, std::queue<QString>& queue)
{

    int startIndex = at(startVisit);

    //on the first call, push the initial vertex onto the stack
    if (printFirst)
    {
        stack.push(startIndex);
    }

    visited[startIndex] = true;

    //need to store the shortest index
    int shortestIndex = startIndex;

    float shortestWeight = 0.0;

    //set the smallst weight initially to a large value
    shortestWeight = 99999;

    int i = shortestIndex;

    for (size_t j = 0; j < n; j++)
    {
        if (adjMat[i][j].first <= shortestWeight && visited[j] == false && adjMat[i][j].first > 0)
        {
               shortestIndex = j;
               shortestWeight = adjMat[i][j].first;
        }
    }

    for (size_t j = 0; j < n; j++)
    {
        if (adjMat[i][j].first == shortestWeight)
        {
            totalDist += shortestWeight;
        }
    }

    //regards printing the actual cities that are being visited in order, printFirst is true when initially called from main
    //in order to print the initial city, and then when recursing pass false then it wont print that again
    if (printFirst)
    {
        queue.push(cities[startIndex]);
        queue.push(cities[shortestIndex]);
    }
    else if (visited[shortestIndex] == false)
    {
        queue.push(cities[shortestIndex]);
    }

    //marks vertex as visited
    visited[shortestIndex] = true;

    size_t trueCount = 0;

    //calculate the total amount of visited nodes by counting the "trues" in the array, which will later be compared to the number of vertices N
    for (size_t i = 0; i < n; i++)
    {
        if (visited[i] == true)
        {
            trueCount++;
        }
    }

    // end of printing cities
    int trueCountBacktrack = 0;

    //try to determine whether backtracking is necessary **
    for (size_t j = 0; j < n; j++)
    {
        if (visited[j] == true && adjMat[i][j].first != 0)
        {
            trueCountBacktrack++;
        }

    }

    //pushes onto the stack if we didnt backtrack on the previous recursion
    if (!backtrack)
    {
        stack.push(shortestIndex);
    }

    //if side indicates that we need to backtrack so we pop from the stack and now shortestIndex holds the top of the stack which was the previous visited node
    //essentially "backtracking"
    if (trueCountBacktrack == count[shortestIndex])
    {
        if (stack.size() != 1)
        {
            stack.pop();
        }

        shortestIndex = stack.top();

        backtrack = true;
    }
    else
    {
        backtrack = false;
    }
    //end logic for determining backtracking **

    //recursion decision will return when complete, meaning that all bool values in the visited array are true, else it will continue to recurse
    if (trueCount == n -1)
    {
        return;
    }
    else
    {
        DFS(visited, cities[shortestIndex], false, stack, backtrack, queue);
    }
}


float graph::getTotalDistDFS() const
{
    return totalDist;
}

float graph::getTotalDistMST() const
{
    return total;
}
