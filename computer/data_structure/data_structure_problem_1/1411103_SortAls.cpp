/*
* MSSV: 1411103
* Họ tên: Nguyễn Quản Bá Hồng
* Tên bài thực hành: Bài tập thực hành tuần 1
* Ngày cập nhật 20/10/2015
*/
#include "1411103_SearchAls.h"
#include "1411103_SortAls.h"
#include <stdio.h>
#include <iostream>
void swap(int& a, int& b){ //hoán vị 2 số
	int c = a;
	a = b;
	b = c;
}
//Cài đặt các thuật toán theo phần hướng dẫn cài đặt trong sách giáo khoa
void InterchangeSort(int *&a, int n){
	for (int i = 0; i<n - 1; i++)
		for (int j = i + 1; j<n; j++)
			if (a[i]>a[j])
				swap(a[i], a[j]);			//hoán vị các nghịch thế
}
void BubbleSort(int *&a, int n){
	for (int i = 0; i<n; i++)
		for (int j = n - 1; j>i; j--)
			if (a[j - 1]>a[j])
				swap(a[j - 1], a[j]);
}
void ShakerSort(int *&a, int n){
	int up = 0, down = n - 1, hv = 0;
	while (up<down){
		for (int i = up; i<down; i++)
			if (a[i]>a[i + 1]){
				swap(a[i], a[i + 1]);
				hv = i;
		}
		down = hv;
		for (int j = down; j>up; j--)
			if (a[j - 1]>a[j]){
				swap(a[j - 1], a[j]);
				hv = j;
		}
		up = hv;
	}
}
void InsertionSort(int *&a, int n){
	for (int i = 1; i<n; i++){
		int x = a[i], j = i - 1;
		while (x<a[j] && j >= 0){
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void ShellSort(int *&a, int n)		
{
	int h[] = { 3, 2, 1 }, k = 3;
	ShellSort(a, n, h, k);
}
void ShellSort(int *&a, int n, int h[], int k){
	int p, j, t, x;
	for (p = 0; p<k; p++){
		t = h[p];
		for (int i = t; i<n; i++){
			x = a[i];
			j = i;
			while (x<a[j - t] && j >= t){
				a[j] = a[j - t];
				j = j - t;
			}
			a[j] = x;
		}
	}
}
void SelectionSort(int *&a, int n){
	for (int i = 0; i<n - 1; i++){
		int k = i;
		for (int j = i + 1; j<n; j++)
		if (a[k]>a[j])
			k = j;
		swap(a[k], a[i]);
	}
}
void InsertHeap(int *&a, int left, int right){
	int p;
	p = 2 * left;
	if (p>right)
		return;
	else
	if (p<right)
	if (a[p]<a[p + 1])
		p++;
	if (a[left]<a[p]){
		swap(a[left], a[p]);
		InsertHeap(a, p, right);
	}
}
void CreateHeap(int *&a, int n){
	for (int k = (n + 1) / 2; k >= 0; k--)
		InsertHeap(a, k, n - 1);
}
void HeapSort(int *&a, int n){
	CreateHeap(a, n);
	for (int i = n - 1; i>0; i--){
		swap(a[0], a[i]);
		InsertHeap(a, 0, i - 1);
	}
}
void QuickSort(int *&a, int left, int right){
	int x = a[(left + right) / 2], i = left, j = right;
	while (i<j){
		while (a[i]<x)
			i++;
		while (a[j]>x)
			j--;
		if (i<j)
			swap(a[i], a[j]);
	}
	if (left<j)
		QuickSort(a, left, j);
	if (i<right)
		QuickSort(a, i + 1, right);
}
void merge(int *&a, int left, int mid, int right){
	int k = left, i = left, j = mid + 1, b[20];
	while (k <= mid && j <= right){
		if (a[k] <= a[j])
			b[i++] = a[k++];
		else b[i++] = a[j++];
	}
	if (j <= right)
	for (int h = j; h <= right; h++)
		b[i++] = a[h];
	if (k <= mid)
	for (int h = k; h <= mid; h++)
		b[i++] = a[h];
	for (int s = left; s <= right; s++)
		a[s] = b[s];
}
void MergeSort(int *&a, int left, int right){
	if (left < right){
		int mid = (left + right) / 2;
		MergeSort(a, left, mid);
		MergeSort(a, mid + 1, right);
		merge(a, left, mid, right);
	}
}
int getMax(int arr[], int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
	if (arr[i] > max)
		max = arr[i];
	return max;
}
void countSort(int arr[], int n, int exp)
{
	int output[100];
	int i, count[10] = { 0 };
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}
/*
phần cài đặt trong sách khi chạy bị hiện lên thông báo Unhandle violence writing at line 
b[temp][t[temp]++]=a[i]. em không biết xử lý nên thay bằng đoạn này.
*/
void RadixSort(int arr[], int n)
{
	int m = getMax(arr, n);
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}