#include <iostream>
using namespace std;

int main () {


//Problem6
	//Problem 65a
	bool p, q, r, s, is_satisfiable = false;
	for (int p = 0; p < 2; ++p)
		for (int q = 0; q < 2; ++q) {
			if ((p || !q) && (!p || q) && (!p || !q)) {
				is_satisfiable = true;
				cout << "satisfiable\n" << p << " " << q << endl;
			}
		}

	//Problem 65b
	for (int p = 0; p < 2; ++p)
		for (int q = 0; q < 2; ++q) {
			if ((p || q) && (p || !q) && (!p || q) && (!p || !q)) {
				is_satisfiable = true;
				cout << "satisfiable\n" << p << " " << q << endl;
			}
		}

	//Problem 65c
	for (int p = 0; p < 2; ++p)
		for (int q = 0; q < 2; ++q) {
			if ((p || q) && (!p || q)) {
				is_satisfiable = true;
				cout << "satisfiable\n" << p << " " << q << endl;
			}
		}


//Problem 7
	//Problem 66a
	for (int p = 0; p < 2; ++p)
		for (int q = 0; q < 2; ++q)
			for (int r = 0; r < 2; ++r)
				for (int s = 0; s < 2; ++s) {
					if ((p || q || !r) && (p || !q || !s) && (p || !r || !s) && (!p || !q || !s) && (p || q || !s)) {
						is_satisfiable = true;
						cout << "satisfiable\n" << p << " " << q << " " << r << " " << s << endl;
					}
				}

	//Problem 66b
	for (int p = 0; p < 2; ++p)
		for (int q = 0; q < 2; ++q)
			for (int r = 0; r < 2; ++r)
				for (int s = 0; s < 2; ++s) {
					if (( !p || !q || r) && (!p || q || !s) && (p || !q || !s) && (!p || !r || !s) && (p || q || !r) && (p || !r || !s))  {
						is_satisfiable = true;
						cout << "satisfiable\n" << p << " " << q << " " << r << " " << s << endl;
					}
				}

	//Problem 66c
	for (int p = 0; p < 2; ++p)
		for (int q = 0; q < 2; ++q)
			for (int r = 0; r < 2; ++r)
				for (int s = 0; s < 2; ++s) {
					if (( p || q || r) && (p || !q || !s) && (q || !r || s) && (!p || r || s) && (!p || q || !s) && (p || !q || !r) && (!p || !q || s) && (!p || !r || !s))  {
						is_satisfiable == true;
						cout << "satisfiable\n" << p << " " << q << " " << r << " " << s << endl;
					}
				}
	return 0;
}