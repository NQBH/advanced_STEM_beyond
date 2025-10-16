#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    bool p, q, r;
    cout << "  p  q  r  |  1  2  3  4  5  6  7  8 9 10 11 12 13 14 15 16 17 18 19" << endl;
    for (int i = 1; i >= 0; --i) {
        for (int j = 1; j >= 0; --j) {
            for (int k = 1; k >= 0; --k) {
                p = i; q = j; r = k;
                bool rule1 = ((p && true) == p);
                bool rule2 = ((p || false) == p);

                bool rule3 = ((p || true) == true);
                bool rule4 = ((p && false) == false);

                bool rule5 = ((p || p) == p); 
                bool rule6 = ((p && p) == p); 

                bool rule7 = (!(!p) == p); 


                bool rule8 = ((p || q) == (q || p)); 
                bool rule9 = ((p && q) == (q && p)); 

                bool rule10 = (((p || q) || r) == (p || (q || r))); 
                bool rule11 = (((p && q) && r) == (p && (q && r)));

                bool rule12 = ((p && (q || r)) == ((p && q) || (p && r))); 
                bool rule13 = ((p || (q && r)) == ((p || q) && (p || r)));

                bool rule14 = ((! (p && q)) == (!p || !q));
                bool rule15 = ((!(p || q)) == (!p && !q));

                bool rule16 = ((p || (p && q)) == p);
                bool rule17 = ((p && (p || q)) == p);

                bool rule18 = ((p || (!p)) == true);
                bool rule19 = ((p && (!p)) == false);
                cout << "  " << p << "  " << q << "  " << r << "  |  "
                     << rule1 << "  " << rule2 << "  " << rule3 << "  " << rule4
                     << "  " << rule5 << "  " << rule6 << "  " << rule7 << "  " << rule8
                     << "  " << rule9 << "  " << rule10 << "  " << rule11
                     << "  " << rule12 << "  " << rule13 << "  " << rule14
                     << "  " << rule15 << "  " << rule16 << "  " << rule17
                     << "  " << rule18 << "  " << rule19 << endl;
            }
        }
    }
    return 0;
}