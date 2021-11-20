#include<bits/stdc++.h>
using namespace std;
int n,m,q,ans;
int s1[505][505],s2[505][505];
bool vis[505][505];
int col[505][505],lv[505][505];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void walk(int x,int y,int color,int level,int last_i)
{
	if(!vis[x][y])
	{
		vis[x][y]=1;
		ans++;
	}
	if(last_i==0) ans--;
	if(last_i==1)
	{
		return;
	}
	for(int i=0;i<4;i++)
	{
		int tx=x+dx[i],ty=y+dy[i];
		if(tx<1||ty<1||tx>n||ty>m) continue;
		if(dy[i]==0)
		{
			if(s2[x][y]==0) continue;
			if(last_i==0)
			{
				if(col[tx][ty]==0)
				{
					walk(tx,ty,color,level,s2[x][y]);
				}
				else
				{
					if(color!=col[tx][ty]&&level>=lv[tx][ty])
					{
						if(!vis[tx][ty])
						{
							vis[tx][ty]=1;
							ans++;
							continue;
						}
					}
				}
			}
			else
			{
				if(!vis[tx][ty]&&s2[x][y]==last_i)
				{
					if(col[tx][ty]==0)
					{
						walk(tx,ty,color,level,s2[x][y]);
					}
					else
					{
						if(color!=col[tx][ty]&&level>=lv[tx][ty])
						{
							if(!vis[tx][ty])
							{
								vis[tx][ty]=1;
								ans++;
								continue;
							}
						}
					}
				}
			}
		}
		if(dx[i]==0)
		{
			if(s1[x][y]==0) continue;
			if(last_i==0)
			{
				if(col[tx][ty]==0)
				{
					walk(tx,ty,color,level,s2[x][y]);
				}
				else
				{
					if(color!=col[tx][ty]&&level>=lv[tx][ty])
					{
						if(!vis[tx][ty])
						{
							vis[tx][ty]=1;
							ans++;
							continue;
						}
					}
				}
			}
			else
			{
				if(!vis[tx][ty]&&s2[x][y]==last_i)
				{
					if(col[tx][ty]==0)
					{
						walk(tx,ty,color,level,s2[x][y]);
					}
					else
					{
						if(color!=col[tx][ty]&&level>=lv[tx][ty])
						{
							if(!vis[tx][ty])
							{
								vis[tx][ty]=1;
								ans++;
								continue;
							}
						}
					}
				}
			}
		}
	}
}
int read()
{
	char c=getchar();
	int x=0,f=1;
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T=read();
	while(T--)
	{
		n=read(),m=read(),q=read();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m-1;j++)
			{
				char ch;
				cin>>ch;
				s1[j][i]=s1[i][j]=ch-'0';
			}
		}
		for(int i=1;i<=n-1;i++)
		{
			for(int j=1;j<=m;j++)
			{
				char ch;
				cin>>ch;
				s2[j][i]=s2[i][j]=ch-'0';
			}
		}
		for(int i=1;i<=q;i++)
		{
			ans=0;
			memset(vis,0,sizeof(vis));
			int a1=read(),a2=read(),a3=read(),a4=read();
			col[a3][a4]=a1+1,lv[a3][a4]=a2;
			walk(a3,a4,a1+1,a2,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}

