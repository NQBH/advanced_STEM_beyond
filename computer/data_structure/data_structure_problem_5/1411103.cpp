/*
* MSSV: 1411103
* Họ tên: Nguyễn Quản Bá Hồng
* Tên bài thực hành: Bài tập thực hành tuần 5
* Ngày cập nhật 19/12/2015
*/

#include <iostream>		
#include <stdio.h>
#include <stdlib.h>
#include <string>		// thư viện xứ lý chuỗi của C++
using namespace std;

#include "1411103_defs.h"
#include <conio.h>
void main(){

	int number = 0;
	ifstream inputFile(INPUT_FILE);			// đọc file data
	ofstream outputFile(OUTPUT_FILE);		// xuất ra file output

	string line, data;
	int n = 0, walk = 0, length = 0;

	int figure;
	bstree* bst = new bstree();		// cấp phát cho cây nptk 

	int arr[100];
	int size;

	while (!inputFile.eof()) {	//chạy nếu chưa đến cuối file inputFile
		getline(inputFile, line);		// lấy từng dòng từ file dữ liệu
		if (number % 2 == 0)			// phân biệt dòng tiêu đề và dòng dữ liệu (xen kẽ)
			outputFile << line << endl;	// xuất ra dòng tiêu đề
		else {
			length = line.length();
			walk = 0;
			while (walk < length) {
				data = "";
				while (line[walk] != ' ' && line[walk] != '\0') {
					data += line[walk];
					walk++;
				}
				figure = atoi(data.c_str());
				insertNode(bst, figure);
				n++;
				if (line[walk] != ' ')
					break;
				walk++;
			}

			switch (number / 10) {
			case 0:
				outputFile << countNode(bst) << endl;
				removeTree(bst->root);
				break;
			case 1:
				outputFile << countLeaf(bst) << endl;
				removeTree(bst->root);
				break;
			case 2:
				outputFile << countParent(bst) << endl;
				removeTree(bst->root);
				break;
			case 3:
				if (countNodeHave2Node(bst) == 0)
					outputFile << "NaN\n";
				else
					outputFile << averageNodeHave2Node(bst) << endl;
				removeTree(bst->root);
				break;
			case 4:
				findNear(bst, arr, size);
				for (int i = 0; i < size; i++)
					outputFile << arr[i] << " ";
				outputFile << endl;
				removeTree(bst->root);
				break;
			}
		}
		number++;
	}
	inputFile.close();		//đóng file inputFile
	outputFile.close();		//đóng file outputFile	
}