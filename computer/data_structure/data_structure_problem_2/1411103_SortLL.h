/*
* MSSV: 1411103
* Họ tên: Nguyễn Quản Bá Hồng
* Tên bài thực hành: Bài tập thực hành tuần 2
* Ngày cập nhật 16/11/2015
*/

/*
* Tên hàm: interchangeSort
* Mô tả: sắp xếp danh sách liên kết bằng thuật toán interchange Sort
* Kiểu trả về: void
* Tham số: List L
*/
void interchangeSort(List* &L);

/*
* Tên hàm: bubbleSort
* Mô tả: sắp xếp danh sách liên kết bằng thuật toán bubble Sort
* Kiểu trả về: void
* Tham số: DList L
*/
void bubbleSort(DList* &L);

/*
* Tên hàm: shakerSort
* Mô tả: sắp xếp danh sách liên kết bằng thuật toán shaker Sort
* Kiểu trả về: void
* Tham số: DList L
*/
void shakerSort(DList* &L);

/*
* Tên hàm: insertionSort
* Mô tả: sắp xếp danh sách liên kết bằng thuật toán insertion Sort
* Kiểu trả về: void
* Tham số: DList L
*/
void insertionSort(DList* &L);

/*
* Tên hàm: shellSort
* Mô tả: sắp xếp danh sách liên kết bằng thuật toán shell Sort
* Kiểu trả về: void
* Tham số: DList L
*/
void shellSort(DList* &L);

/*
* Tên hàm: selectionSort
* Mô tả: sắp xếp danh sách liên kết bằng thuật toán selection Sort
* Kiểu trả về: void
* Tham số: List L
*/
void selectionSort(List* &L);

// Sắp xếp danh sách liên kết bằng phương pháp Heap Sort

/*
* Tên hàm: posNode
* Mô tả: trả về vị trí của node trong danh sách liên kết
* Kiểu trả về: int
* Tham số: DList L, DNode x
*/
int posNode(DList* &L, DNode* &x);

/*
* Tên hàm: getDNodeIndex
* Mô tả: hàm truy xuất đến 1 node của 1 danh sách liên kết khi biết vị trí của nó trong danh sách liên kết đó
* Kiểu trả về: DNode
* Tham số: DList L
*/
DNode* getDNodeIndex(DList* &L, int &x);

/*
* Tên hàm: insertHeap
* Mô tả: chèn Heap
* Kiểu trả về: void
* Tham số: DList L, số nguyên left: vị trí trái, số nguyên right: vị trí phải
*/
void insertHeap(DList* &L, int left, int right);

/*
* Tên hàm: createHeap
* Mô tả: tạo heap
* Kiểu trả về: void
* Tham số: DList L
*/
void createHeap(DList* &L);

/*
* Tên hàm: heapSort
* Mô tả: sắp xếp danh sách liên kết bằng thuật toán heap Sort
* Kiểu trả về: void
* Tham số: DList L
*/
void heapSort(DList* &L);

/*
* Tên hàm: quickSort
* Mô tả: sắp xếp danh sách liên kết bằng thuật toán quick Sort
* Kiểu trả về: void
* Tham số: List L
*/
void quickSort(List* &L);

/*
* Tên hàm: splitList
* Mô tả: ngắt danh sách (dùng hỗ trợ trong quick sort)
* Kiểu trả về: void
* Tham số: List L,L1,L2, Node x
*/
void splitList(List* &L, List* &L1, List* &L2, Node* &x);

/*
* Tên hàm: concatList
* Mô tả: hỗ trợ thuật toán quickSort
* Kiểu trả về: void
* Tham số: List L
*/
void concatList(List* &L, List* &L1, Node* &x, List* &L2);

// Sắp xếp danh sách liên kết bằng phương pháp Merge Sort

/*
* Tên hàm: mergeSort
* Mô tả: sắp xếp danh sách liên kết bằng thuật toán merge Sort
* Kiểu trả về: void
* Tham số: List L
*/
void mergeSort(List* &L);

/*
* Tên hàm: divideList
* Mô tả: chia danh sách, hỗ trợ thuật toán mergeSort
* Kiểu trả về: void
* Tham số: List L,L1,L2
*/
void divideList(List* &L, List* &L1, List* &L2);

/*
* Tên hàm: mergeList
* Mô tả: trộn danh sách, hỗ trợ thuật toán mergeSort
* Kiểu trả về: void
* Tham số: List L, L1,L2
*/
void mergeList(List* &L, List* &L1, List* &L2);


// Sắp xếp danh sách liên kết bằng phương pháp Radix Sort

/*
* Tên hàm: radixSort
* Mô tả: sắp xếp danh sách liên kết bằng thuật toán radix Sort
* Kiểu trả về: void
* Tham số: List L
*/
void radixSort(List* &L);

/*
* Tên hàm: send2Box
* Mô tả: hỗ trợ thuật toán radixSort
* Kiểu trả về: void
* Tham số: List L, temp[],số nguyên n
*/
void send2Box(int n, List* &L, List* temp[]);

/*
* Tên hàm: getDigit
* Mô tả: hỗ trợ thuật toán radixSort
* Kiểu trả về: int
* Tham số: số nguyên n, số nguyên t
*/
int getDigit(int n, int t);

/*
* Tên hàm: getMaxDigit
* Mô tả: lấy chữ số lớn nhất
* Kiểu trả về: int
* Tham số: List L
*/
int getMaxDigit(List* L);

/*
* Tên hàm: findMax
* Mô tả: hỗ trợ radixSort
* Kiểu trả về: int
* Tham số: List L
*/
int findMax(List* L);

/*
* Tên hàm: countDigit
* Mô tả: hỗ trợ radixSort
* Kiểu trả về: int
* Tham số: số nguyên m
*/
int countDigit(int m);