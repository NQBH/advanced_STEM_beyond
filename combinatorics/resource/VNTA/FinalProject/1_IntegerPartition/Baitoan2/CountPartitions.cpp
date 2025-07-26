#include <bits/stdc++.h>
using namespace std;

const int MAX = 205;
int p[MAX][MAX]; // p(n,k): số phân hoạch của n dùng phần tử <= k
int pk[MAX][MAX]; // p_k(n): số phân hoạch của n thành đúng k phần tử

void calPartition() {
    for (int i = 0; i < MAX; ++i) {
        p[0][i] = 1; // chỉ có 1 cách phân hoạch 0 là rỗng
        pk[0][i] = (i == 0); // chỉ pk[0][0] = 1, còn lại = 0
    }
    for (int n = 1; n < MAX; ++n)
        for (int k = 1; k < MAX; ++k) {
            if (n >= k) pk[n][k] = pk[n - 1][k - 1] + pk[n - k][k];
            else pk[n][k] = 0;
            p[n][k] = p[n][k - 1];
            if (n >= k) p[n][k] += p[n - k][k];
        }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;

    calPartition();
    int pnk = p[n][k];
    int pn_k1 = (k > 0) ? p[n][k - 1] : 0;
    int pmax = pnk - pn_k1;
    int pk_val = pk[n][k];

    cout << "So phan hoach cua " << n << " voi phan tu khong lon hon " << k << ": p(n,k) = " << pnk << "\n";
    cout << "So phan hoach cua " << n << " voi phan tu lon nhat bang " << k << ": p_max(n,k) = " << pmax << "\n";
    cout << "So phan hoach cua " << n << " thanh dung " << k << " phan tu: p_k(n) = " << pk_val << "\n";
    if (pmax == pk_val) cout << "=> p_max(n,k) = p_k(n)";
    else if (pmax < pk_val) cout << "=> p_max(n,k) < p_k(n)";
    else cout << "=> p_max(n,k) > p_k(n)";
}