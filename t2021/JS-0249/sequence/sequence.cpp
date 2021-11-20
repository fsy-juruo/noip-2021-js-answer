#include<bits/stdc++.h>
using namespace std;
long long v[50],a[50];
const long long MOD=998244353;
long long n,m,k;
long long ans;
bool check()
{
	long long S;
	for(long long i=0;i<n;i++)
		S+=1<<a[i];
	long long cnt=0;
	while(S)
	{
		cnt+=S&1;
		S>>=1;	
	}
	return cnt<=k;
}
void DFS(long long x)
{
	if(x==n)
	{
		long long value=1;
		if(check())
		{
			for(long long i=0;i<n;i++)
				value=value*v[a[i]]%MOD;
			ans=(ans+value)%MOD;
		}
		return;
	}
	for(long long i=0;i<=m;i++)
	{
		a[x]=i;
		DFS(x+1);
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=0;i<=m;i++)
		scanf("%lld",&v[i]);
	DFS(0);
	printf("%lld",ans);
	return 0;
	//freopen
	//大小写
	//return
	//文件名
}

