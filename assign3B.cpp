// B. There are flight paths between cities. If there is a flight between city A and city B
// then there is an edge between the cities. The cost of the edge can be the time that
// flight take to reach city B from A, or the amount of fuel used for the journey.
// Represent this as a graph. The node can be represented by airport name or name of the
// city. Use adjacency list representation of the graph or use adjacency matrix
// representation of the graph. Check whether the graph is connected or not. Justify the
storage representation used.


#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Graph 
{
    unordered_map<string, list<pair<string, int>>> adjList;
public:
    void addEdge(const string& city1, const string& city2, int cost) {
        adjList[city1].push_back({city2, cost});
        adjList[city2].push_back({city1, cost});
    }

    void displayGraph() const {
        cout << "\nFlight Paths (Adjacency List):\n";
        for (const auto& city : adjList) {
            cout << city.first << " -> ";
            for (const auto& neighbor : city.second) {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }

    void DFS(const string& city, unordered_set<string>& visited) const 
    {
        visited.insert(city);
        for (const auto& neighbor : adjList.at(city)) 
        {
            if (visited.find(neighbor.first) == visited.end()) 
            {
                DFS(neighbor.first, visited);
            }
        }
    }

    bool isConnected() const {
        if (adjList.empty()) return true;  // Empty graph is trivially connected

        unordered_set<string> visited;
        auto startCity = adjList.begin()->first;  // Start DFS from the first city
        DFS(startCity, visited);

        return visited.size() == adjList.size();
    }
};

int main() {
    Graph flightGraph;
    int numEdges;
    cout << "Enter the number of flight connections: ";
    cin >> numEdges;

    cout << "Enter the flight connections (city1 city2 cost):\n";
    for (int i = 0; i < numEdges; ++i) {
        string city1, city2;
        int cost;
        cin >> city1 >> city2 >> cost;
        flightGraph.addEdge(city1, city2, cost);
    }

    flightGraph.displayGraph();

    if (flightGraph.isConnected()) {
        cout << "The graph is connected. All cities are reachable.\n";
    } else {
        cout << "The graph is not connected. Some cities are isolated.\n";
    }

    return 0;
}
