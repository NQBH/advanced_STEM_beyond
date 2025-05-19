#include <iostream>
using namespace std;
const long nMAX = 10000;

// recurrence
long fib(long i) {
	if (i == 0 || i == 1)
		return 1;
	else
		return fib(i - 1) + fib(i - 2);
}

// \cite{Thu_Phuong_Tien_Triet_Phuong_KTLT}, p. 443
long fib_recurrence(long n) {
	long ans, Fn_1, Fn_2;
	if (n <= 1)
		ans = 1;
	else {
		Fn_1 = fib_recurrence(n - 1);
		Fn_2 = fib_recurrence(n - 2);
		ans = Fn_1 + Fn_2;
	}
	return ans;
}

// \cite{Thu_Phuong_Tien_Triet_Phuong_KTLT}, p. 443
long fib_dynamic(long n) {
	long F[nMAX + 1];
	F[0] = F[1] = 1;
	for (int i = 2; i <=n; ++i)
		F[i] = F[i - 1] + F[i - 2];
	return F[n];
}

long Lucas_dynamic(long n) {
	long L[nMAX + 1];
	L[0] = 2;
	L[1] = 1;
	for (int i = 2; i <=n; ++i)
		L[i] = L[i - 1] + L[i - 2];
	return L[n];
}

// \cite{Thu_Phuong_Tien_Triet_Phuong_KTLT}, p. 443
long fib_dynamic_improved(long n) {
	long lastF = 1, F = 0;
	int i = 0;
	while (i <= n) {
		F += lastF;
		lastF = F - lastF;
		++i;
	}
	return F;
}

long Lucas_dynamic_improved(long n) {
	long lastL = 2, L = 1;
	int i = 1;
	while (i < n) {
		L += lastL;
		lastL = L - lastL;
		++i;
	}
	return L;
}

int main() {
	long n, i;
	cin >> n;
	cout << "Fibonacci sequence of length " << n << ":\n";

	for (i = 0; i <= n; ++i)
		cout << fib(i) << " ";
	cout << "\n";

	for (i = 0; i <= n; ++i)
		cout << fib_recurrence(i) << " ";
	cout << "\n";

	for (i = 0; i <= n; ++i)
		cout << fib_dynamic(i) << " ";
	cout << "\n";

	for (i = 0; i <= n; ++i)
		cout << fib_dynamic_improved(i) << " ";
	cout << "\n";

	cout << "Lucas sequence of length " << n << ":\n";

	for (i = 0; i <= n; ++i)
		cout << Lucas_dynamic(i) << " ";
	cout << "\n";

	for (i = 0; i <= n; ++i)
		cout << Lucas_dynamic_improved(i) << " ";
	cout << "\n";
}