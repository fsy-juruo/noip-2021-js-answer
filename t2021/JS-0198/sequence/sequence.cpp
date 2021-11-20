#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define lowbit(x) (x & (-x))

const int N=105;
const int mo=998244353;

int n,m,k;
int a[N],pr[N],s,b[N];
long long ans=0,ttt=0;

int ca(int x)
{
	int t=x,tot=0;
	while(t>0) t-=lowbit(t),tot++;
	return tot;
}

void dfs(int ss,int ii,int ll)
{
	if (ss<0) return;
	if (ll==n && ss==0)
	{
		long long mm=1;
		rep(i,0,m) 
		{
			rep(j,1,b[i])
			{
				mm=mm*a[i]%mo;
			}
		}
		ans=(ans+mm)%mo;
	}
	rep(j,0,ii)
	{
		if (ss-(1<<j)>=n-ll && ss-(1<<j)<=(n-ll)*(1<<(j)));
		{
			b[j]++;
			dfs(ss-(1<<j),j,ll+1);
			b[j]--;
		}
	}
}

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,m+1)
	{
		scanf("%d",&a[i]);
	}
	
	int cnt=0;
	rep(i,n,n*(1<<m))
	{
		if (ca(i)<=k)
		{
			pr[++cnt]=i;
		}
	}
	
	rep(i,1,cnt)
	{
		s=pr[i];
		memset(b,0,sizeof(b));
		rep(u,0,m) dfs(s,u,1);
		ttt=(ttt+ans)%mo;
	}
	printf("%lld\n",ttt);
	return 0;
} 
