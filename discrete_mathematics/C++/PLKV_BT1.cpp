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
    cout << "nhap y: ";
    cin >> y;
    cout << "nhap z: ";
    cin >> z;
    
    if (x + 1 == 2)
      cout << "true" << endl;
    else
      cout << "False" << endl;
    if (x + y == z)
      cout << "true" << endl;
    else
      cout << "False" << endl;
    
    return 0;
}