#include <iostream>
using namespace std;

int main() {
	int l = 1, r = 1000000;
	while (l != r) {
		int mid = (l + r + 1) / 2;
		cout << mid << '\n';
		string response;
		cin >> response;
		if (response == "<") r = mid - 1;
		else l = mid;
	}
	cout << "! " << l << '\n';
}