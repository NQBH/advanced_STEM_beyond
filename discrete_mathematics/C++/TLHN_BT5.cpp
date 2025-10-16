#include <iostream>
using namespace std;


int main() {
    bool p, q, p_imply_q, r, ans = true;
    int i, j, k;

    // Identity laws


    for (i = 0; i <= 1; ++i) {

        p = i;

        if ((p && true) != p) ans = false;

        if ((p || false) != p) ans = false;
    }


    cout << "p and true ~ p là " << ans << endl;
    cout << "p or false ~ p là " << ans << endl;



    // Domination laws

    for (i = 0; i <= 1; ++i) {

        p = i;


        if ((p || true) != true) ans = false;

        if ((p && false) != false) ans = false;

    }
    cout << "p or true ~ true là " << ans << endl;
    cout << "p and false ~ false là " << ans << endl;


    // Idempotent laws

    for (i = 0; i <= 1; ++i) {

        p = i;

        if ((p || p) != p) ans = false;

        if ((p && p) != p) ans = false;

    }

    cout << "p or p ~ p là " << ans << endl;
    cout << "p and p ~ p là " << ans << endl;


    //Double negation law
    for (i = 0; i <= 1; ++i) {
        p = i;

        if (!(!p) != p) ans = false;
    }
    cout << "not(not p) ~ p là " << ans << endl;




    // Commutative laws

    for (i = 0; i <= 1; ++i)

        for (j = 0; j <= 1; ++j) {

            p = i;
            q = j;

            if ((p || q) != (q || p)) ans = false;


            if ((p && q) != (q && p)) ans = false;
        }


    cout << "p or q ~ q or p là " << ans << endl;
    cout << "p and q ~ q and p là " << ans << endl;




    // Associative laws

    for (i = 0; i <= 1; ++i)

        for (j = 0; j <= 1; ++j)

            for (k = 0; k <= 1; ++k) {

                p = i; q = j; r = k;
                if (((p || q) || r) != (p || (q || r))) ans = false;

                if (((p && q) && r) != (p && (q && r))) ans = false;
            }
    cout << "(p or q) or r ~ p or (q or r) là " << ans << endl;
    cout << "(p and q) and r ~ p and (q and r) là " << ans << endl;

    // Distributive laws

    for (i = 0; i <= 1; ++i)

        for (j = 0; j <= 1; ++j)

            for (k = 0; k <= 1; ++k) {

                p = i; q = j; r = k;

                if ((p || (q && r)) != ((p || q) && (p || r))) ans = false;

                if ((p && (q || r)) != ((p && q) || (p && r))) ans = false;

            }
    cout << "p or (q and r) ~ (p or q) and (p or r) là " << ans << endl;
    cout << "p and (q or r) ~ (p and q) or (p and r) là " << ans << endl;



    // De Morgan’s laws
    for (i = 0; i <= 1; ++i)
        for (j = 0; j <= 1; ++j) {
            p = i; q = j;
            if (!(p && q) != (!p || !q)) ans = false; // ¬(p ∧ q) ≡ ¬p ∨ ¬q
            if (!(p || q) != (!p && !q)) ans = false; // ¬(p ∨ q) ≡ ¬p ∧ ¬q
        }
    cout << "not(p and q) ~ not p or not q là " << ans << endl;
    cout << "not(p or q) ~ not p and not q là " << ans << endl;

    // Absorption laws
    for (i = 0; i <= 1; ++i)
        for (j = 0; j <= 1; ++j) {
            p = i; q = j;
            if ((p || (p && q)) != p) ans = false; // p ∨ (p ∧ q) ≡ p
            if ((p && (p || q)) != p) ans = false; // p ∧ (p ∨ q) ≡ p
        }
    cout << "p or (p and q) ~ p là " << ans << endl;
    cout << "p and (p or q) ~ p là " << ans << endl;

    // Negation laws
    for (i = 0; i <= 1; ++i) {
        p = i;
        if ((p || !p) != true) ans = false;  // p ∨ ¬p ≡ T
        if ((p && !p) != false) ans = false; // p ∧ ¬p ≡ F
    }
    cout << "p or not p ~ true là " << ans << endl;
    cout << "p and not p ~ false là " << ans << endl;

    return 0;
}
