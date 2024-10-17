/*
* MSSV: 1411103
* Họ tên: Nguyễn Quản Bá Hồng
* Tên bài thực hành: Bài tập thực hành tuần 5
* Ngày cập nhật 19/12/2015
*/

#ifndef DEFS_H_									// Tổ chức các tệp thư viện sao cho chúng có thể được kết nối nhiều lần vào một chương trình nguồn mà không gây lỗi.
#define DEFS_H_

#define INPUT_FILE  "data.txt"					// file lấy dữ liệu: data.txt
#define OUTPUT_FILE  "output\\1411103.txt"		// xuất ra file 1411103.txt nằm trong thư mục output, thư mục output nằm chung với các file .cpp .h
#define Error 846252.1410232
#define MAX 100 								// hằng số MAX quy định số người tối đa đi mua vé
#define dis 100									// định trước khoảng cách giữa 2 người là 100
using namespace std;

#include <iostream>			
#include <cmath>
#include <fstream>								// thư viện xử lý file của C++
#include <string>								// thư viện xử lý chuỗi của C++

/*
* Định nghĩa kiểu dữ liệu node
* data để chứa dữ liệu số nguyên của cây NPTK.
* trỏ tới 2 node con là left và right
*/
struct node {
	int data;
	node* left;
	node* right;
};

/*
* Định nghĩa kiểu dữ liệu cây nhị phân tìm kiếm
* bao gồm duy nhất 1 node root
*/
struct bstree{
	node* root;
};

/*
* Tên hàm: isEmpty
* Mô tả: Kiểm tra cây nhị phân có rỗng hay không
* Kiểu trả về: int
* Tham số: bSTree* bst
*/
int isEmpty(bstree* bst);

/*
* Tên hàm: initBSTree
* Mô tả: Khởi tạo cây nhị phân tìm kiếm
* Kiểu trả về: void 
* Tham số: cây nptk bst
*/
void initBSTree(bstree* &bst);


// DUYỆT CÂY 
// Duyệt cây theo thứ tự trước (node - left - right)
/*
* Tên hàm: NLR
* Mô tả: Duyệt cây theo thứ tự trước
* Kiểu trả về: void
* Tham số: bst
*/
void NLR(bstree* bst);
/*
* Tên hàm: NLR
* Mô tả: Duyệt cây theo thứ tự trước
* Kiểu trả về: void
* Tham số: node t
*/
void NLR(node* t);

// Duyệt cây theo thứ tự giữa (left - node - right)
/*
* Tên hàm: LNR
* Mô tả: Duyệt cây theo thứ tự giữa
* Kiểu trả về: void 
* Tham số: bstree
*/
void LNR(bstree* bst);
/*
* Tên hàm: LNR
* Mô tả: Duyệt cây theo thứ tự giữa
* Kiểu trả về: void
* Tham số: node
*/
void LNR(node* t);

// Duyệt cây theo thứ tự sau (left - right - node)
/*
* Tên hàm: LRN
* Mô tả: Duyệt cây theo thứ tự sau
* Kiểu trả về: void
* Tham số: bstree 
*/
void LRN(bstree* bst);
/*
* Tên hàm: LRN
* Mô tả: Duyệt cây theo thứ tự sau
* Kiểu trả về: void
* Tham số: node
*/
void LRN(node* t);

/*
* Tên hàm: searchNode
* Mô tả: Tìm kiếm node chứa dữ liệu x trong cây nptk
* Kiểu trả về: node cần tìm
* Tham số: bstree, số nguyên x
*/
node* searchNode(bstree* bst, int x);
/*
* Tên hàm: searchNode
* Mô tả: Tìm kiếm node chứa dữ liệu x trong cây nptk
* Kiểu trả về: node cần tìm
* Tham số: node, số nguyên x
*/
node* searchNode(node* t, int x);

/*
* Tên hàm: insertNode
* Mô tả: Chèn node chứa dữ liệu x vào cây nptk
* Kiểu trả về: int, trả về 1 nếu thành công, 0 nếu thất bại
* Tham số: bstree, số nguyên x
*/
int insertNode(bstree* &bst, int x);
/*
* Tên hàm: insertNode
* Mô tả: Chèn node chứa dữ liệu x vào cây nptk
* Kiểu trả về: int, trả về 1 nếu thành công, 0 nếu thất bại
* Tham số: node, số nguyên x
*/
int insertNode(node* &t, int x);

/*
* Tên hàm: deleteNode
* Mô tả: Xóa node chứa dữ liệu x trong cây nptk
* Kiểu trả về: int, trả về 1 nếu thành công, 0 nếu thất bại
* Tham số: bstree, số nguyên x
*/
int deleteNode(bstree* &bst, int x);
/*
* Tên hàm: deleteNode
* Mô tả: Xóa node chứa dữ liệu x trong cây nptk
* Kiểu trả về: int, trả về 1 nếu thành công, 0 nếu thất bại
* Tham số: node, số nguyên x
*/
int deleteNode(node* &t, int x);

/*
* Tên hàm: searchStandFor
* Mô tả: Tìm phần tử nhỏ nhất bên phải
* Kiểu trả về: void
* Tham số: node,node
*/
void searchStandFor(node* &p, node* &q);

/*
* Tên hàm: isLeaf
* Mô tả: Kiểm tra 1 node có phải là node lá hay không
* Kiểu trả về: int, trả về 1 nếu thành công, 0 nếu thất bại
* Tham số: node
*/
int isLeaf(node* N);

/*
* Tên hàm: getHighofTree
* Mô tả: Tính chiều cao của cây
* Kiểu trả về: int, chiều cao của cây
* Tham số: bstree.
*/
int getHighofTree(bstree* bst);
/*
* Tên hàm: getHighofTree
* Mô tả: Tính chiều cao của cây
* Kiểu trả về: int, chiều cao của cây
* Tham số: node
*/
int getHighofTree(node* N);

/*
* Tên hàm: removeTree
* Mô tả: Hủy 1 cây
* Kiểu trả về: void
* Tham số: bstree.
*/
void removeTree(bstree* &bst);
/*
* Tên hàm: removeTree
* Mô tả: Hủy 1 cây
* Kiểu trả về: void
* Tham số: node
*/
void removeTree(node* &t);

/*
* Tên hàm: countNode
* Mô tả: Đếm số lượng phần tử của cây
* Kiểu trả về: int : số lượng phần tử của cây
* Tham số: bstree.
*/
int countNode(bstree* bst);
/*
* Tên hàm: countNode
* Mô tả: Đếm số lượng phần tử của cây
* Kiểu trả về: int : số lượng phần tử của cây
* Tham số: node.
*/
int countNode(node* N);

/*
* Tên hàm: countLeaf
* Mô tả: Đếm số lượng node lá của cây
* Kiểu trả về: int : số lượng node lá của cây
* Tham số: bstree.
*/
int countLeaf(bstree* bst);
/*
* Tên hàm: countLeaf
* Mô tả: Đếm số lượng node lá của cây
* Kiểu trả về: int : số lượng node lá của cây
* Tham số: node, int count,
*/
int countLeaf(node* t, int &count);

/*
* Tên hàm: countParent
* Mô tả: Đếm số lượng node cha mẹ của cây
* Kiểu trả về: int : số lượng node cha mẹ của cây
* Tham số: bstree.
*/
int countParent(bstree* bst);
/*
* Tên hàm: countParent
* Mô tả: Đếm số lượng node cha mẹ của cây
* Kiểu trả về: int : số lượng node cha mẹ của cây
* Tham số: node, int count
*/
int countParent(node* t, int &count);

/*
* Tên hàm: averageNodeHave2Node
* Mô tả: Tính trung bình các node có 2 node con
* Kiểu trả về: float: trung bình các node có 2 node con
* Tham số: bstree.
*/
float averageNodeHave2Node(bstree* bst);
/*
* Tên hàm: averageNodeHave2Node
* Mô tả: Tính trung bình các node có 2 node con
* Kiểu trả về: float: trung bình các node có 2 node con
* Tham số: node, float, float
*/
float averageNodeHave2Node(node* t, float &count, float &sum);

/*
* Tên hàm: averageNode
* Mô tả: Tính trung bình tất cả các node của cây
* Kiểu trả về: float: trung bình tất cả các node của cây
* Tham số: bstree.
*/
float averageNode(bstree* bst);
/*
* Tên hàm: averageNode
* Mô tả: Tính trung bình tất cả các node của cây
* Kiểu trả về: float: trung bình tất cả các node của cây
* Tham số: node, float, float
*/
float averageNode(node* t, float &count, float &sum);

/*
* Tên hàm: findNear
* Mô tả: Tìm node có dữ liệu gần nhất với số cho trước
* Kiểu trả về: void
* Tham số: bstree, int arr[], int size
*/
void findNear(bstree* bst, int arr[], int &size);
/*
* Tên hàm: findNear
* Mô tả: Tìm node có dữ liệu gần nhất với số cho trước
* Kiểu trả về: void
* Tham số: bstree, int arr[], int size, node, float min.
*/
void findNear(bstree* bst, node* t, float &min, int *arr, int &size);

/*
* Tên hàm: countNodeHave2Node
* Mô tả: Đếm số lượng các node có 2 node con
* Kiểu trả về: int
* Tham số: bstree.
*/
int countNodeHave2Node(bstree* bst);
/*
* Tên hàm: countNodeHave2Node
* Mô tả: Đếm số lượng các node có 2 node con
* Kiểu trả về: int
* Tham số: node, int count
*/
int countNodeHave2Node(node* t, int& count);

/*
* Tên hàm: bai4
* Mô tả: Hàm xử lý cho bài 4
* Kiểu trả về: void
* Tham số: bstree.
*/
void bai4(bstree* bst);

#endif /* DEFS_H_ */

