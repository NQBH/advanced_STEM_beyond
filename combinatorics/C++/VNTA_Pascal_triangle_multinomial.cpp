#include<bits/stdc++.h>
using namespace std;

unsigned long long Pn(int n) {
    if (n == 0) return 1;
    unsigned long long res = 1;
    for (int i = 2; i <= n; i++)res *= i;
    return res;
}

unsigned long long nCk(int n, int k) {
    long long res = Pn(n) / (Pn(n - k) * Pn(k));
    return res;
}

void pascalTriangle(int n) {
    cout << "1st " << n + 1 << " lines of the Pascal triangle: \n";
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << nCk(i, j) << " ";
        }
        cout << '\n';
    }
    cout << "\n========================================\n";
}

void generatePartitions(int n, int m, int idx, vector<int>& cur, vector<vector<int>>& res) {
    if (idx == m - 1) {
        cur[idx] = n;
        res.push_back(cur);
        return;
    }
    for (int i = 0; i <= n; i++) {
        cur[idx] = i;
        generatePartitions(n - i, m, idx + 1, cur, res);
    }
}

double multinomialExpansion(int n, const vector<double>& a) {
    int m = a.size();
    vector<vector<int>> partitions;
    vector<int> cur(m, 0);
    generatePartitions(n, m, 0, cur, partitions);

    double res = 0;
    for (const auto& k : partitions) {
        unsigned long long coeff = Pn(n);
        double term = 1;
        for (int i = 0; i < m; i++) {
            coeff /= Pn(k[i]);
            term *= pow(a[i], k[i]);
        }
        res += coeff * term;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;

    pascalTriangle(n);

    vector<double>a(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    double result = multinomialExpansion(n, a);
    if (m > 2) cout << "(a1 +... + a" << m << ")^" << n << " = " << result << "\n";
    else cout <<  "(a1 + a2)^" << n << " = " << result << "\n";
}