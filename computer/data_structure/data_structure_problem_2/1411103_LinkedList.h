/*
* MSSV: 1411103
* Họ tên: Nguyễn Quản Bá Hồng
* Tên bài thực hành: Bài tập thực hành tuần 2
* Ngày cập nhật 16/11/2015
*/


// CÀI ĐẶT DANH SÁCH LIÊN KẾT ĐƠN

// cài đặt Node
struct Node{
	int Data;
	Node *Next;
};

// cài đặt danh sách liên kết đơn List
struct List{
	Node* Head;
	Node* Tail;
};

// CÀI ĐẶT DANH SÁCH LIÊN KẾT ĐÔI

// cài đặt DNode
struct DNode{
	int Data;
	DNode *Next;
	DNode *Prev;
};

// cài đặt danh sách liên kết đôi DList
struct DList{
	DNode* Head;
	DNode* Tail;
};

// CÁC THAO TÁC TRÊN DANH SÁCH LIÊN KẾT ĐƠN

/*
* Tên hàm: initSLL
* Mô tả: Khởi tạo danh sách liên kết đơn rỗng
* Kiểu trả về: void
* Tham số: List L
*/
void initSLL(List* &L);

/*
* Tên hàm: isEmpty
* Mô tả: Kiểm tra danh sách liên kết rỗng
* Kiểu trả về: int (trả về 1 nếu rỗng)
* Tham số: List L
*/
int isEmpty(List* L);

/*
* Tên hàm: insertNode2Head
* Mô tả: thêm phần tử vào đầu danh sách liên kết
* Kiểu trả về: int
* Tham số: List L, số nguyên x (dữ liệu của node cần đưa vào)
*/
int insertNode2Head(List* L, int x);

/*
* Tên hàm: insertNode2Tail
* Mô tả: thêm phần tử vào cuối danh sách liên kết
* Kiểu trả về: int
* Tham số: List L, số nguyên x (dữ liệu của node cần đưa vào)
*/
int insertNode2Tail(List* L, int x);

/*
* Tên hàm: insertNode2After
* Mô tả: thêm 1 phần tử vào sau phần tử q trong danh sách liên kết đơn
* Kiểu trả về: int
* Tham số: List L, node q, số nguyên x (dữ liệu của node cần đưa vào)
*/
int insertNode2After(List* L, Node* q, int x);

/*
* Tên hàm: removeNodeAtHead
* Mô tả: hủy 1 phần tử ở đầu danh sách liên kết
* Kiểu trả về: int
* Tham số: List L.
*/
int removeNodeAtHead(List* L);

/*
* Tên hàm: removeNodeAtTail
* Mô tả: hủy 1 phần tử ở cuối danh sách liên kết
* Kiểu trả về: int
* Tham số: List L.
*/
int removeNodeAtTail(List* L);

/*
* Tên hàm: removeNode
* Mô tả: hủy 1 phần tử mang giá trị x trong danh sách liên kết
* Kiểu trả về: int
* Tham số: List L, số nguyên x.
*/
int removeNode(List* L, int x);

/*
* Tên hàm: appendSLL
* Mô tả: nối danh sách liên kết 1 vào cuối danh sách liên kết 2
* Kiểu trả về: void
* Tham số: List L1, List L2.
*/
void appendSLL(List* &L1, List* &L2);

/*
* Tên hàm: addHead
* Mô tả: thêm node p vào đầu danh sách liên kết
* Kiểu trả về: void
* Tham số: List L, Node p
*/
void addHead(List* L, Node* p);

/*
* Tên hàm: addTail
* Mô tả: thêm node p vào cuối danh sách liên kết
* Kiểu trả về: void
* Tham số: List L, Node p
*/
void addTail(List* L, Node* p);

/*
* Tên hàm: getHead
* Mô tả: Lấy node đầu tiên của 1 danh sách liên kết
* Kiểu trả về: Node*
* Tham số: List L.
*/
Node* getHead(List* L);

/*
* Tên hàm: countList
* Mô tả: đếm số phần tử của 1 danh sách liên kết
* Kiểu trả về: int
* Tham số: List L.
*/
int countList(List* L);

// CÁC THAO TÁC TRÊN DANH SÁCH LIÊN KẾT ĐÔI

/*
* Tên hàm: initDLL
* Mô tả: Khởi tạo danh sách liên kết đôi rỗng
* Kiểu trả về: void
* Tham số: DList L.
*/
void initDLL(DList* L);

/*
* Tên hàm: isEmpty
* Mô tả: kiểm tra danh sách có rỗng hay không
* Kiểu trả về: int
* Tham số: DList L.
*/
int isEmpty(DList* T);

/*
* Tên hàm: insertNode2Head
* Mô tả: chèn 1 node có giá trị x vào đầu danh sách liên kết
* Kiểu trả về: int
* Tham số: DList L, số nguyên x.
*/
int insertNode2Head(DList* &L, int x);

/*
* Tên hàm: insertNode2Tail
* Mô tả: chèn 1 node có giá trị x vào cuối danh sách liên kết
* Kiểu trả về: int
* Tham số: DList L, số nguyên x.
*/
int insertNode2Tail(DList* &L, int x);

/*
* Tên hàm: insertNode2After
* Mô tả: chèn 1 node có giá trị x vào sau node q trong danh sách liên kết
* Kiểu trả về: int
* Tham số: DList L, số nguyên x, DNode q
*/
int insertNode2After(DList* L, DNode* q, int x);

/*
* Tên hàm: removeNodeAtHead
* Mô tả: hủy node đầu tiên của danh sách liên kết
* Kiểu trả về: int
* Tham số: DList L.
*/
int removeNodeAtHead(DList* &L);

/*
* Tên hàm: removeNodeAtTail
* Mô tả: hủy node cuối cùng của danh sách liên kết
* Kiểu trả về: int
* Tham số: DList L.
*/
int removeNodeAtTail(DList* &L);

/*
* Tên hàm: getHead
* Mô tả: lấy Node đầu tiên của danh sách liên kết
* Kiểu trả về: DNode
* Tham số: DList L, số nguyên x.
*/
DNode* getHead(DList* L);

/*
* Tên hàm: countDList
* Mô tả: đếm số phần tử của 1 danh sách liên kết
* Kiểu trả về: int
* Tham số: DList L
*/
int countDList(DList* &L);

/*
* Tên hàm: searchNode
* Mô tả: Tìm kiếm node có giá trị x trong danh sách liên kết
* Kiểu trả về: DNode*
* Tham số: DList L, số nguyên x.
*/
DNode* searchNode(DList* L, int x);

/*
* Tên hàm: removeNode
* Mô tả: hủy 1 node có giá trị x khỏi danh sách liên kết
* Kiểu trả về: int
* Tham số: DList L, số nguyên x.
*/
int removeNode(DList* &L, int x);

// MỘT SỐ HÀM PHỤ KHÁC

/*
* Tên hàm: swap
* Mô tả: hoán vị 2 số nguyên
* Kiểu trả về: void
* Tham số: số nguyên a và số nguyên b
*/
void swap(int &a, int &b);