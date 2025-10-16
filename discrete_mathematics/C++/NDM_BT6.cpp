#include <iostream>
using namespace std;

int main() {
    bool p, q, r, ans;
    cout << boolalpha;

    // 1. p => q <=> !p or q
    ans = true;
    p = false; q = false; if ((!(p) || q) != (!p || q)) ans = false;
    p = false; q = true;  if ((!(p) || q) != (!p || q)) ans = false;
    p = true;  q = false; if ((!(p) || q) != (!p || q)) ans = false;
    p = true;  q = true;  if ((!(p) || q) != (!p || q)) ans = false;
    cout << ans << "\n";

    // 2. p => q <=> !q => !p
    ans = true;
    p = false; q = false; if ((!(p) || q) != (!(q) || !(p))) ans = false;
    p = false; q = true;  if ((!(p) || q) != (!(q) || !(p))) ans = false;
    p = true;  q = false; if ((!(p) || q) != (!(q) || !(p))) ans = false;
    p = true;  q = true;  if ((!(p) || q) != (!(q) || !(p))) ans = false;
    cout << ans << "\n";

    // 3. p or q <=> !p => q
    ans = true;
    p = false; q = false; if ((p || q) != ((!(p)) || q)) ans = false;
    p = false; q = true;  if ((p || q) != ((!(p)) || q)) ans = false;
    p = true;  q = false; if ((p || q) != ((!(p)) || q)) ans = false;
    p = true;  q = true;  if ((p || q) != ((!(p)) || q)) ans = false;
    cout << ans << "\n";

    // 4. p and q <=> !(p => !q)
    ans = true;
    p = false; q = false; if ((p && q) != (!(!(p) || !(q)))) ans = false;
    p = false; q = true;  if ((p && q) != (!(!(p) || !(q)))) ans = false;
    p = true;  q = false; if ((p && q) != (!(!(p) || !(q)))) ans = false;
    p = true;  q = true;  if ((p && q) != (!(!(p) || !(q)))) ans = false;
    cout << ans << "\n";

    // 5. !(p => q) <=> p and !q
    ans = true;
    p = false; q = false; if ((!(!(p) || q)) != (p && !q)) ans = false;
    p = false; q = true;  if ((!(!(p) || q)) != (p && !q)) ans = false;
    p = true;  q = false; if ((!(!(p) || q)) != (p && !q)) ans = false;
    p = true;  q = true;  if ((!(!(p) || q)) != (p && !q)) ans = false;
    cout << ans << "\n";

    // 6. (p => q) and (p => r) <=> p => (q and r)
    ans = true;
    p = false; q = false; r = false; if (((!p || q) && (!p || r)) != (!p || (q && r))) ans = false;
    p = false; q = false; r = true;  if (((!p || q) && (!p || r)) != (!p || (q && r))) ans = false;
    p = false; q = true;  r = false; if (((!p || q) && (!p || r)) != (!p || (q && r))) ans = false;
    p = false; q = true;  r = true;  if (((!p || q) && (!p || r)) != (!p || (q && r))) ans = false;
    p = true;  q = false; r = false; if (((!p || q) && (!p || r)) != (!p || (q && r))) ans = false;
    p = true;  q = false; r = true;  if (((!p || q) && (!p || r)) != (!p || (q && r))) ans = false;
    p = true;  q = true;  r = false; if (((!p || q) && (!p || r)) != (!p || (q && r))) ans = false;
    p = true;  q = true;  r = true;  if (((!p || q) && (!p || r)) != (!p || (q && r))) ans = false;
    cout << ans << "\n";

    // 7. (p => r) and (q => r) <=> (p or q) => r
    ans = true;
    p = false; q = false; r = false; if (((!p || r) && (!q || r)) != (!(p || q) || r)) ans = false;
    p = false; q = false; r = true;  if (((!p || r) && (!q || r)) != (!(p || q) || r)) ans = false;
    p = false; q = true;  r = false; if (((!p || r) && (!q || r)) != (!(p || q) || r)) ans = false;
    p = false; q = true;  r = true;  if (((!p || r) && (!q || r)) != (!(p || q) || r)) ans = false;
    p = true;  q = false; r = false; if (((!p || r) && (!q || r)) != (!(p || q) || r)) ans = false;
    p = true;  q = false; r = true;  if (((!p || r) && (!q || r)) != (!(p || q) || r)) ans = false;
    p = true;  q = true;  r = false; if (((!p || r) && (!q || r)) != (!(p || q) || r)) ans = false;
    p = true;  q = true;  r = true;  if (((!p || r) && (!q || r)) != (!(p || q) || r)) ans = false;
    cout << ans << "\n";

    // 8. (p => q) or (p => r) <=> p => (q or r)
    ans = true;
    p = false; q = false; r = false; if (((!p || q) || (!p || r)) != (!p || (q || r))) ans = false;
    p = false; q = false; r = true;  if (((!p || q) || (!p || r)) != (!p || (q || r))) ans = false;
    p = false; q = true;  r = false; if (((!p || q) || (!p || r)) != (!p || (q || r))) ans = false;
    p = false; q = true;  r = true;  if (((!p || q) || (!p || r)) != (!p || (q || r))) ans = false;
    p = true;  q = false; r = false; if (((!p || q) || (!p || r)) != (!p || (q || r))) ans = false;
    p = true;  q = false; r = true;  if (((!p || q) || (!p || r)) != (!p || (q || r))) ans = false;
    p = true;  q = true;  r = false; if (((!p || q) || (!p || r)) != (!p || (q || r))) ans = false;
    p = true;  q = true;  r = true;  if (((!p || q) || (!p || r)) != (!p || (q || r))) ans = false;
    cout << ans << "\n";

    // 9. (p => r) or (q => r) <=> (p and q) => r
    ans = true;
    p = false; q = false; r = false; if (((!p || r) || (!q || r)) != (!(p && q) || r)) ans = false;
    p = false; q = false; r = true;  if (((!p || r) || (!q || r)) != (!(p && q) || r)) ans = false;
    p = false; q = true;  r = false; if (((!p || r) || (!q || r)) != (!(p && q) || r)) ans = false;
    p = false; q = true;  r = true;  if (((!p || r) || (!q || r)) != (!(p && q) || r)) ans = false;
    p = true;  q = false; r = false; if (((!p || r) || (!q || r)) != (!(p && q) || r)) ans = false;
    p = true;  q = false; r = true;  if (((!p || r) || (!q || r)) != (!(p && q) || r)) ans = false;
    p = true;  q = true;  r = false; if (((!p || r) || (!q || r)) != (!(p && q) || r)) ans = false;
    p = true;  q = true;  r = true;  if (((!p || r) || (!q || r)) != (!(p && q) || r)) ans = false;
    cout << ans << "\n";

    // 10. p <=> q <=> (p => q) and (q => p)
    ans = true;
    p = false; q = false; if ((p == q) != ((!(p) || q) && (!(q) || p))) ans = false;
    p = false; q = true;  if ((p == q) != ((!(p) || q) && (!(q) || p))) ans = false;
    p = true;  q = false; if ((p == q) != ((!(p) || q) && (!(q) || p))) ans = false;
    p = true;  q = true;  if ((p == q) != ((!(p) || q) && (!(q) || p))) ans = false;
    cout << ans << "\n";

    // 11. p <=> q <=> !p <=> !q
    ans = true;
    p = false; q = false; if ((p == q) != ((!p) == (!q))) ans = false;
    p = false; q = true;  if ((p == q) != ((!p) == (!q))) ans = false;
    p = true;  q = false; if ((p == q) != ((!p) == (!q))) ans = false;
    p = true;  q = true;  if ((p == q) != ((!p) == (!q))) ans = false;
    cout << ans << "\n";

    // 12. p <=> q <=> (p and q) or (!p and !q)
    ans = true;
    p = false; q = false; if ((p == q) != ((p && q) || (!p && !q))) ans = false;
    p = false; q = true;  if ((p == q) != ((p && q) || (!p && !q))) ans = false;
    p = true;  q = false; if ((p == q) != ((p && q) || (!p && !q))) ans = false;
    p = true;  q = true;  if ((p == q) != ((p && q) || (!p && !q))) ans = false;
    cout << ans << "\n";

    // 13. !(p <=> q) <=> (p <=> !q)
    ans = true;
    p = false; q = false; if ((!(p == q)) != (p == !q)) ans = false;
    p = false; q = true;  if ((!(p == q)) != (p == !q)) ans = false;
    p = true;  q = false; if ((!(p == q)) != (p == !q)) ans = false;
    p = true;  q = true;  if ((!(p == q)) != (p == !q)) ans = false;
    cout << ans << "\n";

    return 0;
}