BÀI 1:
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;

    int A[100][100]; // Giả sử kích thước tối đa 100x100

    cout << "Nhap cac phan tu cua ma tran A:\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Ma tran A vua nhap:\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

BÀI 2:
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;

    int A[100][100], B[100][100], C[100][100];

    cout << "Nhap ma tran A:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> A[i][j];
        }
    }

    cout << "Nhap ma tran B:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> B[i][j];
        }
    }

    // Cộng ma trận
    cout << "Tong A + B:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            C[i][j] = A[i][j] + B[i][j];
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    // Trừ ma trận
    cout << "Hieu A - B:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            C[i][j] = A[i][j] - B[i][j];
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

BÀI 3:
#include <iostream>
using namespace std;

int main() {
    int m, n;
    double c;
    cout << "Nhap so hang m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;

    double A[100][100];
    cout << "Nhap ma tran A:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> A[i][j];
        }
    }

    cout << "Nhap so thuc c: ";
    cin >> c;

    cout << "Ma tran c*A:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << A[i][j]*c << " ";
        }
        cout << endl;
    }

    return 0;
}
