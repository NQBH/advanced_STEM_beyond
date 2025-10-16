#include <iostream>
using namespace std;

int main() {
    int m, n;
    double A[100][100];

    cout << " hang ";
    cin >> m;
    cout << " cot ";
    cin >> n;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }

    cout << "Ma tran A \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }

    return 0;
}
