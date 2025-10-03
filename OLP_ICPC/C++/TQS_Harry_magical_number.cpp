#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    //std::cout<<"Hello World";
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int>divi;
    for (int i = 2 ; i * i <= c; i++) {
    
        if (c % i == 0) {
            divi.push_back(i);
            if (i != (c / i)) divi.push_back(c / i);
        }
    }
    sort(divi.begin(), divi.end());
    for (auto num : divi) {
        if (d % num != 0 && num % b != 0 && num % a == 0) {
            cout << num;
            return 0;
        }
    }
    cout << -1;
    return 0;
}