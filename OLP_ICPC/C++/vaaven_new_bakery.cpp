#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;
        if (b <= a) {
            cout << n * a << endl;
        } else {
            long long k = min(b &mdash; a + 1, n);
            cout << (b &mdash; k + 1) * n + k * (k &mdash; 1) / 2 << endl;
        }
    }
}
/*
(base) nqbh@nqbh:~/advanced_STEM_beyond/OLP_ICPC/C++$ g++ -O2 -Wall vaaven_new_bakery.cpp -o vaaven_new_bakery
vaaven_new_bakery.cpp: In function ‘int main()’:
vaaven_new_bakery.cpp:13:34: error: ‘mdash’ was not declared in this scope
   13 |             long long k = min(b &mdash; a + 1, n);
      |                                  ^~~~~
vaaven_new_bakery.cpp:13:43: warning: left operand of comma operator has no effect [-Wunused-value]
   13 |             long long k = min(b &mdash; a + 1, n);
      |                                         ~~^~~
vaaven_new_bakery.cpp:13:49: error: expected ‘;’ before ‘)’ token
   13 |             long long k = min(b &mdash; a + 1, n);
      |                                                 ^
      |                                                 ;
vaaven_new_bakery.cpp:13:50: warning: right operand of comma operator has no effect [-Wunused-value]
   13 |             long long k = min(b &mdash; a + 1, n);
      |                                                  ^
vaaven_new_bakery.cpp:14:30: error: expected ‘)’ before ‘;’ token
   14 |             cout << (b &mdash; k + 1) * n + k * (k &mdash; 1) / 2 << endl;
      |                     ~        ^
      |                              )
vaaven_new_bakery.cpp:14:37: error: expected ‘;’ before ‘)’ token
   14 |             cout << (b &mdash; k + 1) * n + k * (k &mdash; 1) / 2 << endl;
      |                                     ^
      |                                     ;
vaaven_new_bakery.cpp:14:34: warning: statement has no effect [-Wunused-value]
   14 |             cout << (b &mdash; k + 1) * n + k * (k &mdash; 1) / 2 << endl;
      |                                ~~^~~
vaaven_new_bakery.cpp:14:61: error: expected ‘;’ before ‘)’ token
   14 |        cout << (b &mdash; k + 1) * n + k * (k &mdash; 1) / 2 << endl;
      |                                                        ^
      |                                                        ;
vaaven_new_bakery.cpp:14:60: warning: statement has no effect [-Wunused-value]
   14 |         cout << (b &mdash; k + 1) * n + k * (k &mdash; 1) / 2 << endl;
      |                                                        ^

(base) nqbh@nqbh:~/advanced_STEM_beyond/OLP_ICPC/C++$
*/