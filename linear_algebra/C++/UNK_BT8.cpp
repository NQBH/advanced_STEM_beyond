#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Nhap so nguyen duong n ";
    cin >> n;

    if (n <= 0) {
        cout << "n phai la so nguyen duong";
        return 0;
    }
    int matran0[100][100];
    int matranDV[100][100];

    for (int i = 0; i < n; i++) {
        matranDV[i][i] = 1;
    }

    cout << "Ma tran 0" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matran0[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Ma tran don vi" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matranDV[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}