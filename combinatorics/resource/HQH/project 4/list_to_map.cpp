#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

// Convert adjacency list to adjacency map
map<int, set<int>> listToMap(const vector<vector<int>>& adjList) {
    map<int, set<int>> adjMap;
    
    for (int i = 0; i < adjList.size(); i++) {
        for (int v : adjList[i]) {
            adjMap[i].insert(v);
        }
    }
    return adjMap;
}

void printAdjMap(const map<int, set<int>>& adjMap) {
    cout << "Adjacency Map:" << endl;
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
}

int main() {
    // Example adjacency list
    vector<vector<int>> adjList = {
        {1, 2},
        {0, 3, 2},
        {0, 3, 1},
        {1, 2}
    };
    
    cout << "Original Adjacency List:" << endl;
    for (int i = 0; i < adjList.size(); i++) {
        cout << i << ": ";
        for (int v : adjList[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    map<int, set<int>> adjMap = listToMap(adjList);
    printAdjMap(adjMap);
    
    return 0;
}
