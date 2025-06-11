#include <bits/stdc++.h>
using namespace std;

int dq(int n) {
    if (n < 5) return 0;
    return n / 5 + dq(n / 5);
}

int main(){
    int n; cin >> n;
    cout << dq(n);
}