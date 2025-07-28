#include <iostream>
#include <vector>
using namespace std;

// Dinh nghia cau truc canh
struct Edge {
    int u, v, w;
};

int main() {
    int n, num_keys;
    cout << "Nhap so dinh: ";
    cin >> n;
    cout << "Nhap so dinh co trong AMap: ";
    cin >> num_keys;

    vector<Edge> eal; // Danh sach canh

    cout << "Nhap AMap (u, so dinh ke, cac cap v w):\n";
    for (int i = 0; i < num_keys; ++i) {
        int u, k;
        cin >> u >> k;
        for (int j = 0; j < k; ++j) {
            int v, w;
            cin >> v >> w;
            eal.push_back({u, v, w}); // Them canh vao danh sach
        }
    }

    cout << "Danh sach canh (EAL):\n";
    for (const Edge& e : eal) {
        cout << "(" << e.u << ", " << e.v << ", " << e.w << ")\n";
    }

    return 0;
}