#include<bits/stdc++.h>
using namespace std;
#define MN 10000000
inline void read(int &x) {
	x = 0;
	register char c = getchar();
	while(c < '0' || c > '9') c = getchar();
	do {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	} while(c >= '0' && c <= '9');
}
int T,x,k = 6,e = 1,N = 10000000,cnt,ans[MN],p[MN / 5] = {1};
bool f[MN + 10],v[MN + 10],g[MN + 10];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> T;
	if(T <= 10000) {
		k = 5;
		N = 1000000;
	}
	if(T <= 1000) {
		k = 4;
		N = 100000;
	}
	memset(f,1,sizeof f);
	memset(g,1,sizeof g);
	f[7] = 0;
	for(int i = 1; i <= k; ++i) {
		e *= 10;
		memset(f + 7 * e,0,e);
		for(int j = 7; j < e; ++j)
			if(!f[j])
				for(int k = 1; k <= 9; ++k)
					f[k * e + j] = 0;
	}
	for(int i = 2; i <= N; ++i) {
		if(!v[i]) p[++cnt] = i;
		for(int j = 1; j <= cnt && i * p[j] <= N; ++j) {
			v[p[j] * i] = 1;
			if(!(i % p[j])) break;
		}
	}
	for(int i = 7; i <= N; ++i)
		if(!f[i] || !g[i])
			for(int j = 0; j <= cnt && i * p[j] <= N; ++j)
				g[i * p[j]] = 0;
	for(int i = 7; i <= N; ++i)
		if(g[i])
			for(int j = i - 1; j > 0; --j) {
				if(ans[j]) break;
				ans[j] = i;
			}
	if(N = 10000000)
		for(int i = N; i > 0; --i) {
			if(ans[i]) break;
			ans[i] = N + 1;
		}
	while(T--) {
		read(x);
		if(!g[x])
			printf("-1\n");
		else
			printf("%d\n",ans[x]);
	}
	return 0;
}
