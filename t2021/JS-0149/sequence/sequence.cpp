#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read() {
	int x(0),neg(1);char ch(getchar());
	while(!isdigit(ch)) {
		if (ch=='-') neg=-1;
		ch=getchar();
	}
	while(isdigit(ch)) {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*neg;
}
const int mod=998244353;
const int MAXN=1000000;
int pw[MAXN+5];
int lg[MAXN+5];
inline void Init() {
	pw[0]=1;
	for (int i=1;i<=16;++i) pw[i]=pw[i-1]*2;
	for (int i=1;i<=(1<<16);++i) lg[i]=log2(i);
}
int v[MAXN+5];
int dp[35][MAXN+5];
int n,m,p;
inline void Subtask1() {
	dp[0][0]=1;
	for (int i=1;i<=n;++i) {
		for (int j=1;j<=(1<<(m+lg[n]+1));++j) {
			for (int k=0;k<=min(lg[j],m);++k) {
				dp[i][j]=(dp[i][j]+dp[i-1][j-pw[k]]*v[k]%mod)%mod;
			}
		}
	}
	int ans=0;
	for (int i=0;i<=(1<<(m+lg[n]+1));++i) {
		int cnt=0;
		for (int j=0;j<=lg[i]+1;++j) {
			if (((1<<j)&i)) ++cnt;
		}
		if (cnt<=p) ans=(ans+dp[n][i])%mod;
	}
	printf("%d\n",ans);
}
int a[55],b[55];
int ans=0;
inline void dfs(int u) {
	if (u==n+1) {
		int res=0;
		for (int i=1;i<=n;++i) b[a[i]]++;
		for (int i=0;i<=54;++i) {
			if (b[i]>0) {
				b[i+1]+=b[i]/2;
				b[i]=b[i]%2;
			} 
			res+=b[i];
		}
		if (res<=p) {
			res=1;
			for (int i=1;i<=n;++i) res=res*v[a[i]]%mod;
			ans=(ans+res)%mod;
		}
		return ;
	}
	for (int i=0;i<=50;++i) {
		a[u]=i;
		dfs(u+1);
	}
}
signed main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	Init();
	n=read(),m=read(),p=read();
	for (int i=0;i<=m;++i) v[i]=read()%mod;
	if (m<=12) Subtask1();
	else if (n==5) {
		dfs(1);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
5 1 1
2 1
*/
