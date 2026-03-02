#include <iostream>
using namespace std;

long long daoSo(long long x) {
    long long dao = 0;
    while (x > 0) {
        dao = dao * 10 + x % 10;
        x /= 10;
    }
    return dao;
}
int main() {
    long long A, a;
    long long pin, pin_input;
    int solanthu;
    cout<<"Nhap so du tai khoan A: ";
    cin>>A;
    cout << "Nhap so tien can rut a: ";
    cin>>a;
    cout<<"Nhap ma PIN that: ";
    cin>>pin;
    cout<<"Nhap so lan thu toi da: ";
    cin>>solanthu;
    int solan = 0;
    bool khoa = false;
    bool baove = false;
    while (solan < solanthu) {
        cout<<"Nhap ma PIN: ";
        cin>>pin_input;
        if (pin_input == pin) {
            cout<<"Dang nhap thanh cong\n";
            break;
        }
        if (pin_input==daoSo(pin)) {
            cout<<"Canh bao bao mat!\n";
            baove=true;
            break;
        }
        solan++;
        if (solan<solanthu) {
            cout<<"Sai ma PIN. Vui long thu lai.\n";
        }
    }
    if (solan==solanthu && !baove && pin_input!=pin) {
        cout<< "The da bi khoa\n";
        khoa = true;
    }
    if (!khoa && !baove && pin_input == pin) {
        if (a>A) {
            cout<<"So tien rut lon hon so du\n";
        } else {
            A -= a;
            cout<< "Rut tien thanh cong. So du con lai: "<< A<< '\n';
        }
    }
}