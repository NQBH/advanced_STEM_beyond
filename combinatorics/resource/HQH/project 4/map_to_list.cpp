#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

// Convert adjacency map to adjacency list
vector<vector<int>> mapToList(const map<int, set<int>>& adjMap) {
    int maxVertex = 0;
    for (const auto& pair : adjMap) {
        maxVertex = max(maxVertex, pair.first);
        for (int v : pair.second) {
            maxVertex = max(maxVertex, v);
        }
    }
    
    vector<vector<int>> adjList(maxVertex + 1);
    for (const auto& pair : adjMap) {
        for (int v : pair.second) {
            adjList[pair.first].push_back(v);
        }
    }
    return adjList;
}

void printAdjList(const vector<vector<int>>& adjList) {
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < adjList.size(); i++) {
        cout << i << ": ";
        for (int v : adjList[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example adjacency map
    map<int, set<int>> adjMap = {
        {0, {1, 2}},
        {1, {0, 2, 3}},
        {2, {0, 1, 3}},
        {3, {1, 2}}
    };
    
    cout << "Original Adjacency Map:" << endl;
    for (const auto& pair : adjMap) {
        cout << pair.first << ": {";
        bool first = true;
        for (int v : pair.second) {
            if (!first) cout << ", ";
            cout << v;
            first = false;
        }
        cout << "}" << endl;
    }
    cout << endl;
    
    vector<vector<int>> adjList = mapToList(adjMap);
    printAdjList(adjList);
    
    return 0;
}
