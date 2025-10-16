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
    cin >> n;
    
    if (pow(2, n) >= 100)
        cout << "true";
    else
        cout << "false";
        
    return 0;
}