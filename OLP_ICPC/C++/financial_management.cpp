// source: [Wu_Wang2016, p. 5]
#include<iostream>
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
// nqbh@nqbh-msi:~/advanced_STEM_beyond/OLP_ICPC/C++$ g++ -O2 -Wall financial_management.cpp -o financial_management
// nqbh@nqbh-msi:~/advanced_STEM_beyond/OLP_ICPC/C++$ ./financial_management < financial_management.inp > financial_management.out