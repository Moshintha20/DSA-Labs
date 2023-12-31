#include <bits/stdc++.h>
using namespace std;
 
// Number of vertices in the graph
#define V 6
 
// A utility function to find the vertex with minimum key value, from the set of vertices
int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}
 
// A utility function to print the constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
}
 
// Function to construct and print MST for a graph represented using adjacency matrix representation
void primMST(int graph[V][V])
{
    int parent[V];          // Array to store constructed MST

    int key[V];             // Key values used to pick minimum weight edge

    bool mstSet[V];         //represent set of vertices included in MST
 
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
    key[0] = 0;          // Make key 0 so that this vertex is picked as first vertex.
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false
                && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
 
    printMST(parent, graph);        // Print the constructed MST
}
 
int main()
{
    int graph[V][V] = { { 0, 3, 0, 0, 0, 1 },
                        { 3, 0, 2, 1, 10, 0 },
                        { 0, 2, 0, 3, 0, 5 },
                        { 0, 1, 3, 0, 5, 0 },
                        { 0, 10, 0, 5, 0, 4 },
                        { 1, 0, 5, 9, 4, 0 } };
 
    primMST(graph);
 
    return 0;
}
 
