#include <iostream>
using namespace std;
int main() {
    bool p, q, r, ans = true;
    // Identity laws
    cout << "Identity laws" << endl;
    for (int i = 0 ; i <= 1 ; ++i) {
        p = i;
        if ((p && true) != p) ans = false;
        if ((p || false) != p) ans = false;
    }
    cout << "p and T ~  p is " << ans << endl;
    cout << "p or F ~  p is " << ans << endl;

    // Domination laws
    cout << "Domination laws" << endl;
    for (int i = 0 ; i <= 1 ; ++i) {
        p = i;
        if ((p || true) != true) ans = false;
        if ((p && !true) != !(true)) ans = false;
    }
    cout << "p or T ~  T is " << ans << endl;
    cout << "p and F  ~  F is " << ans << endl;

    //Idempotent laws
    cout << "Idempotent laws" << endl;
    for (int i = 0 ; i <= 1 ; ++i) {
        p = i;
        if ((p || p) != p) ans = false;
        if ((p || p) != p) ans = false;
    }
    cout << "p  or p ~  p is " << ans << endl;
    cout << "p  and  p ~  p is " << ans << endl;

    //Double negation law
    cout << "Double negation law" << endl;
    for (int i = 0 ; i <= 1 ; ++i) {
        p = i;
        if (!(!(p)) != p) ans = false;
    }
    cout << "not (not p) ~  p is " << ans << endl;

    //Commutative laws
    cout << "Commutative laws" << endl;
    for (int i = 0 ; i <= 1 ; ++i) {
        for (int j = 0 ; j <= 1; ++j) {
            p = i;
            q = j;
            if ((p || q) != (q || p)) ans = false;
            if ((p && q) != (q && p)) ans = false;
        }
    }
    cout << "p or q ~ q or p is " << ans << endl;
    cout << "p and q ~ q and p is " << ans << endl;

    // Associative laws
    cout << "Associative laws" << endl;
    for (int i = 0 ; i <= 1; ++i) {
        for (int j = 0 ; j <= 1 ; ++j) {
            for (int k = 0 ; k <= 1 ; ++k) {
                p = i;
                q = j;
                r = k;
                if (((p || q) || r) != (p || (q || r))) ans = false;
                if (((p && q) && r) != (p && (q && r))) ans = false;
            }
        }
    }
    cout << "(p or q) or r ~ p or (q or r) is " << ans << endl;
    cout << "(p and q) and r ~ p and (q and r) is " << ans << endl;

    // Distributive laws
    cout << "Distributive laws" << endl;
    for (int i = 0 ; i <= 1; ++i) {
        for (int j = 0 ; j <= 1 ; ++j) {
            for (int k = 0 ; k <= 1 ; ++k) {
                p = i;
                q = j;
                r = k;
                if ((p || (q && r)) != ((p || r) && (p || q))) ans = false;
                if ((p && (q || r)) != ((p && r) || (p && q))) ans = false;
            }
        }
    }
    cout << "p or (q and r) != (p or r) and (p or q) is " << ans << endl;
    cout << "p and (q or r) != (p and r) or (p and q) is " << ans << endl;

    //De Morgan's laws
    cout << "De Morgan's laws" << endl;
    for (int i = 0 ; i <= 1 ; ++i) {
        for (int j = 0 ; j <= 1 ; ++j) {
            if (!(p && q) != (!p || !q)) ans = false;
            if (!(p || q) != (!p && !q)) ans = false;
        }
    }
    cout << "not (p and q) ~ (not p) and (not q)" << ans << endl;
    cout << "not (p or q) ~  (not p) and (not q)" << ans << endl;

    //Absorption laws
    cout << "Absorption laws" << endl;
    for (int i = 0; i <= 1 ; ++i) {
        for (int j = 0; j <= 1; ++j) {
            if ((p || (p && q)) != p ) ans = false;
            if ((p && (p || q)) != p) ans = false;
        }
    }
    cout << "p or (p and q) ~ p is " << ans << endl;
    cout << "p and (p or q) ~ p is " << ans << endl;

    // Negation laws
    cout << "Negation laws" << endl;
    for (int i = 0; i <= 1; ++i) {
        if ((p || !p) != true) ans = false;
        if ((p && !p) != false) ans = false;
    }
    cout << "p or (not p) ~ true is " << ans << endl;
    cout << "p and (not p) ~ false is " << ans << endl;
    return 1;
}