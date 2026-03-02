#include <bits/stdc++.h>
using namespace std;

int main() {
    const string pin_dung = "191919";
    const int max_trial = 5;
    long long A, a;
    cout << "Nhap so du tai khoan" << '\n';
    cin >> A;
    bool unlocked = false;
    for ( int i =1; i <= max_trial; i++){
        string nhap_pin;
        cin >> nhap_pin;
        if(nhap_pin == pin_dung){
            unlocked = true;
            break;
        }else{
            cout << "Ma pin sai( " << i << "/" << max_trial << ")" << '\n';
        }
    } 
    if(!unlocked){
        cout << "Tai khoan bi khoa" << '\n';
    }    
    else if(unlocked){
        cout << "Nhap so tien can rut" << '\n';
        cin>>a;
    } 
    else if(unlocked){
        if(a>A){
            cout << "So du khong du de rut" << '\n';
        } else {
            A -= a;
        cout << "HOA DON ATM\n";
    cout << "So tien rut : " << a << " dong\n";
    cout << "So du con lai: " << A << " dong\n";
    cout << "Cam on quy khach!\n";
        }
    }
}