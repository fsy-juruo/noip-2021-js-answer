#include<bits/stdc++.h>
#define ALL(v) v.begin(),v.end()
#define srt(v) sort(ALL(v))
#define rALL(v) v.rbegin(),v.rend()
#define rsrt(v) sort(rALL(v))
#define rev(v) reverse(ALL(v))
#define sz(v) (int)(v.size())
#define inf 0x3f3f3f3f
#define eps 1e-9
#define pii pair<int,int>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
const int maxn=200200;
string row[maxn];
string col[maxn];
int n,m,q;
vector<pii> grid[maxn];
vector<bool> vis[maxn];
vector<bool> hav[maxn];
char Getchar()
{
	char c=getchar();
	while(!isdigit(c))
		c=getchar();
	return c;
}
void input()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		row[i].clear();
		col[i].clear();
		grid[i].resize(m+1);
		vis[i].resize(m+1);
		hav[i].resize(m+1);
		for(int j=1;j<=m;j++)
			hav[i][j]=0;
	}
	for(int i=1;i<=n;i++)
	{
		row[i]+='0';
		for(int j=1;j<m;j++)
			row[i]+=Getchar();
	}
	for(int i=1;i<n;i++)
	{
		col[i]+='0';
		for(int j=1;j<=m;j++)
			col[i]+=Getchar();
	}
}
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
char getedge(int x,int y,int d)
{
	if(d==0)
		return row[x][y];
	if(d==1)
		return row[x][y-1];
	if(d==2)
		return col[x][y];
	if(d==3)
		return col[x-1][y];
	return '0';
}
class Subtask1
{
	private:
		int dfs(int x,int y,int co,int lev)
		{
			vis[x][y]=1;
			if(hav[x][y])
				if(co==grid[x][y].first||lev<grid[x][y].second)
					return 0;
			int ans=1;
			if(hav[x][y])
				return ans;
			for(int d=0;d<4;d++)
			{
				int nx=x+dx[d];
				int ny=y+dy[d];
				if(nx&&ny&&nx<=n&&ny<=m&&!vis[nx][ny]&&getedge(x,y,d)=='3')
					ans+=dfs(nx,ny,co,lev);
			}
			return ans;
		}
		int check(int x,int y,int co,int lev,int d)
		{
			if(!x||!y||x>n||y>m||(hav[x][y]&&(co==grid[x][y].first||lev<grid[x][y].second)))
				return 0;
			if(getedge(x,y,d)!='2')
			{
				int ans=!vis[x][y];
				vis[x][y]=1;
				return ans;
			}
			int ans=!vis[x][y]+(hav[x][y]?0:check(x+dx[d],y+dy[d],co,lev,d));
			vis[x][y]=1;
			return ans;
		}
		int check2(int x,int y,int co,int lev,int d)
		{
			if(getedge(x,y,d)!='1')
				return 0;
			x+=dx[d];
			y+=dy[d];
			if(!x||!y||x>n||y>m||(hav[x][y]&&(co==grid[x][y].first||lev<grid[x][y].second)))
				return 0;
			int ans=!vis[x][y];
			vis[x][y]=1;
			return ans;
		}
	public:
		void solve()
		{
			while(q--)
			{
				int x,y,a,b;
				scanf("%d%d%d%d",&a,&b,&x,&y);
				for(int i=1;i<=n;i++)
					for(int j=1;j<=m;j++)
						vis[i][j]=0;
				int ans=dfs(x,y,a,b);
				for(int i=0;i<4;i++)
					ans+=check(x,y,a,b,i)+check2(x,y,a,b,i);
//				puts("vis[][]:");
//				for(int i=1;i<=n;i++)
//				{
//					for(int j=1;j<=m;j++)
//						cout<<vis[i][j];
//					puts("");
//				}
				printf("%d\n",ans-1);
				hav[x][y]=1;
				grid[x][y]=mp(a,b);
			}
		}
}S1;
void solve()
{
	input();
	if(n*m<=5000&&q<=2000)//Testcase 1~6 | Points:24
		S1.solve();
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
		solve();
	return 0;
}
