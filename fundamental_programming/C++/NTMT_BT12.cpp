#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    long long S=0;
    for (int i=1; i <= n; i++) {
        S += pow(i,m);
    }
    cout << S << endl;
}