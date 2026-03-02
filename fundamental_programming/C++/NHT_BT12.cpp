/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, m;
    long long S = 0;
    
    cout << "nhap n= ";
    cin >> n;
    cout << "nhap m= ";
    cin >> m;
    
    for (int i = 1; i <= n; i++){
        S += pow(i, m);
    }
    
    cout << "Sm = " << S;
    return 0;
}