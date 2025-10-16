#include <iostream>
using namespace std;
int main() {
    bool p, q;   // p: proposition a, q : proposition b
    int x, y, z;
    cout << "Nhap gia tri cua x (so nguyen):";
    cin >> x;
    cout << "Nhap gia tri cua y (so nguyen):";
    cin >> y;
    cout << "Nhap gia tri cua z (so nguyen):";
    cin >> z;
    p = (x + 1 == 2);
    q = (x + y == z);
    cout << "truth value cua menh de p -> q :" << (not p or q) << '\n';
    cout << "truth value cua menh de dao cua p -> q :" << (not q or p ) << '\n';
    cout << "truth value cua menh de phan dao cua p -> q :" << (p or not q) << '\n';
    cout << "truth value cua menh de nghich dao cua p -> q :" << (q or not p) << '\n';
}