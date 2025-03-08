#include <iostream>
using namespace std;
int main() {
	double avg, sum = 0.0, a[12] = {0};
	for (int i = 0; i < 12; ++i) { // input income of 12 motnhs a[0..11] & summation
		cin >> a[i];
		sum += a[i];
	}
	avg = sum/12; // compute average monthly
	printf("$%.2f", avg); // output average monthly
	return 0;
}