#include <iostream>;
#include <cmath>
using namespace std;

int main() {
	float a;//CD
	float b;//CR
	float c; //dg cao
	float d ; //dg chéo
	float S; //DTTP
	float s;//DTXQ
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	if (a < 0 || b < 0 || c < 0) {
		cout << "không có hình" << endl;
	}
	else if (a == b , b == c , a == c) {
		cout << "HLP" << '\n';
	}
	else if (a == b , a != c || b == c , c != a) {
		cout << "HHCN" << endl;
		d = sqrt(a * a + b * b + c * c );
		cout << "dg chéo =" << d << endl;
		s = (a + b) * 2 * c ;
		cout << "DTXQ =" << s << endl;
		S = s + 2 * a * b;
		cout << "DTTP =" << S << endl;
	}
	else {
		cout << "-1" << endl;
	}


	return 0;
}
