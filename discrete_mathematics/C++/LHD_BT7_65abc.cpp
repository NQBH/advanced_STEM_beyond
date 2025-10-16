#include <iostream>
using namespace std;
bool imply(bool a, bool b) { return (!a || b); }
bool bicond(bool a, bool b) { return (a == b); }

int main() {
    bool sat_a = false;
    bool sat_b = false;
    bool sat_c = false;

    for (int p = 0; p <= 1; ++p) {
        for (int q = 0; q <= 1; ++q) {
            bool a = ( (p || !q) && (!p || q) && (!p || !q) );
            bool b = ( imply(p, q) && imply(p, !q) && imply(!p, q) && imply(!p, !q) );
            bool c = ( bicond(p, q) && bicond(!p, q) );
            if (a && !sat_a) {
                cout << "sat a: p=" << p << " q=" << q << endl;
                sat_a = true;
            }
            if (b && !sat_b) {
                cout << "sat b: p=" << p << " q=" << q << endl;
                sat_b = true;
            }
            if (c && !sat_c) {
                cout << "sat c: p=" << p << " q=" << q << endl;
                sat_c = true;
            }
        }
    }
    if (sat_a == false) cout << "sat a) is not sat.\n";
    if (sat_b == false) cout << "sat b) is not sat.\n";
    if (sat_c == false) cout << "sat c) is not sat.\n";
    return 0;
}
