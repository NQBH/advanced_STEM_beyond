#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

// Vi AMap va EAL deu la danh sach (u, v, w) nen tra ve truc tiep
vector<tuple<int, int, int>> amapToEal(const vector<tuple<int, int, int>>& amap_entries) {
    return amap_entries;
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

    auto eal = amapToEal(amap_entries);

    cout << "Danh sach ke mo rong (EAL):\n";
    for (auto [u, v, w] : eal) {
        cout << u << " " << v << " " << w << "\n";
    }

    return 0;
}