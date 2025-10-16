/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
int main() {
    int x, y, z;
    cout << "Nhap so x: ";
    cin >> x;
    cout << "Nhap so y: ";
    cin >> y;
    cout << "Nhap so z: ";
    cin >> z;
    // (1a):
    if (x + 1 == 2)
      cout << "true" << endl;
    else 
      cout << "false" << endl;
    // (1b):
    if (x + y == z)
      cout << "true" << endl;
    else
      cout << "false" << endl;
      
    return 0;
}