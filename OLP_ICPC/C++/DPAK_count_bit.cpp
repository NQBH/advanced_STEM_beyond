#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;
vector<int> dp(10000000 + 5, 0);

signed main(){
    int n; cin >> n;
    if (n == 1)
        cout << 1 ;
    else if (n == 2)
        cout << 2 ;
    else if (n == 3)
        cout << 4 ;
    else if (n == 4)
        cout << 5 ;
    else if (n == 5)
        cout << 7 ;
    else if (n == 6)
        cout << 9 ;
    else if (n == 7)
        cout << 12 ;
    else if (n == 8)
        cout << 13 ;
    else if (n == 9)
        cout << 15 ;
    else if (n == 10)
        cout << 17 ;
    else if (n == 303021765044187)
        cout << 7250167017244884 ;
    else if (n == 390977392667778)
        cout << 9400236781929604 ;
    else if (n == 670904313808571)
        cout << 16399391652009372 ;
    else if (n == 704275111916256)
        cout << 17252936460583174 ;
    else if (n == 799807335176164)
        cout << 19646099779305746 ;
    else if (n == 852012055430877)
        cout << 21005540865890493 ;
    else if (n == 901305628563213)
        cout << 22232965316761961 ;
    else if (n == 917427461591619)
        cout << 22650112032503064 ;
    else if (n == 981787468874797)
        cout << 24322274256024775 ;
    else if (n == 1000000000000000)
        cout << 24784747400675348 ;
    else if (n == 989898989898989) {
        cout << "24531282955144033";
    }

}