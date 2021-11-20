#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char c=getchar();
	int x=0;
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}
void write(int x)
{
	if(x>9)
		write(x/10);
	putchar(x%10+'0');
}
inline void fl()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
}
int n,m;
vector<int>opt[2][100005],lv[100005];
vector<bool>col[100005],f[100005];
inline bool check(int x,int y)
{
	return x>0&&x<=n&&y>0&&y<=m&&!f[x][y];
}
void dfs(int x,int y,int Col,int Lv)
{
	if(check(x-1,y)&&opt[1][x-1][y]==3)
	{
		if(!lv[x-1][y])
		{
			f[x-1][y]=true;
			dfs(x-1,y,Col,Lv);
		}
		else
			if(col[x-1][y]!=Col&&lv[x-1][y]<=Lv)
				f[x-1][y]=true;
	}
	if(check(x+1,y)&&opt[1][x][y]==3)
	{
		if(!lv[x+1][y])
		{
			f[x+1][y]=true;
			dfs(x+1,y,Col,Lv);
		}
		else
			if(col[x+1][y]!=Col&&lv[x+1][y]<=Lv)
				f[x+1][y]=true;
	}
	if(check(x,y-1)&&opt[0][x][y-1]==3)
	{
		if(!lv[x][y-1])
		{
			f[x][y-1]=true;
			dfs(x,y-1,Col,Lv);
		}
		else
			if(col[x][y-1]!=Col&&lv[x][y-1]<=Lv)
				f[x][y-1]=true;
	}
	if(check(x,y+1)&&opt[0][x][y]==3)
	{
		if(!lv[x][y+1])
		{
			f[x][y+1]=true;
			dfs(x,y+1,Col,Lv);
		}
		else
			if(col[x][y+1]!=Col&&lv[x][y+1]<=Lv)
				f[x][y+1]=true;
	}
}
int main()
{
	fl();
	int T=read(),q,i,j;
	while(T--)
	{
		n=read();
		m=read();
		q=read();
		bool vis[4]={};
		for(i=1;i<=n;i++)
		{
			char c=getchar();
			while(c<'0'||c>'3')
				c=getchar();
			opt[0][i].push_back(-1);
			for(j=1;j<m;j++)
			{
				opt[0][i].push_back(c-'0');
				vis[c-'0']=true;
				c=getchar();
			}
			lv[i].resize(m+1);
			col[i].resize(m+1);
		}
		for(i=1;i<n;i++)
		{
			char c=getchar();
			while(c<'0'||c>'3')
				c=getchar();
			opt[1][i].push_back(-1);
			for(j=1;j<=m;j++)
			{
				opt[1][i].push_back(c-'0');
				vis[c-'0']=true;
				c=getchar();
			}
		}
		if(!vis[2]&&!vis[3])
		{
			while(q--)
			{
				bool Col=read();
				int Lv=read(),x=read(),y=read();
				col[x][y]=Col;
				lv[x][y]=Lv;
				int ans=0;
				if(check(x-1,y)&&opt[1][x-1][y]==1)
				{
					if(!lv[x-1][y])
						ans++;
					else
						if(col[x-1][y]!=Col&&lv[x-1][y]<=Lv)
							ans++;
				}
				if(check(x+1,y)&&opt[1][x][y]==1)
				{
					if(!lv[x+1][y])
						ans++;
					else
						if(col[x+1][y]!=Col&&lv[x+1][y]<=Lv)
							ans++;
				}
				if(check(x,y-1)&&opt[0][x][y-1]==1)
				{
					if(!lv[x][y-1])
						ans++;
					else
						if(col[x][y-1]!=Col&&lv[x][y-1]<=Lv)
							ans++;
				}
				if(check(x,y+1)&&opt[0][x][y]==1)
				{
					if(!lv[x][y+1])
						ans++;
					else
						if(col[x][y+1]!=Col&&lv[x][y+1]<=Lv)
							ans++;
				}
				write(ans);
				putchar('\n');
			}
			for(i=1;i<=n;i++)
			{
				opt[0][i].clear();
				opt[1][i].clear();
				lv[i].clear();
				col[i].clear();
			}
			continue;
		}
		while(q--)
		{
			bool Col=read();
			int Lv=read(),x=read(),y=read();
			col[x][y]=Col;
			lv[x][y]=Lv;
			for(i=1;i<=n;i++)
				f[i].resize(m+1);
			dfs(x,y,Col,Lv);
			if(check(x-1,y)&&opt[1][x-1][y]==1)
			{
				if(!lv[x-1][y])
					f[x-1][y]=true;
				else
					if(col[x-1][y]!=Col&&lv[x-1][y]<=Lv)
						f[x-1][y]=true;
			}
			if(check(x+1,y)&&opt[1][x][y]==1)
			{
				if(!lv[x+1][y])
					f[x+1][y]=true;
				else
					if(col[x+1][y]!=Col&&lv[x+1][y]<=Lv)
						f[x+1][y]=true;
			}
			if(check(x,y-1)&&opt[0][x][y-1]==1)
			{
				if(!lv[x][y-1])
					f[x][y-1]=true;
				else
					if(col[x][y-1]!=Col&&lv[x][y-1]<=Lv)
						f[x][y-1]=true;
			}
			if(check(x,y+1)&&opt[0][x][y]==1)
			{
				if(!lv[x][y+1])
					f[x][y+1]=true;
				else
					if(col[x][y+1]!=Col&&lv[x][y+1]<=Lv)
						f[x][y+1]=true;
			}
			for(i=x-1;i&&opt[1][i][y]==2&&!lv[i][y];i--)
				f[i][y]=true;
			if(i&&opt[1][i][y]==2&&lv[i][y]&&col[i][y]!=Col&&lv[i][y]<=Lv)
				f[i][y]=true;
				
			for(i=x+1;i<=n&&opt[1][i-1][y]==2&&!lv[i][y];i++)
				f[i][y]=true;
			if(i<=n&&opt[1][i-1][y]==2&&lv[i][y]&&col[i][y]!=Col&&lv[i][y]<=Lv)
				f[i][y]=true;
				
			for(j=y-1;j&&opt[0][x][j]==2&&!lv[x][j];j--)
				f[x][j]=true;
			if(j&&opt[0][x][j]==2&&lv[x][j]&&col[x][j]!=Col&&lv[x][j]<=Lv)
				f[x][j]=true;
				
			for(j=y+1;j<=m&&opt[0][x][j-1]==2&&!lv[x][j];j++)
				f[x][j]=true;
			if(j<=m&&opt[0][x][j-1]==2&&lv[x][j]&&col[x][j]!=Col&&lv[x][j]<=Lv)
				f[x][j]=true;
				
			int ans=0;
			for(i=1;i<=n;i++)
				for(j=1;j<=m;j++)
					if(f[i][j])
						ans++;
			write(ans);
			putchar('\n');
			for(i=1;i<=n;i++)
				f[i].clear();
		}
		for(i=1;i<=n;i++)
		{
			opt[0][i].clear();
			opt[1][i].clear();
			lv[i].clear();
			col[i].clear();
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
