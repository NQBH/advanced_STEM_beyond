#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang va so cot: ";
    cin >> m >> n;

    float A[10][10];
    cout << "Nhap cac phan tu vao trong A:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }
    // list menu
    cout << "** Cho phep bien doi **" << endl;
    cout << "1. Hoan doi hai dong" << endl;
    cout << "2. Nhan mot dong voi mot so khac" << endl;
    cout << "3. Cong boi cua dong nay voi dong khac" << endl;
    // ham chon 
    int chon;
    cin >> chon;

    if (chon == 1) {
        int i, j;
        cout << "Nhap hai dong can hoan doi: ";
        cin >> i >> j;
        for (int k = 0; k < n; ++k) {
            swap(A[i - 1][k], A[j - 1][k]);
        }
    }
    else if (chon == 2) {
        int i;
        float k;
        cout << "Nhap dong can nhan va so nhan: ";
        cin >> i >> k;
        for (int c = 0; c < n; ++c) {
            A[i - 1][c] *= k;
        }
    }
    else if (chon == 3) {
        int i, j;
        cout << "Nhap dong i va dong j : ";
        cin >> i >> j;
        for (int c = 0; c < n; ++c) {
            A[j - 1][c] += A[i - 1][c];
        }
    }
    else {
        cout << "Lua chon khong hop le." << endl;
    }

    // In ma tran sau khi bien doi
    cout << "Ma tran sau khi bien doi:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
