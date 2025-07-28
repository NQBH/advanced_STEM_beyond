#include <iostream>
#include <vector>
using namespace std;

void array_input(vector<float> &a) {
	int n;
	cin >> n;
	if (n < 1) return; // invalid size
	a.resize(n);
	for (int i = 0; i < a.size(); ++i) cin >> a[i];
}

void array_output(vector<float> &a) {
	for (int i = 0; i < a.size(); ++i) cout << a[i] << " ";
}

int main() {
	vector<float> a;
	cout << "Input an array, 1st is the number of elements: " << '\n';
	array_input(a);
	cout << "Element(s) in the array: ";
	array_output(a);	
}