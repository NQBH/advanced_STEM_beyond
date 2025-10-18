/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>  // Thư viện toán học để dùng pow()
using namespace std;

int main() {
    double n;

    
    cout << "Nhập n: ";
    cin >> n;
   
    double result = pow(2, n);

    if (result >= 100) {
        cout << "2^n >= 100: Đúng" << endl;
    } else {
        cout << "2^n >= 100: Sai" << endl;
    }

    cout << "Giá trị 2^n = " << result << endl;

    return 0;
}