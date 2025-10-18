#include <iostream>
using namespace std;

int main(){
    bool p, q, p_imply_q, j, i, k, r, ans = true;
	p = false, q = false , r = false;
    for (int i = 0; i <= 1; ++i)
            for (int j = 0; j <= 1; ++j) 
                for (int k = 0; k <= 1; ++k){ 
                    p = i;
                    q = j;
                    r = k;
    // Identity laws
                    if ((p && true) != p) ans = false;
    cout << "p and true == p: " << ans << endl;
                    if ((p || false) != p) ans = false;
    cout << "p or false == p: " << ans << endl; 
    // Domination laws
                    if ((p || true) != true) ans = false;
    cout << "p || true == true: " << ans << endl;
                    if ((p && false) != false) ans = false;
    cout << "  p && false == false: " << ans << endl;  
    // Idenmpotent laws 
                    if ((p || p) != p) ans = false;
    cout << "  p || p == p: " << ans << endl;
                    if ((p && p) != p) ans = false;
    cout << "  p && p == p: " << ans << endl;
    // Double negation law
                    if ((!(!p)) != p) ans = false;
     cout << "  !(!p) == p: " << ans << endl;
    // Commutative laws
                    if ((p || q) != (q || p)) ans = false;
    cout << "  p || q == q || p: " << ans << endl;
                    if ((p && q) != (q && p)) ans = false;
    cout << "  p && q == q && p: " << ans << endl;
    // Associative laws
                    if (((p || q) || r) != (p || (q || r))) ans = false;
    cout << "  (p || q) || r == p || (q || r): " << ans << endl;
                    if (((p && q) && r) != (p && (q && r))) ans = false;
    
    cout << "  (p || q) || r == p || (q || r): " << ans << endl;
    // Distributive laws
                    if ((p || (q && r)) != ((p || q) && (p || r))) ans = false;
    cout << "  p || (q && r) == (p || q) && (p || r): " << ans << endl;
                    if ((p && (q || r)) != ((p && q) || (p && r))) ans = false;
    cout << "  p && (q || r) == (p && q) || (p && r): " << ans << endl;
    // De Morgan`s laws
                    if (!(p && q) != ((!p) || (!q))) ans = false;
    cout << "  !(p && q) == !p || !q: " << ans << endl;
                    if (!(p || q) != ((!p) && (!q))) ans = false;
     cout << "  !(p || q) == !p && !q: " << ans << endl;
    // Absorption laws
                    if ((p || (p && q)) != p) ans = false;
    cout << "  p || (p && q) == p: " << ans << endl;
                    if ((p && (p || q)) != p) ans = false;
    cout << "  p && (p || q) == p: " << ans << endl;
    // Negation laws
                    if ((p || !p) != true) ans = false;
    cout << "  p || !p == true : " << ans << endl;
                    if ((p && !p) != false) ans = false;
    cout << "  p && !p == false: " << ans << endl;
            }
}