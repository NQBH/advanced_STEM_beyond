// Matrix - Ma trận
// Bài toán 1 (Nhập xuất ma trận). Viết chương trình Python, C++ để nhập vào số hàng, số cột, & các phần tử của 1 ma trận
// A thuộc Rm×n, sau đó xuất ra màn hình

#include <bits/stdc++.h>
using namespace std;

int main(){
    int m ,n ;
    cout << "Nhap so dong va so cot: ";
    cin >> m >> n ;

    vector<vector<double>> a(m, vector<double>(n));
    cout << "Nhap cac phan tu của ma tran " << m << "x" << n << ":\n";
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> a[i][j];
        }
    }
    cout  << "\nMa tran vua nhap:\n";
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// BÀI 2: (Cộng hai ma trận). Viết chương trình Python, C++ để nhập vào số hàng, số cột, & các phần tử của 2 ma trận A, B thuộc Rm×n,
// sau đó tính và xuất ra màn hình
#include <bits/stdc++.h>
using namespace std;

using Matrix = vector<vector<double>>;
Matrix inputMatrix(int m, int n, char name) {
    Matrix M(m, vector<double>(n));
    cout << "Nhap ma tran " << name << " (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }
    return M;
}
void printMatrix(const Matrix &M) {
    for (auto &row : M) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
}
Matrix addMatrix(const Matrix &A, const Matrix &B) {
    int m = A.size(), n = A[0].size();
    Matrix C(m, vector<double>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}
Matrix subtractMatrix(const Matrix &A, const Matrix &B) {
    int m = A.size(), n = A[0].size();
    Matrix D(m, vector<double>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            D[i][j] = A[i][j] - B[i][j];
        }
    }
    return D;
}

int main() {
    int m, n;
    cout << "Nhap so hang va so cot (m n): ";
    cin >> m >> n;

    Matrix A = inputMatrix(m, n, 'A');
    Matrix B = inputMatrix(m, n, 'B');

    cout << "\nMa tran A:\n"; printMatrix(A);
    cout << "Ma tran B:\n"; printMatrix(B);

    Matrix C = addMatrix(A, B);
    Matrix D = subtractMatrix(A, B);

    cout << "\nA + B =\n"; printMatrix(C);
    cout << "\nA - B =\n"; printMatrix(D);

    return 0;
}
// Bài 3: phép nhân vô hướng của 2 ma trận với 1 hằng số. Viết chương trình Python, C ++ thực hiện phép nhân vô hướng của 2 ma trận A, B thuộc Rm×n với 1 số thực thuộc R
// in ra màn hình
 #include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang va so cot (m n): ";
    cin >> m >> n;

    int A[100][100], C[100][100];
    int k;
    cout << "Nhap ma tran A (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    cout << "Nhap so k: ";
    cin >> k;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = k * A[i][j];
        }
    }
    cout << "\nMa tran C = k * A:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

//  bài 4 : nhân 2 ma trận. viết chương trình c++ thực hiện phép nhân 2 ma trận A thuoc R (m x n) và B thuoc R (n x p) 
// in ra màn hình
#include <bits/stdc++.h>
using namespace std;
 
#include <iostream>
using namespace std;

int main() {
    int m, n, p;
    cout << "Nhap so hang va so cot cua ma tran A (m n): ";
    cin >> m >> n;

    cout << "Nhap so cot cua ma tran B (p): ";
    cin >> p;

    int A[100][100], B[100][100], C[100][100];
    cout << "Nhap ma tran A (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    cout << "Nhap ma tran B (" << n << "x" << p << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cin >> B[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout << "\nMa tran C = A * B:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

