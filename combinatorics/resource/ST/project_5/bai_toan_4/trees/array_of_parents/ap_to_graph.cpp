#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Nhap so nut: ";
    cin >> n;

    vector<int> parent(n);
    cout << "Nhap mang parent:\n";
    for (int i = 0; i < n; ++i)
        cin >> parent[i];

    // Khoi tao danh sach ke
    vector<vector<int>> adj(n);

    // Tao canh giua moi nut va cha cua no
    for (int i = 0; i < n; ++i) {
        if (parent[i] != -1) {
            int u = i, v = parent[i];
            adj[u].push_back(v);
            adj[v].push_back(u); // Do thi vo huong
        }
    }

    // In danh sach ke
    cout << "Danh sach ke (Graph tu AP):\n";
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        for (int v : adj[i])
            cout << v << " ";
        cout << "\n";
    }

    return 0;
}