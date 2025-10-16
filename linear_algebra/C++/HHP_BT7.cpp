#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cout << "nhap so hang: " << endl;
    cin >> m;
    cout << "nhap so cot: " << endl;
    cin >> n;

    double A[m][n];
    cout << "nhap so phan tu cua ma tran A: ";
    for (int i = 0 ; i < m ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }
    // Ma trận ban đầu
    cout << "\n Ma tran ban dau \n";
    for (int i = 0 ; i < m ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            cout << A[i][j] << "\t";
        }
        cout << endl;

    }

    int choice;
    cout << "\nChon phep bien doi:\n";
    cout << "1. Hoan vi hai hang\n";
    cout << "2. Nhan mot hang voi mot so khac 0\n";
    cout << "3. Cong mot boi cua hang nay vao hang khac\n";
    cout << "Lua chon: ";
    cin >> choice;

    if (choice == 1) {
        int r1, r2;
        cout << "Nhap 2 hang can doi" << endl;
        cin >> r1 >> r2;
        for (int j = 0; j < n; j++)
        {   swap(A[r1][j], A[r2][j]);
        }
    }
    else if (choice == 2)
    {
        int r;
        double k;
        cout << "Nhap hang can nhan: ";
        cin >> r;
        cout << "Nhap so k (k != 0): ";
        cin >> k;
        for (int j = 0; j < n; j++)
        {    A[r][j] *= k; }
    }
    else if (choice == 3) {
        int r1, r2;
        double k;
        cout << "Nhap hang bi thay doi (r1): ";
        cin >> r1;
        cout << "Nhap hang dung de cong (r2): ";
        cin >> r2;
        cout << "Nhap he so k (r1 = r1 + k * r2): ";
        cin >> k;
        for (int j = 0; j < n; j++)
            A[r1][j] += k * A[r2][j];
    }
    else {
        cout << "Lua chon khong hop le!\n";
        return 0;
    }
    cout << "\n Ma tran luc sau \n";
    for (int i = 0 ; i < m ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            cout << A[i][j] << "\t";
        }
        cout << endl;

    }
    return 0;

}