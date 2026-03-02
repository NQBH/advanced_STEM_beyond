#include <bits/stdc++.h>
using namespace std;

int main(){
    long long A,a,max_trial;
    cout << "Nhập Số tiền tài khoản hiện có : "; cin >> A ;
    cout << "Nhập Số tiền muốn rút : "; cin >> a ;
    cout << "Nhập Số lần được nhập pin sai : "; cin >> max_trial ;
    string PIN = "123456";
    while (max_trial--){
        string YOURPIN;
        cout << "NHẬP MÃ PIN 6 SỐ CỦA BẠN : ";
        cin >> YOURPIN;
        if (YOURPIN == PIN) {
            if (a <= A) {
                cout << "RÚT TIỀN THÀNH CÔNG" << '\n';
                cout << "SỐ DƯ CÒN LẠI : "<< A-a << "VND";
                break;
            }
            else {
                cout << "Số tiền rút lớn hơn số dư khả dụng. Bạn bị ảo tưởng sức mạnh tài chính à?"; break;
            }
        }
        else if (YOURPIN != PIN){
            int cnt = 0;
            for (int i = 0 , j = 5; i <= 5, j >= 0; i++,j--){
                if (PIN[j] == YOURPIN[i]){
                    cnt++;
                }
                else {break;}
            }
            if (cnt == 6) {cout << "ĐÃ BÁO VỚI SECURITY!"; break;}
        }
        else {continue;}
    }
    if (max_trial == -1) {cout << "THẺ ĐÃ BỊ KHÓA" ;} 
}