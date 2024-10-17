/*
* MSSV: 1411103
* Họ tên: Nguyễn Quản Bá Hồng
* Tên bài thực hành: Bài tập thực hành tuần 2
* Ngày cập nhật 16/11/2015
*/

#include "1411103_LinkedList.h"
#include "1411103_SortLL.h"
#include <stdio.h>
#include <iostream>

// Sắp xếp danh sách liên kết bằng phương pháp Interchange Sort
void interchangeSort(List* &L){
	for (Node* p = L->Head; p->Next; p = p->Next)
	for (Node* q = p->Next; q; q = q->Next)
	if (p->Data > q->Data){
		int temp = p->Data;
		p->Data = q->Data;
		q->Data = temp;
	}
}

// Sắp xếp danh sách liên kết bằng phương pháp Bubble Sort
void bubbleSort(DList* &L){
	for (DNode* p = L->Head; p->Next; p = p->Next){
		for (DNode* q = L->Tail; q != p;q=q->Prev)
		if (q->Data < q->Prev->Data){
			int temp = q->Data;
			q->Data = q->Prev->Data;
			q->Prev->Data = temp;
		}
	}
}

// Sắp xếp danh sách liên kết bằng phương pháp Shaker Sort

void shakerSort(DList* &L){
	DNode* first = L->Head;
	DNode* last = L->Tail;
	DNode* F;
	DNode* T;
	int left = 0, right = countDList(L);
	while (left < right){ // có từ 2 nút trở lên
		for (F = first; F->Next != last;F=F->Next)
		if (F->Data > F->Next->Data) {
			DNode* p = F->Next;
			swap(F->Data, p->Data);
		}
		for (T = last; T->Prev != first;T=T->Prev)
		if (T->Data < T->Prev->Data)
			swap(T->Data, T->Prev->Data);
		left++; right--;
	}
}


// Sắp xếp danh sách liên kết bằng phương pháp Insertion Sort 
void insertionSort(DList* &L){
	for (DNode* p = L->Head->Next; p; p = p->Next){
		int x = p->Data; 
		DNode* j = p->Prev;
		while (j->Prev && x < j->Data){
			j->Next->Data = j->Data;
			j = j->Prev;
		}
		j->Next->Data = x;
	}
}

// Sắp xếp danh sách liên kết bằng phương pháp Shell Sort

void shellSort(DList* &L){
	if (L->Head){
		int step = 0;
		int length = 0;
		DNode* p = L->Head;
		while (p){
			length++;
			p = p->Next;
		}
		while (2 * (3 * step + 1) <= length)
			step = 3 * step + 1;
		for (step; step > 0;step/=3)
		for (int i = step; i > 0;i--)
		for (int j = step - i; j < length; j += step){
			p = L->Head;
			int k;
			for (k = 0; k < j; k++)
				p = p->Next;
			DNode* c = p;
			int temp = k + step;
			while (c){
				for (k; k < temp;)
				if (c){
					k++;
					c = c->Next;
				}
				else break;
				if (c)
				if (p->Data > c->Data){
					int t = p->Data;
					p->Data = c->Data;
					c->Data = t;
				}
				temp += step;
			}
		}
	}
}


// Sắp xếp danh sách liên kết bằng phương pháp Selection Sort
void selectionSort(List* &L){
	for (Node* p = L->Head; p->Next; p = p->Next){
		Node* lc = p;
		for (Node* q = p; q; q = q->Next)
		if (q->Data < lc->Data)
			lc = q;
		int temp = p->Data;
		p->Data = lc->Data;
		lc->Data = temp;
	}
}

// Sắp xếp danh sách liên kết bằng phương pháp Heap Sort
// trả về vị trí của Node* x trong danh sách liên kết T, như chỉ số của một số trong mảng số nguyên
int posNode(DList* &L, DNode* &x){
	if (isEmpty(L) == 1)
		return -1;
	else {
		int pos = 0;
		DNode* p = L->Head;
		while (p && p!=x){
			pos++;
			p = p->Next;
		}
		return pos;
	}
}


// Hàm truy xuất đến 1 Node* nếu biết "chỉ số" trong danh sách liên kết
DNode* getDNodeIndex(DList* &L, int &x){
	if (isEmpty(L) == 1)
		return NULL;
	else{
		DNode* p = L->Head; 
		int index = 0;
		while (index < x){
			p = p->Next;
			index++;
		}
		return p;
	}
}

void insertHeap(DList* &L, int left, int right){
	int p;
	p = 2 * left;
	if (p > right)
		return;
	else
	if (p < right){
		DNode* a = getDNodeIndex(L, p);
		if (a->Data < a->Next->Data)
			p++;
	}
	DNode* a = getDNodeIndex(L, p);
	DNode* b = getDNodeIndex(L, left);
	if (b->Data < a->Data){
		swap(b->Data, a->Data);
		insertHeap(L, p, right);
	}
}

void createHeap(DList* &L){
	int n = countDList(L);
	for (int k = (n + 1) / 2; k >= 0; k--)
		insertHeap(L, k, n - 1);
}

void heapSort(DList* &L){
	int n = countDList(L);
	createHeap(L);
	DNode* a0 = L->Head;
	for (int i = n - 1; i > 0; i--){
		DNode* b = getDNodeIndex(L, i);
		swap(a0->Data, b->Data);
		insertHeap(L, 0, i - 1);
	}
}

// Sắp xếp danh sách liên kết bằng phương pháp Quick Sort
void quickSort(List* &L){
	List* T1;
	List* T2;
	if (L->Head == L->Tail)
		return;
	initSLL(T1);
	initSLL(T2);
	Node* x = L->Head;
	splitList(L, T1, T2, x);
	quickSort(T1);
	quickSort(T2);
	concatList(L, T1, x, T2);
	initSLL(T1);
	initSLL(T2);
}
void splitList(List* &L, List* &L1, List* &L2, Node* &x){
	Node* p;
	x = L->Head;
	L->Head = x->Next;
	x->Next = NULL;
	while (!isEmpty(L)){
		p = L->Head;
		L->Head = p->Next;
		p->Next = NULL;
		if (p->Data <= x->Data)
			insertNode2Tail(L1, p->Data);
		else
			insertNode2Tail(L2, p->Data);
	}
	initSLL(L);
}
void concatList(List* &L, List* &L1, Node* &x, List* &L2){
	appendSLL(L, L1);
	insertNode2Tail(L, x->Data);
	appendSLL(L, L2);
	initSLL(L1);
	initSLL(L2);
}

// Sắp xếp danh sách liên kết bằng phương pháp Merge Sort
void mergeSort(List* &L){
	List* T1;
	List* T2;
	if (L->Head == L->Tail)
		return;
	initSLL(T1);
	initSLL(T2);
	divideList(L, T1, T2);
	mergeSort(T1);
	mergeSort(T2);
	mergeList(L, T1, T2);
}

void divideList(List* &L, List* &L1, List* &L2){
	Node* p;
	while (!isEmpty(L)){
		p = L->Head;
		L->Head = p->Next;
		p->Next = NULL;
		insertNode2Tail(L1, p->Data);
		if (!isEmpty(L)){
			p = L->Head;
			L->Head = p->Next;
			p->Next = NULL;
			insertNode2Tail(L2, p->Data);
		}
	}
	initSLL(L);
}
void mergeList(List* &L, List* &L1, List* &L2){
	Node* p;
	while (!isEmpty(L1) && !isEmpty(L2)){
		if (L1->Head->Data <= L2->Head->Data){
			p = L1->Head;
			L1->Head = p->Next;
			p->Next = NULL;
		}
		else {
			p = L2->Head;
			L2->Head = p->Next;
			p->Next = NULL;
		}
		insertNode2Tail(L, p->Data);
	}
	if (!isEmpty(L1))
		appendSLL(L, L1);
	if (!isEmpty(L2))
		appendSLL(L, L2);
	initSLL(L1);
	initSLL(L2);
}

// Sắp xếp danh sách liên kết bằng phương pháp Radix Sort
void radixSort(List* &L){
	List* temp[10];
	if (L->Head == L->Tail)
		return;
	for (int i = 0; i < 10; i++)
		initSLL(temp[i]);
	int numDigit = getMaxDigit(L);
	for (int i = 0; i < numDigit; i++){
		send2Box(i, L, temp);
		for (int j = 0; j < 10; j++){
			if (!isEmpty(temp[j]))
				appendSLL(L, temp[j]);
			initSLL(temp[j]);
		}
	}
}
void send2Box(int n, List* &L, List* temp[]){
	Node* p;
	while (!isEmpty(L)){
		p = getHead(L);
		addTail(temp[getDigit(n, p->Data)], p);
	}
	initSLL(L);
}
int getDigit(int n, int t){
	long temp = 1;
	for (int i = 0; i < n; i++)
		temp *= 10; //t=t/10
	return abs((t / temp) % 10); //abs((t%10))
}
int getMaxDigit(List* T){
	int max = findMax(T);
	return countDigit(max);
}
int findMax(List* L){
	Node* p = L->Head;
	int max = p->Data;
	while (p){
		if (p->Data > max)
			max = p->Data;
		p = p->Next;
	}
	return max;
}
int countDigit(int m){
	int count = 0;
	while (m){
		m /= 10;
		count++;
	}
	return count;
}
