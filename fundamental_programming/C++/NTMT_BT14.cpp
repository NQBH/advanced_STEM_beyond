#include <iostream>
#include <cmath>
using namespace std;
int main() {
    long long A, a; 
    cout << "Nhập số dư: " ;
    cin >> A ;
    string b, PIN = "084989";
    int i=1;
    while (1) {
        cout << "Nhập số tiền cần rút: " ;
        cin >> a;
        if (a > A) cout << "Số tiền rút lớn hơn số dư khả dụng. Bạn bị ảo tưởng sức mạnh tài chính à?" << endl; 
        else {
            cout << "#so lan thu: ";
            int max_trial; cin >> max_trial;
            while (max_trial - (i -1) > 0) {
                cout << "Nhập mã PIN: ";
                cin >> b;
                if (b!=PIN && b != "989480") {
                    cout <<"Bạn còn " << max_trial - i << " lần thử." << endl;
                    if (!(max_trial - (i))) {
                        cout <<"Thẻ của bạn đã bị khóa."<< endl;
                        break;
                    }
                }
                else if (b == "989480") {
                    cout << "Security!" << endl;
                    break;
                }
                else {
                    cout << "Rút tiền thành công." << endl;
                    cout << "Số dư còn lại là: " << A -a << endl;
                    break;
                }
                ++i;
            }
            break;
        }
    }
    
    
}

