// ==========================  BT7: Câu 65 (a)


#include <iostream>
using namespace std;

int main() {
    bool p, q, is_satisfiable = false;

    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j <= 1; ++j) {
            p = i; q = j;
            if ((p || !q) && (!p || q) && (!p || !q)) {
                cout << "satisfiable\np=" << p << " q=" << q << endl;
                return 0;
            }
        }

    cout << "unsatisfiable";
}
