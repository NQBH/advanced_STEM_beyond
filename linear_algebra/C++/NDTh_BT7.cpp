#include <iostream>
#include <vector>
using namespace std;

void nhapMaTran(vector< vector<double> > &A, int m, int n) {
    A.resize(m, vector<double>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }
}

void xuatMaTran(const vector< vector<double> > &A) {
    for (int i = 0; i < (int)A.size(); i++) {
        for (int j = 0; j < (int)A[i].size(); j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int m, n;
    cout << "Nhap so dong va cot: ";
    cin >> m >> n;

    vector< vector<double> > A;
    nhapMaTran(A, m, n);

    cout << "\nMa tran ban dau:\n";
    xuatMaTran(A);

    int choice;
    cout << "\nChon phep bien doi:\n";
    cout << "1. Hoan doi hai dong\n";
    cout << "2. Nhan mot dong voi mot hang so\n";
    cout << "3. Cong boi cua mot dong vao dong khac\n";
    cout << "Nhap lua chon: ";
    cin >> choice;

    if (choice == 1) {
        int r1, r2;
        cout << "Nhap hai dong can doi: ";
        cin >> r1 >> r2;
        for (int j = 0; j < n; j++)
            swap(A[r1][j], A[r2][j]);
    } 
    else if (choice == 2) {
        int r; double k;
        cout << "Nhap dong va he so k: ";
        cin >> r >> k;
        for (int j = 0; j < n; j++)
            A[r][j] *= k;
    } 
    else if (choice == 3) {
        int r1, r2; double k;
        cout << "Nhap dong nguon r1, dong dich r2, he so k: ";
        cin >> r1 >> r2 >> k;
        for (int j = 0; j < n; j++)
            A[r2][j] += k * A[r1][j];
    }

    cout << "\nMa tran sau bien doi:\n";
    xuatMaTran(A);
    return 0;
}

