#include <iostream>
using namespace std;

int main() {

// 65a
    bool p, q, is_satisfiable = false;
    for (int p = 0; p <= 1; ++p)
        for (int q = 0; q <= 1; ++q) {
            if ((p || !q) && (!p || q) && (!p || !q)) {
                is_satisfiable = true;
                cout << "satisfiable\n";
                cout << p << " " << q << '\n';
            }
        }
    if (!is_satisfiable) cout << "unsatisfiable\n";
// 65b
    is_satisfiable = false;
    for (int p = 0; p <= 1; ++p)
        for (int q = 0; q <= 1; ++q) {
            if (( !p || q ) && ( !p || !q ) && ( p || q ) && ( p || !q )) {
                is_satisfiable = true;
                cout << "satisfiable\n";
                cout << p << " " << q << '\n';
            }
        }
    if (!is_satisfiable) cout << "unsatisfiable\n";

// 65c
    is_satisfiable = false;
    for (int p = 0; p <= 1; ++p)
        for (int q = 0; q <= 1; ++q) {
            if ((p == q) && ((!p) == q)) {
                is_satisfiable = true;
                cout << "satisfiable\n";
                cout << p << " " << q << '\n';
            }
        }
    if (!is_satisfiable) cout << "unsatisfiable\n";

// 66a
    is_satisfiable = false;
    for (int p = 0; p <= 1; ++p)
        for (int q = 0; q <= 1; ++q)
            for (int r = 0; r <= 1; ++r)
                for (int s = 0; s <= 1; ++s) {
                    if ((p || q || !r) && (p || !q || !s) && (p || !r || !s) && (!p || !q || !s) && (p || q || !s)) {
                        is_satisfiable = true;
                        cout << "satisfiable\n";
                        cout << p << " " << q << " " << r << " " << s << '\n';
                    }
                }
    if (!is_satisfiable) cout << "unsatisfiable\n";

// 66b
    is_satisfiable = false;
    for (int p = 0; p <= 1; ++p)
        for (int q = 0; q <= 1; ++q)
            for (int r = 0; r <= 1; ++r)
                for (int s = 0; s <= 1; ++s) {
                    if ((!p || !q || r) && (!p || q || !s) && (p || !q || !s) &&
                            (!p || !r || !s) && (p || q || !r)) {
                        is_satisfiable = true;
                        cout << "satisfiable\n";
                        cout << p << " " << q << " " << r << " " << s << '\n';
                    }
                }
    if (!is_satisfiable) cout << "unsatisfiable\n";

// 66c
    is_satisfiable = false;
    for (int p = 0; p <= 1; ++p)
        for (int q = 0; q <= 1; ++q)
            for (int r = 0; r <= 1; ++r)
                for (int s = 0; s <= 1; ++s) {
                    if ((p || q || r) && (p || !q || !s) && (q || !r || s) && (!p || r || s) && (!p || q || !s) && (p || !q || !r) && (!p || !q || s) && (!p || !r || !s)) {
                        is_satisfiable = true;
                        cout << "satisfiable\n";
                        cout << p << " " << q << " " << r << " " << s << '\n';
                    }
                }
    if (!is_satisfiable) cout << "unsatisfiable\n";

    return 0;
}
