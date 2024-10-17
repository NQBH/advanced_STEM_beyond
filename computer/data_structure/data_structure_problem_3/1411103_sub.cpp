/*
* MSSV: 1411103
* Họ tên: Nguyễn Quản Bá Hồng
* Tên bài thực hành: Bài tập thực hành tuần 3
* Ngày cập nhật 9/11/2015
*/

#ifndef _DEFS_H_
#include "1411103_defs.h"	
#define _DEFS_H_
#endif

// CÁC HÀM XỬ LÝ NODE

node* makeNewNode() {
	node* p = new node();	// khởi tạo node mới
	p->data = "";			// gán dữ liệu trống cho node
	p->next = NULL;			// 1 node
	p->firgue = 0;			
	return p;				// trả về node mới vừa tạo
}

// CÁC HÀM XỬ LÝ STACK

// tạo stack mới 
stack* makeNewStack() {
	stack *s = new stack();	// khởi tạo stack mới
	s->top = NULL;			// gán các dữ liệu trống/0/NULL cho các thành phần của stack mới
	s->count = 0;
	return s;				// trả về stack mới vừa tạo
}
// thêm đối tượng vào đầu stack
void pushStack(stack* &s, string data, double firgue = 0) {
	node* p = makeNewNode();	// tạo node mới
	p->data = data;				// đưa tham số data vào data của node p
	p->firgue = firgue;			// đưa dữ liệu vào node p	
	p->next = s->top;			// tạo liên kết: p nối với đầu của stack s
	s->top = p;					// gán p cho s->top
	s->count++;					// tăng số lượng thành phần của stack
}

// lấy đối tượng ở đầu stack ra
void popStack(stack* &s, string &dataOut, double &firgue) {
	if (s->count == 0)		// kiểm tra, nếu số phần tử của stack = 0 thì không thực hiện
		return;				
	node* p = s->top;		// gán node p cho node s->top
	dataOut = p->data;		// lưu dữ liệu của node p bị lấy ra lưu vào chuỗi dataOut
	firgue = p->firgue;		// lưu giá trị của node p bị lấy ra
	s->top = s->top->next;	// thay đổi vị trí s->top
	s->count--;				// giảm số thành phần của stack s đi 1
	delete p;				// xóa node p
}

// xóa stack 
void clearStack(stack* &s) {
	if (s->count != 0) {			// nếu số lượng thành phần của stack khác 0 thì mới thực hiện
		while (s->top != NULL) {	// kiểm tra điều kiện s->top khác NULL
			node* temp = s->top;	// gán s->top cho node trung gian temp
			s->top = s->top->next;	// thay đổi vị trí s->top
			delete temp;			// xóa node trung gian
		}
	}
	s->top = NULL;					// gán s->top bằng NULL
	s->count = 0;					// số lượng thành phần của stack gán bằng 0
}

// CÁC HÀM XỬ LÝ QUEUE

// tạo queue mới
queue* makeNewQueue() {
	queue* q = new queue();		// khởi tạo queue mới 
	q->front = NULL;			// gán phần tử đầu bằng NULL
	q->rear = NULL;				// gán phần tử cuối bằng NULL
	q->count = 0;				// gán số lượng thành phần của queue bằng 0
	return q;					// trả về queue q vừa mới tạo
}

// thêm đối tượng vào cuối queue
void enQueue(queue* &q, string data) {
	node* p = makeNewNode();	// khởi tạo node mới p
	p->data = data;				// gán data của node p bằng tham số data
	if (q->count == 0)			// trường hợp queue có 0 phần tử 
		q->front = p;			// thì gán node p cho q->front
	else						// trường hợp queue có >0 phần tử
		q->rear->next = p;		// thêm node p vào node sau q->rear
	q->rear = p;				// gán node p cho q->rear
	q->count++;					// tăng số lượng phần tử của queue lên 1
}

// lấy đối tượng ở đầu queue ra
void deQueue(queue* &q, string &dataOut) {
	if (q->count == 0)			// trường hợp số lượng phần tử của q bằng 0
		return;					// thì không thực hiện 
	dataOut = q->front->data;	// gán dữ liệu của q->front vào chuỗi dataOut
	node* p = q->front;			// gán q->front cho node p
	if (q->count == 1)			// trường hợp số lượng phần tử của q bằng 1
		q->rear = NULL;			// xóa phần tử cuối của q
	q->front = q->front->next;	// thay đổi vị trí đầu tiên trong q
	q->count--;					// giảm phần tử của q đi 1
	delete p;					// xóa node p
}

// xóa queue
void clearQueue(queue* &q) {
	if (q->count != 0) {				// kiểm tra điều kiện số lượng phần tử của queue khác 0
		while (q->front != NULL) {		// thực hiện với điều kiện phần tử đầu của queue khác NULL
			node* temp = q->front;		// gán q->front cho node trung gian
			q->front = q->front->next;	// thay đổi vị trí của phần tử đầu trong q
			delete temp;				// xóa node trung gian
		}
	}
	q->front = NULL;		// gán NULL cho q->front
	q->rear = NULL;			// gán NULL cho q->rear
	q->count = 0;			// gán số lượng phần tử của q bằng 0
}

// CÁC HÀM XỬ LÝ BIỂU THỨC TRONG THUẬT TOÁN BA LAN NGƯỢC

// kiểm tra biểu thức 
bool makeExpQueue(queue* exp, string line) {
	string data = "";	// tạo data, count, c
	int count = 0;		
	char c;			
	if (line == "")		// kiểm tra: nếu biểu thức rỗng thì trả về false
		return false;	// trả về false: biểu thức sai
	while (count < line.length()) {		// chạy cho đến khi hết chuỗi line
		c = line[count];				// gán ký tự thứ count trong dòng line vào biến c
		if ((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '(') || (c == ')')) { 
			// kiểm tra điều kiện c là các phép toán hoặc dấu ngoặc
			if (data != "")
				enQueue(exp, data);		// thêm data vào cuối exp
			data = c;
			enQueue(exp, data);			// thêm data vào cuỗi exp
			data = "";					// gán data rỗng trở lại
		}
		else if ((c <= '9') && (c >= '0')) { // kiểm tra để trích số
			data += c;		
		}
		else
			return false;
		count++;	// tăng biến chạy count trên line
	}
	if (data != "")	// nếu data khác rỗng
		enQueue(exp, data);		// thêm data vào cuối biểu thức exp
	return true;				// trả về true
}

// Thực hiện thuật toán chuyển đổi
bool polandFirst(queue* exp, queue* expNew) {
	string data;		// tạo chuỗi data và dataOut
	string dataOut;
	stack* s = makeNewStack();	// Bước 1: Khởi tạo stack rỗng 
	double a;
	while (exp->count != 0) {	// Bước 2: lặp cho đến khi kết thúc biểu thức
		deQueue(exp, data);		// đọc phần tử của biểu thức exp
		if (data == "(")		// nếu phần tử là "(": 
			pushStack(s, data); // đưa vào stack
		else if (data == ")") {	// ")" nếu phần tử là ")"
			bool meetBracket = false;	// biến meetBracket: kiểm tra đã gặp "(" trong stack chưa
			while (s->count != 0) {		// nếu stack khác rỗng
				if (s->top->data == "(") {	
					popStack(s, dataOut, a);
					meetBracket = true;		// gặp dấu ngoặc
					break;
				}
				else {
					popStack(s, dataOut, a); // lấy dữ liệu ở đầu s ra và lưu vào dataOut
					enQueue(expNew, dataOut);	// thêm dataOut vào cuối biểu thức mới expNew
				}
			}
			if (!meetBracket) {		// nếu chưa gặp dấu ngoặc
				clearStack(s);		// xóa stack s
				delete s;
				return false;		// trả về sai
			}
		}
		else if ((data == "*") || (data == "/")) {		// nếu ký tự là phép nhân hoặc chia
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
		else if ((data == "+") || (data == "-")) {		// nếu ký tự là phép cộng hoặc trừ
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
// Thuật toán tính giá trị
double polandSecond(queue* exp) {
	stack* s = makeNewStack();		// khởi tạo stack rỗng
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