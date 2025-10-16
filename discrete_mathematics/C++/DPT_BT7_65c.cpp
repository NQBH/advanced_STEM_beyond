/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
int main() {
	//cau 65(c)
	bool p, q, r, s, is_satisfiable = false;
	for (int p = 0; p <= 1; ++p)
		for (int q = 0; q <= 1; ++q) {
			if ((p == q) && (!p == q)) {
				is_satisfiable = true;
				cout << "satisfiable\n" << p << " " << q <<  '\n';
				return 0;
			}
		}
	if (is_satisfiable == false) cout << "unsatisfiable";


}
