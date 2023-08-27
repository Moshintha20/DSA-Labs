#include <iostream>
#include <list>
using namespace std;

struct Node {
    int label;
    list<int> neighbors;
};

struct Graph {
    int n = 8;
    Node* nodes = new Node[n];

    void initializeNodes() {
        for (int i = 0; i < n; i++) {
            nodes[i].label = i;
        }
    }

    void addEdge(int u, int v) 
    {
        nodes[u-1].neighbors.push_back(v);  // Add v to u-1's neighbors
        nodes[v-1].neighbors.push_back(u);  // Add u to v-1's neighbors
    }

    void print()       //printing node and its neigbors
    {
        for (int i = 0; i < n; i++) {
            cout << "Node " << i+1 << " -> ";
            for (int neighbor : nodes[i].neighbors) 
            {
                cout << neighbor << "  ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph* g = new Graph;
    g->initializeNodes();

    // Adding edges for the graph
    g->addEdge(1, 2);
    g->addEdge(1, 3);
    g->addEdge(1, 4);
    g->addEdge(1, 5);
    g->addEdge(2, 3);
    g->addEdge(2, 6);
    g->addEdge(4, 6);
    g->addEdge(4, 7);
    g->addEdge(4, 8);
    g->addEdge(5, 6);
    g->addEdge(5, 7);
    g->addEdge(5, 8);
    
    g->print();                 // Printing the graph's adjacency list
    return 0;
}
