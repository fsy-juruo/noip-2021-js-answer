#include <bits/stdc++.h>
#define inf 1000000007
#define mod 1000000007
//#define int long long
using namespace std;
template <typename T> void read(T &x){
	x=0;int fh=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') fh=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x*=fh;
}
template <typename T> void write(T x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
template <typename T> void writeln(T x){
	write(x);
	puts("");
}
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int n,m,tp;
int dir[200005][4];
pair<int,int> chess[200005];
char str[300005];
bool vis[200005];
int check(int x,int y,int col,int lv)
{
	if(chess[(x-1)*m+y].second==0) return 2;
	if(chess[(x-1)*m+y].first!=col&&lv>=chess[(x-1)*m+y].second) return 1;
	return 0;
}
signed main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int tc;
	read(tc);
	while(tc--)
	{
		read(n);read(m);read(tp);
		for(int i=1;i<=n*m;++i)
		{
			memset(dir[i],0,sizeof(dir[i]));
			chess[i]={0,0};
		}
		for(int i=1;i<=n;++i)
		{
			scanf("%s",str+1);
			for(int j=1;j<m;++j)
			{
				dir[(i-1)*m+j][0]=str[j]-'0';
				dir[(i-1)*m+j+1][2]=str[j]-'0';
			}
		}
		for(int i=1;i<n;++i)
		{
			scanf("%s",str+1);
			for(int j=1;j<=m;++j)
			{
				dir[(i-1)*m+j][1]=str[j]-'0';
				dir[i*m+j][3]=str[j]-'0';
			}
		}
		if(n*m<=5000&&tp<=2000)
		{
			while(tp--)
			{
				int col,lv,sx,sy;
				read(col);read(lv);read(sx);read(sy);
				memset(vis,0,sizeof(vis));
				vis[(sx-1)*m+sy]=1;
				int ans=0;
				for(int d=0;d<4;++d)
					if(dir[(sx-1)*m+sy][d]==1&&check(sx+dx[d],sy+dy[d],col,lv))
					{
						vis[(sx+dx[d]-1)*m+sy+dy[d]]=1;
						ans++;
					}
				for(int d=0;d<4;++d)
				{
					int x=sx,y=sy;
					while(dir[(x-1)*m+y][d]==2&&check(x+dx[d],y+dy[d],col,lv))
					{
						x+=dx[d],y+=dy[d];
						ans++;
						vis[(x-1)*m+y]=1;
						if(check(x,y,col,lv)==1) break;
					}
				}
				queue<pair<int,int>> q;
				q.push({sx,sy});
				while(!q.empty())
				{
					pair<int,int> p=q.front();
					q.pop();
					int x=p.first,y=p.second;
					for(int d=0;d<4;++d)
						if(dir[(x-1)*m+y][d]==3&&!vis[(x+dx[d]-1)*m+y+dy[d]]&&check(x+dx[d],y+dy[d],col,lv))
						{
							ans++;
							vis[(x+dx[d]-1)*m+y+dy[d]]=1;
							if(check(x+dx[d],y+dy[d],col,lv)==2)
								q.push({x+dx[d],y+dy[d]});
						}
				}
				writeln(ans);
				chess[(sx-1)*m+sy]={col,lv};
			}
		}
	}
	return 0;
}

