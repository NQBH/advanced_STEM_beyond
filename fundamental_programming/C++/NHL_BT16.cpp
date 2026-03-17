#include <cmath>
#include <iostream>
using namespace std;
double f(double a , double b , double c , double x) {

  return a * x * x + b * x + c;
}
double F(int n, double alpha, double a, double b, double c) {
  double a_i = alpha;
  for (int i = 0; i < n; i++)
  {
    a_i = f(a, b, c, a_i);
  }
  return a_i;
}
int main()
{
  int n;
  double a, b, c, x, alpha;
  cout << "nhập n và alpha: ";
  cin >> n >> alpha;
  cout << "nhập a,b,c: ";
  cin >> a >> b >> c;
  cout << "giá trị của a_" << n << ": " << F(n, alpha, a, b, c);
}