#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#include <fstream>

using namespace std;

struct Flight {
    int destination;
    int departureTime; // indicating hours
    int duration; // indicating hours
};

class Graph {
private: 
    int numOfVertices;
    vector<vector<Flight>> adjacencyList;
    map<string, int> cityToIndex;
    map<int, string> indexToCity;

public:
    Graph(int vertices) : numOfVertices(vertices), adjacencyList(vertices) {}

    // Add flight to the graph
    void addFlight(string source, string destination, int departureTime, int duration);

    // Get corresponding integer value assigned to city
    int getIndex(string city);

    // Print the graph's info
    void printFlightGraph();

    // Dijkstra's algorithm to find the fastest flight route between two cities
    pair<vector<int>, int> findFastestFlightRoute(string source, string destination);

    // Print path
    void printPath(const vector<int>& path, ofstream& outputFile);
};

#endif