#include<iostream>
#include<cmath>
using namespace std;
int main() {
   int a;
   cout << "Nhap a: ";
   cin >> a;
   int n;
   cout << "Nhap n: ";
   cin >> n;
   int shiftleft = a << n;
   cout << "a << n = " << shiftleft << endl;
   int multiply = a * pow(2, n);
   cout << "a * 2^n = " << multiply << endl;
   if (shiftleft == multiply)
      cout << "=> Chung minh: a << n = a * 2^n" << endl;
   else
      cout << "=> Khong bang nhau" << endl;
   int shiftright = a >> n;
   cout << "a >> n = " << shiftright << endl;
   int divide = a / pow(2, n);
   cout << "a / (2^n) =" << divide << endl;
   if (shiftright == divide)
      cout << "=> Chung minh: a >> n = a * 2^n" << endl;
   else
      cout << "Khong bang nhau" << endl;
}



