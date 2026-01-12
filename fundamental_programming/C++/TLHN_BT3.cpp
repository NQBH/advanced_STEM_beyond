

// BT3: (+2) Viết chương trình C++ nhập vào 3 số nguyên a,b,c. Kiểm tra xem chúng có phải là 3 cạnh 1 hình lập phương không,
// nếu có xuất ra "HLP", nếu không kiểm tra tiếp xem chúng có phải 3 cạnh 1 hình hộp chữ nhật không, nếu có xuất ra "HHCN".
// Nếu hình thu được là 1 hình hộp chữ nhật, tính diện tích xung quanh, diện tích toàn phần, đường chéo & thể tích của nó.
// Nếu không phải hình hộp chữ nhật thì xuất ra -1.



#include <iostream>
#include <cmath>
using namespace std;

int canhA, canhB, canhC;
int main() {
    cout << "Nhap canh A: " << endl;
    cin >> canhA;

    cout << "Nhap canh B: " << endl;
    cin >> canhB;

    cout << "Nhap canh C: " << endl;
    cin >> canhC;


    if (canhA > 0 && canhA == canhB && canhB == canhC) {
        cout << "HLP";
        return 0;
    }

    if (canhA > 0 && canhB > 0 && canhC > 0) {
        cout << "HHCN" << endl;

        int dienTichXungQuanh = 2 * (canhA + canhB) * canhC;
        int dienTichToanPhan = 2 * (canhA * canhB + canhB * canhC + canhA * canhC);
        double duongCheoHHCN = sqrt(canhA * canhA + canhB * canhB + canhC * canhC);
        int theTichHHCN = canhA * canhB * canhC;

        cout << "Dien tich xung quanh: " << dienTichXungQuanh << endl;
        cout << "Dien tich toan phan: " << dienTichToanPhan << endl;
        cout << "Duong cheo: " << duongCheoHHCN << endl;
        cout << "The tich: " << theTichHHCN << endl;


        return 0;
    }

    cout << -1;
    return 0;
}



