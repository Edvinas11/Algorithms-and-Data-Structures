#include "graph.h"

void Graph::addFlight(string source, string destination, int departureTime, int duration)
{
        int sourceIndex = getIndex(source);
        int destinationIndex = getIndex(destination);
        adjacencyList[sourceIndex].push_back({destinationIndex, departureTime, duration});
}

int Graph::getIndex(string city)
{
        if (cityToIndex.find(city) == cityToIndex.end())
        {
                int index = cityToIndex.size();
                cityToIndex[city] = index;
                indexToCity[index] = city;
        }
        return cityToIndex[city];
}

void Graph::printFlightGraph()
{
        for (int i = 0; i < numOfVertices; ++i)
        {
                std::cout << "Flights from city " << i << ":\n";
                for (const Flight &flight : adjacencyList[i])
                {
                        std::cout << "  Destination: " << flight.destination
                                  << ", Departure Time: " << flight.departureTime
                                  << ", Duration: " << flight.duration << " hours\n";
                }
                std::cout << endl;
        }
}

pair<vector<int>, int> Graph::findFastestFlightRoute(string source, string destination)
{
        int sourceIndex = getIndex(source);
        int destinationIndex = getIndex(destination);

        vector<int> distances(numOfVertices, INT_MAX);
        vector<int> parents(numOfVertices, -1);
        vector<bool> visited(numOfVertices, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        distances[sourceIndex] = 0;
        pq.push({0, sourceIndex});

        while (!pq.empty())
        {
                int currentDistance = pq.top().first;
                int currentCity = pq.top().second;
                pq.pop();

                if (visited[currentCity])
                {
                        continue;
                }
                visited[currentCity] = true;

                if (currentCity == destinationIndex)
                {
                        break;
                }

                for (const Flight &flight : adjacencyList[currentCity])
                {
                        int nextCity = flight.destination;
                        int arrivalTime = currentDistance + flight.duration;

                        if (arrivalTime < distances[nextCity])
                        {
                                distances[nextCity] = arrivalTime;
                                parents[nextCity] = currentCity;
                                pq.push({arrivalTime, nextCity});
                        }
                }
        }

        vector<int> path;
        int current = destinationIndex;
        while (current != -1)
        {
                path.push_back(current);
                current = parents[current];
        }
        reverse(path.begin(), path.end());

        return {path, distances[destinationIndex]};
}

void Graph::printPath(const vector<int> &path, ofstream& outputFile)
{
        outputFile << "Path: ";
        for (int cityIndex : path)
        {
                outputFile << indexToCity[cityIndex] << " -> ";
        }
        outputFile << "End" << endl;
}