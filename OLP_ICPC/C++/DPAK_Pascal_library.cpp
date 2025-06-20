/*
Source: ACM South America 2005.
IDs for online judges: POJ 2864, UVA 3470.
Status: Accepted
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, d;
    while (cin >> n >> d && n != 0 && d != 0) {
        vector<vector<int>> a(d, vector<int>(n));
        for (int i = 0; i < d; ++i)
            for (int j = 0; j < n; ++j)
                cin >> a[i][j];
        bool check = false;
        for (int i = 0; i < n; ++i) {
            bool attended_check = true;
            for (int j = 0; j < d; ++j) {
                if (a[j][i] == 0) {
                    attended_check = false;
                    break;
                }
            }
            if (attended_check) {
                check = true;
                break;
            }
        }
        if (check) cout << "yes";
        else cout << "no";
        cout << endl;
    }
}