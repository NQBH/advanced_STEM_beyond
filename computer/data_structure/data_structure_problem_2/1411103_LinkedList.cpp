/*
* MSSV: 1411103
* Họ tên: Nguyễn Quản Bá Hồng
* Tên bài thực hành: Bài tập thực hành tuần 2
* Ngày cập nhật 16/11/2015
*/

#include "1411103_LinkedList.h"
#include <stdio.h>
#include <iostream>

// CÁC THAO TÁC TRÊN DANH SÁCH LIÊN KẾT ĐƠN

// khởi tạo danh sách liên kết đơn
void initSLL(List* &L){
	L = new List();
	L->Head = L->Tail = NULL;
}

// kiểm tra danh sách liên kết có rỗng hay không
int isEmpty(List* L){
	return(L->Head == NULL);
}

// chèn node có giá trị x vào đầu danh sách liên kết
int insertNode2Head(List* L, int x){
	Node* p = new Node();
	if (p == NULL)
		return 0;
	p->Data = x;
	p->Next = NULL;
	if (isEmpty(L)){
		L->Head = L->Tail = p;
	}
	else{
		p->Next = L->Head;
		L->Head = p;
	}
	return 1;
}

// chèn node có giá trị x vào cuối danh sách liên kết
int insertNode2Tail(List* L, int x){
	Node* p = new Node();
	if (p == NULL)
		return 0;
	p->Data = x;
	p->Next = NULL;
	if (isEmpty(L)){
		L->Head = L->Tail = p;
	}
	else{
		L->Tail->Next = p;
		L->Tail = p;
	}
	return 1;
}

// chèn node có giá trị x vào sau node q trong danh sách
int insertNode2After(List* L, Node* q, int x){
	Node* p = new Node();
	if (p == NULL)
		return 0;
	p->Data = x;
	p->Next = NULL;
	if (isEmpty(L)){
		L->Head = L->Tail = p;
	}
	else{
		p->Next = q->Next;
		q->Next = p;
		if (q == L->Tail)
			L->Tail = p;
	}
	return 1;
}

// loại bỏ node đầu tiên
int removeNodeAtHead(List* L){
	Node* p = L->Head;
	if (isEmpty(L))
		return -1;
	L->Head = p->Next;
	if (L->Head == NULL)
		L->Tail = NULL;
	p->Next = NULL;
	delete p;
	return 1;
}

// loại bỏ node cuối cùng
int removeNodeAtTail(List* L){
	Node* p = L->Head;
	Node* q = NULL;
	while (p != L->Tail){
		q = p;
		p = p->Next;
	}
	if (!p)
		return -1;
	if (q){
		q->Next = NULL;
		L->Tail = q;
	}
	else{
		L->Head = L->Tail = NULL;
	}
	delete p;
	return 1;
}

// loại bỏ node đầu tiên trong danh sách có giá trị bằng x
int removeNode(List* L, int x) {
	Node* p = L->Head;
	if (!p)
		return -1;
	if (p->Data != x && L->Tail->Data != x){
		Node* q = NULL;
		while (p->Data != x && p){
			q = p;
			p = p->Next;
		}
		if (!p)
			return 0;
		q->Next = p->Next;
		p->Next = NULL;
		delete p;
	}
	else {
		if (p->Data == x)
			return removeNodeAtHead(L);
		if (L->Tail->Data == x)
			return removeNodeAtTail(L);
	}
	return 1;
}

// Hàm dùng để nối 2 danh sách liên kết
void appenSLL(List* L1, List* L2){
	if (isEmpty(L1))
		L1 = L2;
	else{
		L1->Tail->Next = L2->Head;
		if (!isEmpty(L2))
			L1->Tail = L2->Tail;
	}
}

// Hàm thêm node p vào đầu danh sách liên kết
void addHead(List* L, Node* p){
	if (L->Head == NULL)
		L->Head = L->Tail = p;
	else{
		p->Next = L->Head;
		L->Head = p;
	}
}

// Hàm thêm node p vào cuối danh sách liên kết
void addTail(List* L, Node* p){
	if (L->Head == NULL)
		L->Head = L->Tail = p;
	else{
		L->Tail->Next = p;
		L->Tail = p;
	}
}

// Hàm lấy node đầu tiên trong danh sách liên kết
Node* getHead(List* L){
	Node* p = L->Head;
	return p;
}

// Hàm đếm số phần tử của danh sách liên kết đơn
int countList(List* L){
	Node* first = L->Head;
	if (isEmpty(L) == 1){
		return 0;
	}
	else{
		int i = 1;
		Node* F = first;
		while (F->Next != NULL){
			i++;
			F = F->Next;
		}
		return i;
	}
}


// CÁC THAO TÁC TRÊN DANH SÁCH LIÊN KẾT ĐÔI

// khởi tạo danh sách liên kết đôi
void initDLL(DList* L) {
	L->Head = L->Tail = NULL;
}

// kiểm tra danh sách liên kết có rỗng hay không
int isEmpty(DList* L) {
	return(L->Head == NULL);
}


// Chèn Node có giá trị x vào đầu danh sách liên kết
int insertNode2Head(DList* &L, int x){
	DNode* p = new DNode();
	if (p == NULL)
		return 0;
	p->Data = x;
	p->Next = p->Prev = NULL;
	if (isEmpty(L)){
		L->Head = L->Tail = p;
	}
	else{
		p->Next = L->Head;
		L->Head->Prev = p;
		L->Head = p;
	}
	return 1;
}

// chèn node có giá trị x vào cuối danh sách liên kết
int insertNode2Tail(DList* &L, int x){
	DNode* p = new DNode();
	if (p == NULL)
		return 0;
	p->Data = x;
	p->Next = NULL;
	if (isEmpty(L)){
		L->Head = L->Tail = p;
	}
	else{
		L->Tail->Next = p;
		p->Prev = L->Tail;
		L->Tail = p;
	}
	return 1;
}

// chèn node có giá trị x vào sau node q trong danh sách
int insertNode2After(DList* &L, DNode* q, int x){
	DNode* p = new DNode();
	if (p == NULL)
		return 0;
	p->Data = x;
	p->Next = NULL;
	if (isEmpty(L)){
		L->Head = L->Tail = p;
	}
	else{
		p->Next = q->Next;
		p->Prev = q;
		q->Next->Prev = p;
		q->Next = p;
		if (q == L->Tail)
			L->Tail = p;
	}
	return 1;
}

// loại bỏ node đầu tiên
int removeNodeAtHead(DList* &L){
	DNode* p = L->Head;
	if (isEmpty(L))
		return -1;
	L->Head = p->Next;
	if (L->Head == NULL)
		L->Tail = NULL;
	//khong biet them ngay day co dung ko
	L->Head->Prev = NULL;
	p->Next = NULL;
	delete p;
	return 1;
}

// loại bỏ node cuối cùng

int removeNodeAtTail(DList* &L){
	DNode* p = L->Tail;
	DNode* q = p->Prev;
	if (!p)
		return -1;
	if (q){
		L->Tail = q;
		L->Tail->Next = NULL;
		p->Next = p->Prev = NULL;
	}
	else{
		L->Head = L->Tail = NULL;
	}
	delete p;
	return 1;
}

DNode* getHead(DList* &L){
	DNode* p = L->Head;
	return p;
}

// Hàm đếm số phần tử của danh sách liên kết đôi
int countDList(DList* &L){
	DNode* first = L->Head;
	if (isEmpty(L) == 1){
		return 0;
	}
	else{
		int i = 1;
		DNode* F = first;
		while (F->Next != NULL){
			i++;
			F = F->Next;
		}
		return i;
	}
}

// Tìm 1 phần tử có giá trị x trong danh sách liên kết
DNode* searchNode(DList* &L, int x){
	DNode* p = L->Head;
	if (p = NULL)
		return NULL;
	while (p){
		if (p->Data == x)
			return p;
		p = p->Next;
	}
	return NULL;
}

// Hủy 1 phần tử mang giá trị x trong danh sách liên kết
int removeNode(DList* &L, int x){
	DNode* p = L->Head;
	if (!p)
		return -1;
	if (p->Data != x && L->Tail->Data != x){
		DNode* q = NULL;
		while (p->Data != x && p){
			q = p;
			p = p->Next;
		}
		if (!p)
			return 0;
		q->Next = p->Next;
		p->Next = NULL;
		delete p;
	}
	else{
		if (p->Data == x)
			return removeNodeAtHead(L);
		if (L->Tail->Data == x)
			return removeNodeAtTail(L);
	}
	return 1;
}

// Nối danh sách liên kết 1 vào cuối danh sách liên kết 2
void appendSLL(List* &L1, List* &L2){
	if (isEmpty(L1))
		L1 = L2;
	else{
		L1->Tail->Next = L2->Head;
		if (!isEmpty(L2))
			L1->Tail = L2->Tail;
	}
}

// MỘT SỐ HÀM PHỤ KHÁC

// hàm swap 2 số nguyên
void swap(int &a, int &b)  {
	int temp = a;
	a = b;
	b = temp;
}
