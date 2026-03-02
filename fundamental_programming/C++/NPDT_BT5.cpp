#include <iostream>
using namespace std;

int main() {
    double a, b;
    cout << "nhap: " << endl;
    cin >> a >> b;
    cout << "ket qua: " << '\n' << endl;
    if (a == 0)  {

        if (b == 0) {
            cout << "vo so nghiem";
        } else cout << "vo nghiem";

    } else cout << "ket qua: " << -b / a << endl;

}