#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a,b,max_trial;
    int pin_fk,pin_real,dem=0;
    cout << "PIN real: ";
    cin >> pin_real;
    cout << "Max_trial: ";
    cin >> max_trial;
    cout << "Nhap so tien: ";
    cin >> a;
    cout << "Nhap so tien muon rut: ";
    cin >> b;
    while (max_trial--){
        cout << "Nhap Pin fk";
        cin >> pin_fk;
        if (dem > max_trial+1){
            cout << "nhap ngu bi khoa the:";
            break;
        } else if (pin_fk == pin_real){
            if (b>a){
                cout << "Số tiền rút lớn hơn số dư khả dụng. Bạn bị ảo tưởng sức mạnh tài chính à?";
                break;
            }else{
                cout << "OK" << endl;
                cout << "so du con lai: " << a - b ;
                break;    
            }
            
        }else{
            cout << "SAI VA NHAP LAI" << endl;
            dem+=1;
        }
    }
    return 0;
}