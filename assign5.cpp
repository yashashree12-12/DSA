// A student wants to travel from Source (A) to destination (B). Student books a cab from A to reach B.
// Calculate a shortest path by avoiding real time traffic to reach destination B.

#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

// Struct to represent an edge with destination node and weight
struct Edge {
    int to;
    int weight;
};

// Function implementing Dijkstra's algorithm to find the shortest path
void dijkstra(int src, const vector<vector<Edge>>& graph, int n, vector<int>& distance) {
    distance.assign(n, INT_MAX); // Initialize all distances to infinity
    distance[src] = 0;          // Distance to the source is 0

    // Priority queue to process nodes by their current shortest distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src}); // Push the source with distance 0

    while (!pq.empty()) {
        int currentDistance = pq.top().first; // Current shortest distance
        int currentNode = pq.top().second;   // Current node being processed
        pq.pop();

        // Skip processing if the current distance is not optimal
        if (currentDistance > distance[currentNode]) {
            continue;
        }

        // Process all edges of the current node
        for (const auto& edge : graph[currentNode]) {
            int newDistance = currentDistance + edge.weight;
            // Update the distance if a shorter path is found
            if (newDistance < distance[edge.to]) {
                distance[edge.to] = newDistance;
                pq.push({newDistance, edge.to});
            }
        }
    }
}

int main() {
    int n, m; // Number of nodes and edges

    // Input for number of nodes and edges
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<Edge>> graph(n); // Adjacency list representation of the graph

    // Input edges in the format: from, to, weight
    cout << "Enter the edges in the format (from to weight):\n";
    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight}); // Assuming an undirected graph
    }

    int src, dest;
    // Input source and destination nodes
    cout << "Enter the source node: ";
    cin >> src;
    cout << "Enter the destination node: ";
    cin >> dest;

    vector<int> distance; // To store shortest distances
    dijkstra(src, graph, n, distance); // Run Dijkstra's algorithm

    // Output shortest distances from source to all nodes
    cout << "Shortest distances from node " << src << " to all other nodes:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Node " << src << " to Node " << i << " : "
             << (distance[i] == INT_MAX ? -1 : distance[i]) << endl;
    }

    // Output shortest distance from source to destination
    cout << "Shortest distance from Node " << src << " to Node " << dest << " : "
         << (distance[dest] == INT_MAX ? -1 : distance[dest]) << endl;

    return 0;
}
