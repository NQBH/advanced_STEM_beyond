#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, int p, const vector<int>& fc, const vector<int>& ns, vector<int>& parent) {
    parent[u] = p;
    if (fc[u] != -1)
        dfs(fc[u], u, fc, ns, parent);
    if (ns[u] != -1)
        dfs(ns[u], p, fc, ns, parent);
}

int main() {
    int n;
    cout << "Nhap so nut: ";
    cin >> n;

    vector<int> fc(n), ns(n), parent(n, -1);
    cout << "Nhap mang fc:\n";
    for (int i = 0; i < n; ++i) cin >> fc[i];
    cout << "Nhap mang ns:\n";
    for (int i = 0; i < n; ++i) cin >> ns[i];

    dfs(0, -1, fc, ns, parent); // Bat dau tu goc 0

    cout << "Mang parent:\n";
    for (int i = 0; i < n; ++i)
        cout << parent[i] << " ";
    cout << "\n";

    return 0;
}