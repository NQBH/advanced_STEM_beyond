#include<iostream>
using namespace std;
int main() {
    int n;
    cout << "Nhap n:";
    cin >> n;
    if (n <= 0) {
        cout << "Nhap lai!!!!!!!!!!!!";
        return 1;
    }
    cout << "Ma tran 0: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << 0 << (j + 1 == n ? "\n" : " ");
    }
    cout << "Ma tran don vi:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << (i == j ? 1 : 0) << (j + 1 == n ? "\n" : " ");
    } return 0;
}