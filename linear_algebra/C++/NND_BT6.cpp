#include<iostream>
#include<vector>
using namespace std;
int main() {
    int m, n;
    cout << "Nhap so hang va cot:";
    cin >> m >> n;

    vector<vector<double>>A(m, vector<double>(n));
    cout << "nhap phan tu cua A:";
    for (int i = 0; i < m ; i++)
        for (int j = 0; j < n : j++)
            cin >> A[i][j];

    vector<double>B(m);
    cout << "Nhap vector B: ";
    for (int i = 0; i < m; i++)
        cin >> B[i];

    if (B.size() !A.size()) {
        cout << "impossible X";
        retrun 0;
    }
    vector<vector<double>>Bosungmatran(m, vector<double>(n + 1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            Bosungmatran[i][j] = A[i][j]; {
                Bosungmatran[i][j] = B[i]
            }
        }
        cout << "Matrix duoc bo sung:";
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                cout << Bosungmatran[i][j] << " ";
            }
        count << \n;
    }
    return 0;
}