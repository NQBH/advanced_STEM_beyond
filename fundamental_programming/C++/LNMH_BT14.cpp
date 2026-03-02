#include <bits/stdc++.h>
using namespace std;

int main() {
    const string pin_dung = "000000";
    const int max_trial = 5;
    long long A, a;
    cout << "Nhap so du tai khoan" << '\n';
    cin >> A;
    bool unlocked = false;
    for ( int i =1; i <= max_trial; i++){
        string nhap_pin;
        cout << "Nhap pin : ";
        cin >> nhap_pin;
        if(nhap_pin == pin_dung){
            unlocked = true;
            break;
        }else{
            cout << "sai pin( " << i << "/" << max_trial << ")" << '\n';
        }
    }
    if(!unlocked){
        cout << "Tai khoan bi khoa" << '\n';
    } else if(unlocked){
        cout << "Nhap so tien can rut" << '\n';
        cin >> a;
        if(a>A){
            cout << "So du khong du de rut !" << '\n';
        } else {
            A -= a;
            cout << " HOA DON ATM \n";
        cout << "So tien rut : " << a << " VND\n";
        cout << "So du con lai: " << A << " VND\n";
        cout << "Cam on quy khach!\n";
       
        }
    }
}