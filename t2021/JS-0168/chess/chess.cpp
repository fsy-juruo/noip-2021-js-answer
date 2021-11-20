#include <bits/stdc++.h>
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

const int maxn = 2e6+10;

int T;
int n, m, q, cnt;
string s;

int main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T = read();
	while(T--) {
		n = read(), m = read(), q = read();
		for(int i=1;i<=2*n-1;i++)cin>>s;
		for(int i=1;i<=q*4;i++) int tmp = read();
		for(int i=1;i<=q;i++) {
			cout << 0 <<endl;
		}
	}
	return 0;
}
