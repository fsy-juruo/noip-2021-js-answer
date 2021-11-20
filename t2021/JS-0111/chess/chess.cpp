#include<bits/stdc++.h>
#define re register
#define rep(i,x,y) for(re int i=x;i<=y;++i)
#define Rep(i,x,y) for(re int i=x;i>=y;--i)
#define _rep(i,x,y) for(re int i=x;i<y;++i)
#define _Rep(i,x,y) for(re int i=x;i>y;--i)
#define id1 id(x,y)
#define id2 id(dx,dy)
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double db;
template<typename T>inline void read(T&x)
{
	x=0;bool f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<3)+(x<<1)+ch-'0';
	x=(f?(-x):x);
}
template<typename T>inline T chkmax(T&x,const T&y){return x=(x>y?x:y);}
template<typename T>inline T chkmin(T&x,const T&y){return x=(x<y?x:y);}
const int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
const int N=2e5+5;
int n,m,q;
int Lv[N],c[N];
int vis[N],ans,vis1[N];
int f[N][4];
int id(int x,int y){return (x-1)*m+y;}
void dfs(int x,int y,int col,int lv)
{
//	cout<<x<<' '<<y<<endl;
	if(!(Lv[id1]==0||(Lv[id1]<=lv&&col!=c[id1])))return;
//	cout<<x<<y<<endl;
	if(vis1[id1]==q)return;vis1[id1]=q;
	if(vis[id1]!=q)++ans,vis[id1]=q;
	if(Lv[id1])return;
	rep(i,0,3)
	{
		int dx=x+d[i][0],dy=y+d[i][1];
		if(f[id1][i]==3)dfs(dx,dy,col,lv);
	}
}
void solve()
{
	while(q)
	{
		int col,lv,x,y;
		read(col),read(lv),read(x),read(y);
		ans=0;vis1[id1]=vis[id1]=q;int xxx=x,yyy=y;
		rep(i,0,3)
		if(f[id1][i]!=0)
		{
			int dx=x+d[i][0],dy=y+d[i][1];
			if(f[id1][i]==1)
			{
				if(vis[id2]!=q)
				if(Lv[id2]==0||(Lv[id2]<=lv&&col!=c[id2]))
				vis[id2]=q,ans++;
			}
			else
			if(f[id1][i]==2)
			{
				while(f[id1][i]==2)
				{
					if(Lv[id2]==0||(Lv[id2]<=lv&&col!=c[id2]))
					{
						if(vis[id2]==q)break;
						vis[id2]=q,ans++,x=dx,y=dy,
						dx=x+d[i][0],dy=y+d[i][1];
						if(Lv[id1])break;
					}
					else break;
				}
			}
			x=xxx,y=yyy;
		}
//		cout<<ans<<endl;
		rep(i,0,3)
		{
			int dx=x+d[i][0],dy=y+d[i][1];
			if(f[id1][i]==3)
			dfs(dx,dy,col,lv);
		}
		--q;c[id1]=col,Lv[id1]=lv;
		printf("%d\n",ans);
	}
	return;
}
int T;
char h[N],g[N];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	read(T);
	while(T--)
	{
		read(n),read(m),read(q);
		memset(f,0,sizeof(f));
		memset(c,0,sizeof(c));
		memset(Lv,0,sizeof(Lv));
		memset(vis,0,sizeof(vis));
		memset(vis1,0,sizeof(vis1));
		rep(i,1,n)
		{
			scanf("%s",h+1);
			rep(j,1,m-1)
			{
				f[id(i,j)][0]=h[j]-'0';
				f[id(i,j+1)][1]=h[j]-'0';
			}
		}
		rep(i,1,n-1)
		{
			scanf("%s",g+1);
			rep(j,1,m)
			{
				f[id(i,j)][2]=g[j]-'0';
				f[id(i+1,j)][3]=g[j]-'0';
			}
		}
		solve();
	}
	return 0;
}
/*
1
1 10 3
222221322
0 1 1 3
0 2 1 2
1 2 1 1

*/
