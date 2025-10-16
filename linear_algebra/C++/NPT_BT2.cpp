// Viết chương trình C/C++ (+1.5), Python (+1)
//để thực hiện 3 phép biến đổi sơ cấp trên dòng của 1 ma trận A
#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cout << "Nhap so hang(m): ";
    cin >> m;
    cout << "Nhap so cot(n): ";
    cin >> n;
    int A[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Ma tran vua nhap: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int choice;
    cout << "1. Chon (1) de nhan mot hang voi mot so: " << endl;
    cout << "2. Chon (2) de cong mot hang voi mot hang khac: " << endl;
    cout << "3. Chon (3) de hoan vi hai hang: " << endl;
    cin >> choice;
    if  (choice == 1) {
        int row;
        int so;
        cout << "Nhap so hang can *: ";
        cin >> row;
        cout << "Nhap he so: ";

        cin >> so;
        for (int j = 0; j < n; j ++) {
            A[row - 1][j] = A[row - 1][j] * so;
        }
        cout << "Ma tran sau khi nhan hang voi 1 so: " << endl;
        for (int i = 0; i < m ; i ++) {
            for (int j = 0; j < n; j ++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if (choice == 2) {
        int row1, row2;
        cout << "Nhap hang cong: ";
        cin >> row1;
        cout << "Nhap hang muon cong: ";
        cin >> row2;
        for (int i = 0; i < n; i++) {
            A[row1 - 1][i] = A[row1 - 1][i] + A[row2 - 1][i];
        }
        cout << "Ma tran sau khi cong 2 hang: " << endl;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if ( choice == 3) {
        int row1 , row2;
        cout << "Nhap 2 hang muon doi cho: ";
        cin >> row1 >> row2;
        for (int j = 0; j < n; j++) {
            swap (A[row1 - 1][j], A[row2 - 1][j]);
        }
        cout << "Ma tran sau khi hoan vi 2 hang: " << endl;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "Khong hop le !!!" << endl;
    }
    return 0;

}