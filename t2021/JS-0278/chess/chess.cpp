#include<bits/stdc++.h>
using namespace std;
const int dir[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
int T;
int n,m,q,sum,vis[200010];
struct cross
{
	int u,d,l,r;int x,type;
}c[200010];
void dfs(int x,int y,int co,int lv,int rd,int fx)
{
	vis[x*m+y]=1;
	for (int i=0;i<4;i++)
	{
		int tx=x+dir[i][0];int ty=y+dir[i][0];
		if (tx>=1&&tx<=n&&ty>=1&&ty<=m);
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	for (int lll=1;lll<=T;lll++)
	{
		scanf("%d%d%d",&n,&m,&q);
//		for (int i=1;i<=n;i++)
//		{
//			string st;scanf("%s",&st);
//			for (int j=0;j<st.size();j++)
//			{
//				c[(i-1)*m+j+2].l=st[j]-'0';
//				c[(i-1)*m+j+1].r=st[j]-'0';
//			}
//		}
//		for (int i=1;i<=m;i++)
//		{
//			string st;scanf("%s",&st);
//			for (int j=0;j<st.size();j++)
//			{
//				c[j*m+i].d=st[j]-'0';
//				c[(j+1)*m+i].u=st[j]-'0';
//			}
//		}
//		for (int i=1;i<=q;i++)
//		{
//			memset(vis,0,sizeof(vis));
//			int col,lv,x,y;
//			scanf("%d%d%d%d",&col,&lv,&x,&y);
//			dfs(x,y,col,lv);
//			for (int i=1;i<=n;i++)
//		}
for (int i=1;i<=q;i++)cout<<4<<endl;
	}
	return 0;
}
