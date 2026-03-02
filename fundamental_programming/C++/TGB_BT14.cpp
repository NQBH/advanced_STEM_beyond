#include <iostream>
#include <string>
using namespace std;
int main() {
	long long A, a;
	string realpin, pin_input;
	int max_trial;
	cout << "Nhap so du tai khoan A: ";
	cin >> A;
	cout << "Nhap so tien can rut a: ";
	cin >> a;
	cout << "Nhap ma PIN that: ";
	cin >> realpin;
	cout << "Nhap so lan thu toi da: ";
	cin >> max_trial;
	int trial = 0;
	bool locked = false;
	bool security = false;
	while (trial < max_trial) {
		cout << "Nhap ma PIN: ";
		cin >> pin_input;
		if (pin_input == realpin) {
			cout << "dang nhap thanh cong" << '\n';
			break;
		} else {
			trial++;
			if (trial < max_trial) {
				cout << "sai ma pin" << '\n';
			}
			string reversedin = string(realpin.rbegin(), realpin.rend());
			if (pin_input == reversedin) {
				cout << "canh bao bao mat:" << '\n';
				security = true;
				break;
			}
			trial++;
			if (trial < max_trial) {
				cout << "Sai ma PIN. Vui long thu lai." << '\n';
			}
		}
	}
	if (trial == max_trial && !security && pin_input != realpin) {
		cout << "The bi khoa" << '\n';
		locked = true;
	}
	if (!locked && !security && pin_input == realpin) {
		if (a > A) {
			cout << "so tien rut hon so du" << '\n';
		} else {
			A = A - a;
			cout << "rut tien thanh cong. so du con lai: " << A << '\n';
		}
	}
}