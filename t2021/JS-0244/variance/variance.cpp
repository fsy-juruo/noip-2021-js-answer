#include<bits/stdc++.h>
using namespace std;
#define x1 xabncasd
#define x2 xajsklddasd
#define y1 ydakldjsakdsa 
#define y2 yajslkdsadsa
#define fi first 
#define se second
#define mp make_pair
#define ll long long
const ll N=100+5,M=1e5+5,MAXN=2147483647;
int n;
int a[M][N];
bool same(int x,int y)
{
	//bool f=0;
	for(int i=1;i<=n;i++)
	{
		if(a[x][i]!=a[y][i])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++)
	{
		cin>>a[1][i];
	}
	queue<int>q;
	q.push(1);
	int tot=1;
	while(!q.empty())
	{
		int t=q.front();q.pop();
		for(j=1;j<=n;j++)
			a[tot+1][j]=a[t][j];
		for(i=2;i<=n;i++)
		{
	 		a[tot+1][i]=a[tot+1][i-1]+a[tot+1][i+1]-a[tot+1][i];
	 		bool f=0;
	 		for(j=1;j<=tot;j++)
	 		{
	 			if(same(j,tot+1))
	 			{
	 				f=1;
	 				break;
				}
			}
			if(!f)
			{
				tot++;
				q.push(tot);
				for(j=1;j<=n;j++)
					a[tot+1][j]=a[t][j];
			}
		}
	}
	ll ans=MAXN;
	for(i=1;i<=tot;i++)
	{
		ll s=0,s1=0;
		for(j=1;j<=n;j++)
		{
			s=s+n*a[i][j]*a[i][j];
			s1=s1+a[i][j];
		} 
		ans=min(ans,s-s1*s1);
	}
	cout<<ans<<endl;
	return 0;
}
