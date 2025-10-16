#include <iostream>
using namespace std;

int main () {
    bool p, q, r ;
    bool x = (p || q) || r , z = p || (q || r);
    bool c = (p && q) && r , v = p && (q && r);
    bool b = p || (q && r) , n = (p || q) && (p || r);
    bool m = p && (q || r) , l = (p && q) || (p && r);
    bool d = !(p && q) , f = (! p) or (! q);
    bool g = !(p || q) , h = (! p) and (! q);
    bool ac = p || (p && q), ab = p && (p || q);

    for (int i = 0; i <= 1; ++i )
        for ( int j = 0; j <= 1; ++j )
            for (int k = 0; k <= 1; ++k )
                p = i, q = j, r = k;
    cout << "p and true <=> p " << (((p && true) && p) || ((!p && false) && !p) )   << '\n';
    cout << "p or false <=> p " << (((p || false) && p) || ((!p && true) && !p)) << '\n';
    cout << "p or true <=> T " << (((p || true) && true) || ((!p && false) && false) ) << '\n';
    cout << "p and false <=> false " << (((p && false) && false) || (!(p && false) && true) ) << '\n';
    cout << "p or p <=> p " << (((p || p) && p) || ((!p && !p) && !p) ) << '\n';
    cout << "p and p <=> p " << (((p && p) && p) || ((!p && !p) && !p) ) << '\n';
    cout << " not(not p) <=> p " << ((( ! ( !p) && p) || (!(!(!p)) && !p))) << '\n';
    cout << "p or q <=> q or p " << (((p || q) && (q || p)) || ((!p && !q) && (!q && !p))) << '\n';
    cout << "p and q <=> q and p " << (((p && q) && (q && p)) || ((!p && !q) && (!q && !p))) << '\n';
    cout << "p or (q or r) <=> (p or q) or r " << ((x && z) || (!x && !z)) << '\n';
    cout << "p and (q and r) <=> (p and q) and r " << ((c && v) || (!c && !v)) << '\n';
    cout << "p or (q and r) <=> (p or q) and (p or r) " << ((b && n) || (!b && !n)) << '\n';
    cout << "p and (q or r) <=> (p and q) or (p and r) " << ((m && l) || (!m && !l)) << '\n';
    cout << "not (p and q) <=> (not p) or (not q) " << ((d && f) || (!d && !f)) << '\n';
    cout << "not (p or q) <=> (not p) and (not q) " << ((g && h) || (!g && !h)) << '\n';
    cout << "p or (p and q) <=> p " << ((ac && p) || (!ac && !p)) << '\n';
    cout << "p and (p or q) <=> p " << ((ab && p) || (!ab && !p)) << '\n';
    cout << "p or not p <=> true " << (((p || !p) && true) || (!(p || !p) && false)) << '\n';
    cout << "p and not p <=> false " << (((p && !p) && false) || (!(p && !p) && true)) << '\n';
}