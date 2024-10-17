#ifndef _DEFS_H_
#include "defs.h"
#define _DEFS_H_
#endif

// node
node* makeNewNode() {
	node* p = new node();
	p->data = "";
	p->next = NULL;
	p->firgue = 0;
	return p;
}

// stack
stack* makeNewStack() {
	stack *s = new stack();
	s->top = NULL;
	s->count = 0;
	return s;
}
void pushStack(stack* &s, string data, double firgue = 0) {
	node* p = makeNewNode();
	p->data = data;
	p->firgue = firgue;
	p->next = s->top;
	s->top = p;
	s->count++;
}
void popStack(stack* &s, string &dataOut, double &firgue) {
	if (s->count == 0)
		return;
	node* p = s->top;
	dataOut = p->data;
	firgue = p->firgue;
	s->top = s->top->next;
	s->count--;
	delete p;
}
void clearStack(stack* &s) {
	if (s->count != 0) {
		while (s->top != NULL) {
			node* temp = s->top;
			s->top = s->top->next;
			delete temp;
		}
	}
	s->top = NULL;
	s->count = 0;
}

// queue
queue* makeNewQueue() {
	queue* q = new queue();
	q->front = NULL;
	q->rear = NULL;
	q->count = 0;
	return q;
}

void enQueue(queue* &q, string data) {
	node* p = makeNewNode();
	p->data = data;
	if (q->count == 0)
		q->front = p;
	else
		q->rear->next = p;
	q->rear = p;
	q->count++;
}
void deQueue(queue* &q, string &dataOut) {
	if (q->count == 0)
		return;
	dataOut = q->front->data;
	node* p = q->front;
	if (q->count == 1)
		q->rear = NULL;
	q->front = q->front->next;
	q->count--;
	delete p;
}
void clearQueue(queue* &q) {
	if (q->count != 0) {
		while (q->front != NULL) {
			node* temp = q->front;
			q->front = q->front->next;
			delete temp;
		}
	}
	q->front = NULL;
	q->rear = NULL;
	q->count = 0;
}

// excute
bool makeExpQueue(queue* exp, string line) {
	string data = "";
	int count = 0;
	char c;
	if (line == "")
		return false;
	while (count < line.length()) {
		c = line[count];
		if ((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '(') || (c == ')')) {
			if (data != "")
				enQueue(exp, data);
			data = c;
			enQueue(exp, data);
			data = "";
		}
		else if ((c <= '9') && (c >= '0')) {
			data += c;
		}
		else
			return false;
		count++;
	}
	if (data != "")
		enQueue(exp, data);
	return true;
}
bool polandFirst(queue* exp, queue* expNew) {
	string data;
	string dataOut;
	stack* s = makeNewStack();
	double a;
	while (exp->count != 0) {
		deQueue(exp, data);
		if (data == "(")
			pushStack(s, data);
		else if (data == ")") {
			bool meetBracket = false;
			while (s->count != 0) {
				if (s->top->data == "(") {
					popStack(s, dataOut, a);
					meetBracket = true;
					break;
				}
				else {
					popStack(s, dataOut, a);
					enQueue(expNew, dataOut);
				}
			}
			if (!meetBracket) {
				clearStack(s);
				delete s;
				return false;
			}
		}
		else if ((data == "*") || (data == "/")) {
			while (s->top != NULL) {
				if ((s->top->data == "*") || (s->top->data == "/")) {
					popStack(s, dataOut, a);
					enQueue(expNew, dataOut);
				}
				else
					break;
			}
			pushStack(s, data);
		}
		else if ((data == "+") || (data == "-")) {
			while (s->top != NULL) {
				if (s->top->data != "(") {
					popStack(s, dataOut, a);
					enQueue(expNew, dataOut);
				}
				else
					break;
			}
			pushStack(s, data);
		}
		else {
			enQueue(expNew, data);
		}
	}
	while (s->count != 0) {
		if (s->top->data == "(") {
			clearStack(s);
			delete s;
			return false;
		}
		else {
			popStack(s, dataOut, a);
			enQueue(expNew, dataOut);
		}
	}
	clearStack(s);
	delete s;
	return true;
}
double polandSecond(queue* exp) {
	stack* s = makeNewStack();
	double a;
	double b;
	string dataOut;
	while (exp->count != 0) {
		if (exp->front->data == "+") {
			if (s->count < 2) {
				clearStack(s);
				delete s;
				return Error;
			}
			else {
				popStack(s, dataOut, b);
				popStack(s, dataOut, a);
				pushStack(s, dataOut, a + b);
				deQueue(exp, dataOut);
			}
		}
		else if (exp->front->data == "-") {
			if (s->count < 2) {
				clearStack(s);
				delete s;
				return Error;
			}
			else {
				popStack(s, dataOut, b);
				popStack(s, dataOut, a);
				pushStack(s, dataOut, a - b);
				deQueue(exp, dataOut);
			}
		}
		else if (exp->front->data == "*") {
			if (s->count < 2) {
				clearStack(s);
				delete s;
				return Error;
			}
			else {
				popStack(s, dataOut, b);
				popStack(s, dataOut, a);
				pushStack(s, dataOut, a * b);
				deQueue(exp, dataOut);
			}
		}
		else if (exp->front->data == "/") {
			if (s->count < 2) {
				clearStack(s);
				delete s;
				return Error;
			}
			else {
				popStack(s, dataOut, b);
				popStack(s, dataOut, a);
				if (b == 0) {
					clearStack(s);
					delete s;
					return Error;
				}
				pushStack(s, dataOut, a / b);
				deQueue(exp, dataOut);
			}
		}
		else {
			a = atoi(exp->front->data.c_str());
			deQueue(exp, dataOut);
			pushStack(s, dataOut, a);
		}
	}
	if (s->count == 1) {
		a = s->top->firgue;
		clearStack(s);
		delete s;
		return a;
	}
	else {
		clearStack(s);
		delete s;
		return Error;
	}
}