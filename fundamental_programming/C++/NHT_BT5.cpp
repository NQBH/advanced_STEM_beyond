/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    if (a == 0) {
        if (b == 0) {
            if (c == 0)
                cout << "Phuong trinh vo so nghiem";
            else
                cout << "Phuong trinh vo nghiem";
        } else {
            cout << "x = " << -c / b;
        }
    } else {
        double delta = b * b - 4 * a * c;

        if (delta < 0)
            cout << "Phuong trinh vo nghiem";
        else if (delta == 0)
            cout << "x = " << -b / (2 * a);
        else {
            cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << endl;
            cout << "x2 = " << (-b - sqrt(delta)) / (2 * a);
        }
    }

    return 0;
}