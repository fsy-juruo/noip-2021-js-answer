#include<bits/stdc++.h>
using namespace std;

const int N = 1e7 + 5;
int T, n, top, num;
int ans[N + 5], id[N + 5], q[N + 5];
bool vis[N + 5];

inline bool check(int x) {
	while(x) {
		if(x % 10 == 7) return true;
		x /= 10;
	}
	return false;
}

inline int read(){
	int s = 0, w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s * w;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	T = read();
	for(int i = 1; i <= T; ++i) {
		q[i] = read(); num = max(num, q[i]);
	}
	int MN = max(num + 10, 200010);
	for(register int i = 1; i <= MN; ++i) {
		if(vis[i]) continue;
		if(!vis[i]) {
			if(check(i)) {
				for(register int j = 1; j * i <= MN; ++j) {
					vis[j * i] = 1;
				}
			}
			else {
				ans[++top] = i;
				id[i] = top;
			}
		}
	}
	for(int i = 1; i <= T; ++i) {
		if(vis[q[i]]) printf("-1\n");
		else printf("%d\n", ans[id[q[i]] + 1]);
	}
	return 0;
}

