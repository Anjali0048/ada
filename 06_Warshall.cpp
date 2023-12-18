#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    int systems;
    vector<vector<bool>> adjacencyMatrix;

    Graph(int n) {
        systems = n;
        adjacencyMatrix.resize(n, vector<bool>(n, false));
    }

    void addConnection(int system1, int system2) {
        adjacencyMatrix[system1][system2] = true;
    }

    void warshallTransitiveClosure() {
        vector<vector<bool>> transitiveClosure(adjacencyMatrix);

        for (int k = 0; k < systems; ++k) {
            for (int i = 0; i < systems; ++i) {
                for (int j = 0; j < systems; ++j) {
                    transitiveClosure[i][j] = transitiveClosure[i][j] || (transitiveClosure[i][k] && transitiveClosure[k][j]);
                }
            }
        }

        cout << "Transitive Closure Matrix:" << endl;
        for (int i = 0; i < systems; ++i) {
            for (int j = 0; j < systems; ++j) {
                cout << transitiveClosure[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int numSystems, numConnections;
    cout << "Enter the number of systems in the network: ";
    cin >> numSystems;

    cout << "Enter the number of connections in the network: ";
    cin >> numConnections;

    Graph network(numSystems);

    cout << "Enter the connections (format: system1 system2):" << endl;
    for (int i = 0; i < numConnections; ++i) {
        int system1, system2;
        cin >> system1 >> system2;
        network.addConnection(system1, system2);
    }

    network.warshallTransitiveClosure();

    return 0;
}
