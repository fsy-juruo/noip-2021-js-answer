#include<bits/stdc++.h>
using namespace std;

inline void read(int &x)
{
	x=0;
	int f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-48;
		c=getchar();
	}
	x*=f;
}

const int maxn = 107;
int T,n,m,q,nx,ny,ans,nf;
int x[maxn],y[maxn];
int opt[57][57][57][57],col[maxn],lv[maxn],ptcol[maxn][maxn],ptlv[maxn][maxn];
bool vis[maxn][maxn];
int addx[6]={0,0,0,1,-1};
int addy[6]={0,1,-1,0,0};

void dfs(int x,int y,int xz,int fx)
{
	vis[x][y]=1;
	if(x==nx&&y==ny)
	{
		for(int i=1;i<=4;++i)
		{
			int xx=x+addx[i],yy=y+addy[i];
			if(vis[xx][yy])
				continue;
			if(opt[x][y][xx][yy]==0)
				continue;
			if(opt[x][y][xx][yy]==1)
			{
				if(ptcol[xx][yy])
				{
					if(ptcol[xx][yy]!=col[nf]&&ptlv[xx][yy]<=lv[nf])
						++ans;
					continue;
				}
				else
				{
					++ans;
					continue;
				}
				continue;
			}
			if(opt[x][y][xx][yy]==2)
			{
				if(ptcol[xx][yy])
				{
					if(ptcol[xx][yy]!=col[nf]&&ptlv[xx][yy]<=lv[nf])
						++ans;
					continue;
				}
				else
				{
					++ans;
					dfs(xx,yy,2,(yy==y));
				}
			}
			if(opt[x][y][xx][yy]==3)
			{
				if(ptcol[xx][yy])
				{
					if(ptcol[xx][yy]!=col[nf]&&ptlv[xx][yy]<=lv[nf])
						++ans;
					continue;
				}
				else
				{
					++ans;
					dfs(xx,yy,3,(yy==y));
				}
			}
		}
	}
	for(int i=1;i<=4;++i)
	{
		int xx=x+addx[i],yy=y+addy[i];
		if(opt[x][y][xx][yy]==2)
			{
				if((yy==y)!=fx)
					continue;
				if(ptcol[xx][yy])
				{
					if(ptcol[xx][yy]!=col[nf]&&ptlv[xx][yy]<=lv[nf])
						++ans;
					continue;
				}
				else
				{
					++ans;
					dfs(xx,yy,2,fx);
				}
			}
			if(opt[x][y][xx][yy]==3)
			{
				if(ptcol[xx][yy])
				{
					if(ptcol[xx][yy]!=col[nf]&&ptlv[xx][yy]<=lv[nf])
						++ans;
					continue;
				}
				else
				{
					++ans;
					dfs(xx,yy,3,fx);
				}
			}	
	}
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	read(T);
	while(T--)
	{
		for(int i=1;i<=n;++i)
		{
			char c;
			for(int j=1;j<m;++j)
			{
				cin>>c;
				opt[i][j][i][j+1]=c-'0';
			}
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<m;++j)
			{
				ptcol[i][j]=0,ptlv[i][j]=0;		
			}
		}
		for(int i=1;i<n;++i)
		{
			char c;
			for(int j=1;j<=m;++j)
			{
				cin>>c;
				opt[i][j][i+1][j]=c-'0';
			}
		}
		for(int i=1;i<=q;++i)
		{
			ans=0;
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<m;++j)
				{
					vis[i][j]=0;
				}
			}
			read(col[i]),read(lv[i]),read(x[i]),read(y[i]);
			nx=x[i],ny=y[i];
			nf=i;
			dfs(x[i],y[i],0,0);
			ptcol[x[i]][y[i]]=col[i];
			ptlv[x[i]][y[i]]=lv[i];
			printf("%lld\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

