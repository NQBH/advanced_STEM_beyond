#include <iostream>
#include <vector>

using namespace std;
vector<vector<int> > MTko(int n) {
    return vector<vector<int> >(n, vector<int>(n, 0));
}

vector<vector<int> > MTdv(int n) {
    vector<vector<int> > B(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        B[i][i] = 1;
    }
    return B;
}
void   xuatMT(const vector<vector<int> >&A) {
    int m = A.size();
    int n = A[0].size();
    cout << " \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << A[i][j] << "\t";
        cout << endl;
    }
}

int main () {
    int n;
    cout << "Nhap cap ma tran vuong n x n: ";
    cin >> n;
    if (n < 0) {
        cout << "Cap ma tran khong hop le!";
        return 1;
    }
    vector<vector<int> >A = MTko(n);
    vector<vector<int> >B = MTdv(n);
    cout << " Ma tran 0 la:\n";
    xuatMT(MTko(n));
    cout << "Ma tran don vi la:\n";
    xuatMT(MTdv(n));
    return 0;
}