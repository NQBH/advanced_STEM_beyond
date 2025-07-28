#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

// Ham chuyen AL sang AMap
map<int, map<int, int>> alToAmap(const vector<vector<int>>& adjList) {
    map<int, map<int, int>> amap;

    for (int u = 0; u < adjList.size(); ++u) {
        for (int v : adjList[u]) {
            amap[u][v]++;  // Tang dem moi khi co canh (u,v)
        }
    }

    return amap;
}

int main() {
    int n;
    cout << "Nhap so dinh: ";
    cin >> n;

    vector<vector<int>> adjList(n);
    cin.ignore(); // Xoa bo dem

    cout << "Nhap danh sach ke:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Ke cua dinh " << i << ": ";
        string line;
        getline(cin, line);
        istringstream iss(line);
        int x;
        while (iss >> x)
            adjList[i].push_back(x);
    }

    // Chuyen doi va in ket qua
    auto amap = alToAmap(adjList);
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