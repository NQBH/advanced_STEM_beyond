#include <iostream>
using namespace std;

int n;
string current_string;

void generate_string(int pos) { // backtracking
	if (pos > n) {
		cout << current_string << '\n';
		return;
	}
	for (char i = '0'; i <= '1'; ++i) {
		current_string.push_back(i); // add new character into string
		generate_string(pos + 1);
		current_string.pop_back(); // remove character just added
	}
}

int main() {
	cin >> n;
	current_string = "";
	generate_string(1);
}