#include <iostream>
#include <vector>
using namespace std;

//Hàm Nhập
void Nhap(vector<vector<double>> &matran, int hang, int cot) {
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            cout << "matran [" << i + 1 << "]" << "[" << j + 1 << "]: ";
            cin >> matran[i][j];
        }
    }
}
//Hàm Xuất
void Xuat(vector<vector<double>> const &matran) {
    int hang = matran.size();
    int cot = matran[0].size();
    cout << "------------------------" << endl;
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            cout << matran[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------------------------" << endl;
}
//Hàm Phép Cộng
vector<vector<double>> Cong(vector<vector<double>> const &matran1, vector<vector<double>> const &matran2) {
    int hang = matran1.size();
    int cot = matran1[0].size();
    vector<vector<double>> kq(hang, vector<double> (cot));
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            kq[i][j] = matran1[i][j] + matran2[i][j];
        }
    }
    return kq;
}
//Hàm Phép Trừ
vector<vector<double>> Tru(vector<vector<double>> const &matran1, vector<vector<double>> const &matran2) {
    int hang = matran1.size();
    int cot = matran1[0].size();
    vector<vector<double>> kq(hang, vector<double> (cot));
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            kq[i][j] = matran1[i][j] - matran2[i][j];
        }
    }
    return kq;
}
//Hàm Nhân Một Số
vector<vector<double>> Nhan_mot_so(vector<vector<double>> const &matran, int so_nhan) {
    int hang = matran.size();
    int cot = matran[0].size();
    vector<vector<double>> kq(hang, vector<double> (cot));
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            kq[i][j] = matran[i][j] * so_nhan;
        }
    }
    return kq;
}
//Hàm nhân hai Ma Trận
vector<vector<double>> Nhan_hai_matran(vector<vector<double>> const &matran1, vector<vector<double>>const &matran2) {
    int m = matran1.size();
    int n = matran1[0].size();
    int p = matran2[0].size();
    vector<vector<double>> kq(m, vector<double> (p));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                kq[i][j] = kq[i][j] + matran1[i][k] * matran2[k][j];
            }
        }
    }
    return kq;
}
//Hàm Phép Chuyển Vị
vector<vector<double>> Chuyen_vi(vector<vector<double>> const &matran) {
    int m = matran.size();
    int n = matran[0].size();
    vector<vector<double>> kq(n, vector<double> (m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            kq[j][i] = matran[i][j];
        }
    }
    return kq;
}
int main() {
    vector<vector<double>> matran1(3, vector<double> (2));
    vector<vector<double>> matran2(2, vector<double> (3));
    vector<vector<double>> matran3(2, vector<double> (3));
    Nhap(matran1, 3, 2);
    Xuat(matran1);
    Nhap(matran2, 2, 3);
    Xuat(matran2);
    Nhap(matran3, 2, 3);
    vector<vector<double>> matran_kq;
    matran_kq = Nhan_hai_matran(matran1, matran2);
    cout << "Phep Nhan: " << endl;
    Xuat(matran_kq);
    vector<vector<double>> matran_kq_2;
    matran_kq_2 = Chuyen_vi(matran1);
    cout << "Phep Chuyen Vi: " << endl;
    Xuat(matran_kq_2);
    vector<vector<double>> matran_kq_3;
    matran_kq_3 = Tru(matran2, matran3);
    cout << "Phep Tru: " << endl;
    Xuat(matran_kq_3);
    vector<vector<double>> matran_kq_4;
    matran_kq_4 = Nhan_mot_so(matran1, -1);
    cout << "Phep Nhan mot so: " << endl;
    Xuat(matran_kq_4);
    return 0;
}