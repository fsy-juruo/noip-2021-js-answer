#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll read()
{
	ll res=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') res=(res<<1)+(res<<3)+(c^48),c=getchar();
	return res*f;
}

const int N=200005;
int n,m,Q;

int xx[5]={0,0,1,-1};
int yy[5]={1,-1,0,0};

struct node{
	int e[4];
	int soldier;
	node()
	{
		e[0]=e[1]=e[2]=e[3]=soldier=0;
	}
};
vector<node> g[N];

int col[N],lv[N];

inline bool out(int x,int y)
{
	return (x<1||y<1||x>n||y>m);
}

void INIT()
{
	for(int i=1;i<=100000;i++)
		g[i].clear();
	memset(col,0,sizeof col);
	memset(lv,0,sizeof lv);	
}

struct normal{

bool vis[5005][5005],battle[5005][5005];

void init()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			vis[i][j]=battle[i][j]=0;
}

void dfs(int x,int y)
{
	vis[x][y]=1;
	for(int k=0;k<4;k++)
	{
		int nx=x+xx[k],ny=y+yy[k];
		if(g[x][y].e[k]!=3)
			continue;
		if(out(nx,ny))
			continue;
		if(vis[nx][ny])
			continue;
		if(battle[nx][ny])
			continue;
		if(g[nx][ny].soldier)
			battle[nx][ny]=1;
		else
			dfs(nx,ny);
	}
}
//int battle[N],tot;

string str;
void solve()
{
	INIT();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m+1;j++)
			g[i].push_back(node());
	
	for(int i=1;i<=n;i++)
	{
		cin>>str;
		for(int j=1;j<m;j++)
		{
			int x=str[j-1]-'0';
			g[i][j].e[0]=x;
			g[i][j+1].e[1]=x;
		}
	}
	for(int i=1;i<n;i++)
	{
		cin>>str;
		for(int j=1;j<=m;j++)
		{
			int x=str[j-1]-'0';
			g[i][j].e[2]=x;
			g[i+1][j].e[3]=x;
		}
	}
	
//	cout<<g[2][2].soldier<<endl;
	
	for(int i=1;i<=Q;i++)
	{
		init();
		
		col[i]=read();
		lv[i]=read();
		int x=read(),y=read();
		
		for(int k=0;k<4;k++)
		{
			int nx=x+xx[k],ny=y+yy[k];
			if(out(nx,ny))
				continue;
			if(g[x][y].e[k]==0)
				continue;
			if(g[x][y].e[k]==1)
			{
				if(g[nx][ny].soldier)
					battle[nx][ny]=1;
				else
					vis[nx][ny]=1;
			}
			if(g[x][y].e[k]==2)
			{
				nx=x,ny=y;
				while(1)
				{
					if(g[nx][ny].e[k]!=2)
						break;
					nx=nx+xx[k],ny=ny+yy[k];
					if(out(nx,ny))
						break;
					if(g[nx][ny].soldier)
					{
						battle[nx][ny]=1;
						break;
					}
					else
						vis[nx][ny]=1;
				}
			}
		}
		dfs(x,y);
		
		int ans=0;
		for(int nx=1;nx<=n;nx++)
			for(int ny=1;ny<=m;ny++)
			{
				if(vis[nx][ny])
					ans++;
				if(battle[nx][ny])
				{
					int b=g[nx][ny].soldier;
					if(col[i]!=col[b]&&lv[i]>=lv[b])
						ans++;
				}
			}
		
//		for(int j=1;j<=tot;j++)
//		{
//			int b=battle[j];
//			if(col[i]!=col[b]&&lv[i]>=lv[b])
//				ans++;
//		}
		printf("%d\n",ans-1);
		
		g[x][y].soldier=i;
	}
}

}p1;

struct only_once{

string str;
void solve()
{
	INIT();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m+1;j++)
			g[i].push_back(node());
	
	for(int i=1;i<=n;i++)
	{
		cin>>str;
		for(int j=1;j<m;j++)
		{
			int x=str[j-1]-'0';
			g[i][j].e[0]=x;
			g[i][j+1].e[1]=x;
		}
	}
	for(int i=1;i<n;i++)
	{
		cin>>str;
		for(int j=1;j<=m;j++)
		{
			int x=str[j-1]-'0';
			g[i][j].e[2]=x;
			g[i+1][j].e[3]=x;
		}
	}
	
//	cout<<g[2][2].soldier<<endl;
	
	for(int i=1;i<=Q;i++)
	{
		col[i]=read();
		lv[i]=read();
		int x=read(),y=read();
		
		int ans=0;
		
		for(int k=0;k<4;k++)
		{
			int nx=x+xx[k],ny=y+yy[k];
			if(out(nx,ny))
				continue;
			if(g[x][y].e[k]==0)
				continue;
			if(g[x][y].e[k]==1)
			{
				if(g[nx][ny].soldier)
				{
					int b=g[nx][ny].soldier;
					if(col[i]!=col[b]&&lv[i]>=lv[b])
						ans++;
				}
				else
					ans++;
			}
		}
		
		printf("%d\n",ans);
		
		g[x][y].soldier=i;
	}
}

}p2;

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	int t=read();
	while(t--)
	{
		n=read(),m=read();Q=read();
		if(n*m<=5000)
			p1.solve();
		else
			p2.solve();
	}
	
	return 0;
}
/*
1
3 3 5
13
22
23
010
233
0 1 2 3
1 2 2 1
1 3 1 2
0 2 3 2
1 3 2 2
*/
/*
2
3 3 5
11
11
11
010
111
0 1 2 3
1 2 2 1
1 3 1 2
0 2 3 2
1 3 2 2

3 3 5
11
11
11
010
111
0 1 2 3
1 2 2 1
1 3 1 2
0 2 3 2
1 3 2 2

*/
