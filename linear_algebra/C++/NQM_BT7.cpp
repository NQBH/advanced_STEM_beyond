#include <iostream>
#include <vector>
using namespace std;

void in(const vector<vector<double>>& A) {
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl; 
    }
}
int main(){
    int m,n;
    cout << "Nhap so hang va cot MT A: ";
    cin >> m >> n;

    vector<vector<double>> A(m, vector<double>(n));
    cout << "Nhap ma tran A: ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
        
    }
    
    cout << "Ma tran da nhap:\n";
    in(A);

    int r1,r2;
    cout << "[1] Nhap hai dong can hoan doi (i,j): ";
    cin >> r1 >> r2;
    swap(A[r1 - 1], A[r2 - 1]);

    cout << "Sau phep 1 (R" << r1 << " <-> R" << r2 << "):\n";
    in(A);
    int r3;
    double k;
    cout << "\n[2] Nhap dong can nhan va he so k (i k): ";
    cin >> r3 >> k;
    for (int j = 0; j < n; ++j){
        A[r3 - 1][j] *= k;
    }

    cout << "Sau phep 2 (R" << r3 << " = " << k << " * R" << r3 << "):\n";
    in(A);

    int i1,j1;
    double k2;
    cout << "\n[3] Nhap dong can thay doi (i), dong duoc nhan (j), va he so k: ";
    cin >> i1 >> j1 >> k2;
    for (int c = 0; c < n; ++c){
        A[i1 - 1][c] += k2 * A[j1 - 1][c];
    }
    cout << "Sau phep 3 (R" << i1 << " = R" << i1 << " + " << k2 << " * R" << j1 << "):\n";
    in(A);
}