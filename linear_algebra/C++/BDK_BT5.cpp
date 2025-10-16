#include <iostream>
using namespace std;

int main() {
    int m, n;
    double A[100][100];

    cout << " buoc dau nhap hang, so cot: ";
    cin >> m >> n;

    cout << "su dung cho  ma tran A:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "su dung Ma tran chuyen vi A*T \n";
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++)
            cout << A[i][j] << " ";
        cout << endl;
    }

    return 0;
}
