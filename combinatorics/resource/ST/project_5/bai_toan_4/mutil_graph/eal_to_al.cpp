#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

// Chuyen EAL sang danh sach ke AL
vector<vector<int>> ealToAl(int n, const vector<tuple<int, int, int>>& eal) {
    vector<vector<int>> al(n);

    for (auto [u, v, w] : eal) {
        for (int i = 0; i < w; ++i)
            al[u].push_back(v);
    }

    return al;
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

    auto al = ealToAl(n, eal);

    cout << "Danh sach ke (AL):\n";
    for (int u = 0; u < n; ++u) {
        cout << u << ": ";
        for (int v : al[u]) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}