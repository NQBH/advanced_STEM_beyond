//3 phép biến đổi sơ cấp trên dòng của 1 ma trận A.
#include<iostream>
using namespace std;
int main() {
    int m, n;
    cout << "nhap hang: ";
    cin >> m;
    cout << "nhap cot: ";
    cin >> n;
    int a[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "]=";
            cin >> a[i][j];
        }
    }
    cout << "ma tran vua nhap la: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    int choice;
    cout << "chon phep bien doi:\n";
    cout << "1. doi 2 dong\n";
    cout << "2. nhan dong voi mot so khac 0\n";
    cout << "3. cong mot dong voi mot so lan dong khac\n";
    cin >> choice;
    if (choice == 1) {
        int d1, d2;
        cout << "chon 2 dong can doi: ";
        cin >> d1 >> d2;
        d1--, d2--;
        for (int j = 0; j < n; j++) {
            std::swap(a[d1][j], a[d2][j]);
        }
        cout << "ma tran sau khi doi: " << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    } else if (choice == 2) {
        int d;
        float k;
        cout << "chon dong can nhan va so k: ";
        cin >> d >> k;
        d--;
        for (int j = 0; j < n; j++) {
            a[d][j] = a[d][j] * k;
        }
        cout << "ma tran sau khi doi: " << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    } else if (choice == 3) {
        int d1, d2;
        float k;
        cout << "chon dong can cong, dong bi cong va so k: ";
        cin >> d1 >> d2 >> k;
        d1--, d2--;
        for (int j = 0; j < n; j++) {
            a[d1][j] = a[d1][j] + k * a[d2][j];
        }
        cout << "ma tran sau khi doi: " << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "khong hop le";
    }
}