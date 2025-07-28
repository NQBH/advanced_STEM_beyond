#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

// Ham chuyen danh sach ke mo rong sang ban do ke
map<int, map<int, int>> ealToAmap(const vector<vector<pair<int, int>>>& eal, int n) {
    map<int, map<int, int>> amap;

    for (int i = 0; i < n; ++i) {
        for (const auto& [j, w] : eal[i]) {
            amap[i][j] = w;  // Gan trong so vao map
            amap[j][i] = w;
        }
    }

    return amap;
}

int main() {
    int n;
    cout << "Nhap so dinh: ";
    cin >> n;
    cin.ignore();

    vector<vector<pair<int, int>>> eal(n);
    cout << "Nhap danh sach ke mo rong:\n";

    for (int i = 0; i < n; ++i) {
        cout << "Dinh " << i << " (dinh,trongso): ";
        string line;
        getline(cin, line);
        stringstream ss(line);
        string token;
        while (ss >> token) {
            int u, w;
            sscanf(token.c_str(), "(%d,%d)", &u, &w);
            eal[i].emplace_back(u, w);
        }
    }

    auto amap = ealToAmap(eal, n);

    cout << "Ban do ke (AMap):\n";
    for (const auto& [u, neighbors] : amap) {
        cout << u << ": ";
        for (const auto& [v, w] : neighbors) {
            cout << "(" << v << "," << w << ") ";
        }
        cout << endl;
    }

    return 0;
}