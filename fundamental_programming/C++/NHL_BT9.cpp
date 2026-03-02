#include <iostream>
using namespace std;
int main()
{
    int n;
    int sochan = 0;
    int sole = 0;
    cout << "nhập số n: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cout << "nhập số x: ";
        cin >> x;
        if (x % 2 == 0) {
            sochan++;

        }
        else {
            sole++;

        }
    }
    cout << "số lượng số chẳn: " << sochan << '\n';
    cout << "số lượng số lẻ: " << sole;

}