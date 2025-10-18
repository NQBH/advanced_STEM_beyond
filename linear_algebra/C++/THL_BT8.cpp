#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout <<"Nhap kich thuoc matran: ";
    cin >> n;
    vector<vector<int > > A(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    cout << endl; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << (i == j ? 1 : 0) << " ";
        cout << endl;
    }
    return 0;
}
