#include <iostream>
#include <vector>
using namespace std;

void nhapMT2x2(vector<vector<float> >& A) {
    A.resize(2, vector<float>(2));
    cout << "Nhap cac ptu cua ma tran 2x2:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }
}

void xuatMT2x2(const vector<vector<float> >& A) {
    cout << "\nMa tran vua nhap la:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << A[i][j] << "\t";
        cout << endl;
    }
}
float dinhthuc2x2(const vector<vector<float> >& A) {
    return A[0][0] * A[1][1] - A[0][1] * A[1][0];
}

int main() {
    vector<vector<float> > A;
    nhapMT2x2(A);
    xuatMT2x2(A);

    float det = dinhthuc2x2(A);
    cout << "det(A) = ad-bc = " << det << endl;

    return 0;
}

