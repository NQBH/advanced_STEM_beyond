#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int vertex;
    int weight;
};

// Convert extended adjacency list to simple adjacency list
vector<vector<int>> extendedListToList(const vector<vector<Edge>>& extList) {
    vector<vector<int>> adjList(extList.size());
    
    for (int i = 0; i < extList.size(); i++) {
        for (const Edge& e : extList[i]) {
            adjList[i].push_back(e.vertex);
        }
    }
    return adjList;
}

void printAdjList(const vector<vector<int>>& adjList) {
    cout << "Simple Adjacency List:" << endl;
    for (int i = 0; i < adjList.size(); i++) {
        cout << i << ": ";
        for (int v : adjList[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example extended adjacency list
    vector<vector<Edge>> extList = {
        {{1, 5}, {2, 3}},
        {{0, 2}, {3, 7}},
        {{0, 4}, {3, 1}},
        {{1, 6}, {2, 8}}
    };
    
    cout << "Original Extended Adjacency List:" << endl;
    for (int i = 0; i < extList.size(); i++) {
        cout << i << ": ";
        for (const Edge& e : extList[i]) {
            cout << "(" << e.vertex << "," << e.weight << ") ";
        }
        cout << endl;
    }
    cout << endl;
    
    vector<vector<int>> adjList = extendedListToList(extList);
    printAdjList(adjList);
    
    return 0;
}
