/*
* MSSV: 1411103
* Họ tên: Nguyễn Quản Bá Hồng
* Tên bài thực hành: Bài tập thực hành tuần 3
* Ngày cập nhật 9/11/2015
*/

#ifndef DEFS_H_									// Tổ chức các tệp thư viện sao cho chúng có thể được kết nối nhiều lần vào một chương trình nguồn mà không gây lỗi.
#define DEFS_H_

#define INPUT_FILE  "data.txt"					// file lấy dữ liệu: data.txt
#define OUTPUT_FILE  "output\\1411103.txt"		// xuất ra file 1411103.txt nằm trong thư mục output, thư mục output nằm chung với các file .cpp .h
#define Error 846252.1410232

using namespace std;

#include <iostream>								
#include <fstream>								// thư viện xử lý file của C++
#include <string>								// thư viện xử lý chuỗi của C++

// Định nghĩa kiểu dữ liệu node
struct node {
	string data;
	double firgue;
	node* next;
};

// Định nghĩa kiểu dữ liệu queue
struct queue {
	node* front;
	node* rear;
	int count;
};

// Định nghĩa kiểu dữ liệu stack
struct stack {
	node* top;
	int count;
};

// CÁC HÀM XỬ LÝ NODE
/*
* Tên hàm: makeNewNode()
* Mô tả: Tạo 1 node mới
* Kiểu trả về: node*
* Tham số: không có tham số
*/
node* makeNewNode();


// CÁC HÀM XỬ LÝ STACK

/*
* Tên hàm: makeNewStack()
* Mô tả: Tạo 1 stack mới
* Kiểu trả về: stack*
* Tham số: không có tham số
*/
stack* makeNewStack();

/*
* Tên hàm: pushStack
* Mô tả: Thêm đối tượng vào đầu stack
* Kiểu trả về: void
* Tham số: ngăn xếp s, chuỗi data, double firgue
*/
void pushStack(stack* &s, string data, double firgue);

/*
* Tên hàm: popStack
* Mô tả: lấy đối tượng ở đầu stack ra
* Kiểu trả về: void
* Tham số: ngăn xếp s, chuỗi data, double firgue
*/
void popStack(stack* &s, string &dataOut, double &firgue);

/*
* Tên hàm: clearStack
* Mô tả: xóa ngăn xếp stack
* Kiểu trả về: void
* Tham số: ngăn xếp s
*/
void clearStack(stack* &s);


// CÁC HÀM XỬ LÝ QUEUE

/*
* Tên hàm: makeNewQueue
* Mô tả: tạo 1 hàng đợi mới
* Kiểu trả về: queue*
* Tham số: không có tham số
*/
queue* makeNewQueue();

/*
* Tên hàm: enQueue
* Mô tả: thêm đối tượng vào cuối queue
* Kiểu trả về: void
* Tham số: hàng đợi q và string data: dữ liệu cần thêm vào ở cuối hàng đợi
*/
void enQueue(queue* &q, string data);

/*
* Tên hàm: deQueue
* Mô tả: lấy đối tượng ở đầu queue ra
* Kiểu trả về: void
* Tham số: hàng đợi q và string data: dữ liệu cần lấy ra ở đầu queue
*/
void deQueue(queue* &q, string &data);

/*
* Tên hàm: clearQueue
* Mô tả: xóa hàng đợi
* Kiểu trả về: void
* Tham số: hàng đợi q
*/
void clearQueue(queue* &q);


// CÁC HÀM XỬ LÝ BIỂU THỨC TRONG THUẬT TOÁN BA LAN NGƯỢC

/*
* Tên hàm: makeExpQueue
* Mô tả: tạo biểu thức
* Kiểu trả về: bool
* Tham số: hàng đợi exp và chuỗi line
*/
bool makeExpQueue(queue* exp, string line);

/*
* Tên hàm: polandFirst
* Mô tả: thực hiện thuật toán chuyển đổi
* Kiểu trả về: bool
* Tham số: hàng đợi exp và hàng đợi expNew
*/
bool polandFirst(queue* exp, queue* expNew);

/*
* Tên hàm: polandSecond
* Mô tả: thực hiện thuật toán tính giá trị
* Kiểu trả về: double
* Tham số: hàng đợi q 
*/
double polandSecond(queue* exp);

#endif /* DEFS_H_ */