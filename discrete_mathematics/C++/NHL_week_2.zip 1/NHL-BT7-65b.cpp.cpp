/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

int main()
{
    // Problem 
	bool p, q, is_satisfiable = false;
	for (int p = 0; p <= 1; ++p)
		for (int q = 0; q <= 1; ++q) {
   if (( !p || q) && (!p || !q) && (p || q) && (p || !q)) {
       	is_satisfiable = true;
					std::cout << "satisfiable " << p << " " << q << '\n';
					}
				}
	if (is_satisfiable == false) std::cout << "unsatisfiable";

}