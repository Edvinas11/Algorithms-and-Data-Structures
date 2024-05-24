#include <iostream>
#include <fstream>
#include "graph.h"

using namespace std;

int main() {
    Graph flightGraph(3);

    flightGraph.addFlight("Vilnius", "Roma", 1, 5);
    flightGraph.addFlight("Vilnius", "Berlynas", 1, 2);
    flightGraph.addFlight("Berlynas", "Roma", 1, 2);

    // flightGraph.printFlightGraph();

    string sourceCity = "Vilnius";
    string destinationCity = "Roma";
    auto result = flightGraph.findFastestFlightRoute(sourceCity, destinationCity);

    ofstream res("result.txt");
    if (result.second != INT_MAX) {
        res << "Fastest flight route from " << sourceCity << " to " << destinationCity << ":\n";
        flightGraph.printPath(result.first, res);
        res << "Total time: " << result.second << " hours\n";
    } else {
        res << "No flight route exists from " << sourceCity << " to " << destinationCity << "\n";
    }
    res.close();

    return 0;
}