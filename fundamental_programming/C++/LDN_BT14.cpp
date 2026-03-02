#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long long A;
    long long a;
    int max_trial;
    string realpin;
    string inputpin;
    cout <<"nhap so du A: ";
    cin >> A;
    cout <<"nhap so tien muon rut a: ";
    cin >> a;
    cout <<"nhap ma PIN thuc : ";
    cin >> realpin;
    cout <<"nhap so lan nhap sai toi da: ";
    cin >> max_trial;
    bool locked = false;
    bool security = false;
    int trial = 0;
    while (trial < max_trial){
        cout <<"nhap ma pin:";
        cin >> inputpin;
        if (inputpin == realpin){
            cout<<"dang nhap thanh cong"<<endl;
            break;
        }else{
            trial++;
            if (trial < max_trial){
                cout <<"sai ma pin"<<endl;
            }
            string reversedin = string(realpin.rbegin(), realpin.rend());
            if (inputpin == reversedin){
                cout <<"canh bao bao mat:"<<endl;
                security = true;
                break;
            }
            trial++;
            if (trial < max_trial) {
                cout << "Sai ma PIN. Vui long thu lai." << endl;
            }
        }
    }
    if (trial == max_trial && !security && inputpin != realpin) {
        cout << "The bi khoa" << endl;
        locked = true;
    }
    if (!locked && !security && inputpin == realpin){
        if (a > A){
            cout << "so tien rut hon so du"<< endl;
        }else{
            A = A - a;
            cout << "rut tien thanh cong. so du con lai: " << A << endl;
        }
        }
    }
