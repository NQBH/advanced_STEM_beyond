#include <iostream>
using namespace std;

bool is_bipartite_Cn(int n) {
    // n: so dinh cua do thi Cn
    // Tra ve true neu n chan (Cn luong phan)
    return n % 2 == 0;
}

bool is_bipartite_Kn(int n) {
    // n: so dinh cua do thi Kn
    // Tra ve true neu n <= 2 (Kn luong phan)
    return n <= 2;
}

int main() {
    cout << "Is C_4 bipartite? " << is_bipartite_Cn(4) << endl; // 1
    cout << "Is K_3 bipartite? " << is_bipartite_Kn(3) << endl; // 0
    return 0;
}