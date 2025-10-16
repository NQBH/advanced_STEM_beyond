#include <iostream>
using namespace std;

int main() {
    int n;
    cout << " nhap n:";
    cin >> n;
    if (n <= 0 ) {
        cout << " nhap lai n fen oiii:";
        return 0;
    }
    cout << "Ma tran 0:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << 0 << " ";
        cout << endl;
    }

    cout << "\nMa tran don vi:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << (i == j ? 1 : 0) << " ";
        cout << endl;
    }
}

