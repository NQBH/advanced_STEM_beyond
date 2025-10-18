#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap kich thuoc ma tran vuong n x n: ";
    cin >> n;
    cout << "Ma tran 0:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << 0 << "\t";
        cout << endl;
    }
    cout << "Ma tran don vi:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                cout << 1 << "\t";
            else
                cout << 0 << "\t";
        }
        cout << endl;
    }

    return 0;
}
