#include <iostream>
#include <cmath>
using namespace std;
int main(){
    long long A;
    long long a;
    int max_trial;
    string pin;
    cin >> A >> a >> max_trial >> pin;

    string pin_n = "";
    int len = pin.length();
    int i = len - 1;
    while(i >= 0){
        pin_n = pin_n + pin[i];
        i--;
    }
    string input;
    int trial = 0;
    bool unlock = false;
    while(trial < max_trial){
        cin >> input;
        if(input == pin_n){
            cout << "Canh bao security! Khong duoc nhap PIN nua" << endl;
            return 0;
        }
        if(input == pin){
            unlock = true;
            break;
        }
        trial++;
    }
    if(!unlock){
        cout << "The da bi khoa do nhap sai qua nhieu" << endl;
        return 0;
    }
    if(a > A){
        cout << "So tien rut lon hon so du kha dung. Ban bi ao tuong suc manh tai chinh a ???" << endl;

    }else{
        long long rut = A - a;
        cout << "Rut tien thanh cong!" << endl;
        cout << "So tien rut: " << a << " VND" << endl;
        cout << "So du con lai: " << rut << " VND" << endl;
        cout << "Cam on quy khach" << endl;
    }

return 0;
}