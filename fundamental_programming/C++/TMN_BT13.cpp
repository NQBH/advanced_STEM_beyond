#include <iostream>
using namespace std;

int main() {
    int n, m;
    long long M;
    cin >> n >> m >> M;

long long Sm = 0;

    for (int i = 1; i <= n; ++i) {
   long long term = 1;

  for (int j = 0; j < m; ++j) {
      term *= i;   }

   if (Sm + term > M) {
       break;
}
  Sm += term;
}

cout << Sm;
   return 0;
}