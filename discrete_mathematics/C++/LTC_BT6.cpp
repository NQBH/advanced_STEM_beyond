#include <iostream>
using namespace std;

int main() {
    bool p, q, r;
    bool p_imply_q;
    
    cout << " CHECK TABLE 7 and 8 \n";
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            for (int k = 0; k <= 1; ++k) {
                p = i; q = j; r = k;
                
                // p ? q
                p_imply_q = (!p || q);

                cout << "\n--- p=" << p << ", q=" << q << ", r=" << r << " ---\n";

                // === TABLE 7 ===
                cout << " p ? q = ¬p ? q : " << (p_imply_q == (!p || q)) << endl;
                cout << " p ? q = ¬q ? ¬p : " << (p_imply_q == ((!q) || (!p))) << endl;
                cout << " p ? q = ¬p ? q : " << ((p || q) == (!p || q)) << endl;
                cout << " p ? q = ¬(p ? ¬q) : " << ((p && q) == (!(p && !q))) << endl;
                cout << " ¬(p ? q) = p ? ¬q : " << ((!p_imply_q) == (p && !q)) << endl;
                cout << " (p ? q) ? (p ? r) = p ? (q ? r) : " 
                     << ((p_imply_q && (!p || r)) == (!p || (q && r))) << endl;
                cout << " (p ? r) ? (q ? r) = (p ? q) ? r : "
                     << (((!p || r) && (!q || r)) == (!(p || q) || r)) << endl;
                cout << " (p ? q) ? (p ? r) = p ? (q ? r) : "
                     << ((p_imply_q || (!p || r)) == (!p || (q || r))) << endl;

                // === TABLE 8 ===
                cout << " p ? q = (p ? q) ? (q ? p) : "
                     << ((p == q) == ((!p || q) && (!q || p))) << endl;
                cout << " p ? q = ¬p ? ¬q : "
                     << ((p == q) == ((!p) == (!q))) << endl;
                cout << " p ? q = (p ? q) ? (¬p ? ¬q) : "
                     << ((p == q) == ((p && q) || (!p && !q))) << endl;
                cout << " ¬(p ? q) = p ? ¬q : "
                     << ((!(p == q)) == (p == !q)) << endl;
            }
        }
    }
    return 0;
}
