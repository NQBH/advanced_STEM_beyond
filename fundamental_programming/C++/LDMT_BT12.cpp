#include <iostream>
#include <cmath> 

using namespace std;

int main() {
    int n, m;
    long long S = 0; 

    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap m: ";
    cin >> m;

    for (int i = 1; i <= n; i++) {
        S += (long long)pow(i, m);
    }

    cout << "Tong S = " << S << endl;
    return 0;
}