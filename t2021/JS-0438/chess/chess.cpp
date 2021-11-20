#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define DEBUG
#ifdef DEBUG
#define debug printf
#else
#define debug(...)
#endif
int read()
{
	int s = 0,f = 1;
	char c = getchar();
	while(!isdigit(c))
	{
		if(c == '-')
		{
			f = 0;
		}
		c = getchar();	
	} 
	while(isdigit(c))
	{
		s = s * 10 + c - '0';
		c = getchar();
	}
	return f ? s : -s;
}
ll readll()
{
	ll s = 0,f = 1;
	char c = getchar();
	while(!isdigit(c))
	{
		if(c == '-')
		{
			f = 0;
		}
		c = getchar();	
	} 
	while(isdigit(c))
	{
		s = s * 10 + c - '0';
		c = getchar();
	}
	return f ? s : -s;
}
const int maxn = 2e5 + 5;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
int n,m,q;
int fg[5];
vector<int> L[maxn],D[maxn];
vector<int> vis[maxn],vis2[maxn];
vector< pair<int,int> > ch[maxn];
void clear()
{
//	return;
	for(int i = 1;i <= n; ++i)
	{
		vis[i].assign(m + 1,0);
		vis2[i].assign(m + 1,0);
		ch[i].assign(m + 1,make_pair(0,0));
	}
}
inline int tst(int x,int y,int nx,int ny,int index,int col,int lv)
{
	if(!(nx >= 1 && nx <= n && ny >= 1 && ny <= m))
	{
		return 0;
	}
	if(x == nx)
	{
		int t = L[x][min(y,ny)];
		if(t != index)
		{
			return 0;
		}
	}
	else
	{
		int t = D[min(x,nx)][y];
		if(t != index)
		{
			return 0;
		}
	}
	if(ch[nx][ny].first != 0)
	{
		if(ch[nx][ny].first == col)
		{
			return 0;
		}
		if(ch[nx][ny].second > lv)
		{
			return 0;
		}
	}
	return 1;
}
void print(int x,int y,int nx,int ny,int road)
{
	debug("%d,%d -> %d,%d use path %d\n",x,y,nx,ny,road);
}
namespace sol1{
	void main()
	{
		while(q--)
		{
			int col,lv,x,y,ans = 0;
			col = read() + 1;
			lv = read();
			x = read();
			y = read();
//			debug("%d %d %d %d\n",x,y,col,lv);
			for(int i = 0;i < 4; ++i)
			{
				if(tst(x,y,x + dx[i],y + dy[i],1,col,lv))
				{
					vis[x + dx[i]][y + dy[i]] = q;
//					print(x,y,x + dx[i],y + dy[i],1);
					++ans;
				}
			}
			for(int i = 0;i < 4; ++i)
			{
				int nx = x,ny = y;
				while(tst(nx,ny,nx + dx[i],ny + dy[i],2,col,lv))
				{
//					print(nx,ny,nx + dx[i],ny + dy[i],2);
					nx = nx + dx[i],ny = ny + dy[i];
					if(vis[nx][ny] != q)
					{
						++ans;
					}
					vis[nx][ny] = q;
					if(ch[nx][ny].first != 0)
					{
						break;
					}
				} 
			}
			queue< pair<int,int> > que;
			que.push(make_pair(x,y));
			vis2[x][y] = q;
			while(!que.empty())
			{
				pair<int,int> now = que.front();
//				debug("now(%d,%d)\n",now.first,now.second);
				que.pop();
				if(ch[now.first][now.second].first != 0)
				{
					continue;
				}
				for(int i = 0;i < 4; ++i)
				{
					int nx = now.first + dx[i],ny = now.second + dy[i];
					if(tst(now.first,now.second,nx,ny,3,col,lv) && vis2[nx][ny] != q)
					{
						if(vis[nx][ny] != q)
						{
//							print(now.first,now.second,nx,ny,3);
							++ans;
						}
						vis[nx][ny] = q;
						vis2[nx][ny] = q;
						que.push(make_pair(nx,ny));
					}
				}
			}
			printf("%d\n",ans);
			ch[x][y] = make_pair(col,lv);
		}
	}
};
char s[maxn];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;
	scanf("%d",&T);
//	clock_t _begin = clock();
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&q);
		clear();
//		printf("ok\n");
		fg[0] = fg[1] = fg[2] = fg[3] = 0;
		for(int i = 1;i <= n; ++i)
		{
			L[i].resize(m);
			scanf("%s",s + 1);
			for(int j = 1;j < m; ++j)
			{
				fg[L[i][j] = s[j] - '0'] = 1;
			}
		}
		for(int i = 1;i < n; ++i)
		{
			D[i].resize(m + 1);
			scanf("%s",s + 1);
			for(int j = 1;j <= m; ++j)
			{
				fg[D[i][j] = s[j] - '0'] = 1;	
			}
		}
//		clock_t now = clock();
//		printf("%.2lf\n",(now - _begin) / 1000.0);
//		if(n * m <= 5000 || (fg[2] == 0 && fg[3] == 0))
		{
			sol1::main();
		}
	}
	return 0;
}
