#include <iostream>
using namespace std;

int main() {
  double x, y, z;
  
  // Nhap gia tri
  cout << "Nhap x: ";
  cin >> x;
  
  cout << "Nhap y: ";
  cin >> y;
  
  cout << "Nhap z: ";
  cin >> z;
  
  // Menh de (a): x + 1 == 2
  if (x + 1 ==2)
      cout << "(a) x + 1 ==2:Dung" << endl;
  else 
      cout << "(a) x + 1 == 2:Sai" << endl;
        
  // Menh de (b): x + y == 2
  if (x + y == z)
      cout <<"(b) x + y == 2:Dung" << endl;
  else 
      cout <<"(b) x + y == 2:sai" << endl;
  return 0;
}
  

