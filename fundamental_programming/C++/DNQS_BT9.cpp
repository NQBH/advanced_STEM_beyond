#include<iostream>
#include<cmath>
using namespace std;

int main() {
  int n, x;
  cout << "nhap so luong phan tu : " ;
  cin >> n;
  int chan = 0, le = 0;
  for (int i = 0; i < n; i++)
  { cout << "nhap so thu " << i + 1 << ": ";
    cin >> x;
    if (x % 2 == 0) {
      chan++;
    }
    else {
      le++;
    }
  }
  cout << "So chan: " << chan << ", So le: " << le << endl;
  return 0;
}