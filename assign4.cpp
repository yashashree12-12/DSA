// You are given an undirected weighted graph with nodes and edges. The nodes are
// numbered from and to. Find the total weight of the minimum spanning tree, as well as
// one specific minimum spanning tree using Prims/Kruskal’s algorithm. Note that there
// may be multiple different minimum spanning trees. You need to construct any one of
// them.

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge 
{
    int to;
    int weight;
};
//prims algorithm
void primsMST(int n, vector<vector<Edge>>& graph) 
{
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    vector<int> parent(n, -1);
    key[0] = 0;

    for (int count = 0; count < n - 1; ++count) 
    {
        int minKey = INT_MAX, minIndex;
        for (int v = 0; v < n; ++v) 
        {
            if (!inMST[v] && key[v] < minKey) 
            {
                minKey = key[v];
                minIndex = v;
            }
        }

        inMST[minIndex] = true;

        for (const auto& edge : graph[minIndex]) 
        {
            if (!inMST[edge.to] && edge.weight < key[edge.to]) 
            {
                parent[edge.to] = minIndex;
                key[edge.to] = edge.weight;
            }
        }
    }

    int totalWeight = 0;
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (int i = 1; i < n; ++i) 
    {
        cout << parent[i] << " - " << i << " : " << key[i] << endl;
        totalWeight += key[i];
    }
    cout << "Total weight of the Minimum Spanning Tree: " << totalWeight << endl;
}

int main() 
{
    int n, m;

    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<Edge>> graph(n);

    cout << "Enter the edges in the format (from to weight):\n";
    for (int i = 0; i < m; ++i) 
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }

    primsMST(n, graph);

    return 0;
}
