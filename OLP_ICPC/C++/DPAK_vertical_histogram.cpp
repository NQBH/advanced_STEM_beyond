/*
Source: USACO, February 2003, Orange.
IDs for online judges: POJ 2136.
Status: Compile Error, Fuck-POJ
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	string s[4];
	for (int i = 0; i < 4; i++) {
		getline(cin, s[i]);
	}

	vector<int>character(26, 0);
	priority_queue<pair<int, char>> pq;

	for (int i = 0; i < 4; i++) {
		for (auto c : s[i]) {
			character[c - 'A']++;
		}
	}
	int maxSize = *max_element(character.begin(), character.end());

	vector<vector<char>> show(maxSize, vector<char>(26, ' '));

	for (int i = 0; i < 26; i++) {
		if (character[i] == 0) continue;
		pq.push({ character[i], i});
	}
	int idx = 0;

	while (pq.empty() == false) {
		auto [Len, C] = pq.top();
		pq.pop();
		show[idx][C] = '*';
		while (pq.empty() == false && pq.top().first == Len) {
			auto [sLen, sC] = pq.top();
			show[idx][sC] = '*';
			pq.pop();
			if (sLen == 1) continue;
			pq.push({ sLen - 1, sC });
		}
		idx++;
		if (Len == 1) continue;
		pq.push({ Len - 1, C });
	}


	for (int i = 0; i < maxSize; i++) {
		for (int j = 0; j < 26; j++) {
			cout << show[i][j] << " ";
		}
		cout << '\n';
	}
	for (char C = 'A'; C <= 'Z'; C++) {
		cout << C << " ";
	}
}