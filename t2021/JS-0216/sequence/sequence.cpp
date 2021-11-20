#include<bits/stdc++.h>
using namespace std;
const long long p=998244353;
long long n,m,k,fac[50],inv[50],v[110],ans=0;
long long co[110];//每个数使用的个数 
long long ksm(long long x,long long y)
{
	long long res=1;
	while(y)
	{
		if(y&1)res=res*x%p;
		x=x*x%p;
		y>>=1;
	}
	return res%p;
}
void get_inv()
{
	fac[0]=1;
	for(int i=1;i<=n;++i)
	fac[i]=fac[i-1]*i%p;
	inv[n]=ksm(fac[n],p-2);
	for(int i=n-1;i>=1;--i)
	inv[i]=inv[i+1]*(i+1)%p;
	inv[0]=1;
}
bool check_S()
{
	long long cnt=0,co2[110];
	memset(co2,0,sizeof(co2));
	for(int i=0;i<=m+6;++i)
	{
		co2[i]+=co[i];
		if(cnt>k)return false;
		if(co2[i]&1)cnt++;
		co2[i+1]+=co2[i]/2;
	}
	return true;
}
void add()
{
	long long ad=fac[n],va=1;
	for(int i=0;i<=m;++i)
	{
		va=va*ksm(v[i],co[i])%p;
		ad=ad*inv[co[i]]%p;
	}
	ans=(ans+va*ad%p)%p;
}
void dfs(int num,int x,int tot)
{
	if(tot>n)return;
	if(x>=m&&tot!=n)return;
	co[x]=num;
	if(x==m)
	{
		if(check_S())add();
		return;
	}
	for(int i=0;i<=n;++i)
	dfs(i,x+1,tot+i);
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	get_inv();
	for(int i=0;i<=m;++i)scanf("%lld",&v[i]);
	for(int i=0;i<=n;++i)dfs(i,0,i);
	printf("%lld",ans);
	return 0;
}
