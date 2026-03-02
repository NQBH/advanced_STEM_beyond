#include<iostream>
#include<cmath>
using namespace std;
int main () {
    int n, m, M;
    long S = 0;
    cin >> n;
    cin >> m;
    cin >> M;
    for (int i = 1; i <= n; i++) {
        long P = pow(i,m);
        if (S + P > M) {
            break;
        }
        S += pow(i,m);    
    }
    cout << "S(m)= " << S;
}