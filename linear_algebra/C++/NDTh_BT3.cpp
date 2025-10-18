#include <iostream>
using namespace std;

#define MAX 100

int main() {
    int m, n, c;
    int A[MAX][MAX], C[MAX][MAX];

    cout << "Nhap so hang m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;

    cout << "Nhap ma tran A:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Nhap so thuc c: ";
    cin >> c;

    cout << "\nc * A = \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] * c;
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}