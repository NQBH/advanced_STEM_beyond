#include <bits/stdc++.h>
#define APC signed
#define int long long
using namespace std;

const int oo = 1e18;

APC main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        int odd = 0;
        vector<int> oddIdx;
        vector<int> evenIdx;
           
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 1) {
                odd++;
                oddIdx.push_back(i);
            }
            else {
                evenIdx.push_back(i);
            }
        }
        int even = n - odd;
        int diff = abs(even - odd);
        if (diff > 1) {
            cout << -1 << endl;
            continue;
        }
        int op = oo;
        if (diff == 0) {
            /*
            O E O E O E
            E O E O E O
            */
            int curOp = 0;

            int curPos = 1;
            for (int i = 0; i < oddIdx.size(); curPos += 2, i++) {
                curOp += abs(oddIdx[i] - curPos);
            }
            op = min(op, curOp);
            curOp = 0;
            curPos = 1;
            for (int i = 0; i < evenIdx.size(); curPos += 2, i++) {
                curOp += abs(evenIdx[i] - curPos);
            }
            op = min(op, curOp);
        }
        else {
            /*
            n : odd
            O V O V O
            V O V O V
            */
            if (oddIdx.size() > evenIdx.size()) {
                int curOp = 0;

                int curPos = 1;
                for (int i = 0; i < oddIdx.size(); curPos += 2, i++) {
                    curOp += abs(oddIdx[i] - curPos);
                }
                op = min(op, curOp);
            }
            else {
                int curOp = 0;
                int curPos = 1;
                for (int i = 0; i < evenIdx.size(); curPos += 2, i++) {
                    curOp += abs(evenIdx[i] - curPos);
                }
                op = min(op, curOp);
            }
        }
        cout << op << endl;
    }
}

