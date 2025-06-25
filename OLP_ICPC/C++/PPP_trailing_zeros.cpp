// PPP_trailing_zeros.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
using ull = unsigned long long;

ull n;

// Bài "Trailing Zeros" với mình là tìm xem giai thừa của 1 số nguyên có thể chia hết cho 10 bao nhiêu lần
// Và khi tính giai thừa của 1 số nguyên thì có sự xuất hiện của việc phân tích kết quả thành các thừa số nguyên tố,
// đặc biệt có 2 số 2 và 5, trong đó bội số của số 2 xuất hiện nhiều hơn. Như vậy thì chúng ta sẽ tìm xem số 5 xuất hiện
// bao nhiêu lần trong khi phân tích giai thừa của số nguyên n thành các thừa số nguyên tố. Từ đó xác định số lượng số
// lượng số 0 trong giai thừa của số nguyên n 
ull n_solve(ull n)
{
    if (n == 0)
        return 0;
    else
    {
        ull count = 0;
        for (ull i = 5; n / i >= 1; i *= 5)
        {
            count += n / i;
        }
        return count;
    }
}

int main()
{
    cin >> n;
    cout << n_solve(n) << endl;
    return 0; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
