#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long LL;

const int N=1e4+10;

LL n;
LL a[N];
LL res;

int read()
{
	int f=1,x=0;
	char c=getchar();
	
	while(c<'0'||c>'9')
	{
		f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}

LL calc()
{
	LL sum=0,r=0;
	for(int i=0;i<n;i++)
		sum+=a[i],r+=a[i]*a[i]*n;
	r+=sum*sum;
	
	for(int i=0;i<n;i++)
		r-=a[i]*2*sum;
	return r;
}

void dfs(int u)
{
	for(int i=1;i<n-1;i++)
	{
		LL k=a[i];
		a[i]=a[i+1]+a[i-1]-a[i];
		
		LL r=calc();
		if(r<res)
		{
			res=min(res,r);
			dfs(u+1);
		}
		a[i]=k;
	}
}

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	
	n=read();
	for(int i=0;i<n;i++)
		a[i]=read();
	
	res=calc();
	dfs(1);
	
	printf("%lld\n",res);
	
	return 0;	
}
