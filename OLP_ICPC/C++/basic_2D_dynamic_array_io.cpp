#include <iostream>
#include <vector>
using namespace std;

typedef vector<float> floats;
typedef vector<floats> float2D;

void float2D_init(float2D &a, int n) {
	a.resize(n);
	for (int i = 0; i < a.size(); ++i) a[i].resize(n);
}

void float2D_input(float2D &a) {
	for (int i = 0; i < a.size(); ++i)
		for (int j = 0; j < a[i].size(); ++j) cin >> a[i][j];
}

void float2D_output(float2D &a) {
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a[i].size(); ++j) cout << a[i][j] << '\t';
		cout << '\n';
	}
}

int main() {
	float2D a;
	int n;
	cout << "Size of square array: ";
	cin >> n;
	if (n <= 0) {
		cout << "Invalid size";
		return 1;
	}
	float2D_init(a, n);
	cout << "Input elements of square array: " << '\n';
	float2D_input(a);
	cout << "Elements of square array: " << '\n';
	float2D_output(a);
}