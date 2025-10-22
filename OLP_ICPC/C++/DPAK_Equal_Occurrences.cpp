#include <bits/stdc++.h>
#define APC signed
#define int long long
using namespace std;

const int oo = 1e9;

APC main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int>a(n + 1);
        vector<int> cnt(101, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        vector<pair<int, int>> freq;
        set<int> ms;
        for (int i = 1; i <= 100; i++) {
            if (cnt[i] > 0) {
                freq.push_back({cnt[i], i});
                ms.insert(i);
            }
        }
        sort(freq.begin(), freq.end());
        int ans = 0;
        for (int i = 0; i < freq.size(); i++) {
            ans = max(ans, freq[i].first * ((int)freq.size() - i));
            //    cout << freq[i].first << " " << freq[i].second << " " << i << " " << ans << endl;
        }
        cout << ans << endl;
    }
}

