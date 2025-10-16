#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	bool p, q, r, ans;
	cout << boolalpha;

	// p and true <=> p
	ans = true;
	p = false;
	if ((p && true) != p) ans = false;
	p = true;
	if ((p && true) != p) ans = false;
	cout << ans << '\n';

	// p or false <=> p
	ans = true;
	p = false;
	if ((p || false) != p) ans = false;
	p = true;
	if ((p || false) != p) ans = false;
	cout << ans << '\n';

	// p or true <=> true
	ans = true;
	p = false;
	if ((p || true) != true) ans = false;
	p = true;
	if ((p || true) != true) ans = false;
	cout << ans << '\n';

	// p and false <=> false
	ans = true;
	p = false;
	if ((p && false) != false) ans = false;
	p = true;
	if ((p && false) != false) ans = false;
	cout << ans << '\n';

	// p or p <=> p
	ans = true;
	p = false;
	if ((p || p) != p) ans = false;
	p = true;
	if ((p || p) != p) ans = false;
	cout << ans << '\n';

	// p and p <=> p
	ans = true;
	p = false;
	if ((p && p) != p) ans = false;
	p = true;
	if ((p && p) != p) ans = false;
	cout << ans << '\n';

	// not (not p) <=> p
	ans = true;
	p = false;
	if ((!(!p)) != p) ans = false;
	p = true;
	if ((!(!p)) != p) ans = false;
	cout << ans << '\n';

	// p or q <=> q or p
	ans = true;
	p = false, q = false;
	if ((p || q) != (q || p)) ans = false;
	p = false, q = true;
	if ((p || q) != (q || p)) ans = false;
	p = true, q = false;
	if ((p || q) != (q || p)) ans = false;
	p = true, q = true;
	if ((p || q) != (q || p)) ans = false;
	cout << ans << '\n';

	// p and q <=> q and p
	ans = true;
	p = false, q = false;
	if ((p && q) != (q && p)) ans = false;
	p = false, q = true;
	if ((p && q) != (q && p)) ans = false;
	p = true, q = false;
	if ((p && q) != (q && p)) ans = false;
	p = true, q = true;
	if ((p && q) != (q && p)) ans = false;
	cout << ans << '\n';

	// not (p and q) <=> not p or not q
	ans = true;
	p = false, q = false;
	if ((!(p && q)) != ((!p) || (!q))) ans = false;
	p = false, q = true;
	if ((!(p && q)) != ((!p) || (!q))) ans = false;
	p = true, q = false;
	if ((!(p && q)) != ((!p) || (!q))) ans = false;
	p = true, q = true;
	if ((!(p && q)) != ((!p) || (!q))) ans = false;
	cout << ans << '\n';

	// not (p or q) <=> not p and not q
	ans = true;
	p = false, q = false;
	if ((!(p || q)) != ((!p) && (!q))) ans = false;
	p = false, q = true;
	if ((!(p || q)) != ((!p) && (!q))) ans = false;
	p = true, q = false;
	if ((!(p || q)) != ((!p) && (!q))) ans = false;
	p = true, q = true;
	if ((!(p || q)) != ((!p) && (!q))) ans = false;
	cout << ans << '\n';

	// p or (p and q) <=> p
	ans = true;
	p = false, q = false;
	if ((p || (p && q)) != p) ans = false;
	p = false, q = true;
	if ((p || (p && q)) != p) ans = false;
	p = true, q = false;
	if ((p || (p && q)) != p) ans = false;
	p = true, q = true;
	if ((p || (p && q)) != p) ans = false;
	cout << ans << '\n';

	// p and (p or q) <=> p
	ans = true;
	p = false, q = false;
	if ((p && (p || q)) != p) ans = false;
	p = false, q = true;
	if ((p && (p || q)) != p) ans = false;
	p = true, q = false;
	if ((p && (p || q)) != p) ans = false;
	p = true, q = true;
	if ((p && (p || q)) != p) ans = false;
	cout << ans << '\n';

	// p or not p <=> true
	ans = true;
	p = false;
	if ((p || !p) != true) ans = false;
	p = true;
	if ((p || !p) != true) ans = false;
	cout << ans << '\n';

	// p and not p <=> false
	ans = true;
	p = false;
	if ((p && !p) != false) ans = false;
	p = true;
	if ((p && !p) != false) ans = false;
	cout << ans << '\n';

	return 0;
}
