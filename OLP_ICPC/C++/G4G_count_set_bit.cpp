#include <iostream>
using namespace std;
// count number of set bits in a number using AND operation & left shifting
int count_set_bit_and(int n) { // time complexity: O(log2 n) & auxiliary space: O(1)
	int count = 0;	
	while (n) { // run still n > 0
		count += n & 1; // check least significant bit
		n >>= 1; // right shift number by 1
	}
	return count;
}
// count number of set bits in a number using Brian Kernighan's algorithm
int count_set_bit_Brian_Kernighan_alg(int n) { // time complexity: O(log2 n) & auxiliary space: O(1)
	int count = 0;
	while (n) { // run till n becomes 0
		n &= (n - 1); // turn off/reset the rightmost set bit
		++count;
	}
	return count;
}
// count number of set bits in a number using a lookup table
unsigned char bit_set_table256[256];
// function to initialize lookup table
void initialize() {
	bit_set_table256[0] = 0;
	for (int i = 1; i < 256; ++i)
		bit_set_table256[i] = (i & 1) + bit_set_table256[i / 2];
}
// time complexity: O(1), time for creating lookup table is not considered
// auxiliary space: O(1), space for lookup table is not considered
int count_set_bit_lookup_table(int n) {
	return bit_set_table256[n & 0xFF] +  bit_set_table256[(n >> 8) & 0xFF] + bit_set_table256[(n >> 16) & 0xFF] +  bit_set_table256[(n >> 24) & 0xFF];
}

int main() {
	int n;
	cin >> n;
	// count & print set bits in n
	cout << count_set_bit_and(n) << '\n';
	cout << count_set_bit_Brian_Kernighan_alg(n) << '\n';
	initialize();
	cout << count_set_bit_lookup_table(n) << '\n';
}