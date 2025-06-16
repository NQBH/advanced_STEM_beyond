/*
Source: ACM Mid-Atlantic 2003.
IDs for online judges: POJ 1581, ZOJ 1764, UVA 2832.
Status: Accepted
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct problem {
	int sub, time;
};
struct team {
	string name;
	problem prob[4];
};
int main() {
	int n; cin >> n;

	vector<team> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].name;
		for (int j = 0; j < 4; j++) {
			cin >> a[i].prob[j].sub >> a[i].prob[j].time;
		}
	}

	int maxSolve = 0;
	int maxPenalty = 0;
	string maxName;

	for (int i = 0; i < n; i++) {
		int currentPenalty = 0;
		int currentSolve = 0;
		string currentName = a[i].name;
		for (int j = 0; j < 4; j++) {
			currentPenalty += (a[i].prob[j].time > 0 ? a[i].prob[j].time + (20 * (a[i].prob[j].sub <= 1 ? 0 : a[i].prob[j].sub - 1)) : 0);
			currentSolve += (a[i].prob[j].time > 0 ? 1 : 0);
		}

		if (currentSolve > maxSolve) {
			maxSolve = currentSolve;
			maxPenalty = currentPenalty;
			maxName = currentName;
		}
		else if (currentSolve == maxSolve) {
			if (currentPenalty < maxPenalty) {
				maxSolve = currentSolve;
				maxPenalty = currentPenalty;
				maxName = currentName;
			}
		}
	}
	cout << maxName << " " << maxSolve << " " << maxPenalty;
}