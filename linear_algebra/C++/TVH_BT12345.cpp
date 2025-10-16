#include <iostream>
#include <vector>
using namespace std;

void cau_1(vector<vector<int>>& matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void cau_2(vector<vector<int>> matrix, int m, int n) {
    cout << "Nhap ma tran thu hai: \n";
    //em để mặc định kích cỡ bằng nhau
    vector<vector<int>> matrix_2(m, vector<int> (n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix_2[i][j];
        }
    }
    cout << "Tong hai ma tran la: \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix_2[i][j] + matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Hieu hai ma tran la: \n" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix_2[i][j] - matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void cau_3(vector<vector<int>> matrix, int m, int n) {
    int k; cout << "Nhap so thuc: "; cin >> k;
    cout << "Tich vo huong ma tran voi k la:\n" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j]*k << " ";
        }
        cout << endl;
    }
}

void cau_4(vector<vector<int>> matrix , int m, int n) {
    int l;
    cout << "Nhap so cot cua ma tran thu hai: \n"; cin >> l;
    cout << "Nhap ma tran thu hai (" << n << "x" << l << ") :\n";
    vector<vector<int>> matrix_2(n, vector<int> (l));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            cin >> matrix_2[i][j];
        }
    }
    vector<vector<int>> C(m, vector<int>(l));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < l; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += matrix[i][k] * matrix_2[k][j];
            }
        }
    }
    cout << "Ket qua nhan hai ma tran la: \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < l; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}
void cau_5(vector<vector<int>> matrix, int m, int n) {
    vector<vector<int>> matrix_2(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix_2[i][j] = matrix[j][i];
        }
    }
    cout << "Ma tran chuyen vi la: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix_2[i][j] << " ";
        }
        cout << endl;
    }

}
int main() {
    int m, n; cout << "Nhap so hang va cot: "; cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int> (n));
    cout << "Nhap phan tu ma tran: \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    int choose;
    while (true) {
        cout << "\n1.cau 1\n";
        cout << "2.cau 2\n";
        cout << "3.cau 3\n";
        cout << "4.cau 4\n";
        cout << "5.cau 5\n";
        cout << "6.Thoat\n";
        cout << "Nhap: ";
        cin >> choose;
        switch (choose) {
        case 1: {
            cau_1(matrix, m, n); break;
        }
        case 2: {
            cau_2(matrix, m, n); break;
        }
        case 3: {
            cau_3(matrix, m, n); break;
        }
        case 4: {
            cau_4(matrix, m, n); break;
        }
        case 5: {
            cau_5(matrix, m, n); break;
        }
        case 6: {
            return 0;
        }
        default: {
            cout << "Nhap lai: ";
            break;
        }
        }
    }
    return 0;
}