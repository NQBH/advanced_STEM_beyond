#include <iostream>
#include <string>
using namespace std;

int main(){
    long long A;
    long long a;
    string pinDung = "123456";
    string pinNhap;
    int maxTrial;
    bool ok = false;

    cin >> A >> maxTrial;
    cout << "Nhap so tai khoan (VND): " << A << endl;
    cout << "Nhap so lan pin toi da: " << maxTrial << endl;

    for(int i = 0; i <= maxtrial; i++){
        cout << "Nhap ma pin:";
        cin >> pinNhap;

        if(pinNhap == pinDung){
            ok = true;
           break;
        }else{
            cout << "Sai PIN!"
        }
    }

    if (!ok){
        cout << "The da bi khoa!" << endl;
        return 0;

    }
    cout << "Nhap so tien can rut (VND): ";
    cin >> a;
    if (a > A){
        cout << "So du khong du de thuc hien giao dich!" << endl;
        return 0;
    }
      A = A - a;
    cout << "Rut tien thanh cong!" << endl;
    cout << "So du con lai: " << A << " VND" << endl;

    return 0;

}
