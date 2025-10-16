/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double n;
    cout << "Nhap so thuc n: ";
    cin >> n;
    
    if (pow(2, n) >= 100)
        cout << "True" << endl;
    else
        cout << "S" << endl;
    
    return 0;
}