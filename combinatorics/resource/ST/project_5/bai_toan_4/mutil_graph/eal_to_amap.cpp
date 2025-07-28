#include <iostream>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

// Ham chuyen EAL sang AMap
map<int, map<int, int>> ealToAmap(const vector<tuple<int, int, int>>& eal) {
    map<int, map<int, int>> amap;

    for (auto [u, v, w] : eal) {
        amap[u][v] = w;  // Gan so canh tu u den v la w
    }

    return amap;
}

int main() {
    int n, k;
    cout << "Nhap so dinh: ";
    cin >> n;
    cout << "Nhap so bo (u v w): ";
    cin >> k;

    vector<tuple<int, int, int>> eal;
    cout << "Nhap cac bo (u v w):\n";
    for (int i = 0; i < k; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        eal.emplace_back(u, v, w);
    }

    auto amap = ealToAmap(eal);

    cout << "Ban do ke (AMap):\n";
    for (int u = 0; u < n; ++u) {
        cout << u << ": ";
        for (auto& [v, w] : amap[u]) {
            cout << "(" << v << "," << w << ") ";
        }
        cout << endl;
    }

    return 0;
}