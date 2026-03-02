#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, m, M;
    int i = 1;
    int S = 0;
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;
    cout << "M = ";
    cin >> M;
    while (S + (int) pow(i,m) <= M) {
        S += (int) pow(i, m);
        ++i;
    }
    cout << S << " <= " << M << '\n';
}