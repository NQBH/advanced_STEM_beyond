#include<iostream>
#include<vector>
using namespace std;
int main() {
    int m, n, k;
    cout << "nhap hang va cot :";
    cin >> m >> n;
    vector<vector<int>>A(m, vector<int>(n));
    cout << "nhap cac phantu cua A:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    cout << " nhap k";
    cin >> k;
    vector<vector<int>>B(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            B[i][j] = k * A[i][j];
        }
    }
    cout << " ma tran b = " << k << "* A la:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    } return 0;
}