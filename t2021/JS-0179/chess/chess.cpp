#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,g[N][4],hs[N];
int col[N],lv[N],Q,T,d[N];
struct node{
	int d,c,x;
}q[N];
inline int read()
{
	int x=0;char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c)){x=x*10+c-48;c=getchar();}
	return x;
}
int shit(int x,int y){return m*(x-1)+y;}
int Bfs(int st,int f)
{
	hs[st]=d[st]=f;
	int sum=0,l=1,r=1;
	q[r++]=(node){-1,-1,st};
	while(l<r)
	{
		node p=q[l++];
		int x=(p.x-1)/m+1,y=p.x-(x-1)*m;
		for(int i=0,tp;i<4;i++)
		{
			if((i==0&&x==1)||(i==1&&x==n)||(i==2&&y==1)||(i==3&&y==m))continue;
			if(i==0)tp=p.x-m;if(i==1)tp=p.x+m;
			if(i==2)tp=p.x-1;if(i==3)tp=p.x+1;
			if(g[p.x][i]&&(((col[st]^col[tp])&&lv[st]>=lv[tp])||(!lv[tp])))
			{
				int flag=lv[tp]?0:1;
				if(g[p.x][i]==1&&p.c==-1)
					if(d[tp]!=f)sum++,d[tp]=f;
				if(g[p.x][i]==2&&(p.c==-1||p.c==2)&&(p.d==-1||p.d==i))
				{
					if(d[tp]!=f)sum++,d[tp]=f;
					if(flag)q[r++]=(node){i,2,tp};
				}
				if(g[p.x][i]==3&&hs[tp]!=f&&(p.c==-1||p.c==3))
				{
					hs[tp]=f;
					if(d[tp]!=f)sum++,d[tp]=f;
					if(flag)q[r++]=(node){-1,3,tp};
				}
			}
		}
	}
	return sum;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=read();
	while(T--)
	{
		memset(d,0,sizeof(d));
		memset(hs,0,sizeof(hs));
		memset(g,0,sizeof(g));
		memset(col,0,sizeof(col));
		memset(lv,0,sizeof(lv));
		n=read(),m=read(),Q=read();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<m;j++)
			{
				int ch=getchar()-48;
				int p=shit(i,j);
				g[p][3]=g[p+1][2]=ch;
			}
			getchar();
		}
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				int ch=getchar()-48;
				int p=shit(i,j);
				g[p][1]=g[p+m][0]=ch;
			}
			getchar();
		}
		for(int i=1;i<=Q;i++)
		{
			int c=read(),l=read();
			int x=read(),y=read();
			int p=shit(x,y);
			col[p]=c,lv[p]=l;
			printf("%d\n",Bfs(p,i));
		}
	}
	return 0;
}
