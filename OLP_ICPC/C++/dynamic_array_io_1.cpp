#include <iostream>
#include <vector>
using namespace std;

void array_float_input(vector<float> &a) {
	float x;
	while (cin >> x) a.push_back(x);
}

void array_float_output(const vector<float> &a) {
	for (int i = 0; i < a.size(); ++i) cout << a[i] << " ";
}

int main() {
	vector<float> a;
	cout << "Input an array, press Ctrl X then Enter to stop: " << '\n';
	array_float_input(a);
	cout << "Element(s) in the array: ";
	array_float_output(a);	
}