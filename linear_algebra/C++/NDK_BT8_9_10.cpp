#include <iostream>
#include <vector>
using namespace std;
void Input(vector<vector<int>> &A) {
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
void Print_Matrix(vector<vector<int>> const &A) {
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
//Bài 8
vector<vector<int>> matran_0 (int n) {
    vector<vector<int>> A (n, vector<int> (n, 0));
    return A;
}
vector<vector<int>> matran_donvi (int n) {
    vector<vector<int>> A (n, vector<int> (n, 0));
    int a = 0;
    for (int i = 0; i < n; i++) {
        A[i][a] = 1;
        a++;
    }
    return A;
}
//Bài 9
bool tam_giac_duoi (vector<vector<int>> const &A) {
    if (A.size() == A[0].size()) {
        int n = A.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (A[i][j] != 0) {
                    return false;
                }
            }
        }
        return true;
    }
    else {
        return false;
    }
}
bool tam_giac_tren(vector<vector<int>> const &A) {
    if (A.size() == A[0].size()) {
        int n = A.size();
        for (int i = 0; i < n; i++) {
            int j = 0;
            while (j < i) {
                if (A[i][j] != 0) {
                    return false;
                }
                j++;
            }
        }
        return true;
    }
    else {
        return false;
    }
}
bool matran_cheo (vector<vector<int>> const &A) {
    if (tam_giac_tren(A) && tam_giac_duoi(A)) {
        return true;
    }
    else {
        return false;
    }
}
bool matran_doixung(vector<vector<int>> const &A) {
    int n = A.size();
    if (n == A[0].size()) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] != A[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }
    else {
        return false;
    }
}
//BÀi 10
double det() {
    vector<vector<int>> A(2, vector<int> (2));
    Input(A);
    return A[0][0] * A[1][1] - A[0][1] * A[1][0];
}

int main() {
    int n;
    cout << "nhap n: ";
    cin >> n;
    vector<vector<int>> A (n, vector<int> (n));
    vector<vector<int>> B;
    vector<vector<int>> C;
    B = matran_0(n);
    Print_Matrix(B);
    C = matran_donvi(n);
    Print_Matrix(C);
    Input(A);
    Print_Matrix(A);
    cout << tam_giac_tren(A) << endl; //1 đúng 0 sai
    cout << tam_giac_duoi(A) << endl;
    cout << matran_cheo(A) << endl;
    cout << matran_doixung(A) << endl;
    double Det = det();
    cout << Det << endl;

}