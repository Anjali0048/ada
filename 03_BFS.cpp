#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

class Graph {
public:
    int vertices;
    vector<unordered_set<int>> adjacencyList;

    Graph(int V) {
        vertices = V;
        adjacencyList.resize(V);
    }

    void addEdge(int src, int dest) {
        adjacencyList[src].insert(dest);
    }

    void BFS(int startVertex) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        cout << "Vertices reachable from vertex " << startVertex << " using BFS: ";

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();

            cout << currentVertex << " ";

            for (int neighbor : adjacencyList[currentVertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        cout << endl;
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices in the graph: ";
    cin >> vertices;

    cout << "Enter the number of edges in the graph: ";
    cin >> edges;

    Graph graph(vertices);

    cout << "Enter the edges (format: source destination):" << endl;
    for (int i = 0; i < edges; ++i) {
        int src, dest;
        cin >> src >> dest;
        graph.addEdge(src, dest);
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    graph.BFS(startVertex);

    return 0;
}
