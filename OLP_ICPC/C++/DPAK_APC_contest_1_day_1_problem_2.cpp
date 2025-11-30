#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n; 
    cin >> n;
    string bestString = "";
    int bestNum = -1;  
    int bestDen = 1; 

    while (n--) {
        string s; cin >> s;
        int cntDigit = 0;
        for (char c : s) if (isdigit(c)) cntDigit++;
        int len = s.size();

        if (bestString == "" || cntDigit * bestDen > bestNum * len) {
            bestString = s;
            bestNum = cntDigit;
            bestDen = len;
        }
    }
    cout << bestString;
}
