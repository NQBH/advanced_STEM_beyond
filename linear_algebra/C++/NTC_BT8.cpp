#include <iostream>
#include <vector>
using namespace std;

void in_mt(const vector<vector<int>>& matran);

int main() {
    int n;
    cout << "nhập kích thước ma trận n x n: ";
    cin >> n;

    vector<vector<int>> matran0(n, vector<int>(n, 0));
    cout << "\nkích thước ma trận 0 vừa nhập" << endl;
    in_mt(matran0);

    vector<vector<int>> mtdonvi(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        mtdonvi[i][i] = 1;
    }
    cout << "\nkích thước ma trận đơn vị vừa nhập" << endl;
    in_mt(mtdonvi);

    return 0;
}

void in_mt(const vector<vector<int>>& matran) {
    for (int i = 0; i < matran.size(); i++) {
        for (int j = 0; j < matran[i].size(); j++) {
            cout << matran[i][j] << "\t";
        }
        cout << endl;
    }
}