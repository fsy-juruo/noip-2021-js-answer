#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[10005];
long long b[10005];
long long ans=10000000000000;
bool f[10005];
int cnt=-1;
bool flag;
long long cmp(long long x,long long y)
{
	return x<y?x:y;
}
bool p(int k)
{
	long long t=a[k-1]+a[k+1]-a[k];
	if(t!=a[k]&&t>=a[k-1]&&t<=a[k+1])
	  return 1;
	return 0;
}
long long var()
{
	long long sum=0,s=0;
	long long ave;
	long long v;
	for(int i=1;i<=n;i++)
		sum+=a[i];
	ave=sum/n;
	for(int i=1;i<=n;i++)
		s=s+(a[i]-ave)*(a[i]-ave);
	v=s/n;
	return v;
}
void dfs()
{
	flag=0;
	for(int i=2;i<n;i++)
	{
		if(b[i]!=a[i])
		{
			flag=1;
			break;
		}
	}
	if(!flag)
	{
		cnt++;
		if(cnt)
		  return;
	}
	ans=cmp(ans,var());
	for(int i=2;i<n;i++)
	{
		if(p(i)&&!f[i])
		{
			long long temp=a[i];
			a[i]=a[i-1]+a[i+1]-a[i];
			f[i]=1;
			dfs();
			a[i]=temp;
			f[i]=0;
		}
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		a[i]*=n;
		b[i]=a[i];
	}
	dfs();
	printf("%lld",ans);
	return 0;
}

