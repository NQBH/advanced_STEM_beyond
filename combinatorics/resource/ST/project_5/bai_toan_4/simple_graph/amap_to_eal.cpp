#include <iostream>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

// Ham chuyen Adjacency Map sang Extended Adjacency List
vector<vector<pair<int, int>>> amapToEAL(const map<int, map<int, int>>& amap, int n) {
    vector<vector<pair<int, int>>> eal(n); // Khoi tao danh sach rong cho n dinh
    for (const auto& [u, neighbors] : amap) {
        for (const auto& [v, w] : neighbors) {
            eal[u].emplace_back(v, w); // Them cap (v, w) vao EAL[u]
        }
    }
    return eal;
}

int main() {
    int n;
    cout << "Nhap so dinh: ";
    cin >> n;
    cin.ignore();

    map<int, map<int, int>> amap;
    cout << "Nhap ban do ke (dinh: (dinh,trongso)...):\n";
    // Vi du: 0: (1,3) (2,5)
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        if (line.find(":") == string::npos) continue;

        stringstream ss(line);
        string u_str, token;
        getline(ss, u_str, ':');
        int u = stoi(u_str);
        amap[u] = {};

        while (ss >> token) {
            int v, w;
            sscanf(token.c_str(), "(%d,%d)", &v, &w);
            amap[u][v] = w;
        }
    }

    auto eal = amapToEAL(amap, n);

    cout << "Danh sach ke mo rong (EAL):\n";
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        for (auto [v, w] : eal[i]) {
            cout << "(" << v << "," << w << ") ";
        }
        cout << endl;
    }

    return 0;
}