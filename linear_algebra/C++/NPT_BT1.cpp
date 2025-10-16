//  Viết chương trình C/C++ (+1.5), Python (+1) để nhập vào 1 ma trận A & 1 vector b.
// Sau đó kiểm tra kích cỡ của A & b để xem có thể tạo ma trận bổ sung [A|b] được hay không. Nếu không thì xuất "Impossible".
// Nếu được thì xuất ra ma trận [A|b].

#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cout << "Nhap so hang(m): ";
    cin >> m;
    cout << "Nhap so cot(n): ";
    cin >> n;

    int A[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    int size_b;
    cout << "Nhap vector b: ";
    cin >> size_b;

    if (m <= 0 || n <= 0) {
        cout << "Impossible !!!" << endl;
    }



    int b[m];
    for (int i = 0; i < size_b; i ++) {
        cin >> b[i];
        if (size_b != m)
            cout << "Impossible !!!" << endl;
    }



    cout << "Ma tran: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";

        }
        cout << "| " << b[i];
        cout << endl;
    }
    return 0;
}