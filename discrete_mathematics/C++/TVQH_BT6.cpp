#include <iostream>
using namespace std;
int main() {
    bool p = true, q = false, r = true;
    bool p_imp_q = (!p || q), q_imp_p = (!q || p), p_bicond_q = (p_imp_q && q_imp_p);
    cout << "7.1. p -> q  <==>  !p v q: " << (p_imp_q == (!p || q)) << endl;
    cout << "7.2. p -> q  <==>  !q -> !p: " << (p_imp_q == (!(!q) || !p)) << endl;
    cout << "7.3. p v q  <==>  !p -> q: " << ((p || q) == (!p || q)) << endl;
    cout << "7.4. p ^ q  <==>  !(p -> !q): " << ((p && q) == !((!p) || !q)) << endl; 
    cout << "7.5. !(p -> q) <==> p ^ !q: " << (!(p_imp_q) == (p && !q)) << endl;
    cout << "7.6. (p -> q) ^ (p -> r) <==> p -> (q ^ r): " << ((p_imp_q && (!p || r)) == (!p || (q && r))) << endl;
    cout << "7.7. (p -> r) ^ (q -> r) <==> (p v q) -> r: " << (((!p || r) && (!q || r)) == (!(p || q) || r)) << endl;
    cout << "7.8. (p -> q) v (p -> r) <==> p -> (q v r): " << ((p_imp_q || (!p || r)) == (!p || (q || r))) << endl;
    cout << "7.9. (p -> r) v (q -> r) <==> (p ^ q) -> r: " << (((!p || r) || (!q || r)) == (!(p && q) || r)) << endl;
    bool notp_bicond_notq = ((!(!p) || !q) && (!!q || !p));
    cout << "8.1. p <-> q  <==>  (p -> q) ^ (q -> p): " << (p_bicond_q == (p_imp_q && q_imp_p)) << endl;
    cout << "8.2. p <-> q  <==>  !p <-> !q: " << (p_bicond_q == notp_bicond_notq) << endl;
    cout << "8.3. p <-> q  <==>  (p ^ q) v (!p ^ !q): " << (p_bicond_q == ((p && q) || (!p && !q))) << endl;
     bool p_bicond_notq = ((!p || !q) && (!!q || p)); // p <-> !q
    cout << "8.4. !(p <-> q) <==> p <-> !q: " << (!(p_bicond_q) == p_bicond_notq) << endl;
    return 0;
}