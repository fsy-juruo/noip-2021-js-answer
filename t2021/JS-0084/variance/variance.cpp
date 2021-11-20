#include<bits/stdc++.h>
using namespace std;
inline void read(int &x)
{
	int y=1;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x=x*y;
}
int n,a[10010],vis[410][410],sum,sum2,ans=0x3f3f3f3f,now;
void dfs(int fr)
{
//	vis[fr][a[fr]]=1;
	int ai=a[fr];
	int dx=a[fr-1]+a[fr+1]-a[fr]*2;
	if((n-1)*dx*dx+2*dx*(a[fr]*n-sum)<0)
	{
		now+=(n-1)*dx*dx+2*dx*(a[fr]*n-sum);
		sum+=dx;
		a[fr]+=dx;
		/*if(vis[fr][a[fr]])
		{
			sum-=dx;
			now-=(n-1)*dx*dx+2*dx*(ai*n-sum);
			a[fr]-=dx;
			return;
		}
		vis[fr][a[fr]]=1;*/
		ans=min(ans,now);
		for(int i=2;i<n;i++)
		{
			if(i==fr)continue;
			dfs(i);
		}
		sum-=dx;
		now-=(n-1)*dx*dx+2*dx*(ai*n-sum);
		a[fr]-=dx;
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){read(a[i]);sum+=a[i];sum2+=a[i]*a[i];vis[i][a[i]]=1;}
	now=sum2*n-sum*sum;
	for(int i=2;i<n;i++)dfs(i);
	printf("%d\n",ans);
	return 0;
}
