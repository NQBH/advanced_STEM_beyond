// ===================== BT7: Câu 66 (b)



#include <iostream>
using namespace std;

int main() {
    bool p, q, r, s;

    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j <= 1; ++j)
            for (int k = 0; k <= 1; ++k)
                for (int t = 0; t <= 1; ++t) {
                    p = i; q = j; r = k; s = t;
                    if ((!p || !q || r) && (!p || q || !s) &&
                        (p || !q || !s) && (!p || !r || !s) &&
                        (p || q || !r) && (p || !r || !s)) {
                        cout << "satisfiable\np=" << p << " q=" << q
                             << " r=" << r << " s=" << s << endl;
                        return 0;
                    }
                }

    cout << "unsatisfiable";
}
