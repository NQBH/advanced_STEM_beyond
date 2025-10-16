/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
int main()
{
    // Problem 4040
	bool p, q, r, s, is_satisfiable = false;
	for (int p = 0; p <= 1; ++p)
		for (int q = 0; q <= 1; ++q)
			for (int r = 0; r <= 1; ++r)
				for (int s = 0; s <= 1; ++s) {
					if (!(!(!p || q) || r) || s) {
						is_satisfiable = true;
						cout << "satisfiable\n" << p << " " << q << " " << r << " " << s << '\n';
						return 0;					
					}
				}
	if (is_satisfiable == false) cout << "unsatisfiable";
}