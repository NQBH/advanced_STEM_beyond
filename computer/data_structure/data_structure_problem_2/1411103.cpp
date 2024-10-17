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
#include <fstream>
#include <string>
using namespace std;

#define inputFileName "data.txt"  //bộ test được đưa vào inputFile
#define outputFileName "output\\1411103.txt"  //kết quả được ghi ra file 1411103.txt trong thư mục output
#define maxN 100
using namespace std;

void clear(List* L) {
	Node* p;
	while (L->Head != NULL) {
		p = L->Head;
		L->Head = L->Head->Next;
		delete p;
	}
	L->Tail = NULL;
}

void clear(DList* L) {
	DNode* p;
	while (L->Head != NULL) {
		p = L->Head;
		L->Head = L->Head->Next;
		delete p;
	}
	L->Tail = NULL;
}

void display(List* L, ofstream &outputFile){
	for (Node* p = L->Head; p; p = p->Next)
		outputFile << p->Data << " ";
	outputFile << endl;
}

void display(DList* L, ofstream &outputFile){
	for (DNode* p = L->Head; p; p = p->Next)
		outputFile << p->Data << " ";
	outputFile << endl;
}

DList* convertList2DList(List* L) {
	DList* DL = new DList();
	for (Node* p = L->Head; p; p = p->Next)
		insertNode2Tail(DL, p->Data);
	return DL;
}

int main() {
	int number = 0;
	ifstream inputFile(inputFileName);
	ofstream outputFile(outputFileName);
	string line, data;
	int n = 0, walk = 0, length = 0;
	int firgure;
	List* L = new List();
	DList* DL = new DList();
	while (!inputFile.eof()) {	//chạy nếu chưa đến cuối file inputFile
		getline(inputFile, line);
		if (number % 2 == 0)
			outputFile << line << endl;
		else {
			Node* p = L->Head;
			data = "";
			length = line.length();
			walk = 0;
			while (walk < length) {
				data = "";
				while (line[walk] != ' ' && line[walk] != '\0') {
					data += line[walk];
					walk++;
				}
				firgure = atoi(data.c_str());	//chuyển ký tự sang số, rồi ghép vào mảng arr.
				insertNode2Tail(L, firgure);
				n++;
				if (line[walk] != ' ')
					break;
				walk++;
			}
			//chạy các thuật toán sắp xếp.
			switch (number / 10) {
			case 0:
				interchangeSort(L);
				display(L, outputFile);
				break;
			case 1:
				DL = convertList2DList(L);
				bubbleSort(DL);
				display(DL, outputFile);
				break;
			case 2:
				DL = convertList2DList(L);
				shakerSort(DL);
				display(DL, outputFile);
				break;
			case 3:
				DL = convertList2DList(L);
				insertNode2Head(DL, -99999);
				insertionSort(DL);
				DL->Head = DL->Head->Next;
				display(DL, outputFile);
				break;
			case 4:
				DL = convertList2DList(L);
				shellSort(DL);
				display(DL, outputFile);
				break;
			case 5:
				selectionSort(L);
				display(L, outputFile);
				break;
			case 6:
				DL = convertList2DList(L);
				heapSort(DL);
				display(DL, outputFile);
				break;
			case 7:
				quickSort(L);
				display(L, outputFile);
				break;
			case 8:
				mergeSort(L);
				display(L, outputFile);
				break;
			case 9:
				radixSort(L);
				display(L, outputFile);
				break;
			}
		}
		number++;
		clear(L);
		clear(DL);
	}
	inputFile.close();		//đóng file inputFile
	outputFile.close();		//đóng file outputFile
	return 0;
}