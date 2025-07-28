#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

// Ham chuyen AMap sang AM
vector<vector<int>> amapToAm(int n, const vector<tuple<int, int, int>>& amap_entries) {
    vector<vector<int>> am(n, vector<int>(n, 0)); // Khoi tao ma tran n x n

    for (auto [u, v, w] : amap_entries) {
        am[u][v] = w;  // Gan so canh tu u den v la w
    }

    return am;
}

int main() {
    int n, k;
    cout << "Nhap so dinh: ";
    cin >> n;
    cout << "Nhap so canh (bo u v w): ";
    cin >> k;

    vector<tuple<int, int, int>> amap_entries;

    cout << "Nhap cac bo (u v w):\n";
    for (int i = 0; i < k; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        amap_entries.emplace_back(u, v, w);
    }

    auto am = amapToAm(n, amap_entries);

    cout << "Ma tran ke (AM):\n";
    for (const auto& row : am) {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }

    return 0;
}