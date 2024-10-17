/*
* MSSV: 1411103
* Họ tên: Nguyễn Quản Bá Hồng
* Tên bài thực hành: Bài tập thực hành tuần 4
* Ngày cập nhật 28/11/2015
*/

#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <stdlib.h>
using namespace cv;
#include "1411103_defs.h"

void drawAMan(Mat &img, int x, int y, int stepStyle, char *text)
{
	/* Kích thước đầu */
	const int HEAD_SIZE = 20;
	/* Vẽ đầu */
	circle(img, Point(x, y), HEAD_SIZE,
		Scalar(255, 0, 0), -1);
	/* Vẽ thân */
	rectangle(img, Point(x + HEAD_SIZE, y+HEAD_SIZE),
		Point(x - HEAD_SIZE, y + 4*HEAD_SIZE),
		Scalar(0, 0, 255),-1);
	/* Kiểu bước chân */
	const int STEP_STYLE = stepStyle;
	/* Vẽ chân */
	line(img, Point(x - HEAD_SIZE, y + HEAD_SIZE * 4),
		Point(x - HEAD_SIZE-STEP_STYLE, y + HEAD_SIZE*5),
		Scalar(0, 0, 255));
	line(img, Point(x + HEAD_SIZE, y + HEAD_SIZE * 4),
		Point(x + HEAD_SIZE + STEP_STYLE, y + HEAD_SIZE * 5),
		Scalar(0, 0, 255));
	/* Vẽ tay phải */
	line(img, Point(x+HEAD_SIZE, y + 2*HEAD_SIZE),
		Point(x + HEAD_SIZE+STEP_STYLE, y + HEAD_SIZE*3),
		Scalar(0, 500, 255));
	/* Vẽ tay trái */
	line(img, Point(x-HEAD_SIZE, y + 2*HEAD_SIZE),
		Point(x - HEAD_SIZE - STEP_STYLE, y + HEAD_SIZE*3),
		Scalar(0, 500, 255));

	/* Vẽ chữ */
	putText(img, text, Point(x, y - 1.5*HEAD_SIZE),
		FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0));

}
void drawDoor(Mat &img, int x, int y, int ticket){
	rectangle(img, Point(x,y),
		Point(x +10, y + 150),		// chieu rong cua cua la 100 va chieu cao cua la 300
		Scalar(0, 0, 255));
	string text = "So ve:";
	putText(img, text, Point(x, y-30),
		FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0),1);
	char buf[5];
	string text2 = _itoa(ticket, buf, 10);
	putText(img, text2, Point(x+50, y -10),
		FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 1);


}
// void drawTest(int numMan, int ticket, Queue){
// CÁC HÀM XỬ LÝ NODE

node* makeNewNode() {
	node* p = new node();	// khởi tạo node mới
	p->data = "";			// gán dữ liệu trống cho node
	p->next = NULL;			// 1 node
	p->firgue = 0;
	return p;				// trả về node mới vừa tạo
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

void all(int numMan, int ticket, int test){
	Mat img(300, 700, CV_32FC3);
	int y = 100, x = 300;
	int a[MAX];
	int ticket0 = 2;
	while (ticket > 0){

		while (x < 450 + ticket0*dis){
			drawDoor(img, 400, 60, ticket);
			for (int i = 1; i <= numMan; i++){

				a[i] = x - dis*i;
				drawAMan(img, a[i], y, x % 15, "man");

			}
			char buf[5];
			string str = _itoa(test, buf, 10);
			string window="[queue_test" + str + "]";
			imshow(window, img);
			waitKey(1);
			img = Mat::zeros(img.rows, img.cols, CV_32FC3);
			imshow(window, img);
			x++;
		}

	}
	ticket--;

}
