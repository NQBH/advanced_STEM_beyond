#include <iostream>
#include <vector>
#include <tuple>
#include <sstream>

using namespace std;

// Ham chuyen danh sach ke sang danh sach ke mo rong
vector<tuple<int, int, int>> alToEal(const vector<vector<int>>& adjList) {
    vector<tuple<int, int, int>> eal;
    for (int u = 0; u < adjList.size(); ++u) {
        for (int v : adjList[u]) {
            eal.emplace_back(u, v, 1); // Gan trong so la 1
        }
    }
    return eal;
}

int main() {
    int n;
    cout << "Nhap so dinh: ";
    cin >> n;
    cin.ignore(); // Loai bo ky tu xuong dong sau khi nhap n

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

    auto eal = alToEal(adjList);

    cout << "Danh sach ke mo rong (EAL):\n";
    for (const auto& [u, v, w] : eal)
        cout << u << " " << v << " " << w << "\n";

    return 0;
}