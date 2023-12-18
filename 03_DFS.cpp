#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Network {
public:
    int systems;
    vector<unordered_set<int>> adjacencyList;

    Network(int n) {
        systems = n;
        adjacencyList.resize(n);
    }

    void addConnection(int system1, int system2) {
        adjacencyList[system1].insert(system2);
        adjacencyList[system2].insert(system1);  // Assuming an undirected network
    }

    void DFS(int startSystem, vector<bool>& visited) {
        cout << startSystem << " ";
        visited[startSystem] = true;

        for (int neighbor : adjacencyList[startSystem]) {
            if (!visited[neighbor]) {
                DFS(neighbor, visited);
            }
        }
    }

    void reachableSystems(int startSystem) {
        vector<bool> visited(systems, false);

        cout << "Systems reachable from system " << startSystem << " using DFS: ";
        DFS(startSystem, visited);
        cout << endl;
    }
};

int main() {
    int numSystems, numConnections;
    cout << "Enter the number of systems in the network: ";
    cin >> numSystems;

    cout << "Enter the number of connections in the network: ";
    cin >> numConnections;

    Network network(numSystems);

    cout << "Enter the connections (format: system1 system2):" << endl;
    for (int i = 0; i < numConnections; ++i) {
        int system1, system2;
        cin >> system1 >> system2;
        network.addConnection(system1, system2);
    }

    int startSystem;
    cout << "Enter the starting system: ";
    cin >> startSystem;

    network.reachableSystems(startSystem);

    return 0;
}
