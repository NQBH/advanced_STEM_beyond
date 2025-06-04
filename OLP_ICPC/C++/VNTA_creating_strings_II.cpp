#include<bits/stdc++.h>
using namespace std;

const long long MOD=1e9+7;
const int MAXN=1e6+5;
long long f[MAXN], inv[MAXN];

long long ppow(long long a, long long b) {
	long long res=1;
	while(b>0) {
		if (b%2!=0) res=(res*a)%MOD;
		a=(a*a)%MOD;
		b/=2;
	}
	return res;
}

void prep() {
	f[0]=1;
	for(int i=1; i<MAXN; i++) f[i]=(f[i-1]*i)%MOD;
	inv[MAXN-1]=ppow(f[MAXN-1], MOD-2);
	for(int i=MAXN-2; i>=0; i--) inv[i]=(inv[i+1]*(i+1))%MOD;
}

long long invMOD(long long a) {
	return ppow(a, MOD-2);
}

long long solve(string s) {
	prep();
	int n=s.length();
	vector<int>freq(26,0);
	for(char c:s) freq[c-'a']++;
	long long res=f[n];
	for (int x:freq) {
		if (x>0) res=(res*inv[x])%MOD;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s;
	getline(cin, s);
	cout<<solve(s);
}
