#include <iostream>
using namespace std;
int main() {
    int x, y, z;
    cout << "nhap x, y, z: ";
    cin >> x >> y >> z;

    bool p = (x + 1 == 2);
    bool q = (x + y == z);

    cout << "p = " << p << endl;
    cout << "q = " << q << endl;

    // BAI TAP 2
    bool converse = (!q || p);
    bool contrapositive = (q || !p);
    bool inverse = (p || !q); // Dao
    cout << "Dao (Q => p) = " << converse << endl; // Phan Dao
    cout << "Phan Dao (!q => !p) = " << contrapositive << endl; // Nghich Dao
    cout << "Nghich Dao (!p => !q) = " << inverse << endl;

}