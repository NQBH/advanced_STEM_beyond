#include<iostream>
#include<cmath>
using namespace std;
int main () {
    int n, m;
    long S = 0;
    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++) {
        S += pow(i, m);
    }
    cout << "S(m) = " << S;
}