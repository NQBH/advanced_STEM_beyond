#include <bits/stdc++.h>

using namespace std;
int n;
const double oo = 1e9 + 7;

int main() {
    cin >> n;
    vector<double> a(n + 1);
    vector<double> maxA(n + 1, -oo), minA(n + 2, oo);

    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        maxA[i] = max(maxA[i - 1], a[i]);
    }
    for (int i = n; i >= 1; i--) {
        minA[i] = min(minA[i + 1], a[i]);
    }

    vector<double> d(n + 1);
    for (int i = 1; i <= n; i++) {
        d[i] = maxA[i] - minA[i + 1];
    }
    double D = -oo;
    int a_idx = -1;
    for (int i = 1; i <= n; i++) {
        if (D < d[i]) {
            D = max(D, d[i]);
            a_idx = i;
        }
    }

    vector<vector<double>> result;
    vector<double> x(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    result.push_back(x);
    /*
    int m = 4; // max value
    int cnt = 10; // sinh 10 dãy
    while (true && cnt--) {
        result.push_back(current);

        int pos = n;
        while (pos >= 1 && current[pos] == m) {
            --pos;
        }

        if (pos <= 0) break;

        current[pos]++;

        for (int i = pos + 1; i <= n; ++i) {
            current[i] = current[pos];
        }
    }
    */
    cout << "\nCau A: \n";
    for (auto x : result) {
        cout << "a : ";
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        cout << "x : ";
        double maxXA = -oo;
        for (int i = 1; i <= n; i++) {
            cout << x[i] << " ";
            maxXA = max(maxXA, abs(x[i] - a[i]));
        }
        cout << endl;
        cout << "max|x[i] - a[i]| = " << maxXA << " >= d/2 = " << D / 2.0 << " - prove: " << (maxXA >= D / 2 ? "True" : "False") << endl;
        cout << "----------------------------" << endl;
    }
    cout << "Cau B: \n";
    vector<double> L(n + 1);
    for (int i = 1; i <= n; i++) {
        L[i] = a[i] - D / 2.0;
    }
    for (int i = 1; i <= n; i++) {
        x[i] =  max(x[i - 1], L[i]);
    }

    cout << "a : ";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "x : ";
    for (int i = 1; i <= n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
    double maxXA = -oo;
    for (int i = 1; i <= n; i++) {
        maxXA = max(maxXA, abs(x[i] - a[i]));
    }
    cout << " max|x[i] - a[i]| = " << maxXA << ", D/2 = " << D / 2.0;
}