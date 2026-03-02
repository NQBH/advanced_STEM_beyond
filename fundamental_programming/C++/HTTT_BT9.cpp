#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    int a;
    int demsosoChan = 0, demsosoLe = 0;

    for (int i = 1; i <= n; i++) {
        cout << "Nhap so thu " << i << ": ";
        cin >> a;

        if (a % 2 == 0)
            demsosoChan++;
        else
            demsosoLe++;
    }

    cout << "So luong so chan: " << demsosoChan << endl;
    cout << "So luong so le: " << demsosoLe << endl;

    return 0;
}
