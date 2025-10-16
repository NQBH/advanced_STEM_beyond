#include <iostream>
using namespace std;

bool P(int x) {
    return (x + 1 == 2);
}

bool Q(int x, int y, int z) {
    return (x + y == z);
}

int main() {
    int x, y, z;
    cout << "Nhap x, y, z: ";
    cin >> x >> y >> z;

    bool p = P(x);
    bool q = Q(x, y, z);

    bool P_implies_Q = !p || q;
    bool Q_implies_P = !q || p;
    bool notP_implies_notQ = p || !q;
    bool notQ_implies_notP = q || !p;

    cout << "P => Q: " << (P_implies_Q ? "True" : "False") << "\n";
    cout << "Dao (Q => P): " << (Q_implies_P ? "True" : "False") << "\n";
    cout << "Phan dao (~P => ~Q): " << (notP_implies_notQ ? "True" : "False") << "\n";
    cout << "Nghich dao (~Q => ~P): " << (notQ_implies_notP ? "True" : "False") << "\n";

    return 0;
}