#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        if (k == n * n - 1) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            vector<vector<char>>a(n + 1, vector<char>(n + 1, 'R'));
            int remain = n * n - k;
            int mod = remain % 2;
//            pair<int,int> lastPos;
            for (int i = 1; i <= n && remain - mod > 0; i++) {
                for (int j = 2; j <= n && remain - mod > 0; j += 2) {
                    a[i][j] = 'L';
                    remain -= 2;
//                    lastPos = {i, j};
                }
            }
            if (remain > 0) {
                if (n % 2 == 1) {
                    if (remain == 1) {
                        bool check = true;
                        for (int i = 1; i < n && check; i++) {
                            for (int j = 2; j <= n && check; j += 2) {
                                if (a[i][j] != a[i + 1][j]) {
                                    a[i + 1][j - 1] = 'U';
                                    check = false;
                                }
                            }
                        }
                        if (check) {
                            for (int i = 1; i < n; i++) {
                                if (a[i][n] == a[i + 1][n]) {
                                    a[i][n] = 'L';
                                    break;
                                }
                            }
                        }
                    }
                    else {
                        int pt = 1;
                        while (remain > 0) {
                            bool check = true;
                            for (int j = 1; j < n; j++) {
                                if (a[pt][j] == a[pt][j + 1]) {
                                    a[pt][j] = 'L';
                                    check = false;
                                    break;
                                }
                            }
                            if (check) {
                                a[pt][n] = 'L';
                            }
                            pt++;
                            remain--;
                        }
                    }
                }
                else {
                    bool check = true;
                    for (int i = 1; i <= n && check; i++) {
                        for (int j = 1; j < n && check; j++) {
                            if (a[i][j] == a[i][j + 1]) {
                                if (i == 1) a[i][j] = 'L';
                                else a[i][j] = 'U';
                                remain--;
                                check = false;
                            }
                        }
                    }
                }
            }

            for (int i = 1; i <= n; i++) {
                for( int j = 1; j <= n; j++) {
                    cout << a[i][j];
                }
                cout << endl;
            }

        }
    }
}
