//kiểm tra 1 ma trận nhập vào có phải là ma trận đường chéo (ma trận chỉ có các phần tử trên đường chéo chính có thể khác 0), ma trận tam giác trên, ma trận tam giác dưới, ma trận đối xứng (A = A^T)
#include <iostream>
using namespace std;
int main() {
    int m, n;
    cout << "nhap so hang: ";
    cin >> m;
    cout << "nhap so cot: ";
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
    bool maTranDuongCheo = true;
    bool maTranTamGiacTren = true;
    bool maTranTamGiacDuoi = true;
    bool maTranDoiXung = true;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && a[i][j] != 0) {
                maTranDuongCheo = false;
            }
            if (i > j && a[i][j] != 0) {
                maTranTamGiacTren = false;
            }
            if (i < j && a[i][j] != 0) {
                maTranTamGiacDuoi = false;
            }
            if (i > j && a[i][j] != a[j][i]) {
                maTranDoiXung = false;
            }
        }
    }

    cout << "\nket qua kiem tra: " << endl;
    if (maTranDuongCheo) {
        cout << "ma tran la ma tran duong cheo" << endl;
    } else if (maTranTamGiacTren) {
        cout << "ma tran la ma tran tam giac tren" << endl;
    } else if (maTranTamGiacDuoi) {
        cout << "Ma tran la ma tran tam giac duoi" << endl;
    } else if (maTranDoiXung) {
        cout << "ma tran la ma tran doi xung" << endl;
    } else {
        cout << "ma tran khong phai la ma tran duong cheo, tam giac tren, tam giac duoi hay doi xung" << endl;
    }
}