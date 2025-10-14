#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> b(n + 1), freq(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			cin >> b[i];
			freq[b[i]]++;
		}
		bool check = true;
		for (int i  = 2; i <= n; i++) {
			if (freq[i] != 0 && freq[i] % i != 0) {
				check = false;
				break;
			}
		}
		if (check == false) {
			cout << -1 << endl;
			continue;
		}
		/*
		1 2 2 1 2 1 2
        1 2 2 3 4 5 4
        int num = 0;
		for (int i = 1; i <= n; i++) {
            num += freq[i] / i;
		}
        */
        int cnt = 1;
        vector<pair<int,int>> last(n + 1);
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            last[b[i]] = {b[i], -1};
        }

        for (int i = 1; i <= n; i++) {
            if (last[b[i]].second == -1) {
                last[b[i]].second = i;
                a[i] = cnt++;
                last[b[i]].first--;
            }
            else {
                last[b[i]].first--;
                a[i] = a[last[b[i]].second];
            }
            if (last[b[i]].first == 0) {
                last[b[i]].first = b[i];
                last[b[i]].second = -1;
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
		cout << endl;
	}
}