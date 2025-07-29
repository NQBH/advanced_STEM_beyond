#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj; 
// adj[u] la danh sach ke cua dinh u
// moi phan tu la cap (v, w) nghia la co canh tu u den v co trong so w

// Ham thuc hien thuat toan Dijkstra tu dinh bat dau
vector<int> dijkstra(int start) {
    const int INF = 1e9; // gia tri vo cung (lon)
    vector<int> dist(n, INF); // mang dist luu khoang cach ngan nhat tu start den moi dinh
    dist[start] = 0; // khoang cach tu start den chinh no la 0

    // hang doi uu tien (min-heap) luu cap (khoang cach tam thoi, dinh)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start}); // dua dinh bat dau vao hang doi

    while (!pq.empty()) {
        auto [d, u] = pq.top(); // lay ra phan tu co khoang cach nho nhat
        pq.pop();

        // neu da tim duoc duong ngan hon truoc do thi bo qua
        if (d > dist[u]) continue;

        // duyet tat ca canh ke cua dinh u
        for (auto [v, w] : adj[u]) {
            // neu tim duoc duong ngan hon den v thi cap nhat
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v}); // dua vao hang doi
            }
        }
    }

    return dist; // tra ve ket qua la mang khoang cach ngan nhat
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m; // nhap so dinh n va so cap dinh co canh noi m
    adj.assign(n, {}); // khoi tao danh sach ke

    // Nhap m cap dinh
    for (int i = 0; i < m; i++) {
        int u, v, k;
        cin >> u >> v >> k; // co k canh giua u va v
        for (int j = 0; j < k; j++) {
            int w;
            cin >> w; // trong so cua canh
            // do thi vo huong nen luu ca 2 chieu
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }

    int start = 0; // chon dinh bat dau la 0
    vector<int> dist = dijkstra(start); // goi ham Dijkstra

    cout << "Khoang cach ngan nhat tu dinh " << start << ":\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == 1000000000)
            cout << "Dinh " << i << ": khong the den\n";
        else
            cout << "Dinh " << i << ": " << dist[i] << "\n";
    }

    return 0;
}