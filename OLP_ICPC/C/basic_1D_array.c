#include <stdio.h>
#define N 50 // const int N = 50

void array_int_input(int a[], int& n) {
	while (1) {
		printf("The number of elements needed to use (<= %d): ", N);
		scanf("%d", &n);
		if ((n < 0) || (n > N)) printf("Wrong input, re-input ...\n");
		else break;
	}
	for (int i = 0; i < n; ++i) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void array_int_output(int a[], int n) {
	for (int i = 0; i < n; ++i) printf("%d ", a[i]);
}

bool insert(int a[], int &n, int x, int k) {
	int (k < 0 || k > n) return false;
	for (int i = n - 1; i >= k; --i) a[i + 1] = a[i];
	a[k] = x;
	++n;
	return true;
}

void remove(int a[], int &n, int k) {
	int (k < 0 || k > n) return;
	a[k] = a[n - 1];
	--n;
}

void remove_preserving_order(int a[], int &n, int k) {
	if (k < 0 || k > n) return;
	for (int i = k; i < n - 1; ++i) a[i] = a[i + 1];
	--n;
}

void split_even_odd(int a[], int n, int even[], int &k, int odd[], int &h) {
	k = h = 0;
	for (int i = 0; i < n; ++i)
		if (a[i] % 2 == 0) even[k++] = a[i]; // <=> even[k] = a[i]; ++k;
		else odd[h++] = a[i]; // <=> odd[h] = a[i]; ++h;

}

void split_half(int a[], int n, int b[], int &k, int c[], int &h) {
	int i;
	h = k = 0;
	for (i = 0; i < n / 2; ++i) b[k++] = a[i];
	for (i = n / 2; i < n; ++i) c[h++] = a[i];
}

void array_int_concatenation(int a[], int &n, int b[], int k, int c[], int h) {
	int i;
	n = 0;
	for (i = 0; i < k; ++i) a[n++] = b[i];
	for (i = 0; i < h; ++i) a[n++] = c[i];
}

void array_int_concatenation_zigzag(int a[], int &n, int b[], int k, int c[], int h) {
	int i, j;
	i = j = n = 0;
	while (i < k && j < h) {
		if (n % 2 == 0) a[n++] = b[i++];
		else a[n++] = c[j++];
	}
	while (i < k) a[n++] = b[i++];
	while (j < h) a[n++] = c[j++];
}

int main() {
	// initialization 1D array
	/*
	int a[5] = {1, 3, 5, 7, 9};
	int a[5] = {1, 3, 5};
	int a[5] = {0};	
	int a[] = {1, 3, 5}, n = sizeof(a) / sizeof(a[0]);
	*/
	int b[N], m;
	array_int_input(b, m);
	array_int_output(b, m);
	return 1;
}