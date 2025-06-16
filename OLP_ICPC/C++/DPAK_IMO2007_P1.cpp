#include <bits/stdc++.h>

using namespace std;
int n;
const double oo = 1e9 + 7;

int main() {
    cin >> n;
    vector<double> a(n + 1);
    vector<double> maxA(n + 1, -oo), minA(n + 2, oo);

    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i)
        maxA[i] = max(maxA[i - 1], a[i]);
    
    for (int i = n; i >= 1; --i)
        minA[i] = min(minA[i + 1], a[i]);
    
    vector<double> d(n + 1);
    for (int i = 1; i <= n; ++i)
        d[i] = maxA[i] - minA[i + 1];
    
    double D = -oo;
    int a_idx = -1;
    for (int i = 1; i <= n; ++i)
        if (D < d[i]) {
            D = max(D, d[i]);
            a_idx = i;
        }
    
    vector<vector<double>> result;
    vector<double> x(n + 1, 1);

    for (int i = 1; i <= n; ++i)
        cin >> x[i];

    result.push_back(x);

    cout << "\nCau A: \n";
    for (auto x : result) {
        cout << "a : ";
        for (int i = 1; i <= n; ++i)
            cout << a[i] << " ";
    
        cout << '\n';
        cout << "x : ";
        double maxXA = -oo;
        for (int i = 1; i <= n; ++i) {
            cout << x[i] << " ";
            maxXA = max(maxXA, abs(x[i] - a[i]));
        }
        cout << '\n';
        cout << "max|x[i] - a[i]| = " << maxXA << " >= d/2 = " << D / 2.0 << " - prove: " << (maxXA >= D / 2 ? "True" : "False") << '\n';
        cout << "----------------------------" << '\n';
    }
    cout << "Cau B: \n";
    vector<double> L(n + 1);
    for (int i = 1; i <= n; ++i)
        L[i] = a[i] - D / 2.0;
    
    for (int i = 1; i <= n; ++i)
        x[i] =  max(x[i - 1], L[i]);
    
    cout << "a : ";
    for (int i = 1; i <= n; ++i)
        cout << a[i] << " ";
    
    cout << '\n';

    cout << "x : ";
    for (int i = 1; i <= n; ++i)
        cout << x[i] << " ";
    
    cout << '\n';
    double maxXA = -oo;
    for (int i = 1; i <= n; ++i)
        maxXA = max(maxXA, abs(x[i] - a[i]));
    
    cout << " max|x[i] - a[i]| = " << maxXA << ", D/2 = " << D / 2.0;
}