/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
int main()
{
    bool p, q, p_imply_q , i, j, k, r, ans = true;
    //identity laws
    for (int i = 0 ; i <= 1 ; ++i) {
        p = i;
        if (p && true != p) ans = false;
        if ((p || false) != p) ans = false;
    }
    cout << "p and true ~ p is " << ans << endl;
    cout << "p or false ~ p is " << ans << endl;

    //domination laws
    for (int i = 0 ; i <= 1 ; ++i) {
        p = i;
        if ((p || true) != true) ans = false;
        if ((p && false) != false) ans = false;
    }
    cout << "p or true ~ p is " << ans << endl;
    cout << "p and false ~ p is " << ans << endl;
    //idempotent laws
    for (int i = 0 ; i <= 1 ; ++i) {
        p = i;
        if ((p || p) != p) ans = false;
        if ((p && p) != p) ans = false;
    }
    cout << "p or p ~ p is " << ans << endl;
    cout << "p and p ~ p is " << ans << endl;
    //double negation law
    for (int i = 0 ; i <= 1 ; ++i) {
        p = i;
        if (!(!p) != p) ans = false;
    }
    cout << "not(not p) ~ p is " << ans << endl;
    //commutative laws
    for (int i = 0 ; i <= 1 ; ++i)
        for (int j = 0 ; j <= 1 ; ++j) {
            p = i;
            q = j;
            if ((p || q) != (q || p)) ans = false;
            if ((p && q) != (q && p)) ans = false;
        }
    cout << "p or q ~ q or p is " << ans << endl;
    cout << "p and q ~ q and p is " << ans << endl;
    //associative laws
    for (int i = 0 ; i <= 1 ; ++i)
        for (int j = 0 ; j <= 1 ; ++j)
            for (int k = 0 ; k <= 1 ; ++k) {
                p = i;
                q = j;
                r = k;
                if (((p || q) || r) != (p || (q || r))) ans = false;
                if (((p && q) && r) != (p && (q && r))) ans = false;
            }
    cout << "(p or q) or r ~ p or (q or r) is " << ans << endl;
    cout << "(p and q) and r ~ p and (q and r) is " << ans << endl;
    //distributive laws
    for (int i = 0 ; i <= 1 ; ++i)
        for (int j = 0 ; j <= 1 ; ++j)
            for (int k = 0 ; k <= 1 ; ++k) {
                p = i;
                q = j;
                r = k;
                if ((p || (q && r)) != ((p || q) && (p || r))) ans = false;
                if (((p && q) && r) != (p && (q && r))) ans = false;
            }
    cout << "p or (q and r) ~ (p or q) and (q or r) is " << ans << endl;
    cout << "p and (q and r) ~ (p and q) or (q and r) is " << ans << endl;
    //de morgan's laws
    for (int i = 0 ; i <= 1 ; ++i)
        for (int j = 0 ; j <= 1 ; ++j) {
            p = i;
            q = j;
            if (!(p && q) != (!p || !q)) ans = false;
            if (!(p || q) != (!p && !q)) ans = false;
        }
    cout << "not(p and q) ~ !p or !q is " << ans << endl;
    cout << "not(p or q) ~ !p and !q is " << ans << endl;
    //absorption laws
    for (int i = 0 ; i <= 1 ; ++i)
        for (int j = 0 ; j <= 1 ; ++j) {
            p = i;
            q = j;
            if ((p || (p && q)) != p) ans = false;
            if ((p && (p || q)) != p) ans = false;
        }
    cout << "p or (p and q) ~ p is " << ans << endl;
    cout << "p and (p or q) ~ p is " << ans << endl;
    //negation laws
    for (int i = 0 ; i <= 1 ; ++i) {
        p = i;
        if ((p || !p) != true) ans = false;
        if ((p && !p) != false) ans = false;
    }
    cout << "p or not p ~ p is " << ans << endl;
    cout << "p and not p ~ p is " << ans << endl;

    return 0;
}