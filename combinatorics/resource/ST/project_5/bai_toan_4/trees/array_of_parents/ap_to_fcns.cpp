#include <iostream>
#include <vector>
using namespace std;

void apToFcns(const vector<int>& parent, vector<int>& fc, vector<int>& ns) {
    int n = parent.size();
    vector<vector<int>> children(n);

    // Xay dung danh sach con
    for (int i = 0; i < n; ++i) {
        if (parent[i] != -1)
            children[parent[i]].push_back(i);
    }

    // Gan fc va ns
    for (int u = 0; u < n; ++u) {
        if (!children[u].empty()) {
            fc[u] = children[u][0];
            for (size_t i = 0; i + 1 < children[u].size(); ++i)
                ns[children[u][i]] = children[u][i + 1];
        }
    }
}

int main() {
    int n;
    cout << "Nhap so nut: ";
    cin >> n;

    vector<int> parent(n), fc(n, -1), ns(n, -1);
    cout << "Nhap mang parent:\n";
    for (int i = 0; i < n; ++i)
        cin >> parent[i];

    apToFcns(parent, fc, ns);

    cout << "First Child (fc): ";
    for (int x : fc) cout << x << " ";
    cout << "\nNext Sibling (ns): ";
    for (int x : ns) cout << x << " ";
    cout << "\n";

    return 0;
}