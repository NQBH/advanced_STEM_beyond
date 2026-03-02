#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    long long tong = 0; 

    cout << "giới hạn của dãy";
    cout << "Nhập n: ";
    cin >> n;
    cout << "số mũ";
    cout << "nhập m: ";
    cin >> m;

    for (int i = 1; i <= n; ++i) {
        tong += (long long)pow(i, m); 
    }

    cout << "Tổng Sm = " << tong <<'\n';

    return 0;
}