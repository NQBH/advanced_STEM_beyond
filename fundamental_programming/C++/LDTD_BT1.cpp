#include <iostream>

using namespace std;

int main() {

  float  chuvi, dientich;
  // canh hinh vuong //
  int a = 2 ;

  // tinh chu vi hinh vuong C = ( a * 4 );
  // tinh dien tich hinh chu nhat  S = a * a ;

  cout << " nhap canh a : ";
  cin >> a ;


  chuvi = ( a * 4) ;
  dientich = ( a * a );


  cout << "\nChu vi hinh vuong: " << chuvi << endl;
  cout << "Dien tich hinh vuong: " << dientich << endl;

  return 0;
}