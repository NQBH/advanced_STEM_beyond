/*
* MSSV: 1411103
* Họ tên: Nguyễn Quản Bá Hồng
* Tên bài thực hành: Bài tập thực hành tuần 5
* Ngày cập nhật 19/12/2015
*/


#include <stdlib.h>

#include "1411103_defs.h"

// Kiểm tra cây nhị phân tìm kiếm rỗng
int isEmpty(bstree* bst){
	return bst->root == NULL;		// kiểm tra node gốc có rỗng hay không
}

// Khởi tạo cây nhị phân tìm kiếm
void initBSTree(bstree* &bst){
	bst->root = NULL;				// gán cho gốc giá trị NULL
}

// Duyệt cây theo thứ tự node - left- right
void NLR(bstree* bst){
	NLR(bst->root);					// gọi hàm NLR bên dưới
}

void NLR(node* t){
	if (t){							// nếu t khác NULL
		printf("%d\t", t->data);	// in ra dữ liệu node
		NLR(t->left);				// truy hồi về bên trái
		NLR(t->right);				// truy hồi về bên phải
	}
}

// Duyệt cây theo thứ tự left - node - right
void LNR(bstree* bst){
	LNR(bst->root);					// gọi hàm LNR bên dưới
}

void LNR(node* t){
	if (t){							// nếu t khác NULL
		LNR(t->left);				// truy hồi về bên trái
		printf("%d\t", t->data);	// in ra dữ liệu node
		LNR(t->right);				// truy hồi về bên phải
	}
}

// Duyệt theo thứ tự sau
void LRN(bstree* bst){		
	LRN(bst->root);					// gọi hàm bên dưới
}

void LRN(node* t){
	if (t){							// nếu t khác NULL
		LRN(t->left);				// truy hồi về bên trái
		LRN(t->right);				// truy hồi về bên phải
		printf("%d", t->data);		// in ra dữ liệu của node
	}
}

// Tìm kiếm node chứa số nguyên x cho trước
node* searchNode(bstree* bst, int x){
	return searchNode(bst->root, x); // gọi hàm bên dưới
}

node* searchNode(node* t, int x){
	if (t){							// nếu t khác NULL	
		if (t->data == x)			// nếu dữ liệu t trùng x
			return t;				// trả về t
		if (t->data > x)			// nếu dữ liệu t vượt x
			return searchNode(t->left, x);	// tìm kiếm về phía bên trái
		else
			return searchNode(t->right, x); // tìm kiếm về phía bên phải
	}
	return NULL;					// nếu t=NULL thì trả về NULL
}

// Thêm 1 node vào cây 
int insertNode(bstree* &bst, int x){
	return insertNode(bst->root, x);	// gọi hàm bên dưới
}

int insertNode(node* &t, int x){
	if (t){							// nếu t khác NULL
		if (t->data == x)			// nếu dữ liệu t trùng x
			return 0;				// không chèn được do có node có dữ liệu đó rồi
		if (t->data > x)			// nếu dữ liệu t vượt x
			return insertNode(t->left, x);	// chèn về phía bên trái
		else
			return insertNode(t->right, x);	// chèn về phía bên phải
	}
	t = new node();					// cấp phát node mới
	if (!t)							// nếu node t=NLL
		return -1;
	t->data = x;					// gán x cho dữ liệu t
	t->left = t->right = NULL;		// t là node lá
	return 1;						// trả về 1, nghĩa là thêm thành công
}

// Hủy 1 phần tử
int deleteNode(bstree* &bst, int x){
	return deleteNode(bst->root, x);	// gọi hàm bên dưới
}

int deleteNode(node* &t, int x){
	if (!t)							// nếu t ==NULL
		return 0;					// không cần delete
	if (t->data > x)				// nếu dữ liệu t vượt x
		return deleteNode(t->left, x);	// xóa về phía bên trái
	if (t->data < x)				// nếu dữ liệu t kém x	
		return deleteNode(t->right, x);	// xóa về phía bên phải
	else {
		node* p = t;
		if (!t->left)				// nếu t->left==NULL
			t = t->right;			// t thành t->right
		if (!t->right)				// nếu t->right==NULL
			t = t->left;			// t thành t->left
		else
			searchStandFor(p, t->right);	// gọi hàm bên dưới
		delete p;					// xóa node p	
		return 1;					// thành công, đã xóa được

	}
}

// Tìm phần tử nhỏ nhất bên phải
void searchStandFor(node* &p, node* &q){
	if (q->left)	// nếu node con trái khác NULL
		searchStandFor(p, q->left);	// tìm về phía bên trái
	else{
		p->data = q->data;		// hoán đổi giá trị các node
		p = q;
		q = q->right;
	}
}

// MỘT SỐ THAO TÁC MỞ RỘNG

//	Kiểm tra 1 node có phải là 1 node lá hay không
int isLeaf(node* N){
	if (N){							// nếu N khác NULL
		if (N->left == NULL && N->right == NULL)	// nếu N không có node con
			return 1;				// N là node lá
		return 0;					// N không là node lá
	}
	return -1;						// trả về -1 nếu N==NULL
}

// Tính chiều cao của cây
int getHighofTree(bstree* bst){
	return getHighofTree(bst->root);	// gọi hàm bên dưới
}

int getHighofTree(node* N){
	if (!N)							// nếu N==NULL
		return 0;					// trả về chiều cao bằng 0
	int left = getHighofTree(N->left);	// chiều cao cây bên trái
	int right = getHighofTree(N->right);	// chiều cao cây bên phải
	return (left > right) ? left : right + 1; // chọn chiều cao
}

// Hủy 1 cây
void removeTree(bstree* &bst){
	removeTree(bst->root);			// gọi hàm bên dưới
}

void removeTree(node* &t){
	if (t){							// nếu node t khác NULL
		removeTree(t->left);		// hủy về phía bên trái
		removeTree(t->right);		// hủy về phía bên phải
		delete t;					// xóa node t
		t = NULL;	
	}
}

// Đếm số lượng phần tử của cây 
// BÀI TẬP 1
int countNode(bstree* bst){
	return countNode(bst->root);	// gọi hàm bên dưới
}
int countNode(node* N){
	if (N == NULL)					// nếu node N==NULL
		return 0;					// trả về 0
	return (countNode(N->left) + countNode(N->right) + 1); // tổng của 2 thành phần trái phải
}

// BÀI TẬP 2
// Đếm số node lá của cây
int countLeaf(bstree* bst){
	int count = 0;
	return countLeaf(bst->root, count); // gọi hàm bên dưới
}
int countLeaf(node* t, int &count){
	if (t){							// nếu node khác NULL
		if (isLeaf(t) == 1)			// nếu t là node lá
			count++;				// tăng biến đếm
		countLeaf(t->left, count);	// đếm về phía bên trái
		countLeaf(t->right, count);	// đếm về phía bên phải
	}		
	return count;					// trả về count
}

// BÀI TẬP 3
// Đếm số node là cha của node của cây
int countParent(bstree* bst){
	int count = 0;
	return countParent(bst->root, count);	// gọi hàm bên dưới
}
int countParent(node* t, int &count){
	if (t){							// nếu node t khác NULL
		if (isLeaf(t) == 0)			// nếu t không là node lá
			if (isLeaf(t->left) == 1 || isLeaf(t->right) == 1) // nếu 1 trong 2 node con của t là node lá
				count++;			// tăng biến count
		countParent(t->left, count);	// đếm về phía bên trái
		countParent(t->right, count);	// đếm về phía bên phải
	}
	return count;					// trả về count
}

// BÀI TẬP 4
// Đếm số node có 2 node con
int countNodeHave2Node(bstree* bst){
	int count = 0;
	return countNodeHave2Node(bst->root, count);	// gọi hàm bên dưới
}
int countNodeHave2Node(node* t, int& count){
	if (t){							// nếu node t khác NULL
		if (t->left != NULL && t->right != NULL)	// nếu t có 2 node con
			count++;				// tăng biến đếm
		countNodeHave2Node(t->left, count);	// đếm về phía bên trái
		countNodeHave2Node(t->right, count);	// đếm về phía bên phải
	}
	return count;			// trả về count
}
// Tính trung bình các node có 2 node con
float averageNodeHave2Node(bstree* bst){
	float count = 0, sum = 0;
	return averageNodeHave2Node(bst->root, count, sum); // gọi hàm bên dưới
}
float averageNodeHave2Node(node* t, float &count, float &sum){
	if (t) {						// nếu t khác NULL
		if (t->left != NULL && t->right != NULL){	// nếu t có 2 node con
			count++;				// tăng biến đếm
			sum = sum + t->data;	// tổng các node có 2 node con
		}
		averageNodeHave2Node(t->left, count, sum); // tính trung bình về phía bên trái
		averageNodeHave2Node(t->right, count, sum);	// tính trung bình về phía bên phải
	}
	return round((sum / count) * 1000) / 1000;	// làm tròn đến 3 chữ số thập phân
}

// Xử lý bài số 4
void bai4(bstree* bst){
	if (countNodeHave2Node(bst) == 0)	// nếu cây không có node nào có 2 node con		
		printf("NaN\n");			// xuất NaN
	else
		printf("%f", averageNodeHave2Node(bst));	// xuất giá trị trung bình
}
// BÀI TẬP 5
// Tính trung bình tất cả các node
float averageNode(bstree* bst){
	float count = 0, sum = 0;
	return averageNode(bst->root, count, sum); // gọi hàm bên dưới
}
float averageNode(node* t, float &count, float &sum){
	if (t){							// nếu node t khác NULL
		count++;					// tăng biến đếm
		sum = sum + t->data;		// tăng tổng
		averageNode(t->left, count, sum);	// tính trung bình về phía bên trái
		averageNode(t->right, count, sum);	// tính trung bình về phía bên phải
	}	
	return sum / count;				// trung bình=tổng/số phần tử
}
// Tìm node có giá trị gần nhất vs giá trị trung bình cộng của các node
void findNear(bstree* bst, int arr[], int &size){
	float min = abs(bst->root->data - averageNode(bst)); // sai số, hiệu dữ liệu node vs giá trị trung bình node
	size = 0;
	findNear(bst, bst->root, min, arr, size);	// gọi hàm bên dưới
}
void findNear(bstree* bst, node* t, float &min, int *arr, int &size){
	if (t) {						// nếu node t khác NULL
		if (abs(t->data - averageNode(bst)) < min) {	// tìm node cho sai số nhỏ hơn
			min = abs(t->data - averageNode(bst));
			arr[0] = t->data;
			size = 1;
		}
		else if (abs(t->data - averageNode(bst)) == min) {
			arr[size] = t->data;
			size++;
		}
		findNear(bst, t->left, min, arr, size); // tìm về bên trái
		findNear(bst, t->right, min, arr, size);	// tìm về bên phải
	}
}


