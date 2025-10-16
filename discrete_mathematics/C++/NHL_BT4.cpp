/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath> // cần cho hàm pow
using namespace std;

int main() {
    double n;  // đổi từ int -> double để đúng đề bài "số thực"
    cout << "Nhập n : ";
    cin >> n;

    double result = pow(2.0, n);  // dùng 2.0 để đảm bảo kết quả là số thực

    if (result >= 100)
        cout << "Bất đẳng thức đúng (Đ)" << endl;
    else
        cout << "Bất đẳng thức sai (S)" << endl;

    return 0;
}