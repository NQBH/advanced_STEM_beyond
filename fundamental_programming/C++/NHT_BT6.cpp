/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b;
    cin >> a >> b;

    if (a == 0) {
        if (b == 0)
            cout << "Phuong trinh vo so nghiem";
        else
            cout << "Phuong trinh vo nghiem";
    } else {
        cout << "x = " << -b / a;
    }

    return 0;
}