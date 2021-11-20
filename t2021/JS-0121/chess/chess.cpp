#include<bits/stdc++.h>
using namespace std;
template<typename T>
void read(T &x)
{
	x=0;
	int tag=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
			tag=-tag;
		c=getchar();
	}
	while(isdigit(c))
	{
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	x*=tag;
	return;
}
template<typename T>
void write(T x)
{
	T y=0;
	int cnt=0;
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x==0)
	{
		putchar('0');
		return;
	}
	while(x%10==0)
	{
		++cnt;
		x/=10;
	}
	while(x>0)
	{
		y*=10;
		y+=x%10;
		x/=10;
	}
	while(y>0)
	{
		putchar(y%10+'0');
		y/=10;
	}
	while(cnt--)
		putchar('0');
	return;
}
char getc()
{
	char c=getchar();
	while(!isdigit(c))
		c=getchar();
	return c;
}
struct chess
{
	int col=2,lv=0;
};
int n,m,q;
vector<vector<chess>> v;
vector<vector<bool>> vis;
vector<vector<char>> a,b;
set<pair<int,int>> r;
void dfs(int x,int y,int s,int col,int lv)
{
	if(v[x][y].lv>lv||v[x][y].col==col||vis[x][y])
		return;
	r.insert(make_pair(x,y));
	if(v[x][y].col!=2||s==0)
		return;
	vis[x][y]=true;
	if(s==5)
	{
		if(x<n&&b[x][y]=='3')
			dfs(x+1,y,s,col,lv);
		if(x>1&&b[x-1][y]=='3')
			dfs(x-1,y,s,col,lv);
		if(y<m&&a[x][y]=='3')
			dfs(x,y+1,s,col,lv);
		if(y>1&&a[x][y-1]=='3')
			dfs(x,y-1,s,col,lv);
	}
	else
	{
		if(s==1&&x<n&&b[x][y]=='2')
			dfs(x+1,y,s,col,lv);
		if(s==2&&x>1&&b[x-1][y]=='2')
			dfs(x-1,y,s,col,lv);
		if(s==3&&y<m&&a[x][y]=='2')
			dfs(x,y+1,s,col,lv);
		if(s==4&&y>1&&b[x][y-1]=='2')
			dfs(x,y-1,s,col,lv);
	}
	vis[x][y]=false;
	return;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;
	read(T);
	while(T--)
	{
		read(n);
		read(m);
		read(q);
		a.clear();
		b.clear();
		a.resize(n+1,vector<char>(m));
		b.resize(n,vector<char>(m+1));
		for(int i=1;i<=n;++i)
			for(int j=1;j<m;++j)
				a[i][j]=getc();
		for(int i=1;i<n;++i)
			for(int j=1;j<=m;++j)
				b[i][j]=getc();
		v.clear();
		v.resize(n+1,vector<chess>(m+1));
		vis.resize(n+1,vector<bool>(m+1));
		while(q--)
		{
			int col,lv,x,y;
			read(col);
			read(lv);
			read(x);
			read(y);
			v[x][y].col=col;
			v[x][y].lv=lv;
			vis[x][y]=true;
			r.clear();
			if(x<n&&b[x][y]!='0')
			{
				if(b[x][y]=='1')
					dfs(x+1,y,0,col,lv);
				if(b[x][y]=='2')
					dfs(x+1,y,1,col,lv);
				if(b[x][y]=='3')
					dfs(x+1,y,5,col,lv);
			}
			if(x>1&&b[x-1][y]!='0')
			{
				if(b[x-1][y]=='1')
					dfs(x-1,y,0,col,lv);
				if(b[x-1][y]=='2')
					dfs(x-1,y,2,col,lv);
				if(b[x-1][y]=='3')
					dfs(x-1,y,5,col,lv);
			}
			if(y<m&&a[x][y]!='0')
			{
				if(a[x][y]=='1')
					dfs(x,y+1,0,col,lv);
				if(a[x][y]=='2')
					dfs(x,y+1,3,col,lv);
				if(a[x][y]=='3')
					dfs(x,y+1,5,col,lv);
			}
			if(y>1&&a[x][y-1]!='0')
			{
				if(a[x][y-1]=='1')
					dfs(x,y-1,0,col,lv);
				if(a[x][y-1]=='2')
					dfs(x,y-1,4,col,lv);
				if(a[x][y-1]=='3')
					dfs(x,y-1,5,col,lv);
			}
			vis[x][y]=false;
			write(r.size());
			putchar('\n');
		}
	}
	return 0;
}

