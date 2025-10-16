/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int x, y, z;

    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap y: ";
    cin >> y;
    cout << "Nhap z: ";
    cin >> z;

    if (x + 1 == 2 )
        cout << "True" << endl;
    else
        cout << "FALSE" << endl;

    if (x + y == z)
        cout << "True" << endl;
    else
        cout << "FALSE" << endl;

    return 0;
}