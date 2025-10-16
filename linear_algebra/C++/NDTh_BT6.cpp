#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m ,n;
    cout << " nhap so hang m vao cot n cua ma tran A:";
    cin >> m >> n;

    vector<vector<double> > A(m, vector<double>(n));
    cout << " nhap ma tran A:\n";
    for ( int i = 0; i < m; i++)
        for ( int j = 0; j < n; j++)
            cin >> A[i][j];
    
    int k;
    cout << " nhap kich thuoc vector b: ";
    cin >> k;

    vector<double> b(k);
    cout << " nhap vector b:\n";
    for ( int i = 0; i < k; i++)
        cin >> b[i];

    if ( k != m ) {
        cout << " impossible\n";
    }else {
        cout << " ma tran bo sung [A|b]:\n";
        for ( int i = 0; i < m; i++) {
            for ( int j = 0; j < n; j++)
                cout << A[i][j] << " ";
            cout << "| " << b[i] << endl;
        }
    }   
    return 0;   
}
