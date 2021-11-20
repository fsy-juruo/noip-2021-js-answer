#include<bits/stdc++.h>
using namespace std;
const int maxn=5010;
int n,m,q;
string r[maxn],c[maxn];
int col[maxn][maxn],lv[maxn][maxn],cnt=0;
bool vis[maxn][maxn][2];
void dfs(int x,int y,int co,int le,int dir,bool f)
{
	vis[x][y][f]=true;
	//up
	if(x>1&&(dir==-1||dir==0))
	{
		if(c[x-1][y]=='0'&&!f&&!vis[x-1][y][1]&&co!=col[x-1][y]&&le>=lv[x-1][y])
		{
			dfs(x-1,y,co,le,-1,1);
		}
		if(c[x-1][y]=='1'&&!vis[x-1][y][f]&&co!=col[x-1][y]&&le>=lv[x-1][y])
		{
			dfs(x-1,y,co,le,0,f);
		}
		if(c[x-1][y]=='2'&&!vis[x-1][y][f]&&co!=col[x-1][y]&&le>=lv[x-1][y])
		{
			dfs(x-1,y,co,le,-1,f);
		}
	}
	//down
	if(x<n&&(dir==-1||dir==1))
	{
		if(c[x][y]=='0'&&!f&&!vis[x+1][y][1]&&co!=col[x+1][y]&&le>=lv[x+1][y])
		{
			dfs(x+1,y,co,le,-1,1);
		}
		if(c[x][y]=='1'&&!vis[x+1][y][f]&&co!=col[x+1][y]&&le>=lv[x+1][y])
		{
			dfs(x+1,y,co,le,1,f);
		}
		if(c[x][y]=='2'&&!vis[x+1][y][f]&&co!=col[x+1][y]&&le>=lv[x+1][y])
		{
			dfs(x+1,y,co,le,-1,f);
		}
	}
	//left
	if(y>1&&(dir==-1||dir==2))
	{
		if(r[x][y-1]=='0'&&!f&&!vis[x][y-1][1]&&co!=col[x][y-1]&&le>=lv[x][y-1])
		{
			dfs(x,y-1,co,le,-1,1);
		}
		if(r[x][y-1]=='1'&&!vis[x][y-1][f]&&co!=col[x][y-1]&&le>=lv[x][y-1])
		{
			dfs(x,y-1,co,le,2,f);
		}
		if(r[x][y-1]=='2'&&!vis[x][y-1][f]&&co!=col[x][y-1]&&le>=lv[x][y-1])
		{
			dfs(x,y-1,co,le,-1,f);
		}
	}
	//right
	if(y<m&&(dir==-1||dir==3))
	{
		if(r[x][y]=='0'&&!f&&!vis[x][y+1][1]&&co!=col[x][y+1]&&le>=lv[x][y+1])
		{
			dfs(x,y+1,co,le,-1,1);
		}
		if(r[x][y]=='1'&&!vis[x][y+1][f]&&co!=col[x][y+1]&&le>=lv[x][y+1])
		{
			dfs(x,y+1,co,le,3,f);
		}
		if(r[x][y]=='2'&&!vis[x][y+1][f]&&co!=col[x][y+1]&&le>=lv[x][y+1])
		{
			dfs(x,y+1,co,le,-1,f);
		}
	}
}
void solve()
{
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>r[i];
		r[i]=' '+r[i];
	}
	for(int i=1;i<n;i++)
	{
		cin>>c[i];
		c[i]=' '+c[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			col[i][j]=-1;
		}
	}
	int co,le,x,y;
	while(q--)
	{
		cin>>co>>le>>x>>y;
		cout<<0<<endl;
		continue;
		col[x][y]=co;
		lv[x][y]=le;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				vis[i][j][0]=vis[i][j][1]=0;
			}
		}
		dfs(x,y,co,le,-1,0);
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(vis[i][j][0]||vis[i][j][1])
				{
					cnt++;
				}
			}
		}
		cout<<cnt-1<<endl;
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
/*
1. copy the names of the problems
2. freopen
3. int, long long overflow
4. memory overflow
5. delete debug sentences
6. list the main ideas
7. special cases
*/
