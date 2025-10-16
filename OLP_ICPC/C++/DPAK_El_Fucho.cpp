#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> winner, loser;
        for (int i = 1; i <= n; i++) winner.push_back(i);

        int cnt = 0;

        while (winner.size() + loser.size() > 1) {
            if (winner.size() == 1 && loser.size() == 1) {
                cnt++;
                break;
            }

            if (winner.size() >= 2) {
                vector<int> tempWinner;
                for (int i = 1; i < winner.size(); i += 2) {
                    loser.push_back(winner[i]);
                    cnt++;
                }

                for (int i = 0; i < winner.size(); i += 2) {
                    tempWinner.push_back(winner[i]);
                }
                winner.swap(tempWinner);
            }

            if (loser.size() >= 2) {
                vector<int> tempLoser;
                for (int i = 0; i < loser.size(); i += 2) {
                    tempLoser.push_back(loser[i]);
                    if (i + 1 < loser.size()) cnt++; 
                }
                loser.swap(tempLoser);
            }

        }

        cout << cnt << endl;
    }
}
