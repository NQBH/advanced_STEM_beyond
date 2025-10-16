#include <iostream>
using namespace std;

int main() {
    bool p, q, r, s;
    bool satA = false, satB = false, satC = false;
    for (p = 0; p <= 1; ++p) {
        for (q = 0; q <= 1; ++q) {
            for (r = 0; r <= 1; ++r) {
                for (s = 0; s <= 1; ++s) {
                    bool a = (((p || q || !r) && (p || !q || !s) && (p || !r || !s) && (!p || !q || !s) && (p || q || !s)));
                    bool b = (((!p || !q || r) && (!p || q || !s) && (p || !q || !s) && (!p || !r || !s) && (p || q || !r) && (p || !r || !s)));
                    bool c = (((p || q || r) && (p || !q || !s) && (q || !r || s) && (!p || r || s) && (!p || q || !s) && (p || !q || !r) && ( !p || !q || s) && (!p || !r || !s)));
                    if (a && !satA) {
                        cout << "sat a:" << p << " q=" << q << " r=" << r << " s=" << s << endl;
                        satA = true;
                    }
                    if (b && !satB) {
                        cout << "sat b:" << p << " q=" << q << " r=" << r << " s=" << s << endl;
                        satB = true;
                    }
                    if (c && !satC) {
                        cout << "sat c:" << p << " q=" << q << " r=" << r << " s=" << s << endl;
                        satC = true;
                    }
                }
            }
        }
    }

    if (satA == false) cout << "sat a) is not sat.\n";
    if (satB == false) cout << "sat b) is not sat.\n";
    if (satC == false) cout << "sat c) is not sat.\n";

    return 0;
}
