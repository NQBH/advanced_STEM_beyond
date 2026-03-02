#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    int maxnumb, minnumb;
    maxnumb = a; minnumb = a;
    if (b > maxnumb) {maxnumb = b;}    
    if (c > maxnumb) {maxnumb = c;}
    if (b < minnumb) {minnumb = b;}    
    if (c < minnumb) {minnumb = c;}
    cout << "Số lớn nhất trong ba số : " << maxnumb << '\n';
    cout << "Số nhỏ nhất trong ba số : " << minnumb << '\n';
}