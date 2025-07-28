#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

// Ham chuyen AMap sang AL
vector<vector<int>> amapToAl(int n, const vector<tuple<int, int, int>>& amap_entries) {
    vector<vector<int>> al(n);

    for (auto [u, v, w] : amap_entries) {
        for (int i = 0; i < w; ++i)
            al[u].push_back(v);  // Them v vao danh sach ke cua u w lan
    }

    return al;
}

int main() {
    int n, k;
    cout << "Nhap so dinh: ";
    cin >> n;
    cout << "Nhap so bo (u v w): ";
    cin >> k;

    vector<tuple<int, int, int>> amap_entries;

    cout << "Nhap cac bo (u v w):\n";
    for (int i = 0; i < k; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        amap_entries.emplace_back(u, v, w);
    }

    auto al = amapToAl(n, amap_entries);

    cout << "Danh sach ke (AL):\n";
    for (int u = 0; u < n; ++u) {
        cout << u << ": ";
        for (int v : al[u])
            cout << v << " ";
        cout << "\n";
    }

    return 0;
}