#include <iostream>
using namespace std;

int main() {
bool p, q, r;
bool ans = true;
cout << "Problem 6\n";
for (int i = 0; i <= 1; ++i) {
for (int j = 0; j <= 1; ++j) {
for (int k = 0; k <= 1; ++k) {
p = i; q = j; r = k;
// (p -> q) && (p -> r)  <=>  p -> (q && r)
bool left = ((!p || q) && (!p || r));
bool right = (!p || (q && r));
if (left != right) ans = false;
}
}
}
cout << "(p -> q) && (p -> r) == p -> (q && r): " << ans << endl;
}