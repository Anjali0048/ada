#include <iostream>
#include <climits>
#include <vector>
using namespace std;

#define V 4 // Number of cities

void floyd(int graph[V][V]) {
    int dist[V][V];

    // Initialize the distance matrix with the given graph
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Update the distance matrix using all vertices as intermediates
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances between all pairs of cities
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) {
                cout << "INF\t";
            } else {
                cout << dist[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

    // warshall
    void transitiveClosure(vector<vector<int>>& graph, int n) {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
                }
            }
        }
    }


int main() {
    // Example adjacency matrix representing distances between cities
    int graph[V][V] = {
        {0, 5, INT_MAX, 10},
        {INT_MAX, 0, 3, INT_MAX},
        {INT_MAX, INT_MAX, 0, 1},
        {INT_MAX, INT_MAX, INT_MAX, 0}
    };

    floyd(graph);

    return 0;
}


// warshall
// int main() {
//     int n;
//     cout << "Enter the number of nodes in the graph: ";
//     cin >> n;

//     // Input: Adjacency matrix representing the graph
//     cout << "Enter the adjacency matrix (0 or 1) of the graph:\n";
//     vector<vector<int>> graph(n, vector<int>(n, 0));
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             cin >> graph[i][j];
//         }
//     }

//     // Find and display the transitive closure
//     transitiveClosure(graph, n);

//     // Display the transitive closure matrix
//     cout << "\nTransitive Closure:\n";
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             cout << graph[i][j] << " ";
//         }
//         cout << "\n";
//     }
//     return 0;
// }
