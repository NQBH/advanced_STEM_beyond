#include <iostream>
using namespace std;

int main() {
    bool p, q, r;
    bool sat;
    cout << "===== Problem 65 =====\n";
    sat = false;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++) {
                p = i; q = j; r = k;
                bool expr = ( (p || !q) && (q || !r) && (r || !p) );
                if (expr) {
                    sat = true;
                    cout << "satisfiable: p=" << p << " q=" << q << " r=" << r << endl;
                    i = j = k = 2; // thoát vòng lặp sớm
                }
            }
    if (!sat) cout << "unsatisfiable\n";

    cout << "\n===== Problem 66 =====\n";
    sat = false;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++) {
                p = i; q = j; r = k;
                bool expr = ( (p || q || r) && (!p || !q) && (!p || !r) && (!q || !r) );
                if (expr) {
                    sat = true;
                    cout << "satisfiable: p=" << p << " q=" << q << " r=" << r << endl;
                    i = j = k = 2; // thoát vòng lặp sớm
                }
            }
    if (!sat) cout << "unsatisfiable\n";

    return 0;
}
