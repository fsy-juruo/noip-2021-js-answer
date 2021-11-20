#include<bits/stdc++.h>
using namespace std;
int T,n,m,q,head[1000010],cnt=0,sum=0;
char c1[1005][1005],c2[1005][1005];
struct edge
{
	int u,v,w;
}e[1000010];
struct chess
{
	int col,lev,x,y;
}c[500050];
void addedge(int u,int v,int w)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	head[u]=cnt;
}
void bfs(int id,int ans)
{
	for(int i=head[id];i!=-1;i=e[i].v)
	{
		
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m-1;j++)
			{
				scanf("%c",&c1[i][j]);
				addedge(m*(i-1)+j,m*(i-1)+j+1,c1[i][j]-'0');
				addedge(m*(i-1)+j+1,m*(i-1)+j,c1[i][j]-'0');
			}
		for(int i=1;i<=n-1;i++)
			for(int j=1;j<=m;j++)
			{
				scanf("%c",&c2[i][j]);
				addedge(m*(i-1)+j,m*i+j,c2[i][j]-'0');
				addedge(m*i+j,m*(i-1)+j,c2[i][j]-'0');
			}
		while(q--)
		{
			scanf("%d%d%d%d",&c[++sum].col,&c[sum].lev,&c[sum].x,&c[sum].y);
			printf("%d",rand());
		}
	}
	return 0;
}
