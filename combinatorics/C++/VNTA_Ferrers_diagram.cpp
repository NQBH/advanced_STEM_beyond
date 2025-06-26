#include <bits/stdc++.h>
using namespace std;

int maxp(const vector<int>&p) {
    int pmax = 0;
    int n = p.size();
    for (int i = 0; i < n; ++i) {
        if (p[i] > pmax)
            pmax = p[i];
    }
    return pmax;
}

void Ferrers(const vector<int>&p) {
    cout << "F:\n";
    int pmax = maxp(p);
    for (int r : p) {
        for (int i = 0; i < r; ++i) cout << '*';
        for (int i = 0; i < pmax - r; ++i) cout << " ";
        cout << " " << r << '\n';
    }
}

void FerrersTrans(const vector<int>& p) {
    cout << "FT:\n";
    int pmax = maxp(p);
    int n = p.size();
    for (int r = 0; r < pmax; ++r) {
        for (int i = 0; i < n; ++i) {
            if (p[i] > r) cout << "* ";
            else cout << " ";
        }
        cout << '\n';
    }
    for (int i = 0; i < n; ++i) {
        cout << p[i];
        if (i != n - 1) cout << " ";
    }
    cout << "\n";
}


void genF(int n, int k, vector<int>&cur, int max_val) {
    if (k == 0) {
        if (n == 0) {
            Ferrers(cur);
            FerrersTrans(cur);
            cout << "====================\n";
        }
        return;
    }
    for (int i = min(n, max_val); i >= 1; --i) {
        cur.push_back(i);
        genF(n - i, k - 1, cur, i);
        cur.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> current;
    genF(n, k, current, n);
    return 0;
}