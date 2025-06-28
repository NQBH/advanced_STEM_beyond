// PPP_traffic_lights.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
using l = long;

l street_length;
l num_lights;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> street_length >> num_lights;
	vector<l> lights(num_lights);

	// Khởi tạo tập hợp các vị trị lắp đèn đường 
	set<l> street_position{ 0, street_length };

	for (l i = 0; i < num_lights; ++i) 
		cin >> lights[i];

	multiset<l> gaps{ street_length };             // Lưu khoảng cách giữa các đèn

	for (l i = 0; i < num_lights; ++i) 
	{
		l pos = lights[i]; // Đèn mới sẽ được gắn tại vị trí pos

		auto it = street_position.upper_bound(pos);
		l right = *it;                  // Tìm đèn bên phải gần nhất
		l left = *prev(it);            // Tìm đèn bên trái gần nhất

		// Đoạn (left, right) bị cắt đôi bởi đèn tại pos
		gaps.erase(gaps.find(right - left));  // Xóa khoảng cách cũ này khỏi multiset

		// Thêm hai khoảng cách mới: (left, pos) và (pos, right)
		gaps.insert(pos - left);
		gaps.insert(right - pos);

		street_position.insert(pos);  // Cập nhật vị trí đèn mới vào set

		cout << *gaps.rbegin() << ' ';  // In ra khoảng cách dài nhất hiện tại
	}

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
