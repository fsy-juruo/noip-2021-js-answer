#include <bits/stdc++.h>
#define lint long long
using namespace std;
const int maxn=105,mod=998244353;
int n,a[maxn],v[maxn],m,k;
lint ans;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void add()
{
	int now=1;
	a[1]++;
	while(a[now]==m+1)
	{
		a[now]=0;
		now++;
		a[now]++;
	}
}
bool check(int x)
{
	int cnt=0;
	while(x)
	{
		if(x&1)
		cnt++;
		x=x>>1;
	}
	if(cnt<=k)
	return true;
	else
	return false;
}
void sol()
{
	add();
	int sum=0;
	lint sum1=1;
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d ",a[i]);
//	}
//	puts("");
	for(int i=1;i<=n;i++)
	{
		sum+=1<<a[i];
	}
//	printf("%d ",sum);
	if(check(sum))
	{
		for(int i=1;i<=n;i++)
		{
			sum1=(sum1*v[a[i]])%mod;
		}
		ans=(ans+sum1)%mod;
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
    n=read();
    m=read();
    k=read();
    for(int i=0;i<=m;i++)
    {
    	v[i]=read();
	}
	while(a[n+1]!=1)
	{
		sol();
	}
//	printf("%d",check(4));
	printf("%lld",ans);
	return 0;
}

