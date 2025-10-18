#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    cout << "Nhap x, y, z: ";
    cin >> x >> y >> z;

    bool P = (x + 1 == 2); 
    bool Q = (x + y == z);

    cout << "P = " << P << endl;
    cout << "Q = " << Q << endl;
    bool converse = (!Q || P);       
    bool contrapositive = (Q || !P); 
    bool inverse = (P || !Q);       
    // Dao
    cout << "Dao (Q => P) = " << converse << endl;
    // Phan Dao 
    cout << "Phan dao (¬Q => ¬P) = " << contrapositive << endl;
    // Nghich dao
    cout << "Nghich dao (¬P => ¬Q) = " << inverse << endl;

    return 0;
}