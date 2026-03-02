#include <bits/stdc++.h>
using namespace std;
int main () {
    int a , b , c , vmax , vmin;
    cin >> a >> b >> c;
    if (a > b) {
        vmax = a;
    }
    else if (a > c) {
        vmax = a;
    }
    else {
        if (b > c) {
            vmax = b;
        }
        else {
            vmax = c;
        }
    }

    if (a < b) {
        vmin = a;
    }
    else if (a < c) {
        vmin = a;
    }
    else {
        if (b < c) {
            vmin = b;
        }
        else {
            vmin = c;
        }
    }

    cout << vmax << " " << vmin;

    return 0;
}