#include <iostream>
#include <cmath>
using namespace std;
int main() {
  cout << "1. double sqrt(double x)";
  double x , y ;
  cin >> x;
  if (x < 0)
    cout << "x không âm";
  else
    cout << sqrt(x) << '\n';

  cout << "2. double pow(double x, double y)";
  cin >> x >> y;
  if (x < 0)  cout << "x dương";
  else cout << pow(x, y) << '\n';

  cout << "3. double exp(double x)";
  cin >> x;
  if (x < 0)  cout << "x dương";
  else cout << exp(x) << '\n';

  cout << "4. double log(double x)";
  cin >> x;
  if (x < 0)  cout << "x dương";
  else cout << log(x) << '\n';

  cout << "5. double log10(double x)";
  cin >> x;
  if (x < 0)  cout << "x dương";
  else cout << log10(x) << '\n';

  cout << "6. int abs(int x)";
  cin >> x;
  if (x < 0)  cout << "x dương";
  else cout << abs(x) << '\n';

  cout << "7. long labs(long x)";
  cin >> x;
  if (x < 0)  cout << "x dương";
  else cout << labs(x) << '\n';

  cout << "8. double fabs(double x)";
  cin >> x;
  if (x < 0)  cout << "x dương";
  else cout << fabs(x) << '\n';

  cout << "9. double cos(double x)";
  cin >> x;
  if (x < 0)  cout << "x dương";
  else cout << cos(x) << '\n';

  cout << "10. double sin(double x)";
  cin >> x;
  if (x < 0) cout << "x dương";
  else cout << sin(x) << '\n';

  cout << "11. double tan(double x)";
  cin >> x;
  if (x < 0) cout << "x dương";
  else cout << tan(x) << '\n';

  cout << "15. double floor(double x)";
  cin >> x;
  cout << floor(x) << '\n';

  cout << "16. double ceil(double x)";
  cin >> x;
  cout << ceil(x) << '\n';
}