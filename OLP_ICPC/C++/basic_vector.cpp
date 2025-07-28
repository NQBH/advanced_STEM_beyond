#include <iostream>
#include <vector>
using namespace std;

void int_array_make(vector<int>& a, int elements[], int n) { // create dynamic array
	int i = 0;
	a.resize(0);
	while (i < n) {
		a.push_back(elements[i]);
		++i;
	}
}

void int_array_out(vector<int>& a, ostream& outDev) { // output dynamic array
	for (int i = 0; i < a.size(); ++i) outDev << a[i] << " ";
	outDev << '\n';
}

void int_array_cat(vector<int>& dest, vector<int>& src) { // concatenate dynamic arrays
	int dest_size = dest.size(), src_size = src.size(), idx = dest_size, new_size = dest_size + src_size, i = 0;
	dest.resize(new_size);
	while (i < src_size) {
		dest[idx] = src[i];
		++idx;
		++i;
	}
}

void int_array_cut_from(vector<int>& a, int pos, vector<int>& b) { // cut dynamic array
	int size = a.size(), j = pos;
	if (j < 0 || j >= size) return;
	b.resize(0);
	while (j < size) {
		b.push_back(a[j]);
		++j;
	}
	a.resize(pos);
}

void int_array_insert(vector<int>& a, int pos, int element) { // insert element
	if (pos < 0 || pos >= a.size()) return;
	vector<int> b;
	int_array_cut_from(a, pos, b);
	a.push_back(element);
	int_array_cat(a, b);
}

int main() {
	int x[] = {3, 5, 2, 4, 9, 7, 8, 6}, n = sizeof(x) / sizeof(x[0]);
	vector<int> a, b, c;
	int_array_make(a, x, n);
	cout << "a: ";
	int_array_out(a, cout);
	int_array_cut_from(a, 3, b);
	cout << "a now: ";
	int_array_out(a, cout);
	cout << "b: ";
	int_array_out(b, cout);
	int_array_cat(b, a);
	cout << "b now: ";
	int_array_out(b, cout);
	a.pop_back();
	cout << "a now: ";
	int_array_out(a, cout);
	int_array_insert(b, 3, 999);
	cout << "b now: ";
	int_array_out(b, cout);
}