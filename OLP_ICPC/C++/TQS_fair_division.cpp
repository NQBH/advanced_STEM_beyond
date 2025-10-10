#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--) {
        int n, a, b; cin >> n;
        multiset<int> st;
        while (n--) {
            cin >> a;
            st.insert(a);
        }
        a = st.count(1);
        b = st.count(2);
        if (b % 2 != 0) {
            a -= 2;
        }
        if (a >= 0 and a % 2 == 0)
            cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}