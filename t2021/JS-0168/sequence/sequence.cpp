#include<bits/stdc++.h>
#define int long long
using namespace std;

int read() {
	char ch = getchar();
	int x = 0, f = 1;
	while((ch > '9' || ch < '0') && ch != '-') {
		ch = getchar();
	}
	if(ch == '-') {
		ch = getchar();
		f = -1;
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch -'0';
		ch = getchar();
	}
	return x * f;
}

const int maxn = 1005;
const int mod = 998244353;

int n, m, q, ans;
int v[maxn],a[maxn];

int b[maxn];

bool check() {
	int c[maxn];
	for(int i=0; i <= 8 * m; i++) {
		c[i] = b[i];
	}
	int cnt = 0;
	for(int i=0; i <= 8 * m; i++) {
		int mor = c[i]/2;
		c[i + 1] += mor;
		c[i] = c[i] % 2;
		if(c[i])cnt ++;
	} 
	if(cnt <= q) return 1;
	else return 0;
}

void myDfs(int k, int res) {
	if(k == n + 1) {
		if(check()) {
			ans = (ans + res) % mod;
		}
		return;
	}
	for(int i = 0; i <= m; i++) {
		a[k] = i;
		b[i]++;
		myDfs(k + 1, res * v[i] % mod);
		b[i]--;
	}
}

signed main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n = read(), m = read(), q = read();
	for(int i=0;i<=m;i++) {
		v[i] = read();
	}
	myDfs(1, 1);
	cout << ans << endl;
	return 0;
}
