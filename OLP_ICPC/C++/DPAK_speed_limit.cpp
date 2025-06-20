/*
Source: ACM Mid-Central United States 2004
IDs for online judges:  POJ 2017, ZOJ 2176, UVA 3059.
Status: Accepted
*/
#include <iostream>
#include <vector>
using namespace std;

int main(){	
	int n; 
	while (cin >> n && n != -1) {
		vector<pair<int, int>> a(n);
		for (int i = 0; i < n; ++i) {
			int speed, time;
			cin >> speed >> time;
			a[i].first = speed;
			a[i].second = time;
		}
		int distance = a[0].first * a[0].second;
		for (int i = 1; i < n; ++i) {
			distance += a[i].first * (a[i].second - a[i - 1].second);
		}
		cout << distance << " miles"<< '\n';
	}
}