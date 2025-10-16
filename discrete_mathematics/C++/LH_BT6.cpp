#include <iostream>
using namespace std;

int main() {
     bool p, q, p_imply_q, j, i, k, r, ans = true;
     p = false, q = false , r = false;
     for (int i = 0; i <= 1; ++i)
          for (int j = 0; j <= 1; ++j)
               for (int k = 0; k <= 1; ++k) {
                    p = i;
                    q = j;
                    r = k;
                    // Table 7
                    cout << "  TABLE 7 " << endl;
                    cout << " p -> q == !p or q : "
                         << (((!p) || q) == ((!p) || q)) << endl;

                    cout << " p -> q == !q -> !p : "
                         << (((!p) || q) == ((!q) || (!p))) << endl;

                    cout << " p or q == !p -> q : "
                         << ((p || q) == ((!p) || q)) << endl;

                    cout << " p and q == !(p -> !q) : "
                         << ((p && q) == (!((!p) || (!q)))) << endl;

                    cout << " !(p -> q) == p and !q : "
                         << ((!((!p) || q)) == (p && (!q))) << endl;

                    cout << " (p -> q) and (p -> r) == p -> (q and r) : "
                         << ((((!p) || q) && ((!p) || r)) == ((!p) || (q && r))) << endl;

                    cout << " (p -> r) and (q -> r) == (p or q) -> r : "
                         << ((((!p) || r) && ((!q) || r)) == ((!(p || q)) || r)) << endl;

                    cout << " (p -> q) or (p -> r) == p -> (q or r) : "
                         << ((((!p) || q) || ((!p) || r)) == ((!p) || (q || r))) << endl;
                    cout << " (p -> r) or (q -> r) == (p and q) -> r : "
                         << ((((!p) || r) || ((!q) || r)) == ((!(p && q)) || r)) << endl;
                    // Table 8
                    cout << "  TABLE 8 " << endl;
                    cout << " p <-> q == (p -> q) and (q -> p) : "
                         << ((p == q) == (((!p) || q) && ((!q) || p))) << endl;

                    cout << " p <-> q == !p <-> !q : "
                         << ((p == q) == ((!p) == (!q))) << endl;

                    cout << " p <-> q == (p and q) or (!p and !q) : "
                         << ((p == q) == ((p && q) || ((!p) && (!q)))) << endl;

                    cout << " !(p <-> q) == p <-> !q : "
                         << ((!(p == q)) == (p == (!q))) << endl;
               }
}



