#include <iostream>
#include <vector>
using namespace std;

template <class T>
void array_make(vector<T>& a, T elements[], int n) { // create dynamic array
	int i = 0;
	a.resize(0);
	while (i < n) {
		a.push_back(elements[i]);
		++i;
	}
}

template <class T>
void array_out(vector<T>& a, ostream& outDev) { // output dynamic array
	for (int i = 0; i < a.size(); ++i) outDev << a[i] << " ";
	outDev << '\n';
}

template <class T>
void array_cat(vector<T>& dest, vector<T>& src) { // concatenate dynamic arrays
	int dest_size = dest.size(), src_size = src.size(), idx = dest_size, new_size = dest_size + src_size, i = 0;
	dest.resize(new_size);
	while (i < src_size) {
		dest[idx] = src[i];
		++idx;
		++i;
	}
}

template <class T>
void array_cut_from(vector<T>& a, int pos, vector<T>& b) { // cut dynamic array
	int size = a.size(), j = pos;
	if (j < 0 || j >= size) return;
	b.resize(0);
	while (j < size) {
		b.push_back(a[j]);
		++j;
	}
	a.resize(pos);
}

template <class T>
void array_insert(vector<T>& a, int pos, T element) { // insert element
	if (pos < 0 || pos >= a.size()) return;
	vector<T> b;
	array_cut_from(a, pos, b);
	a.push_back(element);
	array_cat(a, b);
}

int main() {
	int x[] = {3, 5, 2, 4, 9, 7, 8, 6}, n = sizeof(x) / sizeof(x[0]);
	vector<int> a, b, c;
	array_make(a, x, n);
	cout << "a: ";
	array_out(a, cout);
	array_cut_from(a, 3, b);
	cout << "a now: ";
	array_out(a, cout);
	cout << "b: ";
	array_out(b, cout);
	array_cat(b, a);
	cout << "b now: ";
	array_out(b, cout);
	a.pop_back();
	cout << "a now: ";
	array_out(a, cout);
	array_insert(b, 3, 999);
	cout << "b now: ";
	array_out(b, cout);
}