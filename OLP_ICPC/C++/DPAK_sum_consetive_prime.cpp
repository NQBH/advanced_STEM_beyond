/*
Source: ACM Japan 2005.
IDs for online judges: POJ 2739, UVA 3399.
Status: Accepted
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> primes;

int main() {
	for (int i = 2; i <= 10000; i++) {
		bool check = true;

		for (int j = 2; j <= sqrt((double)i); j++) {
			if (i % j == 0) {
				check = false;
				break;
			}
		}
		if (check) {
			primes.push_back(i);
		}
	}

	int N;
	while (cin >> N && N != 0) {
		int count = 0;
		int left = 0, right = 0, sum = 0;

		while (right < primes.size()) {
			if (sum < N) {
				sum += primes[right++];
			}
			else if (sum > N) {
				sum -= primes[left++];
			}
			else {
				count++;
				sum -= primes[left++];
			}
		}

		cout << count << endl;
	}
}