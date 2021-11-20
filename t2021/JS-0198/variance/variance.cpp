#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)

const int N=10005;

bool flag;
int n,a[N],p[N],b[N];
long long ans=1e16,cur,s;

void ca()
{
	s=0; cur=0;
	rep(j,1,n) s+=b[j];
	rep(j,1,n) cur+=(n*b[j]-s)*(n*b[j]-s);
	ans=min(ans,cur/n);
}

bool check()
{
	rep(j,1,n)
	{
		if (b[j]!=a[j]) return false;
	}
	return true;
}

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n)
	{
		scanf("%d",&a[i]);
		p[i]=i+1;
	}
	
	if (n<=4)
	{
		rep(i,1,n) b[i]=a[i];
		flag=1;
		while (flag)
		{
			rep(i,1,n-2)
			{
				b[p[i]]=b[p[i]-1]+b[p[i]+1]-b[p[i]];
				ca();
				if (check())
				{
					flag=0;
					break;
				}
			}
		}
	}
	else
	{
		rep(i,1,n) b[i]=a[i];
		flag=1;
		while (flag)
		{
			rep(i,1,n-2)
			{
				b[p[i]]=b[p[i]-1]+b[p[i]+1]-b[p[i]];
				ca();
				if (check())
				{
					flag=0;
					break;
				}
			}
		}
	}
	
	printf("%lld\n",ans);
	
	return 0;
}
