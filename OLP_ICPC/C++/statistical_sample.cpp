#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000 // max length of statistical sample

double median(double x[], int statistical_sample_length) {
	double Me;
	sort(x, x + statistical_sample_length + 1); // sorting increasing/ascending order
	if (statistical_sample_length % 2 != 0)
		Me = x[(statistical_sample_length + 1) / 2];
	else
		Me = (x[statistical_sample_length / 2] + x [statistical_sample_length / 2 + 1]) / 2;
	return Me;
}

int main() {
	int statistical_sample_length, sum_n = 0;
	double avg, sum = 0.0, Me, x[MAX] = {0}, x_left[MAX / 2] = {0}, x_right[MAX / 2] = {0}, n[MAX] = {0}, f[MAX] = {0};
	cin >> statistical_sample_length;

	// compute sum
	for (int i = 0; i < statistical_sample_length; i++) {
		cin >> x[i];
		sum += x[i];
	}

	// compute average
	avg = sum / statistical_sample_length;
	cout << avg << "\n";

	// compute average via frequencies (number of appearances)
	sum = 0.0; // reset
	cin >> statistical_sample_length;
	for (int i = 0; i < statistical_sample_length; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < statistical_sample_length; i++) {
		cin >> n[i];
		sum += x[i] * n[i];
		sum_n += n[i];
	}
	avg = sum / sum_n;
	cout << avg << "\n";

	// compute average via frequencies
	avg = 0.0; // reset
	for (int i = 0; i < statistical_sample_length; i++) {
		cin >> f[i];
		avg += x[i] * f[i];
	}
	cout << avg << "\n";

	// compute median
	cin >> statistical_sample_length;
	for (int i = 0; i < statistical_sample_length; i++) {
		cin >> x[i];
	}

	Me = median(x, statistical_sample_length);
	cout << Me << "\n";

	// compute quartile Q1, Q2, Q3
	cout << "compute quartile Q1, Q2, Q3";
	double Q1, Q2, Q3;
	cin >> statistical_sample_length;
	x[statistical_sample_length] = {0};
	for (int i = 0; i < statistical_sample_length; i++) {
		cin >> x[i];
	}
	sort(x, x + statistical_sample_length + 1); // sorting increasing/ascending order
	if (statistical_sample_length % 2 != 0)
		Me = x[(statistical_sample_length + 1) / 2];
	else
		Me = (x[statistical_sample_length / 2] + x [statistical_sample_length / 2 + 1]) / 2;
	Q2 = Me;
	cout << "start debug";
	if (statistical_sample_length % 2 == 0) {
		for (int i = 0; i < statistical_sample_length / 2; i++)
			x_left[i] = x[i];
		for (int i = statistical_sample_length / 2 - 1; i < statistical_sample_length; i++)
			x_right[i - statistical_sample_length / 2 + 1] = x[i];
		for (int i = 0; i < statistical_sample_length / 2; i++) {
			cout << x_left[i] << " ";
		}
		cout << "break";
		for (int i = 0; i < statistical_sample_length / 2; i++) {
			cout << x_right[i] << " ";
		}
		Q1 = median(x_left, statistical_sample_length / 2);
		Q3 = median(x_right, statistical_sample_length / 2);
	}
	else {
		for (int i = 0; i < (statistical_sample_length - 1) / 2; i++)
			x_left[i] = x[i];
		for (int i = (statistical_sample_length + 1) / 2 ; i < statistical_sample_length; i++)
			x_right[i - (statistical_sample_length + 1) / 2] = x[i];
		Q1 = median(x_left, (statistical_sample_length - 1) / 2);
		Q3 = median(x_right, (statistical_sample_length - 1) / 2);
	}
	cout << Q1 << " " << Q2 <<" " << Q3 << "\n";
}