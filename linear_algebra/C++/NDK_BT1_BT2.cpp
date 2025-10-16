#include <iostream>
#include <vector>
using namespace std;
void Input(vector<vector<double>> &A, vector<double> &b) {
    //nhap vector
    int size_B = b.size();
    cout << "nhap vector cot (1xn): " << endl;
    for (int i = 0; i < size_B; i++) {
        cout << "nhap b[" << i << "]: " << endl;
        cin >> b[i];
    }
    //nhập ma trận
    int hang_A = A.size();
    int cot_A = A[0].size();
    for (int i = 0; i < hang_A; i++) {
        for (int j = 0; j < cot_A; j++) {
            cout << "A [" << i << "]" << "[" << j << "]: ";
            cin >> A[i][j];
        }
    }

}
void Print_Matrix(vector<vector<double>> const &A) {
    int hang = A.size();
    int cot = A[0].size();
    cout << "--------------------------" << endl;
    cout << "Ma tran: " << endl;
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << "--------------------------" << endl;
}
void Print_vector(vector<double> const &b) {
    //in vector cot
    cout << "--------------------------" << endl;
    cout << "Vector Cot: " << endl;
    int size_b = b.size();
    for (int i = 0; i < size_b; i++) {
        cout << b[i] << endl;
    }
    cout << "--------------------------" << endl;
    //in ma tran
}
//Bài 1
void Check(vector<vector<double>> const &A, vector<double> const &b) {
    int cot_A = A[0].size();
    int hang_A = A.size();
    int size_b = b.size();
    if (hang_A != size_b) {
        cout << "Impossible" << endl;
    }
    else {
        vector<vector<double>> Ab(hang_A, vector<double> (cot_A + 1));
        for (int i = 0; i < hang_A; i++) {
            for (int j = 0; j < cot_A; j++) {
                Ab[i][j] = A[i][j];
            }
            Ab[i][cot_A] = b[i];
        }
        Print_Matrix(Ab);
        Print_vector(b);
    }

}
//Bài 2
void Phep_nhan_1sokhac0(vector<vector<double>> &Matrix, double k) {
    if (k == 0) {
        return;
    }
    int hang_nhan;
    int hang_Matrix = Matrix.size();
    int cot_Matrix = Matrix[0].size();
    cout << "chon hang muon nhan: ";
    cin >> hang_nhan;
    if (hang_nhan < 0 || hang_nhan >= hang_Matrix) {
        cout << "Loiiiii";
        return;
    }
    for (int i = 0; i < cot_Matrix; i++) {
        Matrix[hang_nhan][i] *= k;
    }

}
void Phep_hoanvi_2hang(vector<vector<double>> &Matrix) {
    int hang_doi_a; int hang_doi_b;
    // đổi a thành b và b thành a
    cout << "chon hai hang muon doi (tu 0): ";
    cin >> hang_doi_a; cin >> hang_doi_b;
    int hang_Matrix = Matrix.size();
    int cot_Matrix = Matrix[0].size();
    if ((hang_doi_a < 0 || hang_doi_a >= hang_Matrix) || (hang_doi_b < 0 || hang_doi_b >= hang_Matrix) ) {
        cout << "LOIIIIIII";
        return;
    }
    for (int i = 0; i < cot_Matrix; i++) {
        double emp = Matrix[hang_doi_a][i];
        Matrix[hang_doi_a][i] = Matrix[hang_doi_b][i];
        Matrix[hang_doi_b][i] = emp;
    }
}
void Phep_cong_boiso1hang(vector<vector<double>> &Matrix) {
    int hang_nguon;
    cout << "chon hang nguon (tu 0)";
    cin >> hang_nguon;
    if (hang_nguon < 0 || hang_nguon >= Matrix.size()) {
        cout << "LOIIIIIII";
        return;
    }
    double k;
    cout << "chon he so: ";
    cin >> k;
    int hang_dich;
    cout << "chon hang dich (tu 0)";
    cin >> hang_dich;
    if (hang_dich < 0 || hang_dich >= Matrix.size()) {
        cout << "LOIIIIIII";
        return;
    }
    int cot_Matrix = Matrix[0].size();
    for (int i = 0; i < cot_Matrix; i++) {
        Matrix[hang_dich][i] += Matrix[hang_nguon][i] * k;
    }
}
int main() {
    int m;
    int n;
    cout << "nhap kich co ma tran (m x n): " << endl;
    cin >> m; cin >> n;
    vector<vector<double>> A(m, vector<double>(n));
    int size_vec;
    cout << "nhap kich co vector: " << endl;
    cin >> size_vec;
    vector<double> b(size_vec);

    Input(A, b);
    cout << "Kiem tra ma tran bo sung: " << endl;
    Check(A, b);
    cout << "Phep cong voi boi so 1 hang: " << endl;
    Phep_cong_boiso1hang(A);
    Print_Matrix(A);
    cout << "phep hoan vi hai hang" << endl;
    Phep_hoanvi_2hang(A);
    Print_Matrix(A);
    cout << "phep nhan voi 1 so khac 0" << endl;
    double k;
    cout << "he so nhan: ";
    cin >> k;
    Phep_nhan_1sokhac0(A, k);
    Print_Matrix(A);

    return 0;
}