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
    
    bool p = (x + 1 == 2);
    bool q = (x + y == z);
    
    cout << "p: " << p << endl;
    cout << "q: " << q << endl;
    
    bool dao = (!q) || p;
    bool phan_dao = (q) || (!p);
    bool nghich_dao = (p) || (!q);
    
    cout << " Dao (q => q): " << dao << endl;
    cout << "Phan dao (not q => not p): " << phan_dao << endl;
    cout << "Nghich dao (not p => not q): " << nghich_dao << endl;
    
    return 0;
}