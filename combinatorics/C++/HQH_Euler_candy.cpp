#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    r = min(r, n - r);
    long long res = 1;
    for (int i = 0; i < r; i++) {
        long long num = n - i;
        long long den = i + 1;
        long long g = gcd(num, den);
        num /= g;
        den /= g;
        res = res * num / den;
    }
    return res;
}

void genSolution(vector<int>& x, vector<int>& lower_bounds, int m, int n, int pos, int sum, vector<vector<int>>& solutions) {
    if (pos == n - 1) {
        int remaining = m - sum;
        if (remaining >= lower_bounds[pos]) {
            x[pos] = remaining;
            solutions.push_back(x);
        }
        return;
    }

    int start = lower_bounds[pos];
    for (int i = start; i <= m - sum; i++) {
        x[pos] = i;
        genSolution(x, lower_bounds, m, n, pos + 1, sum + i, solutions);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int m, n;
    cin >> m >> n;
    vector<int> lower_bounds(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> lower_bounds[i];
        s += lower_bounds[i];
    }

    if (m < s) {
        cout << "Ket qua tinh ra: 0\n";
        cout << "So bo nghiem generate ra: 0\n";
        return 0;
    }

    long long res = nCr(m - s + n - 1, n - 1);
    cout << "Ket qua tinh ra: " << res << '\n';

    vector<int> x(n, 0);
    vector<vector<int>> solutions;
    genSolution(x, lower_bounds, m, n, 0, 0, solutions);

    cout << "So bo nghiem generate ra: " << solutions.size() << '\n';
    for (const auto& sol : solutions) {
        for (int i = 0; i < n; i++) {
            cout << sol[i];
            if (i < n - 1) cout << " ";
        }
        cout << '\n';
    }

    return 0;
}