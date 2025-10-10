#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> a(n + 1), b(n + 1), one, two;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        for (int i = 1; i <= n; i++) {
            if (b[i] == 1) one.push_back(a[i]);
            else two.push_back(a[i]);
        }
        one.push_back(1e10);
        two.push_back(1e10);
        sort(one.begin(), one.end(), greater<int>());
        sort(two.begin(), two.end(), greater<int>());
        int one_n = one.size() - 1, two_n = two.size() - 1;
        vector<int> f1(one_n + 1, 0);
        vector<int> f2(two_n + 1, 0);
        for (int i = 1; i <= one_n; i++) {
            f1[i] = f1[i - 1] + one[i];
        }
        for (int i = 1; i <= two_n; i++) {
            f2[i] = f2[i - 1] + two[i];
        }
        int min_ope = 1e10;
        int ans = -1;
        for (int i = 1; i <= one_n; i++) {
            int temp_ope = i;
            int temp_val = f1[i];
            if (temp_val >= m) {
                if (min_ope > temp_ope) {
                    min_ope = temp_ope;
                    ans = temp_val;
                }
            }
            else {
                int l = 1, r = two_n;
                while (l <= r) {
                    int mid = l + r >> 1;
                    int ttemp_val = temp_val + f2[mid];
                    if (ttemp_val >= m) {
                        if (min_ope > temp_ope + 2*mid) {
                            min_ope = temp_ope + 2*mid;
                            ans = ttemp_val;
                        }
                        r = mid - 1;
                    }
                    else {
                        l = mid + 1;
                    }
                }
            }
        }
        int temp_min_ope= 0;
        int temp_min_ans= 0;
        for (int i = 1; i <= two_n; i++) {
            temp_min_ans += two[i];
            temp_min_ope += 2;
            if (temp_min_ans >= m) {
                if (temp_min_ope < min_ope) {
                    min_ope = temp_min_ope;
                    ans = temp_min_ans;
                }
                break;
            }
        }
        
        if (ans < m) min_ope = -1;
        cout << min_ope << endl;
    }
}