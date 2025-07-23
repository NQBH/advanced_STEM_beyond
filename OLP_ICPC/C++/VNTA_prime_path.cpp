#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
bool isPrime[N];

void eratosthenes() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; ++i)
        if (isPrime[i])
            for (int j = i * i; j <= N; j += i) isPrime[j] = false;
}

int bfs(int s, int e) {
    vector<bool> visited(N, false);
    queue<pair<int, int>> q;
    q.push({s, 0});
    visited[s] = true;

    while (!q.empty()) {
        auto [cur, step] = q.front();
        q.pop();
        if (cur == e) return step;
        string s = to_string(cur);
        for (int i = 0; i < 4; ++i) {
            char o = s[i];
            for (char d = '0'; d <= '9'; ++d) {
                s[i] = d;
                int next = stoi(s);
                if (next >= 1000 && isPrime[next] && !visited[next]) {
                    visited[next] = true;
                    q.push({next, step + 1});
                }
            }
            s[i] = o;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    eratosthenes();
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int res = bfs(a, b);
        if (res == -1) cout << "Impossible\n";
        else cout << res << "\n";
    }
}
/*
Input:
3
1033 8179
1373 8017
1033 1033
Output:
6
7
0
*/