#include <iostream>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

// Ham chuyen ban do ke sang danh sach ke
vector<vector<int>> amapToAl(const map<int, map<int, int>>& amap, int n) {
    vector<vector<int>> al(n); // Khoi tao danh sach ke rong

    for (const auto& [i, neighbors] : amap) {
        for (const auto& [j, _] : neighbors) {
            al[i].push_back(j); // Bo qua trong so, chi lay dinh ke
        }
    }

    return al;
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

    // Chuyen doi va in danh sach ke
    auto al = amapToAl(amap, n);

    cout << "Danh sach ke (AL):\n";
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        for (int v : al[i]) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}