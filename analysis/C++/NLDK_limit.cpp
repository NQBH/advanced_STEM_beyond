#include<bits/stdc++.h>
#define Sanic_speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define el "\n";
#define fre(i, a, b) for(int i = a; i <= b; ++i)
using namespace std;

double long qa(int n) {
    return (pow(-1, n)/n);
}
double long qb(int n) {
    double long deno = sqrt(n);
    return (1/deno);
}
double long qc(int n) {
    double long deno = sqrt(n);
    return (-1/deno);
}
double long qd(int n) {
    double long deno = sqrt(n);
    return (pow(-1, n)/deno);
}

void solve() {
    double long epsilon;
    cin >> epsilon;
    int maxN = 100000;
    fre(i, 1 ,maxN) {
        if (abs(qa(i)) < epsilon) {
            cout << "a) " << i << el
            break;
        }
    }
    fre(i, 1 ,maxN) {
        if (abs(qb(i)) < epsilon) {
            cout << "b) " << i << el
            break;
        }
    }
    fre(i, 1 ,maxN) {
        if (abs(qc(i)) < epsilon) {
            cout << "c) " << i << el
            break;
        }
    }
    fre(i, 1 ,maxN) {
        if (abs(qd(i)) < epsilon) {
            cout << "d) " << i << el
            break;
        }
    }
}

int main() {
    Sanic_speed
    int t = 1;// cin >> t;
    while(t > 0) {solve(); --t;}
}