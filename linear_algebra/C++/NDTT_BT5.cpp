#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "so hang: ";
    cin >> n;
    cout << "so cot: ";
    cin >> m;

    double a[100][100],A[100][100];

    cout << "nhap phan tu trong ma tran:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cout << "ma tran sau khi nhap:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << a[i][j] << " ";;
        }
        cout << endl;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            A[j][i] = a[i][j];
        }
    }
    cout << "ma tran sau khi chuyen vi:\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
