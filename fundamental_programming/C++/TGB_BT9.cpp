#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap n: " << '\n';
    cin >> n;
    int Chan = 0, Le = 0;
    for (int i = 1; i <= n; ++i) {
        int a;
        cout << "nguyen thu " << i << '\n';
        cin >> a;
        if (a % 2 == 0) {
            Chan++;
        } else {
            Le++;
        }
    }
    cout << " Ket qua" << '\n';
    cout << "so chan  " << Chan << '\n';
    cout << "so le " << Le << '\n';
}