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
int main()
{
    vector<vector<float> > a;
    int m, n;
    NhapMT(a, m, n);
    XuatMT(a);
    return 0;
}
