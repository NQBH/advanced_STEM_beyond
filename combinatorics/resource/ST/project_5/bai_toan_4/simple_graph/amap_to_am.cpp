#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

// Ham chuyen ban do ke sang ma tran ke
vector<vector<int>> amapToMatrix(const map<int, map<int, int>>& amap, int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0)); // Ma tran n x n

    for (const auto& [i, neighbors] : amap) {
        for (const auto& [j, w] : neighbors) {
            matrix[i][j] = w;  // Gan trong so vao vi tri [i][j]
        }
    }

    return matrix;
}

int main() {
    int n;
    cout << "Nhap so dinh: ";
    cin >> n;
    cin.ignore();

    map<int, map<int, int>> amap;
    cout << "Nhap ban do ke (dinh: (dinh,trongso)...):\n";

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        if (line.find(":") == string::npos) continue;

        stringstream ss(line);
        string u_str, rest;
        getline(ss, u_str, ':');
        int u = stoi(u_str);
        amap[u] = {};

        while (ss >> rest) {
            int v, w;
            sscanf(rest.c_str(), "(%d,%d)", &v, &w);
            amap[u][v] = w;
        }
    }

    auto matrix = amapToMatrix(amap, n);

    cout << "Ma tran ke:\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}