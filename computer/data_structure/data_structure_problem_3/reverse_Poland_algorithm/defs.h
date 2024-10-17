#ifndef DEFS_H_
#define DEFS_H_

#define INPUT_FILE  "input.txt"
#define OUTPUT_FILE  "output.txt"
#define Error 846252.1410232

using namespace std;

#include <iostream>
#include <fstream>
#include <string>

struct node {
	string data;
	double firgue;
	node* next;
};

struct queue {
	node* front;
	node* rear;
	int count;
};

struct stack {
	node* top;
	int count;
};

node* makeNewNode();

stack* makeNewStack();
void pushStack(stack* &s, string data, double firgue);
void popStack(stack* &s, string &dataOut, double &firgue);
void clearStack(stack* &s);

queue* makeNewQueue();
void enQueue(queue* &q, string data);
void deQueue(queue* &q, string &data);
void clearQueue(queue* &q);

bool makeExpQueue(queue* exp, string line);
bool polandFirst(queue* exp, queue* expNew);
double polandSecond(queue* exp);

#endif /* DEFS_H_ */