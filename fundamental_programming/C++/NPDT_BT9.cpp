#include <vector>
using namespace std;

int main() {
    int n;
    int chan = 0, le = 0;
    cout << "nhap vao n so nguyen: ";
    cin >> n;

    vector<int> arr(n);

//nhap so
    for (int i = 0; i < n; i++) {
        cout << "nhap so: ";
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if ((arr[i] % 2) == 0) {
            chan += 1;
        } else le += 1;
    }

    cout << "so luong so chan: " << chan << endl;
    cout << "so luong so le: " << le << endl;
}