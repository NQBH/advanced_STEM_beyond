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

int main() {
	ifstream inputFile(INPUT_FILE);	
	ofstream outputFile(OUTPUT_FILE);
	string line;
	queue* exp = makeNewQueue();	// tạo biểu thức
	queue* expNew = makeNewQueue();	// tạo biểu thức mới
	bool success;				
	double ans;
	while (!inputFile.eof()) {		// lặp cho đến khi hết file data
		getline(inputFile, line);	// lấy hàng trong file data
		outputFile << line << endl;
		getline(inputFile, line);
		success = makeExpQueue(exp, line);	// kiểm tra biểu thức lần thứ 0
		if (!success) {						// nếu biểu thức không hợp lệ
			outputFile << "NaN" << endl;	// xuất NaN
			clearQueue(exp);				// xóa exp
		}
		else {								
			success = polandFirst(exp, expNew);	// nếu biểu thức hợp lệ
			if (!success) {						// nếu biểu thức không hợp lệ
				outputFile << "NaN" << endl;	// xuất NaN
				clearQueue(exp);				// xóa exp
				clearQueue(expNew);				// xóa expNew
			}
			else {
				ans = polandSecond(expNew);		// kết quả của thuật toán tính giá trị
				if (ans == Error) {				// nếu kết quả bị lỗi (error định nghĩa trong 1411103_defs.h)
					outputFile << "NaN" << endl;	// xuất NaN
					clearQueue(exp);			// xóa dữ liệu của exp
					clearQueue(expNew);			// xóa dữ liệu của expNew
				}
				else {
					outputFile << round(ans * 1000) / 1000 << endl;		// làm tròn đến chữ số thập phân thứ 3
					clearQueue(exp);			// xóa dữ liệu exp		
					clearQueue(expNew);			// xóa dữ liệu expNew
				}
			}
		}
	}
	delete exp;		// xóa exp
	delete expNew;	// xóa expNew
	return 0;
}