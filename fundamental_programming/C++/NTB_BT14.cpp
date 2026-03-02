#include <iostream>
#include <cmath>

using namespace std;
int main() {
    long long  M, N;
    cout << "nhap so tien: ";
    cin >> M;
    cout << "nhap so tien rut: ";
    cin >> N;
    long long max_trial, PINR;
    cout << "tao ma pin: ";
    cin >> PINR;
    cout << "so lan nhap: ";
    cin >> max_trial;
    while (max_trial >= 0){
        if (max_trial >= 1){
            long long PINF;
            cin >> PINF;
            if (PINR == PINF){
                if (N>M){
                    cout << "Số tiền rút lớn hơn số dư khả dụng. Bạn bị ảo tưởng sức mạnh tài chính à?";
                    break;
                } else {
                    cout << "rut thanh cong: " << N << endl;
                    cout << "so du con lai: " << M - N << endl;
                    break;
                }
            } else if(max_trial>1){
                cout << "Sai vui long nhap lai: ";
            }
        } else {
            cout << "khóa thẻ";
            break;
        }
        max_trial--;
    }
    return 0;
}
