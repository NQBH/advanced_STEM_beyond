#include <bits/stdc++.h>
#include <cmath>
#define int long long
using namespace std;

signed main() {
    int a, b, max_trial;
    string s, pin;
    cout << "PIN real: ";
    cin >> pin;
    cout << "Max_trial: ";
    cin >> max_trial;
    cout << "Nhap so tien: ";
    cin >> a;
    cout << "Nhap so tien muon rut: ";
    cin >> b;
    max_trial += 1;
    while (max_trial--) {
        if (max_trial != 0) {
            cout << "Ma PIN: ";
            cin >> s;
            int demx = 0, demn = 0;
            for (int i = 0; i < pin.length(); i++) {
                if (pin[i] != s[i]) break;
                else demx += 1;
            }
            int k = pin.length();
            for (int i = 0; i < pin.length(); i++) {
                if (pin[i] != s[k - 1]) break;
                else {
                    demn += 1;
                    k--;
                }
            }
            if (demn == pin.length()) {
                cout << "Police will come in 30s";
                break;
            } else {
                if (demx == pin.length()) {
                    if (b > a) {
                        cout << "Số tiền rút lớn hơn số dư khả dụng. Bạn bị ảo tưởng sức mạnh tài chính à?";
                        return 0;
                    } else {
                        cout << "Rut thanh cong " << b << " VND" << '\n';
                        cout << "So du con lai: " << a - b << " VND" << '\n';
                        return 0;
                    }
                } else cout << "Nhap lai ma PIN _ ";
            }
        } else {
            cout << "The bi lock. Di lam lai the moi =)";
            break;
        }
    }
    return 0;
}