#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Ham chuyen danh sach ke sang danh sach ke mo rong
vector<vector<pair<int, int>>> adjacencyListToExtended(const vector<vector<int>>& adjList, int n) {
    vector<vector<pair<int, int>>> extendedList(n); // Tao danh sach moi

    for (int i = 0; i < n; ++i) {
        for (int j : adjList[i]) {
            extendedList[i].emplace_back(j, 1); // Them (j, 1) voi trong so mac dinh la 1
        }
    }

    return extendedList;
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

    auto extendedList = adjacencyListToExtended(adjList, n);

    // In danh sach ke mo rong
    cout << "Danh sach ke mo rong (EAL):\n";
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        for (const auto& [v, w] : extendedList[i]) {
            cout << "(" << v << ", " << w << ") ";
        }
        cout << endl;
    }

    return 0;
}