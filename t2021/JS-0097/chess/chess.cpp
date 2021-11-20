#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5+5;
const int MN = 2e5+5;
int T;
int n,m,q;
char s[N];
inline int ID(int x,int y){ return (x-1)*m+y; }
inline int getx(int id){ return (id+m-1)/m; }
inline int gety(int id){ return id-(getx(id)-1)*m; }
struct node{
	int col,lv;
}chess[MN];
bool tak[MN];
vector<int> tp[MN],sta[MN];
int hang[]={-1,0,0,1},lie[]={0,-1,1,0};
int qcol,qlv,qx,qy;
bool vis[MN];
int ans;
inline int read()
{
	char ch=getchar();
	int a=0;
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch))
	{
		a=a*10+(ch^48);
		ch=getchar();
	}
	return a;
}
inline void sub1()
{
	for(int i=1;i<=q;++i)
	{
		for(int j=1;j<=n*m;++j) vis[j]=0;
		qcol=read(),qlv=read(),qx=read(),qy=read();
		int id=ID(qx,qy);
		tak[id]=1;
		chess[id]={qcol,qlv};
		for(unsigned j=0;j<tp[id].size();++j)
		{
			int px=qx+hang[tp[id][j]],py=qy+lie[tp[id][j]];
			if(tak[ID(px,py)])
			{
				if(!vis[ID(px,py)]&&chess[id].col!=chess[ID(px,py)].col&&chess[id].lv>=chess[ID(px,py)].lv)
				{
					vis[ID(px,py)]=1;
					
				}
			}
			else
			{
				
			}
		}
	}
}
inline void sub2()
{
	for(int i=1;i<=q;++i)
	{
		qcol=read(),qlv=read(),qx=read(),qy=read();
		int id=ID(qx,qy);
		tak[id]=1;
		chess[id]={qcol,qlv};
		ans=0;
		for(unsigned j=0;j<tp[id].size();++j)
		{
			int px=qx+hang[tp[id][j]],py=qy+lie[tp[id][j]];
			if(tak[ID(px,py)])
			{
				if(chess[id].col!=chess[ID(px,py)].col&&chess[id].lv>=chess[ID(px,py)].lv)
				  ++ans;
			}
			else ++ans;
		}
		printf("%d\n",ans);
	}
}
inline void dfs1(int x,int y,int type)
{
	int id=ID(x,y);
	for(unsigned i=0;i<tp[id].size();++i)
	{
		if(tp[id][i]!=type) continue;
		int px=x+hang[tp[id][i]],py=y+lie[tp[id][i]];
		if(tak[ID(px,py)])
		{
			if(chess[id].col!=chess[ID(px,py)].col&&chess[id].lv>=chess[ID(px,py)].lv)
			  ++ans;
		}
		else
		{
			++ans;
			dfs1(px,py,type);
		}
		break;
	}
}
inline void sub3()
{
	for(int i=1;i<=q;++i)
	{
		qcol=read(),qlv=read(),qx=read(),qy=read();
		int id=ID(qx,qy);
		tak[id]=1;
		chess[id]={qcol,qlv};
		ans=0;
		for(unsigned j=0;j<tp[id].size();++j)
		{
			int px=qx+hang[tp[id][j]],py=qy+lie[tp[id][j]];
			if(sta[id][j]==1)
			{
				if(tak[ID(px,py)])
				{
					if(chess[id].col!=chess[ID(px,py)].col&&chess[id].lv>=chess[ID(px,py)].lv)
					  ++ans;
				}
				else ++ans;
			}
			else
			{
				if(tak[ID(px,py)])
				{
					if(chess[id].col!=chess[ID(px,py)].col&&chess[id].lv>=chess[ID(px,py)].lv)
					  ++ans;
					continue;
				}
				int tt=tp[id][j];
				++ans;
				dfs1(px,py,tt);
			}
		}
		printf("%d\n",ans);
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
		bool ex2=0,ex3=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m-1;++j)
			{
				int in;
				scanf("%1d",&in);
				if(!in) continue;
				if(in==2) ex2=1; if(in==3) ex3=1;
				tp[ID(i,j)].pb(2),tp[ID(i,j+1)].pb(1);
				sta[ID(i,j)].pb(in),sta[ID(i,j+1)].pb(in);
			}
		}
		for(int i=1;i<n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				int in;
				scanf("%1d",&in);
				if(!in) continue;
				if(in==2) ex2=1; if(in==3) ex3=1;
				tp[ID(i,j)].pb(3),tp[ID(i+1,j)].pb(0);
				sta[ID(i,j)].pb(in),sta[ID(i+1,j)].pb(in);
			}
		}
		if(!ex2&&!ex3) sub2();
		else if(!ex3) sub3();
		else if(n*m<=5000&&q<=2000) sub1();
		for(int i=1;i<=n*m;++i) tp[i].clear(),sta[i].clear();
		memset(tak,0,sizeof(tak));
	}
}
