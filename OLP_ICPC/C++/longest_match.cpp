#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
#define N 1014

struct text { // 2 successive lines of string
	int num; // number of words
	string word[1024]; // words
} t1, t2;

string s1, s2;
int f[N][N]; // number of matched words for the 1st ith words in s1 & the 1st jth words in s2 is f[i, j]

void divide(string s, text &t) { // sequence of words t.word[] whose length is t.num is taken out from s
	int l = s.size(); // length of s
	t.num = 1;
	for (int i = 0; i < 1000; ++i) t.word[i].clear();
	for (int i = 0; i < l; ++i)
		if ('A' <= s[i] && s[i] <= 'Z' || 'a' <= s[i] && s[i] <= 'z' || '0' <= s[i] && s[i] <= '9')
			t.word[t.num] += s[i];
		else ++t.num;
	int now = 0;
	for (int i = 1; i <= t.num; ++i)
		if (!t.word[i].empty()) t.word[++now] = t.word[i];
	t.num = now;
}

int main(void) {
	int test = 0; // initialization: the number of test cases
	while (!cin.eof()) {
		++test;
		getline(cin, s1); // input string s1
		divide(s1, t1);
		getline(cin, s2); // input string s2
		divide(s2, t2);
		printf("%2d. ", test);
		if (s1.empty() || s2.empty()) {
			printf("Blank!\n");
			continue;
		}
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= t1.num; ++i) // words in s1
			for (int j = 1; j <= t2.num; ++j) { // words in s2
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
				if (t1.word[i] == t2.word[j])
					f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
			}
		printf("Length of longest match: %d\n", f[t1.num][t2.num]); // output result
	}
}