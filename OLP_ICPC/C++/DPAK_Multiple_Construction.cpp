#include <bits/stdc++.h>
#define APC signed
#define int long long
using namespace std;

const int oo = 1e9;

APC main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        // 2 * n
        // number n must be in n && 2 * n
        /*
        n = 6 -> arr.size() = 12
        -> 2 segments with length = n - 1 

        [ , , , , ,6, 5, 3, ,3, 5, 6]
        */      
        vector<int>a(2 * n + 1, 0);
        a[n] = a[2 * n] = n;
        int firstSegmentLength = n - 1;
        int secondSegmentLength = n - 1;
        int iFirstSegment = 1, jFirstSegment = n - 1;
        int iSecondSegment = n + 1, jSecondSegment = 2 * n - 1;
        for (int i = n - 1; i >= 1; i--) {
            if ((jFirstSegment - iFirstSegment) % i == 0) {
                a[iFirstSegment++] = a[jFirstSegment--] = i;
                //--firstSegmentLength--;
            }
            else if ((jSecondSegment - iSecondSegment) % i == 0) {
                a[iSecondSegment++] = a[jSecondSegment--] = i;
                //--(secondSegmentLength--);
            }
            else if ((iSecondSegment - jFirstSegment) % i == 0) {
                a[iSecondSegment++] = a[jFirstSegment--] = i;
                //firstSegmentLength--;
                //secondSegmentLength--;
            }
            else if ((iSecondSegment - iFirstSegment) % i == 0) {
                a[iSecondSegment++] = a[iFirstSegment++] = i;
                //firstSegmentLength--;
                //secondSegmentLength--;
            }
            else if ((jSecondSegment - iFirstSegment) % i == 0) {
                a[jSecondSegment--] = a[iFirstSegment++] = i;
            }
            else if ((jSecondSegment - jFirstSegment) % i == 0) {
                a[jSecondSegment--] = a[jFirstSegment--] = i;
            }
        }
        for (int i = 1; i <= 2 * n; i++) {
            if (a[i] == 0) a[i] = 1;
        }
        for (int i = 1; i <= 2 * n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}
