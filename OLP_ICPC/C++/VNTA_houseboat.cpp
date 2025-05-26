#include <bits/stdc++.h>
#define KhangGPT40_TramAnhGrok3 ios_base::sync_with_stdio(0)
using namespace std;

const double pi = 3.141592653589793;

int main(){
    KhangGPT40_TramAnhGrok3;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        double x, y;
        cin >> x >> y;
        double d = x*x + y*y;
        double z = d*pi/100.0;
        cout << "Property " << i << ": This property will begin eroding in year " << ceil(z) <<".\n";
    }
    cout << "END OF OUTPUT.";
    return 0;
}