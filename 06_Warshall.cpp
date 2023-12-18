#include <iostream>
#include <vector>
using namespace std;

// Function to apply Warshall's algorithm and find the transitive closure
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
    int n;

    // Input: Number of nodes in the graph
    cout << "Enter the number of nodes in the graph: ";
    cin >> n;

    // Input: Adjacency matrix representing the graph
    cout << "Enter the adjacency matrix (0 or 1) of the graph:\n";
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // Find and display the transitive closure
    transitiveClosure(graph, n);

    // Display the transitive closure matrix
    cout << "\nTransitive Closure:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
