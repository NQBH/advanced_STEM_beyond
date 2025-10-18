#include <iostream>
using namespace std;

int main() {
    //
    bool p = true, q = false, r = true;
    //
    const bool T = true, F = false;
    cout << "1 = True, 0 - Fales";
    cout << "1. (p && T) == p: " << ((p && T) == p) << endl;
    cout << "   (p || F) == p: " << ((p || F) == p) << endl;
    cout << "2. (p || T) == T: " << ((p || T) == T) << endl;
    cout << "   (p && F) == F: " << ((p && F) == F) << endl;
    cout << "3. (p || p) == p: " << ((p || p) == p) << endl;
    cout << "   (p && p) == p: " << ((p && p) == p) << endl;
    cout << "4. (!(!p)) == p: " << ((!(!p)) == p) << endl;
    cout << "5. (p || q) == (q || p): " << ((p || q) == (q || p)) << endl;
    cout << "   (p && q) == (q && p): " << ((p && q) == (q && p)) << endl;
    cout << "6.((p || q) || r) == (p || (q || r)): " << (((p || q) || r) == (p || (q || r))) << endl;
    cout << "   ((p && q) && r) == (p && (q && r)): " << (((p && q) && r) == (p && (q && r))) << endl;
    cout << "7.(p || (q && r)) == ((p || q) && (p || r)): " << ((p || (q && r)) == ((p || q) && (p || r))) << endl;
    cout << "   (p && (q || r)) == ((p && q) || (p && r)): " << ((p && (q || r)) == ((p && q) || (p && r))) << endl;
    cout << "8.(!(p && q)) == (!p || !q): " << (!(p && q) == (!p || !q)) << endl;
    cout << "   (!(p || q)) == (!p && !q): " << (!(p || q) == (!p && !q)) << endl;
    cout << "9. (p || (p && q)) == p: " << ((p || (p && q)) == p) << endl;
    cout << "   (p && (p || q)) == p: " << ((p && (p || q)) == p) << endl;
    cout << "10.(p || !p) == T: " << ((p || !p) == T) << endl;
    cout << "   (p && !p) == F: " << ((p && !p) == F) << endl;
    return 0;
}