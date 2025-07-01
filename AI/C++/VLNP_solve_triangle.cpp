#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
using namespace std;

struct Node {
    string fact;
    double val;

};

bool isValidTriangle(double a, double b, double c) {
    return (a + b > c) && (a + c > b) && (b + c > a) && (a > 0) && (b > 0) && (c > 0);
}

double P(double a, double b, double c) {
    return a + b + c;
}

double S(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Ha(double a, double S) {
    if (a == 0) return 0;
    return (2 * S) / a;
}
double Hb(double b, double S) {
    if (b == 0) return 0;
    return (2 * S) / b;
}
double Hc(double c, double S) {
    if (c == 0) return 0;
    return (2 * S ) / c;
}
double Ma(double a, double b, double c) {
    return 0.5 * sqrt(2 * b * b + 2 * c * c - a * a);
}
double Mb(double a, double b, double c) {
    return 0.5 * sqrt(2 * a * a + 2 * c * c - b * b);
}
double Mc(double a, double b, double c) {
    return 0.5 * sqrt(2 * a * a + 2 * b * b - c * c);
}

double Pa(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return (2 * sqrt(b * c * p * (p - a))) / (b + c);
}
double Pb(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return (2 * sqrt(a * c * p * (p - b))) / (a + c);
}
double Pc(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return (2 * sqrt(a * b * p * (p - c))) / (a + b);
}

double R(double a, double b, double c, double S) {
    if (S == 0) return 0;
    return (a * b * c) / (4 * S);
}

double r(double S, double P) {
    if (P == 0) return 0;
    return S / (P / 2);
}

double ra(double a, double S , double p) {
    double perimeter = p / 2;
    if (perimeter - a == 0) return 0;
    return S / (perimeter - a);
}

double rb(double b, double S , double p) {
    double perimeter = p / 2;
    if (perimeter - b == 0) return 0;
    return S / (perimeter - b);
}

double rc(double c, double S , double p) {
    double perimeter = p / 2;
    if (perimeter - c == 0) return 0;
    return S / (perimeter - c);
}

double gocA(double a, double b, double c) {
    return acos((b * b + c * c - a * a) / (2 * b * c));
}

double gocB(double a, double b, double c) {
    return acos((a * a + c * c - b * b) / (2 * a * c));
}
double gocC(double a, double b, double c) {
    return acos((a * a + b * b - c * c) / (2 * a * b));
}
double radtodeg(double rad) {
    return rad * 180 / M_PI;
}
int main() {
    Node a, b, c;
    ifstream inputFile("triangle.txt");
    // cout<<"nhap 3 canh tam giac: ";
    // cin>>a.val>>b.val>>c.val;
    if (!inputFile.is_open()) {
        cout << "Khong the mo file triangle.txt" << endl;
        return 1;
    }
    inputFile >> a.val >> b.val >> c.val;
    inputFile.close();

    cout << "Da doc tu file triangle.txt: " << a.val << " " << b.val << " " << c.val << endl;

    if (!isValidTriangle(a.val, b.val, c.val)) {
        cout << "ba canh nay khong tao thanh tam giac!ERROR" << endl;
        return 1;
    }
    double chuvi = P(a.val, b.val, c.val);
    double dientich = S(a.val, b.val, c.val);
    double ha = Ha(a.val, dientich);
    double hb = Hb(b.val, dientich);
    double hc = Hc(c.val, dientich);
    double ma = Ma(a.val, b.val, c.val);
    double mb = Mb(a.val, b.val, c.val);
    double mc = Mc(a.val, b.val, c.val);
    double pa = Pa(a.val, b.val, c.val);
    double pb = Pb(a.val, b.val, c.val);
    double pc = Pc(a.val, b.val, c.val);
    double R_ngoai = R(a.val, b.val, c.val, dientich);
    double R_noi = r(dientich, chuvi);
    double r_a = ra(a.val, dientich, chuvi);
    double r_b = rb(b.val, dientich, chuvi);
    double r_c = rc(c.val, dientich, chuvi);

    double angleA_rad = gocA(a.val, b.val, c.val);
    double angleB_rad = gocB(a.val, b.val, c.val);
    double angleC_rad = gocC(a.val, b.val, c.val);

    double angleA_deg = radtodeg(angleA_rad);
    double angleB_deg = radtodeg(angleB_rad);
    double angleC_deg = radtodeg(angleC_rad);

    cout << fixed << setprecision(2);
    cout << "\nCac thong so cua tam giac:\n";
    cout << "----------------------------------------\n";
    cout << "1. Cac canh:\n";
    cout << "   - Canh a: " << a.val << endl;
    cout << "   - Canh b: " << b.val << endl;
    cout << "   - Canh c: " << c.val << endl;

    cout << "\n2. Cac goc (tinh theo do):\n";
    cout << "   - Goc A (doi dien canh a): " << angleA_deg << "°\n";
    cout << "   - Goc B (doi dien canh b): " << angleB_deg << "°\n";
    cout << "   - Goc C (doi dien canh c): " << angleC_deg << "°\n";

    cout << "\n3. Cac thong so khac:\n";
    cout << "   - Chu vi (P): " << chuvi << endl;
    cout << "   - Dien tich (S): " << dientich << endl;

    cout << "\n4. Cac duong dac biet:\n";
    cout << "   - Duong cao ha: " << ha << endl;
    cout << "   - Duong cao hb: " << hb << endl;
    cout << "   - Duong cao hc: " << hc << endl;
    cout << "   - Trung tuyen ma: " << ma << endl;
    cout << "   - Trung tuyen mb: " << mb << endl;
    cout << "   - Trung tuyen mc: " << mc << endl;
    cout << "   - Phan giac pa: " << pa << endl;
    cout << "   - Phan giac pb: " << pb << endl;
    cout << "   - Phan giac pc: " << pc << endl;

    cout << "\n5. Cac ban kinh duong tron:\n";
    cout << "   - Ban kinh duong tron ngoai tiep (R): " << R_ngoai << endl;
    cout << "   - Ban kinh duong tron noi tiep (r): " << R_noi << endl;
    cout << "   - Ban kinh duong tron bang tiep doi dien a (ra): " << r_a << endl;
    cout << "   - Ban kinh duong tron bang tiep doi dien b (rb): " << r_b << endl;
    cout << "   - Ban kinh duong tron bang tiep doi dien c (rc): " << r_c << endl;

    // Kiểm tra tổng 3 góc có bằng 180 độ không (làm tròn để tránh sai số)
    double sumAngles = angleA_deg + angleB_deg + angleC_deg;
    cout << "\n6. Kiem tra:\n";
    cout << "   - Tong 3 goc: " << sumAngles << "° ";
    if (abs(sumAngles - 180.0) < 0.01) {
        cout << "(hop le)";
    } else {
        cout << "(khong hop le, co loi tinh toan)";
    }
    cout << endl;

    return 0;
}