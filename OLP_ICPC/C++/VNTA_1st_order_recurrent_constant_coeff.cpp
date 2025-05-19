#include <bits/stdc++.h>
#define KhangGPT40_TramAnhGrok3 ios_base::sync_with_stdio(0)
#define ll long long
using namespace std;

struct phuc {
    double thuc;
    double ao;
    phuc(double a = 0, double b = 0) {
        thuc = a; ao = b;
    }

    phuc operator * (const phuc &other) {
        return phuc(thuc*other.thuc - ao*other.ao, thuc*other.ao + ao *other.thuc);
    }

    phuc operator + (const phuc &other) {
        return phuc(thuc + other.thuc, ao + other.ao);
    }

};

long A(int n) {
	return n * n * n;
}

long B(int n) {
	return 2 * n + 1;
}

const ll NUM = 1000;
int main(){
    KhangGPT40_TramAnhGrok3;

    vector<phuc> f(NUM + 1), F(NUM + 1);

    phuc a, b;
    phuc al, bt;

    cin >> a.thuc >> a.ao >> b.thuc >> b.ao;
    cin >> al.thuc >> al.ao >> bt.thuc >> bt.ao;
    f[0] = F[0] = al;
    f[1] = F[1] = bt;
    for (int i = 2; i <= NUM; i++) {
        f[i] = f[i - 1] * a + f[i - 2] * b;
        F[i] = F[i - 1] * A(i) + F[i - 2] * B(i);
    }
    for (int i = 0; i <= 10; i++) {
        cout << f[i].thuc << " " << f[i].ao <<"i" << endl;
        cout << F[i].thuc << " " << F[i].ao <<"i" << endl;
    }
    return 0;
}