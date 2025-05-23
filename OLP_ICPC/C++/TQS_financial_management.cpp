#include <bits/stdc++.h>
using namespace std;
int main()
{
   long double a,s=0;
   for (int i=0; i<12;i++) {
      cin >> a;
      s += a;
   }
   cout << "$" << round(s*(1.0/12)*100)/100;
}