#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cout <<"Nhap kich co ma tran: ";
    cin >> n;
    vector<vector<int > > a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    bool duongcheo = true, tamgiactren = true, tamgiacduoi = true, doixung = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i != j && a[i][j] != 0) duongcheo = false;     
            if (i > j && a[i][j] != 0) tamgiactren = false;    
            if (i < j && a[i][j] != 0) tamgiacduoi = false;    
            if (a[i][j] != a[j][i]) doixung = false;         
        }
    if (duongcheo)
        cout << "Ma tran duong cheo";
    else if (tamgiactren)
        cout << "Ma tran tam giac tren";
    else if (tamgiacduoi)
        cout << "Ma tran tam giac duoi";
    else if (doixung)
        cout << "Ma tran doi xung";
    else
        cout << "Khong thuoc loai nao";
    return 0;
}
