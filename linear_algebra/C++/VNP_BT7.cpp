#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang cua ma tran A: ";
    cin >> m;
    cout << "Nhap so cot cua ma tran A: ";
    cin >> n;
    double A[100][100];
    cout << "Nhap cac phan tu cua ma tran A:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    cout << "CAC PHEP BIEN DOI SO CAP\n";
    cout << "1. Doi cho 2 dong\n";
    cout << "2. Nhan 1 dong voi mot so khac 0\n";
    cout << "3. Cong boi cua dong nay vao dong khac\n";
    cout << "Chon phep bien doi (1-3): ";

    int chon;
    cin >> chon;
    if (chon == 1) {
        int r1, r2;
        cout << "Nhap 2 dong can doi cho (tu 1 den " << m << "): ";
        cin >> r1 >> r2;
        if (r1 < 1 || r1 > m || r2 < 1 || r2 > m) {
            cout << "Dong khong hop le!";
            return 0;
        }
        for (int j = 0; j < n; j++) {
            double temp = A[r1 - 1][j];
            A[r1 - 1][j] = A[r2 - 1][j];
            A[r2 - 1][j] = temp;
        }
    }
    else if (chon == 2) {
        int r;
        double k;
        cout << "Nhap dong can nhan (1-" << m << ") va he so k (k != 0): ";
        cin >> r >> k;

        if (r < 1 || r > m || k == 0) {
            cout << "Nhap sai!";
            return 0;
        }

        for (int j = 0; j < n; j++) {
            A[r - 1][j] *= k;
        }
    }
    else if (chon == 3) {
        int r1, r2;
        double k;
        cout << "Nhap dong bi thay doi (r1), dong dung de cong (r2), va he so k: ";
        cin >> r1 >> r2 >> k;

        if (r1 < 1 || r1 > m || r2 < 1 || r2 > m) {
            cout << "Chi so dong khong hop le!";
            return 0;
        }

        for (int j = 0; j < n; j++) {
            A[r1 - 1][j] += k * A[r2 - 1][j];
        }
    }
    else {
        cout << "Lua chon khong hop le!";
        return 0;
    }
    cout << "\nMa tran sau khi bien doi:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}