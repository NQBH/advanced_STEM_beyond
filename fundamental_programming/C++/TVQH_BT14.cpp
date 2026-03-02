#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
int main () {
    long long n;
    cout <<"So du hien tai trong tai khoan: ";
    cin>>n;
    int m;
    cout <<"So lan nhap sai ma PIN duoc phep: ";
    cin>>m;
    string PIN = "123456";
    string PINdaonguoc = PIN;
    reverse(PINdaonguoc.begin(), PINdaonguoc.end());
    int solannhap = 0;
    string Pinnhap;
    bool dangnhapthanhcong = false;
    while (solannhap < m) {
        cout <<"Nhap ma PIN: ";
        cin>>Pinnhap;
       solannhap++;
       if (Pinnhap == PINdaonguoc) {
           cout <<"Security!" << endl;
           return 0;
       }
         if (Pinnhap == PIN) {
              dangnhapthanhcong = true;
         } else {
              cout <<"Ma PIN khong dung." << endl;
         }
         if (solannhap == m) {
             cout <<"Tai khoan bi khoa." << endl;
             return 0;
         }
         if (dangnhapthanhcong) {
             long long sotienrut;
             cout <<"So du hien tai trong tai khoan: " << n << endl;
             cout <<"Nhap so tien can rut: ";
             cin>>sotienrut;
             if (sotienrut > n) {
                 cout <<"So du khong du de thuc hien giao dich.Ban bi ao tuong suc manh tai chinh a." << endl;
             } else {
                 n = n - sotienrut;
                 cout <<"Giao dich thanh cong. So du con lai: " << n << endl;
             }
         }
    }
    return 0;
}
