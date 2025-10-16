/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    // (a): x + 1 = 2
    cout << "(a) Goc: " << (x + 1 == 2) << endl;
    cout << "(a) Dao: " << (2 == x + 1) << endl;
    cout << "(a) Phan Dao: " << ((x + 1 != 2) == (2 != x + 1 )) << endl;
    cout << "(a) Nghich Dao: " << ((x != 1) == (x + 1 != 2)) << endl;
    // (b): x + y = z
    cout << "(b) Goc: " << (x + y == z) << endl;
    cout << "(b) Dao: " << (z == x + y) << endl;
    cout << "(b) Phan Dao: " << ((x + y != z) == (z != x + y )) << endl;
    cout << "(b) Nghich Dao: " << (!(x + y == z)) << endl;
}