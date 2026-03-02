#include <iostream>
#include <cmath>
using namespace std;

int main() {
   // problem 1
   int a,n;
   cin >> a >> n;
   cout << "nhap a:";
   cout << "nhap n:";

   cout << "a << n = " << (a << n) << endl;
   cout << " a * 2^n = " << (a * pow (2, n)) << endl;
   return 0;
}
