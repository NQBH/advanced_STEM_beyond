#include <bits/stdc++.h>
using namespace std;
/*
(\_/)          (\___/)
( " ")		   ( ^ ^  )
 /  >> <3      he(#)(#)
/	??		   (") (")
bruth lmeo lmeo
*/

int n, l, r, x;
int c[20];
int main()
{
	cin >> n >> l >> r >> x;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    int ans=0;
    for (int mask = 0; mask < (1 << n) ; mask++) {
        int Np = 0; // tong so bai toan
        int Sd = 0; // Sum_difficultys -  tong do kho
        int ll = INT_MAX, rr = -1;
        for (int i = 0; i < n; i++)
            if (1 & (mask >> i)) {
                Np++;
                Sd+=c[i];
                ll=min(ll,c[i]);
                rr=max(rr,c[i]);
            }
        if (Np >= 2 && Sd >= l && Sd <= r && (rr - ll) >= x) ans++;
    }
    cout << ans;
	return 0;
}
