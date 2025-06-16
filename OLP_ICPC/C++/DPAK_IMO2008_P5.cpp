#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k;
int cnt = 0;

bool check(vector<bool> &bongden) {
    for (int i = 1; i <= n; i++)
        if (!bongden[i]) return false;      
    for (int i = n + 1; i <= 2 * n; i++)
        if (bongden[i]) return false;   
    return true;
}

void backTracking(int stepLeft, vector<bool> &bongden, bool sang_nua_sau) {
    if (stepLeft == 0) {
        if (check(bongden)) cnt++;
        return;
    }

    for (int i = 1; i <= n * 2; i++) {
        bool before = bongden[i];
        bongden[i] = !bongden[i];   

        if (!sang_nua_sau && i > n && bongden[i] == true) {
            bongden[i] = before;  
            continue;
        }

        backTracking(stepLeft - 1, bongden, sang_nua_sau);
        bongden[i] = before;       
    }
}

signed main() {
    cin >> n >> k;

    if (k < n || (k - n) % 2 != 0) {
        cout << "0";
        return 0;
    }

    vector<bool> bongden(2 * n + 1, false); 

    cnt = 0;
    backTracking(k, bongden, true);
    int N = cnt;

    cnt = 0;
    fill(bongden.begin(), bongden.end(), false);
    backTracking(k, bongden, false);
    int M = cnt;

    double ans = (double) M / N;

    cout << "M = " << M << ", N = " << N << endl;
    cout << "M / N = " << ans << endl;
}
