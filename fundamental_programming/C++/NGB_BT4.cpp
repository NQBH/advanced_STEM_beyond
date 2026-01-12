#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y;
    cout << "Nhập x: ";
    cin >> x;
    cout << "Nhập y: ";
    cin >> y;
    //Hàm căn bậc 2 (sqrt)
    if (x >= 0) {
        cout << "1.sqrt = " << sqrt(x) << endl;
    } else {
        cout << "Không tính được" << endl;
    }
    //Hàm lũy thừa (pow)
    cout << "2. pow = " << pow(x, y) << endl;
    //Hàm e^x (exp)
    cout << "3. exp = " << exp(x) << endl;
    //Hàm logarit tự nhiên (log)
    if (x > 0) {
        cout << "4. log = " << log(x) << endl;
    } else {
        cout << "Không tính được" << endl;
    }
    //Hàm logarit cơ số 10
    if (x > 0) {
        cout << "5. log10 = " << log10(x) << endl;
    } else {
        cout << "Không tính được" << endl;
    }
    //Hàm trị tuyệt đối (abs, labs, fabs)
    cout << "abs(int) = " << abs(int(x)) << endl;
    cout << "labs(long) = " << labs(long(x)) << endl;
    cout << "fabs = " << fabs(x) << endl;
    //Hàm lượng giác (cos, sin, tan)
    cout << "cos = " << cos(x) << endl;
    cout << "sin = " << sin(x) << endl;
    cout << "tan = " << tan(x) << endl;
    //Hàm lượng giác ngược (acos, asin, atan)
    if (x >= -1 && x <= 1) {
        cout << "acos = " << acos(x) << endl;
        cout << "asin = " << asin(x) << endl;
    } else {
        cout << "Không tính được" << endl;
    }
    cout << "atan = " << atan(x) << endl;
    //Hàm tính số nguyên lớn nhất (floor, ceil)
    cout << "floor = " << floor(x) << endl;
    cout << "ceil = " << ceil(x) << endl;
    
    return 0;
}