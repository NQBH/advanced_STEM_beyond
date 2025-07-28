#include <iostream>
#include <vector>
using namespace std;

void buildFCNS(int u, int p, const vector<vector<int>>& adj,
               vector<int>& fc, vector<int>& ns) {
    vector<int> children;
    for (int v : adj[u]) {
        if (v != p)
            children.push_back(v);
    }

    if (!children.empty()) {
        fc[u] = children[0];
        for (size_t i = 0; i + 1 < children.size(); ++i)
            ns[children[i]] = children[i + 1];
    }

    for (int v : children)
        buildFCNS(v, u, adj, fc, ns);
}

int main() {
    int n;
    cout << "Nhap so dinh: ";
    cin >> n;
    cin.ignore();

    vector<vector<int>> adj(n);
    cout << "Nhap danh sach ke:\n";
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        string line;
        getline(cin, line);
        stringstream ss(line);
        int v;
        while (ss >> v)
            adj[i].push_back(v);
    }

    vector<int> fc(n, -1), ns(n, -1);
    buildFCNS(0, -1, adj, fc, ns);

    cout << "Mang fc: ";
    for (int x : fc) cout << x << " ";
    cout << "\nMang ns: ";
    for (int x : ns) cout << x << " ";
    cout << "\n";

    return 0;
}