#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<string> G(n);
        for (int i = 0; i < n; ++i) cin >> G[i];

        // ---- 1.  forbid three consecutive black cells already present ----
        auto has_three = [&]() -> bool {
            // rows
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n-2; ++j)
                    if (G[i][j]=='#' && G[i][j+1]=='#' && G[i][j+2]=='#') return true;
            // columns
            for (int j = 0; j < n; ++j)
                for (int i = 0; i < n-2; ++i)
                    if (G[i][j]=='#' && G[i+1][j]=='#' && G[i+2][j]=='#') return true;
            return false;
        };
        if (has_three()) { cout << "NO\n"; continue; }

        // ---- 2.  collect all original black cells ----
        vector<pair<int,int>> orig;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (G[i][j] == '#') orig.emplace_back(i,j);

        if (orig.empty()) {                     // paint any single cell
            cout << "YES\n";
            continue;
        }

        // ---- 3.  try to connect them using a zigzag pattern ----
        //   we keep a temporary grid where we paint the needed cells
        vector<string> temp = G;                // copy original
        vector<vector<bool>> used(n, vector<bool>(n,false));
        queue<pair<int,int>> q;

        // start from the first original black cell
        auto [si,sj] = orig[0];
        q.emplace(si,sj);
        used[si][sj] = true;
        temp[si][sj] = '#';                     // already black

        const int di[] = {-1,0,1,0};
        const int dj[] = {0,1,0,-1};

        while (!q.empty()) {
            auto [ci,cj] = q.front(); q.pop();
            for (int d = 0; d < 4; ++d) {
                int ni = ci + di[d], nj = cj + dj[d];
                if (ni>=0 && ni<n && nj>=0 && nj<n && !used[ni][nj]) {
                    // we may paint a white cell
                    used[ni][nj] = true;
                    temp[ni][nj] = '#';
                    q.emplace(ni,nj);
                }
            }
        }

        // ---- 4.  all original black cells must be reachable ----
        bool all_reached = true;
        for (auto [i,j] : orig)
            if (!used[i][j]) { all_reached = false; break; }
        if (!all_reached) { cout << "NO\n"; continue; }

        // ---- 5.  final component must contain NO three consecutive ----
        bool ok = true;
        // rows
        for (int i = 0; i < n && ok; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (temp[i][j] == '#') ++cnt; else cnt = 0;
                if (cnt == 3) { ok = false; break; }
            }
        }
        // columns
        for (int j = 0; j < n && ok; ++j) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (temp[i][j] == '#') ++cnt; else cnt = 0;
                if (cnt == 3) { ok = false; break; }
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}