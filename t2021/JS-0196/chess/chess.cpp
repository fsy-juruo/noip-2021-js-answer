#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=(x<<1)+(x<<3)+ch-48;ch=getchar();}
	return x*f;
}
inline void write(int x)
{
	if(x<0) {putchar('-');x=~(x-1);}
	if(x>9) write(x/10);
	putchar(x%10+48);
}

#define MAX 10005
int T,n,m,q,cnt,tot;
int dx[5]={0,0,0,1,-1};
int dy[5]={0,1,-1,0,0};
int head[MAX],ver[2*MAX],nxt[2*MAX],edg[2*MAX];
int rel[MAX][MAX];
int level[MAX][MAX];
int color[MAX][MAX];
bool v[MAX][MAX];

int pos(int i,int j) {return (i-1)*m+j;}

void add(int x,int y,int val)
{
	ver[++cnt]=y;edg[cnt]=val;nxt[cnt]=head[x];head[x]=cnt;
}

void dfs(int x,int y,int col,int lev,int op,int hx,int hy)//0 none 1 one step  2 any dir 
{
	v[x][y]=true;
	for(int i=1;i<=4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx<1||xx>n||yy<1||yy>m||v[xx][yy]) continue;
		if(rel[pos(xx,yy)][pos(x,y)]==0) continue;
//		if(op==0)
//		{
//			if(rel[pos(xx,yy)][pos(x,y)]==)
//		}
	}
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read(),m=read(),q=read();
		for(int i=1;i<=n;i++)
			for(int j=1;j<m;j++) 
			{
				int w=read();
				rel[pos(i,j)][pos(i,j+1)]=w;
				rel[pos(i,j+1)][pos(i,j)]=w;
			}
		for(int i=1;i<n;i++)
			for(int j=1;j<=m;j++)
			{
				int w=read();
				rel[pos(i,j)][pos(i+1,j)]=w;
				rel[pos(i+1,j)][pos(i,j)]=w;
			}
		for(int i=1;i<=q;i++)
		{
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++) v[i][j]=false;
			int col=read(),lev=read(),x=read(),y=read();
			dfs(x,y,col,lev,0,0,0);
			level[x][y]=lev;
			color[x][y]=col;
			write(0);
			putchar('\n');
		}
	}
	return 0;
}

