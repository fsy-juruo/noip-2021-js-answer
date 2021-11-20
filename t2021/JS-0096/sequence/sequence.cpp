#include <bits/stdc++.h>
#define re register
#define MOD 998244353
#define LL long long
using namespace std;
template <typename T>
inline void read(T &x)
{
	int f;char c;
	x=0;f=0;c=getchar();
	while(c<'0' || '9'<c)	f|=(c=='-'),c=getchar();
	while('0'<=c && c<='9')	x=(x<<3)+(x<<1)+c-48,c=getchar();
	x=f?-x:x;
}
int n,m,k;
int maxn;
LL v[30];
LL ans=0;
inline bool isok(int sum)
{
	int cnt=0;maxn=0;
	for(re int i=16;i>=0;--i)
	{
		if(sum>=(1<<i))
			sum-=(1<<i),++cnt,maxn=max(maxn,i);
		if(cnt>k)
			return false;
	}
	return true;
}
LL S=1;
inline void dfs(int d,int sum,LL tot,int Last,LL var,int con)
{
	if(d>n)
	{
		if(sum==0)
			ans=(ans+(S/var)%MOD*tot%MOD)%MOD;
		return;
	}
	if(sum<0)
		return;
	LL p=(1<<Last)*(n+1-d);
	if(p<sum)
		return;
	for(re int i=Last;i>=0;--i)
	{
		if(i==Last)
			dfs(d+1,sum-(1<<i),tot*v[i]%MOD,i,var*(con+1),con+1);
		else
			dfs(d+1,sum-(1<<i),tot*v[i]%MOD,i,var,1);
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);read(m);read(k);
	for(re int i=1;i<=n;++i)
		S*=i;
	for(re int i=0;i<=m;++i)
		read(v[i]);
	for(re int i=n;i<=n*pow(2,m);++i)
		if(isok(i))
			dfs(1,i,1,min(maxn,m),1,0);
	printf("%lld\n",ans);
	return 0;
}
/*
8 9 7
934258593 150407625 187068439 162292791 219945760 512449588 803393963 983648121 484675481 412407699
*/
