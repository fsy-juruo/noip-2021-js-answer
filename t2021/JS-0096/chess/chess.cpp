#include <bits/stdc++.h>
#define re register
#define SIZE 5005
using namespace std;
template <typename T>
inline void read(T &x)
{
	int f;char c;
	x=0;f=0;c=getchar();
	while(c<'0' || '9'<c)	f|=(c=='-'),c=getchar();
	while('0'<=c && c<='9')	x=(x<<3)+(x<<1)+c-48,c=getchar();
	x=f?-x:x;
}
int TT;
int n,m,q;
char x[SIZE][SIZE],y[SIZE][SIZE];
int col[SIZE],lv[SIZE],sx[SIZE],sy[SIZE];
int vis[SIZE][SIZE];
int ans=0;
inline void dfs(int i,int j,int now)
{
	if(vis[i][j])
		return;
	vis[i][j]=1;
	for(re int k=1;k<now;++k)
		if(i==sx[k] && j==sy[k])
		{
			if(col[now]!=col[k] && lv[now]>lv[k])
				++ans;
			return;
		}
	if(x[i][j]!=0 && j+1<=m)
	{
		if(x[i][j]==1)
			dfs(i,j+1,now);
	}
	if(x[i][j-1]!=0 && j-1>=1)
	{
		if(x[i][j-1]==1)
			dfs(i,j-1,now);
	}
	if(y[i][j]!=0 && i+1<=n)
	{
		if(y[i][j]==1)
			dfs(i+1,j,now);
	}
	if(y[i-1][j]!=0 && i-1>=1)
	{
		if(y[i-1][j]==1)
			dfs(i-1,j,now);
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>TT;
	for(re int t=1;t<=TT;++t)
	{
		cin>>n>>m>>q;
		for(re int i=1;i<=n;++i)
			for(re int j=1;j<m;++j)
				cin>>x[i][j];
		for(re int i=1;i<n;++i)
			for(re int j=1;j<=m;++j)
				cin>>y[i][j];
		for(re int i=1;i<=q;++i)
		{
			ans=0;
			cin>>col[i]>>lv[i]>>sx[i]>>sy[i];
			dfs(sx[i],sy[i],i);
			cout<<ans<<endl;
		}
	}
	return 0;
}
