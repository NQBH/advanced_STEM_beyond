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

    for (int i = 0 ; i <= 1 ; ++i)
        for (int j = 0 ; j <= 1 ; ++j)
        {
            p = i;
            q = j;
            r = k;
        }
    //table 7
    if ((!p || q) != (!p || q)) ans = false;
    cout << "p -> q ~ not p or q is " << ans << endl;
    if ((!p || q) != (q || !p)) ans = false;
    cout << "p -> q ~ not q -> not p is  " << ans << endl;
    if ((p || q) != (!p || q)) ans = false;
    cout << "p or q ~ not q -> p is  " << ans << endl;
    if ((p && q) != (!(!p || !q))) ans = false;
    cout << "p and q ~ not (p -> not q) is  " << ans << endl;
    if ((!(!p || q)) != (p && !q)) ans = false;
    cout << "not (p -> q) ~ p and not q is  " << ans << endl;
    for (int r = 0; r <= 1; ++r)
        if (((!p || q) && (!p || r)) != (!p || (q && r))) ans = false;
    cout << "(p -> q) and ( p -> r) ~ p -> (q and r) is  " << ans << endl;
    if (((!p || r) && (!q || r)) != (!(p || q)) || r) ans = false;
    cout << "(p -> r) and ( q -> r) ~ (p or q) -> r is  " << ans << endl;
    if (((!p || q) || (!p || r)) != (!p || (q || r))) ans = false;
    cout << "(p -> q) or ( p -> r) ~ p -> (q or r) is  " << ans << endl;
    if (((!p || r) || (!q || r)) != (!(p && q)) || r) ans = false;
    cout << "(p -> r) or ( q -> r) ~ (p and q) -> r is  " << ans << endl;
    //table 8
    if ((p == q) != (!p || q) && (!q || p)) ans = false;
    cout << "p <-> q ~ (p -> q) and (q -> p) is " << ans << endl;
    if ((p == q) != (!p == !q)) ans = false;
    cout << "p <-> q ~ (not p <-> not q) is " << ans << endl;
    if ((p == q) != (p && q) || (!p && !q)) ans = false;
    cout << "p <-> q ~ (p and q) or (!p and not q) is " << ans << endl;
    if ((!(p == q)) != (p == !q)) ans = false;
    cout << "not (p <-> q) ~ p <-> not q is " << ans << endl;

    return 0;


}