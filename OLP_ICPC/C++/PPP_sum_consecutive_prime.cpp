// Sum of consecutive prime numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
using namespace std;

bool prime_number_checking(unsigned x)
{
    if (x == 0 || x == 1)
        return false; 
    if (x >= 2)
    {
        for (unsigned k = 2; k * k <= x; k++)
            if (x % k == 0)
                return false;
    }
    return true;
}

int main()
{
    vector<int> primes;
    for (int i = 2; i <= 10000; i++) 
    {
        if (prime_number_checking(i))
            primes.push_back(i);
    }
    
    unsigned p; // Khai báo biến nhập vào 
    while (true)
    {
        cout << "Nhap so nguyen p (nhap 0 de thoat): ";
        cin >> p;
        if (p == 0) break;

        int count = 0;

        // Tìm các dãy liên tiếp có tổng bằng p
        for (int i = 0; i < primes.size(); i++)
        {
            int tong = 0;
            vector<int> current_sequence;
            for (int j = i; j < primes.size(); j++)
            {
                tong += primes[j];
                current_sequence.push_back(primes[j]);

                if (tong == p)
                {
                    // In ra dãy thỏa điều kiện
                    cout << "Cach " << ++count << ": ";
                    for (int num : current_sequence)
                        cout << num << " ";
                    cout << endl;
                    break;
                }
                else if (tong > p) {
                    break;
                }
            }
        }

        if (count == 0)
            cout << "Khong co cach nao bieu dien " << p << " bang tong cac so nguyen to lien tiep." << endl;
        else
            cout << "Tong cong co " << count << " cach." << endl;
    }
    

    return 0;
}