#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, rank, Size, Max, Min, sum, avg;

// naive merge
void make_set(int v) {
	parent[v] = v; // tạo ra cây mới có gốc là đỉnh v
}

int find_set(int v) {
	if (v == parent[v]) return v; // trả về đỉnh v nếu như đỉnh v là gốc của cây
	return find_set(parent[v]); // đệ quy lên cha của đỉnh v
}

void union_set(int a, int b) {
	a = find_set(a); // tìm gốc của cây có chứa đỉnh a
	b = find_set(b); // tìm gốc của cây có chứa đỉnh b
	if (a != b) parent[b] = a; // gộp 2 cây nếu như 2 phần tử ở 2 cây khác nhau
}

// merge according to size
void make_set_size(int v) {
	parent[v] = v;
	Size[v] = 1; // ban đầu tập hợp chứa v có kích cỡ là 1
}

void union_set_size(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (Size[a] < Size[b]) swap(a, b); // đặt biến a là gốc của cây có kích cỡ lớn hơn
		parent[b] = a;
		Size[a] += Size[b]; // cập nhật kích cỡ của cây mới gộp lại
	}
}

// merge according to size
void make_set_height(int v) {
	parent[v] = v;
	rank[v] = 0; // gốc của cây có độ cao là 0
}

void union_set_height(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (rank[a] < rank[b]) swap(a, b); // đặt biến a là gốc của cây có độ cao lớn hơn
		parent[b] = a;
		if (rank[a] == rank[b]) ++rank[a]; // nếu 2 cây có cùng 1 độ cao, độ cao của cây mới sau khi gộp sẽ tăng 1
	}
}

// path compression
int find_set_path_compression(int v) {
	if (v == parent[v]) return v; // trả về đỉnh v nếu như đỉnh v là gốc của cây
	int p = find_set(parent[v]); // đệ quy lên cha của đỉnh v
	parent[v] = p; // nén đoạn từ v lên gốc của cây
	return p;
}

// brief find set
int find_set_brief(int v) {
	return v == parent[v] ? v : parent[v] = find_set_brief(parent[v]);
}

// alternative implementation of DSU
void make_set_lab(int v) {
	lab[v] = -1;
}

int find_set_lab(int v) {
	return lab[v] < 0 ? v : lab[v] = find_set_lab(lab[v]);
}

void union_set_lab(int a, int b) {
	a = find_set_lab(a);
	b = find_set_lab(b);
	if (a != b) {
		if (lab[a] > lab[b]) swap(a, b);
		lab[a] += lab[b];
		lab[b] = a;
	}
}

// save additional information for each set in DSU
voi make_set_size_more_info(int v) {
	parent[v] = v;
	Size[v] = 1;
	Min[v] = value[v]; // value[v] là giá trị của phần tử thứ v
	Max[v] = value[v];
	sum[v] = value[v];
	avg[v] = value[v];
}

int find_set_size_more_info(int v) {
	return v == parent[v] ? v : parent[v] = find_set_size_more_info(parent[v]);
}

void union_set_size_more_info(int a, int b) {
	a = find_set_size_more_info(a);
	b = find_set_size_more_info(b);
	if (a != b) {
		if (Size[a] < Size[b]) swap(a, b);
		parent[b] = a;
		Size[a] += Size[b];
		sum[a] += sum[b];
		Min[a] = min(Min[a], Min[b]);
		Max[a] = max(Min[a], Min[b]);
		avg[a] = static_cast<double>(sum[a]) / Size(a);
	}
}

int find_sum(int v) { // trả về tổng của các phần tử trong tập hợp chứa v
	v = find_set_size_more_info(v);
	return sum[v];
}

int find_min(int v) { // trả về giá trị nhỏ nhất của các phần tử trong tập hợp chứa v
	v = find_set_size_more_info(v);
	return Min[v];
}

int find_max(int v) { // trả về giá trị lớn nhất của các phần tử trong tập hợp chứa v
	v = find_set_size_more_info(v);
	return Max[v];
}

double find_avg(int v) { // trả về giá trị trung bình của các phần tử trong tập hợp chứa v
	v = find_set_size_more_info(v);
	return avg[v];
}

int main() {
	int n, num_query, type_query, node;
	cin >> n >> num_query;
	parent.resize(n);
	Size.resize(n);
	Max.resize(n);
	for (int i = 1; i <= n; ++i) make_set_size_max(i);
}