#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    long long M;
    long long S = 0;

    cout << "Nhap n: "; 
    cin >> n;
    cout << "Nhap m: "; 
    cin >> m;
    cout << "Nhap M: "; 
    cin >> M;

    int i = 1;

    while (i <= n) {
        if (S + pow(i, m) > M) {
            break; 
        }

        S += pow(i, m);
        ++i;
    }

    cout << "S = " << S << endl;

    return 0;
}