#include <iostream>
using namespace std;

int main() {
    bool is_satisfiable = false;

    for (int p = 0; p <= 1; ++p)
        for (int q = 0; q <= 1; ++q)
            for (int r = 0; r <= 1; ++r)
                for (int s = 0; s <= 1; ++s) {

                    bool expr = (p || q || !r) &&
                                (p || !q || !s) &&
                                (p || !r || !s) &&
                                (!p || !q || !s) &&
                                (p || q || !s);

                    if (expr) {
                        cout << "satisfiable\n";
                        cout << "p = " << p << ", q = " << q << ", r = " << r << ", s = " << s << endl;
                        is_satisfiable = true;
                        break;
                    }
                }

    if (!is_satisfiable)
        cout << "unsatisfiable\n";

    return 0;
}
