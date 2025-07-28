#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

// Ham chuyen danh sach ke sang ban do ke
map<int, vector<int>> adjacencyListToMap(const vector<vector<int>>& adjList, int n) {
    map<int, vector<int>> adjMap;  // Khoi tao ban do ke

    for (int i = 0; i < n; ++i) {
        adjMap[i] = adjList[i];  // Gan danh sach ke cua i vao map
    }

    return adjMap;
}

int main() {
    int n;
    cout << "Nhap so dinh: ";
    cin >> n;
    cin.ignore();

    vector<vector<int>> adjList(n);
    cout << "Nhap danh sach ke:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Dinh " << i << ": ";
        string line;
        getline(cin, line);
        stringstream ss(line);
        int x;
        while (ss >> x) {
            adjList[i].push_back(x);
        }
    }

    // Chuyen doi va in ban do ke
    auto adjMap = adjacencyListToMap(adjList, n);

    cout << "Adjacency Map:\n";
    for (const auto& [u, neighbors] : adjMap) {
        cout << u << ": ";
        for (int v : neighbors) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}