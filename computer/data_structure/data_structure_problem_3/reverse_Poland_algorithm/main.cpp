#ifndef _DEFS_H_
#include "defs.h"
#define _DEFS_H_
#endif

int main() {
	ifstream inputFile(INPUT_FILE);
	ofstream outputFile(OUTPUT_FILE);
	string line;
	queue* exp = makeNewQueue();
	queue* expNew = makeNewQueue();
	bool success;
	double ans;
	while (!inputFile.eof()) {
		getline(inputFile, line);
		outputFile << line << endl;
		getline(inputFile, line);
		success = makeExpQueue(exp, line);
		if (!success) {
			outputFile << "NaN" << endl;
			clearQueue(exp);
		}
		else {
			success = polandFirst(exp, expNew);
			if (!success) {
				outputFile << "NaN" << endl;
				clearQueue(exp);
				clearQueue(expNew);
			}
			else {
				ans = polandSecond(expNew);
				if (ans == Error) {
					outputFile << "NaN" << endl;
					clearQueue(exp);
					clearQueue(expNew);
				}
				else {
					outputFile << round(ans * 1000) / 1000 << endl;
					clearQueue(exp);
					clearQueue(expNew);
				}
			}
		}
	}
	delete exp;
	delete expNew;
	return 0;
}