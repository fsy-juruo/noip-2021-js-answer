#include<bits/stdc++.h>
using namespace std;
int T,n,m,q,dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
char col[10005][10005],lv[10005][10005];
string s1[100005],s2[100005];
bool v[10005][10005],f[10005][10005];
set<pair<int,int> >mp;
char road(int a,int b,int c,int d)
{
	if(a==c)
	{
		if(d==b-1)return s1[a][b-1-1];
		else return s1[a][b-1];
	}
	else
	{
		if(a==c-1)return s2[c-1][b-1];
		else return s2[c][b-1];
	}
}
void dfs(int fx,int fy,int x,int y)
{
	if(fx==x&&fy==y)
	{
		for(int i=0;i<4;++i)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(f[nx][ny])continue;
			if(nx<1||nx>n||ny<1||ny>m)continue;
			if(v[nx][ny])
			{
				if(col[nx][ny]!=col[x][y]&&lv[x][y]>=lv[nx][ny])mp.insert(make_pair(nx,ny)),f[nx][ny]=true;
			}
			if(road(x,y,nx,ny)!='0')
			{
				mp.insert(make_pair(nx,ny));
				f[nx][ny]=true;
				dfs(x,y,nx,ny);
				f[nx][ny]=false;
			}
		}
	}
	else
	{
		for(int i=0;i<4;++i)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(f[nx][ny])continue;
			if(nx<1||nx>n||ny<1||ny>m)continue;
			if(v[nx][ny])
			{
				if(col[nx][ny]!=col[x][y]&&lv[x][y]>=lv[nx][ny])mp.insert(make_pair(nx,ny)),f[nx][ny]=true;
			}
			else
			{
				char r1=road(fx,fy,x,y),r2=road(x,y,nx,ny);
				if(r1!=r2)continue;
				if((r2=='0')||(r2=='1'))continue;
				if(r2=='2')
				{
					if((fx==x&&x==nx)||(fy==y&&y==ny))
					{
						mp.insert(make_pair(nx,ny));
						f[nx][ny]=true;
						dfs(x,y,nx,ny);
						f[nx][ny]=false;
					}
					else continue;
				}
				if(r2=='3')
				{
					mp.insert(make_pair(nx,ny));
					f[nx][ny]=true;
					dfs(x,y,nx,ny);
					f[nx][ny]=false;
				}
			}
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(col,0,sizeof(col));
		memset(lv,0,sizeof(lv));
		memset(f,false,sizeof(f));
		memset(v,false,sizeof(v));
		cin>>n>>m>>q;
		for(int i=1;i<=n;++i)
		{
			cin>>s1[i];
		}
		for(int i=1;i<n;++i)
		{
			cin>>s2[i];
		}
		for(int i=1;i<=q;++i)
		{
			int col1,lv1,x1,y1;
			memset(f,false,sizeof(f));
			mp.clear();
			cin>>col1>>lv1>>x1>>y1;
			v[x1][y1]=true;
			col[x1][y1]=col1;
			lv[x1][y1]=lv1;
			f[x1][y1]=true;
			dfs(x1,y1,x1,y1);
			printf("%d\n",mp.size());
		}
	}
	return 0;
}
