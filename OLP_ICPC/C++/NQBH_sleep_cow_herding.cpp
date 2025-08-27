#include <iostream>
using namespace std;

int main() {
	int a[3], a_min[3], a_max[3], min_ans, max_ans;
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	for (int i = 0; i < 3; ++i) a_min[i] = a_max[i] = a[i];
	while (a_min[2] - a_min[0]) > 2 {
		if (a_min[2] - a_min[1] > a_min[1] - a_min[0]) {

		}
		else {
			
		}
	}
	while (a_max[2] - a_max[0]) > 2 {

		
	}
}