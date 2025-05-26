// Double.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main() 
{
    while (true) 
    {
        int a[20];  // Mảng tối đa 20 phần tử
        int n = 0;  // Đếm số phần tử trong dòng hiện tại
        int x;

        cout << "Nhap cac so nguyen (ket thuc bang 0, -1 de ket thuc chuong trinh):\n";

        // Đọc một dòng dữ liệu
        while (cin >> x && x != 0) 
        {
            if (x == -1) return 0; // Kết thúc toàn bộ chương trình
            a[n++] = x;
        }

        // Đếm số phần tử là gấp đôi phần tử khác
        int count = 0;  // Biến đếm số lượng phần tử là gấp đôi của phần tử khác
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (i != j && a[i] == 2 * a[j]) 
                {
                    count++;
                    break; // Tránh đếm trùng
                }
            }
        }

        cout << count << endl;  // Trả về kết quả
    }

    return 0;
}