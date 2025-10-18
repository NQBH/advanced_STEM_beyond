#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    if (n <= 0){
        cout << "Vui long n hap so nguyen duong > 0.";
        return 0;
    }

    int A[100][100];

    cout << "\nMa tran 0:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 0;
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMa tran don vi:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                A[i][j] = 1;
            else
                A[i][j] = 0;
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
