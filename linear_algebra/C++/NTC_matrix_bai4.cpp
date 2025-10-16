#include <iostream>
using namespace std;

int main() {
    int a[50][50], b[50][50], tich[50][50];
    int hangA, cotA, hangB, cotB;

    cout << "Nhập số hàng ma trận A: ";
    cin >> hangA;
    cout << "Nhập số cột ma trận A: ";
    cin >> cotA;

    cout << "Nhập số hàng ma trận B: ";
    cin >> hangB;
    cout << "Nhập số cột ma trận B: ";
    cin >> cotB;

    if (cotA != hangB) {
        cout << "\nHông nhân được, cột A phải bằng hàng B cơ :<" << endl;
        return 0;
    }

    cout << "\nNhập ma trận A:" << endl;
    for (int i = 0; i < hangA; i++) {
        for (int j = 0; j < cotA; j++) {
            cout << "Nhập a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }

    cout << "\nNhập ma trận B:" << endl;
    for (int i = 0; i < hangB; i++) {
        for (int j = 0; j < cotB; j++) {
            cout << "Nhập b[" << i << "][" << j << "]: ";
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < hangA; i++) {
        for (int j = 0; j < cotB; j++) {
            tich[i][j] = 0;
            for (int k = 0; k < cotA; k++) {
                tich[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    cout << "\nTích hai ma trận A x B là:" << endl;
    for (int i = 0; i < hangA; i++) {
        for (int j = 0; j < cotB; j++) {
            cout << tich[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}