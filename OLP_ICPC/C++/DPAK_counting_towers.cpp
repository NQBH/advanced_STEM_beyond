#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int MAXN = 1e6;

    vector<int> a(MAXN + 1); // a[i] : số cách xây tháp độ cao n với cách đặt cả 2 ô thuộc 1 block (2 x 1)
    vector<int> b(MAXN + 1); // b[i] : số cách xây tháp độ cao n với cách đặt cả 2 ô riêng biệt (1x1 + 1x1)

    /*
    Giả sử tháp hiện tại có độ cao N
    ta ko xét hàng trên cùng --> tháp có độ cao  2 x (N - 1) và còn dư 1 hàng 2x1

    ở hàng dư, nếu ta:
    - đặt 2 ô cùng thuộc 1 block, sẽ có các trường hợp có thể xảy ra:
      + block hiện tại: 2x1 , block cùng loại (a[i-1]) trước đó: 2x1 + 2x1
      + block hiện tại nối liền với block cùng loại (a[i - 1]) trước đó: 2x2

      + block hiện tại nối với block trước đó với 2 ô riêng biệt: 2x1 + (1x1 + 1x1)

      ====> a[i] = 2 * a[i - 1] + b[i - 1]

    - đặt 2 ô khác block, sẽ có các trường hợp có thể xảy ra:
      + block hiện tại 1x1 + 1x1, block trước đó cùng loại là 1x1 + 1x1
      + ô đầu tiên của block hiện tại nối với ô đầu tiên của block cùng loại trước đó: 1x2 + 1x1 + 1x1
      + ô thứ 2 của block hiện tại nối với ô thứ 2 của block cùng loại trước đó: 1x1 + 1x1 + 1x2
      + cả 2 ô đầu tiên và ô thứ 2 nối với 2 ô trước đó: 1x2 + 1x2

      + đặt với ô khác loại trước đó: 2x1 + 1x1 + 1x1
    
      ====> b[i] = 4*b[i - 1] + a[i - 1]

    ====> answer = a[i] + b[i]
    */
   
    vector<int> dp(MAXN + 1);
    a[1] = 1;
    b[1] = 1;
    dp[1] = 2;

    for (int i = 2; i <= MAXN; i++) {
        (a[i] = 2 *a[i - 1] + b[i - 1]) %= mod;
        (b[i] = 4 * b[i - 1] + a[i - 1]) %= mod;
        (dp[i] = a[i] + b[i]) %= mod;
    }
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << dp[n] << endl;
    }
    
    return 0;
}
