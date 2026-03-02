#include <iostream>
using namespace std;

// BT1 midterm
void tong_hieu_tich_thuong(long long a, long long b) {
    long long tong = a + b, hieu = a - b, tich = a * b;
    cout << tong << " " << hieu << " " << tich << " ";
    if (!b) cout << "division by zero";
    else cout << a / b;
}

// BT2 midterm
void hcn(long long a, long long b) {
    if (a <= 0 || b <= 0) cout << "-1";
    else {
        long long chu_vi = (a + b) * 2;
        long long dien_tich = a * b;
        cout << chu_vi << " " << dien_tich;
    }
}

// BT3 midterm
void ptb1(long long a, long long b) {
    if (!a) {
    	if (!b) cout << "infinity";
    	else cout << 0;
    } else cout << 1;
}

// BT4 midterm
void ptb2(long long a, long long b, long long c) {
    if (!a) {
    	if (!b) {
            if (!c) cout << "infinity";
            else cout << 0;
        } else cout << 1;
    } else {
        long long delta = b * b - 4 * a * c;
        if (delta > 0) cout << 2;
        else if (!delta) cout << 1;
        else cout << 0;
    }
}

// BT5 midterm
void count_even_odd(int n) {
	int a, even = 0, odd = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a & 1) ++odd;
        else ++even;
    }
    cout << even << ' ' << odd;
}

int main() {
	// BT1 midterm
	long long a, b;
	cin >> a >> b;
	tong_hieu_tich_thuong(a, b);

	// BT2 midterm
    cin >> a >> b;
    hcn(a, b);

    // BT3 midterm
    cin >> a >> b;
    ptb1(a, b);

    // BT4 midterm
    long long c;
    cin >> a >> b >> c;
    ptb2(a, b, c);

    // BT5 midterm
    int n;
    cin >> n;
    count_even_odd(n);
}