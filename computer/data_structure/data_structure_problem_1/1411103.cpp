/*
* MSSV: 1411103
* Họ tên: Nguyễn Quản Bá Hồng
* Tên bài thực hành: Bài tập thực hành tuần 1
* Ngày cập nhật 20/10/2015
*/
#include <stdio.h>
#include <iostream>
#include <fstream>	//thư viện filestream xử lý file trong C++
#include <string>	//thư viện string xử lý chuỗi
#include "1411103_SearchAls.h"
#include "1411103_SortAls.h"

#define inputFileName "data.txt"  //bộ test được đưa vào inputFile
#define outputFileName "output\\1411103.txt"  //kết quả được ghi ra file 1411103.txt trong thư mục output
#define maxN 100
using namespace std;

void display(int arr[], int n, ofstream &outputFile){
	for (int i = 0; i < n; i++)
		outputFile << arr[i] << " ";
	outputFile << endl;
}

int main() {
	int number = 0;
	ifstream inputFile(inputFileName);
	ofstream outputFile(outputFileName);
	string line, data;
	int arr[maxN]{};
	int n = 0, walk = 0, length = 0;
	int *p = NULL;
	while (!inputFile.eof()) {	//chạy nếu chưa đến cuối file inputFile
		getline(inputFile, line);
		if (number % 2 == 0)
			outputFile << line << endl;
		else {
			n = 0;
			walk = 0;
			data = "";
			length = line.length();
			while (walk < length) {
				data = "";
				while (line[walk] != ' ' && line[walk] != ':' && line[walk] != '\0') {
					data += line[walk];
					walk++;
				}
				arr[n] = atoi(data.c_str());	//chuyển ký tự sang số, rồi ghép vào mảng arr.
				n++;
				if (line[walk] != ' ')
					break;
				walk++;
			}
			//chạy các thuật toán tìm kiếm.
			if (number < 20) {
				data = "";
				walk++;
				for (; walk < length; walk++)
					data += line[walk];
				int x = atoi(data.c_str());
				if (number / 10 == 0)
					outputFile << LinearSearch(arr, n, x) << endl;
				else
					outputFile << BinarySearch(arr, n, x) << endl;
			}
			else {
				p = arr;
				//chạy các thuật toán sắp xếp.
				switch (number / 10) {
				case 2:
					InterchangeSort(p, n);
					display(arr, n, outputFile);
					break;
				case 3:
					BubbleSort(p, n);
					display(arr, n, outputFile);
					break;
				case 4:
					ShakerSort(p, n);
					display(arr, n, outputFile);
					break;
				case 5:
					InsertionSort(p, n);
					display(arr, n, outputFile);
					break;
				case 6:
					ShellSort(p, n);
					display(arr, n, outputFile);
					break;
				case 7:
					SelectionSort(p, n);
					display(arr, n, outputFile);
					break;
				case 8:
					HeapSort(p, n);
					display(arr, n, outputFile);
					break;
				case 9:
					QuickSort(p, 0, n - 1);
					display(arr, n, outputFile);
					break;
				case 10:
					MergeSort(p, 0, n - 1);
					display(arr, n, outputFile);
					break;
				case 11:
					RadixSort(arr , n);
					display(arr, n, outputFile);
					break;
				}
			}
		}
		number++;
	}
	inputFile.close();		//đóng file inputFile
	outputFile.close();		//đóng file outputFile
	return 0;
}