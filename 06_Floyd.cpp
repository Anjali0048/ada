#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class CityNetwork {
public:
    int cities;
    vector<vector<int>> adjacencyMatrix;

    CityNetwork(int n) {
        cities = n;
        adjacencyMatrix.resize(n, vector<int>(n, numeric_limits<int>::max()));
    }

    void addConnection(int city1, int city2, int distance) {
        adjacencyMatrix[city1][city2] = distance;
    }

    void floydsShortestPaths() {
        vector<vector<int>> shortestPaths(adjacencyMatrix);

        for (int k = 0; k < cities; ++k) {
            for (int i = 0; i < cities; ++i) {
                for (int j = 0; j < cities; ++j) {
                    if (shortestPaths[i][k] != numeric_limits<int>::max() &&
                        shortestPaths[k][j] != numeric_limits<int>::max() &&
                        shortestPaths[i][k] + shortestPaths[k][j] < shortestPaths[i][j]) {
                        shortestPaths[i][j] = shortestPaths[i][k] + shortestPaths[k][j];
                    }
                }
            }
        }

        cout << "Shortest Paths Matrix:" << endl;
        for (int i = 0; i < cities; ++i) {
            for (int j = 0; j < cities; ++j) {
                cout << (shortestPaths[i][j] == numeric_limits<int>::max() ? "INF" : to_string(shortestPaths[i][j])) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int numCities, numConnections;
    cout << "Enter the number of cities in the network: ";
    cin >> numCities;

    cout << "Enter the number of connections in the network: ";
    cin >> numConnections;

    CityNetwork network(numCities);

    cout << "Enter the connections and distances (format: city1 city2 distance):" << endl;
    for (int i = 0; i < numConnections; ++i) {
        int city1, city2, distance;
        cin >> city1 >> city2 >> distance;
        network.addConnection(city1, city2, distance);
    }

    network.floydsShortestPaths();

    return 0;
}
