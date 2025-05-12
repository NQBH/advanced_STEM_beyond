#include <bits/stdc++.h>

using namespace std;

int main(){
    double e;
    cin >> e;
    int n = 1;
    double d = 1.0 / (pow(2,n));
    while (d >= e) {
        n++;
        d = 1.0 / (pow(2,n));
    }
    cout << n;
}