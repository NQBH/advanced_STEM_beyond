/*
* MSSV: 1411103
* Họ tên: Nguyễn Quản Bá Hồng
* Tên bài thực hành: Bài tập thực hành tuần 1
* Ngày cập nhật 20/10/2015
*/
#include "1411103_SearchAls.h"
#include "1411103_SortAls.h"
int LinearSearch(int a[], int& n, int& x){
	for (int i = 0; i<n; i++)	//Tìm kiếm tuần tự từ đầu đến cuối mảng.
		if (a[i] == x)
			return i;			//trả về chỉ số (thứ tự) của phần tử x cần tìm trong mảng	
	return -1;
}
int BinarySearch(int a[], int& n, int& x){
	int b[50]; //thêm mảng b là mảng "chỉ số" của mảng a. Sắp xếp đồng thời mảng a và b để trả về kết quả tương ứng với mảng a ban đầu (chưa được sắp xếp).
	for (int i = 0; i<n; i++){
		b[i] = i;			// khởi tạo mảng b - chỉ số của mảng a.
	}
	for (int i = 0; i<n - 1; i++) //sắp xếp đồng thời mảng a và b theo thứ tự tăng dần để có thể sử dụng thuật toán tìm kiếm nhị phân.
		for (int j = i + 1; j<n; j++)
			if (a[i]>a[j]){
				swap(a[i], a[j]);
				swap(b[i], b[j]);
	}
	int left = 0, right = n - 1; int mid;
	do{
		mid = (left + right) / 2;
		if (x == a[mid])
			return b[mid];		// trả về chỉ số của phần tử bằng x trong mảng a. b[mid] tương ứng với chỉ số của mảng a ban đầu.
		else
			if (x<a[mid])
				right = mid - 1;	//tìm kiếm x ở phần bên trái của mảng so với mid.
			else
				left = mid + 1;		//tìm kiếm x ở phần bên phải của mảng so với mid.
	} while (left <= right);
	return -1; // trả về -1 nếu không tìm thấy.
}


