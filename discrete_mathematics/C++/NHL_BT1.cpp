/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int main() {

    int x, y, z;
    cout << " nhap x: ";
    cin >> x;
    cout << " nhap y: ";
    cin >> y;
    cout << " nhap z: ";
    cin >> z;

    // (t) kiem tra menh de x + 1 = 2
    if (x + 1 == 2)
        cout << "(t) dung" << endl;
    else
        cout << "(t) sai" << endl;

    // (n) kiem tra menh de x + y = z
    if (x + y == z)
        cout << "(n) dung" << endl;
    else
        cout << "(n) sai" << endl;



    return 0;
}