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
    
    bool p = (x + 1 == 2);
    bool q = (x + 1 == 2);
    
    cout << "p: " << p << endl;
    cout << "q: " << q << endl;
     
    cout << "p and q: " << (p && q) <<endl;
    cout << "p or q: " << (p || q) << endl;
    cout << "not p: " << (!p) << endl;
    cout << "not q: " << (!q) << endl;
    cout << "p xor q: " << (p ^ q) << endl;
     
    return 0;
}