#include <iostream>
#include <iomanip>
using namespace std;

bool imply(bool a, bool b) { return (!a || b); }
bool bicond(bool a, bool b) { return (a == b); }
int main() {
    bool p, q, r;
    bool p_imply_q, p_imply_r;
    cout << "  p  q  r  |  1  2  3  4  5  6  7  8 | 9 10 11 12" << endl;
    for (int i = 1; i >= 0; --i) {
        for (int j = 1; j >= 0; --j) {
            for (int k = 1; k >= 0; --k) {
                p = i; q = j; r = k;
                bool left1  = imply(p, q);
                bool right1 = (!p || q);
                bool rule1  = (left1 == right1);

                bool left2  = imply(p, q);
                bool right2 = imply(!q, !p);
                bool rule2  = (left2 == right2);

                bool left3  = (p || q);
                bool right3 = imply(!p, q);
                bool rule3  = (left3 == right3);

                bool left4  = (p && q);
                bool right4 = !(imply(p, !q));
                bool rule4  = (left4 == right4);

                bool left5  = !(imply(p, q));
                bool right5 = (p && !q);
                bool rule5  = (left5 == right5);

                bool left6  = (imply(p, q) && imply(p, r));
                bool right6 = imply(p, (q && r));
                bool rule6  = (left6 == right6);

                bool left7  = (imply(p, r) && imply(q, r));
                bool right7 = imply((p || q), r);
                bool rule7  = (left7 == right7);

                bool left8  = (imply(p, q) || imply(p, r));
                bool right8 = imply(p, (q || r));
                bool rule8  = (left8 == right8);
// table 8
                bool left9  = bicond(p, q);
                bool right9 = (imply(p, q) && imply(q, p));
                bool rule9  = (left9 == right9);

                bool left10  = bicond(p, q);
                bool right10 = bicond(!p, !q);
                bool rule10  = (left10 == right10);

                bool left11  = bicond(p, q);
                bool right11 = ((p && q) || (!p && !q));
                bool rule11  = (left11 == right11);

                bool left12  = !(bicond(p, q));
                bool right12 = bicond(p, !q);
                bool rule12  = (left12 == right12);
                cout << "  " << p << "  " << q << "  " << r << "  |  " << rule1 << "  " << rule2 << "  " << rule3 << "  " << rule4 << "  " << rule5 << "  " << rule6 << "  " << rule7 << "  " << rule8 << "  " << rule9 << "  " << rule10 << "  " << rule11 << "  " << rule12<< endl;
            }
        }
    }
    return 0;
}