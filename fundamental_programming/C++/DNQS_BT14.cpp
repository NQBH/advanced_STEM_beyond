#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    long long A , a;
    string pin_real , pin_input;
    int max_traial;

    cout << "nhap so du ban dau(A): ";
    cin >> A;
    cout << "nhap so tien can rut (a): ";
    cin >> a;
    cout << "nhap ma PIN (6 chu so): ";
    cin >> pin_real;
    cout << "nhap so lan thu toi da :";
    cin >> max_traial ;

    int traial = 0;
    bool authenticated = false;
    string reverse_pin = pin_real;
    reverse(reverse_pin.begin(), reverse_pin.end());
    while(traial < max_traial){
        cout << "nhap ma PIN: ";
        cin >> pin_input;
        if(pin_input == reverse_pin){
            cout << "SECURITY ALERT" << endl;
            return 0;
        }
        if(pin_input == pin_real){
            authenticated = true;
            break;
        } 
            traial++;
        }
    if(!authenticated){
        cout << "the da bi khoa do nhap sai qua so lan quy dinh!" << endl;
        return 0;
    }
    if(a > A){
        cout << "So du khong du de thuc hien giao dich!" << endl;
    } else {
        A -= a;
        cout << "Rut tien thanh cong! So du con lai: " << A << endl;
    }
    cout << "\n ban co muon in hoa don khong? (Y/N): ";
    char choice;
    if(cin >> choice && (choice == 'Y' || choice == 'y')){
    cout << "\n=========== Hoa don ATM ===========" << endl;
    cout << "ngan hang: ABC Bank" << endl;
    cout << "so tai khoan: 123456789" << endl;
    cout << "So tien rut: " << a << endl;
    cout << "So du tai khoan: " << A << endl;
    cout << "trang thai giao dich: thanh cong" << endl;
    cout << "cam on quy khach da su dung dich vu!" << endl;
    }
    else {
        cout << "\n giao dich ket thuc. khong xuat hoa don!" << endl;
    }
    return 0;
}