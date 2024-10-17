/*
* MSSV: 1411103
* Họ tên: Nguyễn Quản Bá Hồng
* Tên bài thực hành: Bài tập thực hành tuần 4
* Ngày cập nhật 28/11/2015
*/
#ifndef DEFS_H_									// Tổ chức các tệp thư viện sao cho chúng có thể được kết nối nhiều lần vào một chương trình nguồn mà không gây lỗi.
#define DEFS_H_

#define INPUT_FILE  "data.txt"					// file lấy dữ liệu: data.txt
#define OUTPUT_FILE  "output\\1411103.txt"		// xuất ra file 1411103.txt nằm trong thư mục output, thư mục output nằm chung với các file .cpp .h
#define Error 846252.1410232
#define MAX 50
#define dis 100
using namespace std;

#include <iostream>								
#include <fstream>								// thư viện xử lý file của C++
#include <string>								// thư viện xử lý chuỗi của C++
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
using namespace cv;

void drawAMan(Mat &img, int x, int y, int stepStyle, char *text);
void drawDoor(Mat &img, int x, int y, int ticket);
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

// CÁC HÀM XỬ LÝ NODE
/*
* Tên hàm: makeNewNode()
* Mô tả: Tạo 1 node mới
* Kiểu trả về: node*
* Tham số: không có tham số
*/
node* makeNewNode();


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

/*
* Tên hàm: all
* Mô tả: thực hiện mô phỏng hàng đợi, với dữ liệu từ file test
* Kiểu trả về: void
* Tham số: numMan (số người), ticket (số vé), test (bộ test thứ mấy)
*/
void all(int numMan, int ticket, int test);
#endif /* DEFS_H_ */

