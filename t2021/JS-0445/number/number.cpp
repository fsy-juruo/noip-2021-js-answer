#include <bits/stdc++.h>
using namespace std;

const int N=1e7+3;
bool f[N],c[N];
int T,n,p[N],cnt=0;
int Ans[N];

inline void Euler() {
	c[7]=1; p[++cnt]=7;
	for(register int i=11;i<N;i=-~i) {
		c[i]=c[i/10]|(i%10==7);
		if(c[i]) p[++cnt]=i;
	}
//	for(int i=1;i<=100;i++) printf("%d %d\n",i,c[i]);
	// 0 -> can ; 1 -> cannot
	for(register int i=1;i<=cnt;i=-~i) {
		if(f[p[i]]) continue;
		for(register int j=1;j<=N/p[i];j=-~j) f[p[i]*j]=1;
	}
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	Euler();
	scanf("%d",&T);
	int k=1e7+1;
	for(register int i=1e7;i>=1;i--) {
		if(!f[i]) Ans[i]=i,k=i;
		else Ans[i]=k;
	}
	while(T--) {
		scanf("%d",&n);
		if(f[n]) puts("-1");
		else printf("%d\n",Ans[n+1]);
	}
	return 0;
}

