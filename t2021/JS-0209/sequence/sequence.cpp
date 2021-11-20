#include<bits/stdc++.h>
/*摆烂了,什么nt题*/ 
/*ccf还我csp的480*/ 
using namespace std;
const long long mod=998244353;
long long ans=0;
int n,m,k;
long long v[110];
int s[10000000];
int cnt=0;
int a[110];
long long jc[120];
int lowbit(int x)
{
	return x&(-x);
}
int count(int x)
{
	int sum=0;
	while(x)
	{
		sum++;
		x-=lowbit(x);
	}
	return sum;
}
long long q()
{
	long long r=1;
	for(int i=0;i<=m;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			r*=v[i];
			r%=mod;
		}
		r%=mod;
	}
	return r;
}
long long __(int x)
{
	if(jc[x])
	{
		return jc[x];
	}
	jc[x]=(__(x-1)*x)%mod;
	return jc[x];
}
void dfs(int i,int sum,int no)
{
	if(i>m+1)
	{
		return;
	}
	if(no>n)
	{
		return;
	}
	if(sum==0&&no<n)
	{
		return;
	}
	if(sum<0||(no==n&&sum>0))
	{
		return;
	}
	if(sum==0&&no==n)
	{
//		for(int i=0;i<=m;i++)
//		{
//			printf("%d %d\n",i,a[i]);
//		}
		long long add=1;
		int nn=n;
		for(int i=1;i<=m;i++)
		{
			add*=__(nn)/__(a[i])/__(nn-a[i]);
			add%=mod;
			nn-=a[i];
		}
//		printf("%lld\n",q());
		ans+=add*q()%mod;
		ans%=mod;
	}
	if(i==m+1)
	{
		return;
	}
	int ss=sum;
	for(int j=0;ss>=0;j++,ss-=(1<<i))
	{
//		printf("%d %d\n",i,ss);
		a[i]=j;
		if(no+j>n)
			break;
		dfs(i+1,ss,no+j);
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	jc[0]=jc[1]=1;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++)
	{
		scanf("%lld",&v[i]);
	}
	for(int i=n;i<=n*(1<<m);i++)
	{
		if(count(i)<=k)
		{
//			printf("%d\n",i);
			cnt++;
			s[cnt]=i;
			memset(a,0,sizeof a);
			dfs(0,i,0);
		}
	}
	printf("%lld",ans);
	return 0;
}

