#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class RoadNetwork {
public:
    int towns;
    vector<vector<int>> roads; // {cost, town1, town2}

    RoadNetwork(int n) : towns(n) {}

    void addRoad(int town1, int town2, int cost) {
        roads.push_back({cost, town1, town2});
    }

    // Find operation with path compression
    int findParent(vector<int>& parent, int town) {
        if (parent[town] == town)
            return town;
        return parent[town] = findParent(parent, parent[town]);
    }

    // Union operation with rank
    void unionSets(vector<int>& parent, vector<int>& rank, int town1, int town2) {
        int root1 = findParent(parent, town1);
        int root2 = findParent(parent, town2);

        if (root1 != root2) {
            if (rank[root1] < rank[root2])
                swap(root1, root2);
            parent[root2] = root1;
            if (rank[root1] == rank[root2])
                rank[root1]++;
        }
    }

    void kruskalMST() {
        // Sort roads by cost in ascending order
        sort(roads.begin(), roads.end());

        vector<int> parent(towns);
        vector<int> rank(towns, 0);

        // Initialize parent array
        for (int i = 0; i < towns; ++i) {
            parent[i] = i;
        }

        cout << "Least Expensive Tree of Roads (Kruskal's Algorithm):" << endl;

        int totalCost = 0;
        for (const auto& road : roads) {
            int cost = road[0];
            int town1 = road[1];
            int town2 = road[2];

            if (findParent(parent, town1) != findParent(parent, town2)) {
                cout << "Road between Town " << town1 << " and Town " << town2 << " with cost " << cost << endl;
                totalCost += cost;
                unionSets(parent, rank, town1, town2);
            }
        }

        cout << "Total Cost of the Road Network: " << totalCost << endl;
    }
};

int main() {
    int numTowns, numRoads;
    cout << "Enter the number of towns in the road network: ";
    cin >> numTowns;

    cout << "Enter the number of roads in the network: ";
    cin >> numRoads;

    RoadNetwork network(numTowns);

    cout << "Enter the roads and their costs (format: town1 town2 cost):" << endl;
    for (int i = 0; i < numRoads; ++i) {
        int town1, town2, cost;
        cin >> town1 >> town2 >> cost;
        network.addRoad(town1, town2, cost);
    }

    network.kruskalMST();

    return 0;
}
