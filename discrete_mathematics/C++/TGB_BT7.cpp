#include <iostream>
using namespace std;

int main() {
	bool p, q, r, s, is_satisfiable;
// Problem 65a
is_satisfiable = false;
for (int p = 0; p <= 1; ++p)
for (int q = 0; q <= 1; ++q)
if ((p || !q) && (!p || q) && (!p || !q)) {
is_satisfiable = true;
cout << "65a satisfiable\n" << p << " " << q << '\n';
goto next_65a;
}
if (!is_satisfiable) cout << "65a unsatisfiable\n";
// Problem 65b
is_satisfiable = false;
for (int p = 0; p <= 1; ++p)
for (int q = 0; q <= 1; ++q)
if (implies(p, q) && implies(p, !q) && implies(!p, q) && implies(!p, !q)) {
is_satisfiable = true;
cout << "65b satisfiable\n" << p << " " << q << '\n';
}
if (!is_satisfiable) cout << "65b unsatisfiable\n";
// Problem 65c
is_satisfiable = false;
for (int p = 0; p <= 1; ++p)
for (int q = 0; q <= 1; ++q)
if (biconditional(p, q) && biconditional(!p, q)) {	
is_satisfiable = true;
cout << "65c satisfiable\n" << p << " " << q << '\n';
}
if (!is_satisfiable) cout << "65c unsatisfiable\n";
// Problem 66a
is_satisfiable = false;
for (int p = 0; p <= 1; ++p)
for (int q = 0; q <= 1; ++q)
for (int r = 0; r <= 1; ++r)
for (int s = 0; s <= 1; ++s)
if ((p || q || !r) && (p || !q || !s) && (p || !r || !s) && (!p || !q || !s) && (p || q || !s)) {
is_satisfiable = true;
cout << "66a satisfiable\n" << p << " " << q << " " << r << " " << s << '\n';
}
if (!is_satisfiable) cout << "66a unsatisfiable\n";
// Problem 66b
is_satisfiable = false;
for (int p = 0; p <= 1; ++p)
for (int q = 0; q <= 1; ++q)
for (int r = 0; r <= 1; ++r)
for (int s = 0; s <= 1; ++s)
if ((!p || !q || r) && (!p || q || !s) && (p || !q || !s) && (!p || !r || !s) && (p || q || !r) && (p || q || !s)) {
is_satisfiable = true;
cout << "66b satisfiable\n" << p << " " << q << " " << r << " " << s << '\n';
}
if (!is_satisfiable) cout << "66b unsatisfiable\n";
// Problem 66c
is_satisfiable = false;
for (int p = 0; p <= 1; ++p)
for (int q = 0; q <= 1; ++q)
for (int r = 0; r <= 1; ++r)
for (int s = 0; s <= 1; ++s)
if ((p || q || r) && (p || !q || !s) && (q || !r || s) && (!p || r || s) &&
(!p || q || !s) && (p || !q || !r) && (!p || !q || s) && (!p || !r || !s)) {
is_satisfiable = true;	
cout << "66c satisfiable\n" << p << " " << q << " " << r << " " << s << '\n';
goto next_66c;
}
	if (!is_satisfiable) cout << "66c unsatisfiable\n";
}
