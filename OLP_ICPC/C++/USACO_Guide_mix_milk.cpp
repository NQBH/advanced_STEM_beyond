#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int N = 3; // the number of buckets (which is 3)
const int NUM_TURN = 100;

int main() {
	vector<int> capacity(N); // capacity[i] is the maximum capacity of bucket i
	vector<int> milk(N); // milk[i] is the current amount of milk in bucket i
	for (int i = 0; i < N; ++i) scanf("%d %d", &capacity[i], &milk[i]);
	for (int i = 0; i < NUM_TURN; ++i) {
		int bucket1 = i % N;
		int bucket2 = (i + 1) % N;
		/*
		 * The amount of milk to pour is the minimum of the remaining milk
		 * in bucket 1 and the available capacity of bucket 2
		 */
		int amt = min(milk[bucket1], capacity[bucket2] - milk[bucket2]);
		milk[bucket1] -= amt;
		milk[bucket2] += amt;
	}
	for (int m : milk) cout << m << '\n';
}