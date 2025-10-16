//nhập vào 1 ma trận A & 1 vector b. Sau đó kiểm tra kích cỡ của A & b để xem có thể tạo ma trận bổ sung [A|b] được hay không. Nếu không thì xuất "Impossible". Nếu được thì xuất ra ma trận [A|b]
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "nhap hang: ";
    cin >> m;
    cout << "nhap cot: ";
    cin >> n;
    int a[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "]=";
            cin >> a[i][j];
        }
    }
    cout << "ma tran vua nhap la: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    int wingnhu;
    int b[wingnhu];
    cout << "nhap vector b: ";
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    if (m != wingnhu) {
        cout << "impossible";
    } else {
        cout << "ma tran vua nhap la: " << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << " | " << b[i];
            cout << endl;
        }

    }

}