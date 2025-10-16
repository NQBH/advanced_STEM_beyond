/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

int main()
{
     // Problem 39a
	bool p, q, r, s, is_satisfiable = false;
	for (int p = 0; p <= 1; ++p)
		for (int q = 0; q <= 1; ++q)
			for (int r = 0; r <= 1; ++r)
				for (int s = 0; s <= 1; ++s) {
   if (!p || (!q || r)) {
       	is_satisfiable = true;
					std::cout << "satisfiable " << p << " " << q << " " << r << " " << s << '\n';
					}
				}
	if (is_satisfiable == false) std::cout << "unsatisfiable";

}