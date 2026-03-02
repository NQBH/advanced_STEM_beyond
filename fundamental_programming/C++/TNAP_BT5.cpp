#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A, B, x ;
    cin >> A >> B;
    if ( A == 0) {
        if ( B == 0) {
            cout << "vo so nghiem";
        } else {cout << "vo nghiem";}
    }
    else {
        if ( B % A == 0) {
            long long x = -B / A;
            cout << x;
        }
        else {
            cout << "vo nghiem";
        }
    }
    return 0;
}
