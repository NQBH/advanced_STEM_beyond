#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Ham chuyen danh sach ke sang ma tran ke
vector<vector<int>> alToAm(const vector<vector<int>>& adjList) {
    int n = adjList.size();
    vector<vector<int>> matrix(n, vector<int>(n, 0)); // Khoi tao ma tran 0

    for (int u = 0; u < n; ++u) {
        for (int v : adjList[u]) {
            matrix[u][v] = 1; // Danh dau canh tu u den v
        }
    }

    return matrix;
}

int main() {
    int n;
    cout << "Nhap so dinh: ";
    cin >> n;
    cin.ignore(); // Loai bo ky tu xuong dong

    vector<vector<int>> adjList(n);

    cout << "Nhap danh sach ke (AL):\n";
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        string line;
        getline(cin, line);
        stringstream ss(line);
        int v;
        while (ss >> v)
            adjList[i].push_back(v);
    }

    auto matrix = alToAm(adjList);

    cout << "Ma tran ke (AM):\n";
    for (const auto& row : matrix) {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }

    return 0;
}