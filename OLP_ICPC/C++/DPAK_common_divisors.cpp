#include <bits/stdc++.h>

using namespace std;
int N = 1e6;
vector<int>bruce(N + 5, 0);

int main(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; cin >> a[i], bruce[a[i]]++, i++);

    for (int i = N; i >= 1; i--) {
        int cnt = 0;
        for (int j = i; j <= N; j+=i) {
            cnt += bruce[j];
        }
        if (cnt >= 2) {
            cout << i;
            break;
        }
    }

    return 0;
}