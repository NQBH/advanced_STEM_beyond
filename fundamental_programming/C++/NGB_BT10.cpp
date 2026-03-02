#include <iostream>
#include <string>
using namespace std;
//Lệnh dựa theo Sách"Nhập môn lập trình" Trang 97
int main(){
    int n;
    cout << "Nhap so (0-20): ";
    cin >> n;
    switch (n){
        case 0: 
        cout << "Zero";
        break;
        case 1:
        cout << "One";
        break;
        case 2:
        cout << "Two";
        break;
        case 3:
        cout << "Three";
        break;
        case 4:
        cout << "Four";
        break;
        case 5:
        cout << "Five";
        break;
        case 6:
        cout << "Six";
        break;
        case 7:
        cout << "Seven";
        break;
        case 8:
        cout << "Eight";
        break;
        case 9:
        cout << "Nine";
        break;
        case 10:
        cout << "Ten";
        break;
        case 11:
        cout << "Eleven";
        break;
        case 12:
        cout << "Twelve";
        break;
        case 13:
        cout << "Thirteen";
        break;
        case 14:
        cout << "Fourteen";
        break;
        case 15:
        cout << "Fifteen";
        break;
        case 16:
        cout << "Sixteen";
        break;
        case 17:
        cout << "Seventeen";
        break;
        case 18:
        cout << "Eighteen";
        break;
        case 19:
        cout << "Nineteen";
        break;
        case 20:
        cout << "Twenty";
        break;
        default:
        if(n < 0){
            cout << "Khong hop le" << endl;
        } else {
            cout <<  "Khong nhap so > 20" << endl;
        }
        break;
    }
    cout << endl;
    return 0;
}