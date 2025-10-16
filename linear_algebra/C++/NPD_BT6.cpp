/*
bt1: viết chương trình c++ để nhập vào 1 ma trận A & 1 vector b.
sau đó kiểm tra kích cỡ của A & b để xem có thể tạo ma trận bổ sung [A|b] được hay không.
nếu không thì xuất "Impossible". Nếu được thì xuất ra ma trận [A|b].
*/

#include <iostream>

using namespace std;

int main(){
    int m, n;
    cout << "Nhap so hang: ";
    cin >> m;
    cout << "nhap so cot: ";
    cin >> n;

    int A[m][n];
    cout << "\nNhap cac phan tu cua ma tran: " << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }
    cout << "\nMa tran vua nhap la: " << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    //vector b
    int phucdui;
    cout << "\nNhap so phan tu (so hang) cua vector b: ";
    cin >> phucdui;

    int b[phucdui];
    cout << "\nNhap cac phan tu cua vector b: " << endl;
    for(int i = 0; i < phucdui; i++){
        cout << "b[" << i << "] = ";
        cin >> b[i];
    }
    cout << "\nVector b vua nhap la: " << endl;
    for(int i = 0; i < phucdui; i++){
        cout << b[i] << " ";
    }

    // kiem tra
    if (m != phucdui) {
        cout << "\n\nImpossible (ko the tao thanh ma tran bo sung [A/b] vi kich thuoc ko phu hop (hang cua ma tran > phan tu(hang) cua vector))" << endl;
    } else {
        cout << "\n\nMa tran bo sung [A/b] la: " << endl;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << A[i][j] << " ";
            }
            cout << "| " << b[i];
            cout << endl;
        }
    }
}