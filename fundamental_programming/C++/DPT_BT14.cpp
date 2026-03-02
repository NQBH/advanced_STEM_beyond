#include <iostream>
#include <cmath>
using namespace std;
string daonguoc(string s) {
	string reverse = "";
	for (int i = s.length() - 1; i >= 0; i--) {
		reverse += s[i];
	}
	return reverse;
}
int main() {
	long long A;
	long long a;
	int max_trial;
	string pin_thiet, pin_nhapvao;
	cout << "So du trong tai khoan: ";
	cin >> A;
	cout << "So tien muon rut: ";
	cin >> a;
	cout << "So lan thu toi da: ";
	cin >> max_trial;
	cout << "Thiet lap ma PIN: ";
	cin >> pin_thiet;
	int sopinsai = 0;
	bool pindung = false;
	while (sopinsai < max_trial) {
		cout << "Nhap ma PIN: ";
		cin >> pin_nhapvao;
		if (pin_nhapvao == daonguoc(pin_thiet)) {
			cout << "SECURITY DANG DEN! Ban vua nhap PIN nguoc " << '\n';
			return 0;
		}
		if (pin_nhapvao == pin_thiet) {
			pindung = true;
			break;
		}
		else {
			sopinsai++;
			cout << "Sai PIN " << '\n';
		}
	}
	if (!pindung) {
		cout << "The da bi khoa do nhap sai qua so lan cho phep " << '\n';
		return 0;
	}
	if (a > A) {
		cout << "So tien rut lon hon so du kha dung " << '\n';
		cout << "Ban bi ao tuong suc manh tai chinh a " << '\n';
	}
	else {
		A -= a;

		cout << '\n' << "     HOA DON ATM       " << '\n';
		cout << "So tien rut: " << a << " VND " << '\n';
		cout << "So du con lai: " << A << " VND " << '\n';
		cout << "Giao dich thanh cong " << '\n';
		cout << "Cam on quy khach " << '\n';
		cout << "==============================\n";
	}

	return 0;
}
