#include <iostream>
using namespace std;
int main() {
    int A[10][10];
    int m, n;
    cout << "Nhap so dong va cot: ";
    cin >> m >> n;
    cout << "Nhap cac phan tu cho ma tran:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    int luaChon;
    cin >> luaChon;
    do {
        cout << "Ma tran hien tai" << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << A[i][j];
            }
            cout << endl;
        }
        if (luaChon == 1) {
            int dong1, dong2;
            cout << "Nhap hai dong can hoan vi (chi so bat dau tu 0): ";
            cin >> dong1 >> dong2;

            for (int j = 0; j < n; j++) {
                int temp = A[dong1][j];
                A[dong1][j] = A[dong2][j];
                A[dong2][j] = temp;
            }
            cout << "=> Da hoan vi dong " << dong1 << " va dong " << dong2 << endl;
        }
        else if (luaChon == 2) {
            int dong;
            float k;
            cout << "Nhap dong can nhan (chi so tu 0): ";
            cin >> dong;
            cout << "Nhap so k (k != 0): ";
            cin >> k;

            for (int j = 0; j < n; j++) {
                A[dong][j] = A[dong][j] * k;
            }
            cout << "=> Da nhan dong " << dong << " voi so " << k << endl;
        }
        else if (luaChon == 3) {
            int dong_i, dong_j;
            float k;
            cout << "Nhap dong can bien doi (dong i): ";
            cin >> dong_i;
            cout << "Nhap dong tac dong (dong j): ";
            cin >> dong_j;
            cout << "Nhap so k: ";
            cin >> k;

            for (int j = 0; j < n; j++) {
                A[dong_i][j] = A[dong_i][j] + k * A[dong_j][j];
            }
            cout << "=> Da lay dong " << dong_i << " cong voi (" << k << " * dong " << dong_j << ")" << endl;
        }

    } while (luaChon != 0);
    cout << "\nKet thuc chuong trinh." << endl;

    return 0;
}