#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n;

    vector<vector<int>> a(2, vector<int>(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a[i][j];
        }
    }
    cout << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    float delta = a[0][0] * a[1][1] - a[0][1] * a[1][0];
    cout << "DetA = " << delta << endl;
    return 0;

}