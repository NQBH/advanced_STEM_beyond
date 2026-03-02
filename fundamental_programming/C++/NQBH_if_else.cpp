#include <iostream>
#include <cmath>
using namespace std; // standard

int a = 1; // global variable: biến toàn cục

int f() {
	double b = 2.1, c = 1.5;
	return 2 * a + b + c;
}

int main() {
	double a = 1, b, c;
	if (a == 1) {
		b = 2, c = 3;
		// b & c can be used here in this code block only
	} else if (a == 2) {
		b = 0, c = 1;
	} else if (a == 3) {
		b = -1, c = 5;
	} else {
		b = 0, c = 0;
	}

	switch(a) {
	case 1: b = 2, c = 3;
	case 2: b = 0, c = 1;
	case 3: b = -1, c = 5;
	default: b = 0, c = 0;
	}

}