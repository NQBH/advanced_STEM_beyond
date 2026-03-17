#include<iostream>
#include<cmath>
using namespace std;
void BT1 () {
   float canh;
   cout << "Nhap do dai canh hinh vuong: ";
   cin >> canh;
   cout << "Chu vi hinh vuong la: " << 4 * canh << endl;
   cout << "Dien tich hinh vuong la: " << canh*canh << endl;
}
void BT2 () {
   float dai, rong;
   cout << "Nhap chieu dai hinh chu nhat: ";
   cin >> dai;
   cout << "Nhap chieu rong hinh chu nhat: ";
   cin >> rong;
   cout << "Chu vi hinh chu nhat la: " << (dai + rong) * 2 << endl;
   cout << "Dien tich hinh chu nhat la: " << dai*rong << endl;
   cout << "Duong cheo hinh chu nhat la: " << sqrt(dai * dai + rong * rong) << endl;
}
void BT3 () {
   float a, b, c;
   cout << "Nhap a: ";
   cin >> a;
   cout << "Nhap b: ";
   cin >> b;
   cout << "Nhap c: ";
   cin >> c;
   if (a == b && b == c && a > 0) {
      cout << "HLP" << endl;
   }
   else if (a > 0 && b > 0 && c > 0) {
      cout << "HHCN" << endl;
      cout << "Dien tich xung quanh: " << 2 * c*(a + b) << endl;
      cout << "Dien tich toan phan: " << 2 * (a * b + a * c + b * c) << endl;
      cout << "The tich: " << a*b*c << endl;
      cout << "Duong cheo: " << sqrt(a * a + b * b + c * c) << endl;
   }
   else cout << -1;
}
void BT4 () {
   double x, y;
   int a;
   long b;
   float c;
   cout << "Nhap x: ";
   cin >> x;
   cout << "Nhap y: ";
   cin >> y;
   cout << "Nhap a: ";
   cin >> a;
   cout << "Nhap b: ";
   cin >> b;
   cout << "Nhap c: ";
   cin >> c;
   if (x >= 0)
      cout << "sqrt(x): " << sqrt(x) << endl;
   else
      cout << "sqrt(x) khong the tinh vi (x < 0)" << endl;
   cout << "pow(x,y): " << pow(x, y) << endl;
   cout << "exp(x): " << exp(x) << endl;
   if (x > 0) {
      cout << "Log(x): " << log(x) << endl;
      cout << "Log10(x): " << log10(x) << endl;
   } else {
      cout << "Log(x) khong tinh duoc vi (x <= 0)" << endl;
   }
   cout << "abs(a): " << abs(a) << endl;
   cout << "labs(b): " << labs(b) << endl;
   cout << "fabs(c): " << fabs(c) << endl;
   cout << "Cos(x) = " << cos(x) << endl;
   cout << "Sin(x) = " << sin(x) << endl;
   cout << "Tan(x) = " << tan(x) << endl;
   if (x >= -1 && x <= 1) {
      cout << "Arccos(x) = " << acos(x) << endl;
      cout << "Arcsin(x) = " << asin(x) << endl;
   }
   cout << "Arctan(x) = " << atan(x) << endl;
   cout << "floor(x): " << floor(x) << endl;
   cout << "ceil(x): " << ceil(x) << endl;
}
void BT5 () {
   double a, b;
   cout << "Nhap a: ";
   cin >> a;
   cout << "Nhap b: ";
   cin >> b;
   if (a == 0) {
      if (b == 0) cout << "Vo so nghiem";
      else cout << "Vo nghiem";
   } else {
      cout << "x = " << -b / a;
   }
}
void BT6 () {
   double a, b, c;
   cout << "Nhap a: ";
   cin >> a;
   cout << "Nhap b: ";
   cin >> b;
   cout << "Nhap c: ";
   cin >> c;
   if (a == 0) {
      if (b == 0) cout << "Vo nghiem";
      else cout << "x = " << -c / b;
      return;
   }
   double delta = b * b - 4 * a * c;
   if (delta < 0) {
      cout << "Vo nghiem";
   }
   else if (delta == 0) {
      cout << "Nghiem kep x = " << -b / (2 * a);
   }
   else {
      cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << endl;
      cout << "x2 = " << (-b - sqrt(delta)) / (2 * a) << endl;
   }
}
void BT7 () {
   double a, b, c;
   cout << "Nhap 3 so: ";
   cin >> a >> b >> c;
   double max = a , min = a;
   if (b > max) max = b;
   if (c > max) max = c;
   if (b < min) min = b;
   if (c < min) min = c;
   cout << "Max: " << max << endl;
   cout << "Min: " << min << endl;
}
void BT8 () {
   int n;
   cout << "Nhap n: ";
   cin >> n;
   double x;
   int demam = 0 , demduong = 0 , dem0 = 0;
   for (int i = 0; i < n; i++) {
      cin >> x;
      if (x > 0) demduong++;
      else if (x < 0) demam++;
      else dem0++;
   }
   cout << "So duong: " << demduong << endl;
   cout << "So am: " << demam << endl;
   cout << "So 0: " << dem0 << endl;
}
void BT9 () {
   int n, x, chan = 0, le = 0;
   cout << "Nhap n: ";
   cin >> n;
   for (int i = 0; i < n; i++) {
      cin >> x;
      if  (x % 2 == 0) chan++;
      else le++;
   }
   cout << "So chan: " << chan << endl;
   cout << "So le: " << le << endl;
}
void BT10 () {
   int n;
   cout << "Nhap n tu 0 - 20: ";
   cin >> n;
   switch (n)  {
   case 0: cout << "zero"; break;
   case 1: cout << "one"; break;
   case 2: cout << "two"; break;
   case 3: cout << "three"; break;
   case 4: cout << "four"; break;
   case 5: cout << "five"; break;
   case 6: cout << "six"; break;
   case 7: cout << "seven"; break;
   case 8: cout << "eight"; break;
   case 9: cout << "nine"; break;
   case 10: cout << "ten"; break;
   case 11: cout << "eleven"; break;
   case 12: cout << "twelve"; break;
   case 13: cout << "thirteen"; break;
   case 14: cout << "fourteen"; break;
   case 15: cout << "fifteen"; break;
   case 16: cout << "sixteen"; break;
   case 17: cout << "seventeen"; break;
   case 18: cout << "eighteen"; break;
   case 19: cout << "nineteen"; break;
   case 20: cout << "twenty"; break;
   default: cout << "Khong hop le";
   }
}
void BT11 () {
   double a, b, c, A, B, C;
   cin >> a >> b >> c >> A >> B >> C;
   double D = a * B - A * b;
   double Dx = c * B - C * b;
   double Dy = a * C - A * c;
   if ( D != 0 ) {
      double x = Dx / D;
      double y = Dy / D;
      cout << "He co nghiem duy nhat: " << endl;
      cout << "x = " << x << endl;
      cout << "y = " << y << endl;
   } else {
      if ( Dx == 0 && Dy == 0 ) {
         cout << "Vo so nghiem";
      } else {
         cout << "Vo nghiem";
      }
   }
}
void BT12 () {
   int n, m;
   double S = 0;
   cin >> n;
   cin >> m;
   for (int i = 1; i <= n; i++) {
      S += pow(i, m);
   }
   cout << "S(m) = " << S;
}
void BT13 () {
   int n, m;
   long long M;
   cin >> n >> m >> M;
   double S = 0;
   int i = 1;
   while (i <= n && S + pow(i, m) <= M) {
      S += pow(i, m);
      i++;
   }
   cout << "Tong lon nhat <= M la: " << S << endl;
   cout << "Dung den i = " << i - 1;
}
void BT14 () {
   string PIN = "123456", nhap;
   int max_trial;
   cout << "Nhap so lan thu toi da: ";
   cin >> max_trial;
   int dem = 0;
   while (dem < max_trial)  {
      cout << "Nhap PIN: ";
      cin >> nhap;
      if (nhap == "654321") {
         cout << "Security Alert!";
         return;
      }
      if (nhap == PIN) break;
      dem++;
   }
   if (dem == max_trial) {
      cout << "Khoa the!";
      return;
   }
   double A, a;
   cout << "Nhap so du: ";
   cin >> A;
   cout << "Nhap so tien muon rut: ";
   cin >> a;
   if  (a > A)
      cout << "So tien rut lon hon so du!";
   else {
      A -= a;
      cout << "Rut thanh cong!\nSo du con lai: " << A;
   }
}
int main () {
   int kiemtra;
   cout << "Kiem tra 1-14 bai tap: ";
   cin >> kiemtra;
   switch (kiemtra) {
   case 1: BT1(); break;
   case 2: BT2(); break;
   case 3: BT3(); break;
   case 4: BT4(); break;
   case 5: BT5(); break;
   case 6: BT6(); break;
   case 7: BT7(); break;
   case 8: BT8(); break;
   case 9: BT9(); break;
   case 10: BT10(); break;
   case 11: BT11(); break;
   case 12: BT12(); break;
   case 13: BT13(); break;
   case 14: BT14(); break;
   default: cout << "Khong hop le!";
   }
}