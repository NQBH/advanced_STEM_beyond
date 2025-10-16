/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
int main() {
    int x, y, z;
    cout << "nhập x: ";
    cin >> x;
    cout << "nhập y: ";
    cin >> y;
    cout << "nhập z: ";
    cin >> z;
    if (1 + x == 2) // đảo
        cout << "p true" << endl;
    else
        cout << "p false" << endl;
    if ((-x + (-1) == 2)) // phản đảo
        cout << "p true" << endl;
    else
        cout << "p false" << endl;
    if ((-1 + (-x) == 2)) // nghịch đảo
        cout << "p true" << endl;
    else
        cout << "p false" << endl;
    return 1;
}

