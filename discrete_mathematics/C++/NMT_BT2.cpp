#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    cout << "Nhap x, y, z: ";
    cin >> x >> y >> z;

    bool p = (x + 1 == 2);   
    bool q = (x + y == z);    

    cout << " p and q is " << (p && q) << '\n'; // (p and q)
	cout << " p or q is " << (p || q) << '\n'; // (p or q)
	cout << " p xor q is " << (p ^ q) << '\n'; // (p xor q) << endl;

    return 0;
}