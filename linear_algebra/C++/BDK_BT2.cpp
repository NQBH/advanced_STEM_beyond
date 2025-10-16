#include <iostream>
using namespace std;

int main() {
    int m, n;
    double A[100][100], B[100][100];

    cout << "kich thuoc  ";
    cin >> m >> n;

    cout << "bo vao day ma tran A:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << " ma tran B:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    cout << "A + B \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << A[i][j] + B[i][j] << " ";
        cout << endl;
    }

    cout << "A - B:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << A[i][j] - B[i][j] << " ";
        cout << endl;
    }

    return 0;
}
