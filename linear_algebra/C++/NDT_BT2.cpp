#include   <iostream>
#include   <vector>
using namespace std;

void NhapMT(vector<vector<float> >& a, int m, int n)
{
    cout << "Nhap so hang:";
    cin >> m;
    cout << " Nhap so cot:";
    cin >> n;
    a.resize(m, vector<float>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
}
void XuatMT(const vector<vector<float> >& a)
{
    int m = a.size();
    int n = a[0].size();
    cout << "Ma tran vua nhap la:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
}
vector< vector<float> > CongMT(const vector< vector<float> > &A, const vector< vector<float> > &B) {
    int m = A.size();
    int n = A[0].size();
    vector< vector<float> > C(m, vector<float>(n));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];

    return C;
}
vector< vector<float> > TruMT(const vector< vector<float> > &A, const vector< vector<float> > &B) {
    int m = A.size();
    int n = A[0].size();
    vector< vector<float> > C(m, vector<float>(n));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];

    return C;
}

int main() {
    vector< vector<float> > A, B, C;
    int m, n;

    cout << "Nhap ma tran A:\n";
    NhapMT(A, m, n);
    cout << "\nNhap ma tran B:\n";
    NhapMT(B, m, n);

    cout << "\nMa tran A:\n";
    XuatMT(A);

    cout << "\nMa tran B:\n";
    XuatMT(B);

    cout << "\nTong hai ma tran A + B:\n";
    C = CongMT(A, B);
    XuatMT(C);

    cout << "\nHieu hai ma tran A - B:\n";
    C = TruMT(A, B);
    XuatMT(C);

    return 0;
}
