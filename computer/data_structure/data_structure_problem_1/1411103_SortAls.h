/*
* MSSV: 1411103
* Họ tên: Nguyễn Quản Bá Hồng
* Tên bài thực hành: Bài tập thực hành tuần 1
* Ngày cập nhật 20/10/2015
*/

/*
* Tên hàm: swap.
* Mô tả: hoán vị 2 số.
* Kiểu trả về: void
* Tham số: số nguyên a và số nguyên b
*/
void swap(int& a, int& b);

/*
* Tên hàm: InterchangeSort.
* Mô tả: Sắp xếp mảng bằng thuật toán đổi chỗ trực tiếp.
* Kiểu trả về: void
* Tham số: mảng nguyên a.
* Tham số: số nguyên n, chiều dài của mảng.
*/
void InterchangeSort(int *&a, int n);

/*
* Tên hàm: BubbleSort
* Mô tả: Sắp xếp mảng bằng thuật toán nổi bọt
* Kiểu trả về: void
* Tham số: mảng nguyên a.
* Tham số: số nguyên n, chiều dài của mảng.
*/
void BubbleSort(int *&a, int n);

/*
* Tên hàm: ShakerSort.
* Mô tả: Sắp xếp mảng bằng thuật toán ShakerSort
* Kiểu trả về: void
* Tham số: mảng nguyên a.
* Tham số: số nguyên n, chiều dài của mảng.
*/
void ShakerSort(int *&a, int n);

/*
* Tên hàm: InsertionSort
* Mô tả: Sắp xếp mảng bằng thuật toán chèn trực tiếp.
* Kiểu trả về: void
* Tham số: mảng nguyên a.
* Tham số: số nguyên n, chiều dài của mảng.
*/
void InsertionSort(int *&a, int n);

/*
* Tên hàm: ShellSort
* Mô tả: Sắp xếp mảng bằng thuật toán ShellSort.
* Kiểu trả về: void
* Tham số: mảng nguyên a.
* Tham số: số nguyên n, chiều dài của mảng.
*/
void ShellSort(int *&a, int n, int h[], int k); //phân hoạch mảng a thành các dãy có chiều dài h[i].
void ShellSort(int *&a, int n);

/*
* Tên hàm: SelectionSort.
* Mô tả: Sắp xếp mảng bằng thuật toán chọn trực tiếp
* Kiểu trả về: void
* Tham số: mảng nguyên a.
* Tham số: số nguyên n, chiều dài của mảng.
*/
void SelectionSort(int *&a, int n);

/*
* Tên hàm: InsertHeap
* Mô tả: tạo 1 heap mới dài hơn 1 phần tử từ 1 heap của mảng a.
* Kiểu trả về: void
* Tham số: mảng nguyên a.
* Tham số: left, right, chỉ số đánh dấu phần mảng con của mảng a cần xử lý.
*/
void InsertHeap(int *&a, int left, int right);

/*
* Tên hàm: CreateHeap
* Mô tả: Sử dụng InsertHeap, trả về mảng a là heap max.
* Kiểu trả về: void
* Tham số: mảng nguyên a.
* Tham số: left, right, chỉ số đánh dấu phần mảng con của mảng a cần xử lý.
*/
void CreateHeap(int *&a, int n);

/*
* Tên hàm: HeapSort.
* Mô tả: Sắp xếp mảng bằng thuật toán HeapSort.
* Kiểu trả về: void
* Tham số: mảng nguyên a.
* Tham số: số nguyên n, chiều dài của mảng.
*/
void HeapSort(int *&a, int n);

/*
* Tên hàm: QuickSort
* Mô tả: Sắp xép mảng a từ left đến right.
* Kiểu trả về: void
* Tham số: mảng nguyên a.
* Tham số: left, right, chỉ số đánh dấu phần mảng con của mảng a cần xử lý.
*/
void QuickSort(int *&a, int left, int right);

/*
* Tên hàm: merge
* Mô tả: Sắp xếp mảng a từ left đến right.
* Kiểu trả về: void
* Tham số: mảng nguyên a.
* Tham số: left, mid, right, chỉ số đánh dấu phần mảng con của mảng a cần xử lý.
*/
void merge(int *&a, int left, int mid, int right);

/*
* Tên hàm: MergeSort.
* Mô tả: Sắp xếp mảng a bằng thuật toán MergeSort.
* Kiểu trả về: void
* Tham số: mảng nguyên a.
* Tham số: left, right, chỉ số đánh dấu phần mảng con của mảng a cần xử lý.
*/
void MergeSort(int *&a, int left, int right);

/*
* Tên hàm: RadixSort
* Mô tả: Sắp xếp mảng a bằng thuật toán RadixSort.
* Kiểu trả về: void
* Tham số: mảng nguyên arr
* Tham số: số nguyên n, chiều dài của mảng arr.
*/
void RadixSort(int arr[], int n);
void countSort(int arr[], int n, int exp);	//hàm countSort phụ trợ cho hàm RadixSort
int getMax(int arr[], int n);				// hàm getMax phụ trợ cho hàm RadixSort.