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

    int opt;
    cout << "\nChon phep bien doi: " << endl;
    cout << "1. Hoan vi 2 dong" << endl;
    cout << "2. Nhan mot dong voi so khac 0" << endl;
    cout << "3. Cong boi so mot dong voi dong khac" << endl;
    cout << "Nhap lua chon (1 hoac 3): ";
    cin >> opt;
    if (opt != 1 && opt != 2 && opt != 3) {
        cout << "Lua chon khong hop le!" << endl;
        return 1;
    } else if (opt == 1) {
        // hoan vi 2 dong
        int s1, s2;
        cout << "\nNhap 2 dong can hoan vi: " << endl;
        cout << "Dong 1: ";
        cin >> s1;
        cout << "Dong 2: ";
        cin >> s2;

        // chuyen ve 0 based index
        s1--; s2--;
        for (int j = 0; j < n; j++) {
            std::swap(A[s1][j], A[s2][j]);
        }
        cout << "\nMa tran sau khi hoan vi dong " << (s1+1) << " va dong " << (s2+1) << ": " << endl;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << A[i][j] << " ";
            }
            cout << endl;
        }  
    } else if (opt == 2) {
        // nhan mot dong voi so khac 0
        int scale, r;
        cout << "\nNhap so dong can nhan: ";
        cin >> r;
        cout << "Nhap he so nhan (khac 0): ";
        cin >> scale;

        // chuyen ve 0 based index
        r--;
        for (int j = 0; j < n; j++) {
            A[r][j] *= scale;
        }
        cout << "\nMa tran sau khi nhan dong " << (r+1) << " voi " << scale << ": " << endl;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    } else if (opt == 3) {
        // cong boi so mot dong voi dong khac
        int scale, src, dst;
        cout << "\nNhap dong dich (nhan vao): ";
        cin >> dst;
        cout << "Nhap dong nguon (bi nhan va cong vao dich): ";
        cin >> src;
        cout << "Nhap he so nhan: ";
        cin >> scale;
        dst--; src--;
        if (dst < 0 || dst >= m || src < 0 || src >= m) {
            cout << "Chi so dong khong hop le!" << endl;
            return 1;
        }
        for (int j = 0; j < n; j++) {
            A[dst][j] += scale * A[src][j];
        }
        cout << "\nMa tran sau khi cong vao dong " << (dst+1) << " (tu dong " << (src+1) << " nhan voi " << scale << ") : " << endl;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
}