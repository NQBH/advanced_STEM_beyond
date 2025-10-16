#include <iostream>
using namespace std;

int main() {
    bool is_satisfiable;

    // 65a
    is_satisfiable = false;
    for (int p = 0; p <= 1; ++p)
        for (int q = 0; q <= 1; ++q)
            if ((p || !q) && (!p || q) && (!p || !q)) {
                cout << "65a: satisfiable\n";
                cout << "p=" << p << ", q=" << q << "\n";
                is_satisfiable = true;
                goto next65a;
            }
next65a:
    if (!is_satisfiable) cout << "65a: unsatisfiable\n";


    // 65b
    is_satisfiable = false;
    for (int p = 0; p <= 1; ++p)
        for (int q = 0; q <= 1; ++q)
            if ( (!p || q) && (!p || !q) && (p || q) && (p || !q) ) {
                cout << "65b: satisfiable\n";
                cout << "p=" << p << ", q=" << q << "\n";
                is_satisfiable = true;
                goto next65b;
            }
next65b:
    if (!is_satisfiable) cout << "65b: unsatisfiable\n";


    // 65c
    is_satisfiable = false;
    for (int p = 0; p <= 1; ++p)
        for (int q = 0; q <= 1; ++q)
            if ( (p == q) && ((!p) == q) ) {
                cout << "65c: satisfiable\n";
                cout << "p=" << p << ", q=" << q << "\n";
                is_satisfiable = true;
                goto next65c;
            }
next65c:
    if (!is_satisfiable) cout << "65c: unsatisfiable\n";


    // 66a
    is_satisfiable = false;
    for (int p = 0; p <= 1; ++p)
        for (int q = 0; q <= 1; ++q)
            for (int r = 0; r <= 1; ++r)
                for (int s = 0; s <= 1; ++s)
                    if ( (p || q || !r) &&
                            (p || !q || !s) &&
                            (p || !r || !s) &&
                            (!p || !q || !s) &&
                            (p || q || !s) ) {
                        cout << "66a: satisfiable\n";
                        cout << "p=" << p << ", q=" << q << ", r=" << r << ", s=" << s << "\n";
                        is_satisfiable = true;
                        goto next66a;
                    }
next66a:
    if (!is_satisfiable) cout << "66a: unsatisfiable\n";


    // 66b
    is_satisfiable = false;
    for (int p = 0; p <= 1; ++p)
        for (int q = 0; q <= 1; ++q)
            for (int r = 0; r <= 1; ++r)
                for (int s = 0; s <= 1; ++s)
                    if ( (!p || !q || r) &&
                            (!p || q || !s) &&
                            (p || !q || !r) &&
                            (p || q || !r) &&
                            (p || !r || !s) ) {
                        cout << "66b: satisfiable\n";
                        cout << "p=" << p << ", q=" << q << ", r=" << r << ", s=" << s << "\n";
                        is_satisfiable = true;
                        goto next66b;
                    }
next66b:
    if (!is_satisfiable) cout << "66b: unsatisfiable\n";


    // 66c
    is_satisfiable = false;
    for (int p = 0; p <= 1; ++p)
        for (int q = 0; q <= 1; ++q)
            for (int r = 0; r <= 1; ++r)
                for (int s = 0; s <= 1; ++s)
                    if ( (p || q || r) &&
                            (p || !q || !s) &&
                            (q || !r || s) &&
                            (!p || r || s) &&
                            (!p || q || !s) &&
                            (p || !q || !r) &&
                            (!p || !q || s) &&
                            (!p || !r || !s) ) {
                        cout << "66c: satisfiable\n";
                        cout << "p=" << p << ", q=" << q << ", r=" << r << ", s=" << s << "\n";
                        is_satisfiable = true;
                        goto next66c;
                    }
next66c:
    if (!is_satisfiable) cout << "66c: unsatisfiable\n";

    return 0;
}
