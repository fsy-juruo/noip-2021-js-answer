#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second

using namespace std;
const int N=2e5+5;
const int M=5005;
int read(){int res=0;char c=getchar();while(!isdigit(c))c=getchar();while(isdigit(c))res=res*10+c-'0',c=getchar();return res;}
void print(int x){if(!x)return;else{print(x/10);putchar(x%10+'0');}return;}
void write(int x){if(!x)putchar('0');else print(x);putchar('\n');return;}
int dx[]={0,1,0,-1},n;
int dy[]={1,0,-1,0},m;
int q,T,v[N][5],e[N][5];
pii p[N];bool vis[N];int qwq;
bool pk(int a,int b)
{
	if(!p[b].S)return true;
	if(p[a].F==p[b].F)return false;
	return p[a].S>=p[b].S;
}
void dfs(int now,int t,int s)
{
	if(now==-1)return;
	if(vis[now]&&s==3)return;
	vis[now]=true;
	if(p[now].S)return;
	if(s==2)
	{
		if(e[now][t]==s)dfs(v[now][t],t,s);
		return;
	}
	for(int i=0;i<4;i++)
		if(e[now][i]==s)
			dfs(v[now][i],i,s);
	return;
}
void init()
{
	for(int i=0;i<n*m*2;i++)
	{
		p[i]=make_pair(0,0);
		vis[i]=false;
		for(int j=0;j<4;j++)
		{
			v[i][j]=-1,e[i][j]=0;
		}
	}
}
void solve()
{
	n=read();m=read();q=read();
	init();
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			for(int k=0;k<4;k++)
			{
				p[i*m+j]=make_pair(0,0);
				int to=(i+dx[k])*m+j+dy[k];
				if(to>=0&&to<n*m)v[i*m+j][k]=to;
			}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m-1;j++)
		{
			char c=getchar();
			while(!isdigit(c))c=getchar();
			int now=i*m+j;
			e[now][0]=c-'0';
			e[v[now][0]][2]=c-'0';
		}
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<m;j++)
		{
			char c=getchar();
			while(!isdigit(c))c=getchar();
			int now=i*m+j;
			e[now][1]=c-'0';
			e[v[now][1]][3]=c-'0';
		}
	}
	
	for(int i=0;i<q;i++)
	{
		for(int j=0;j<n*m;j++)vis[j]=false;
		int col=read(),lvl=read(),x=read(),y=read();
		x--,y--;p[x*m+y]=make_pair(col,lvl);int ans=0;
		for(int j=0;j<4;j++)
		{
			int X=x+dx[j];
			int Y=y+dy[j];
			int nxt=X*m+Y,now=x*m+y;
			vis[now]=true;qwq=now;
			if(0<=nxt&&nxt<n*m)
				if(e[now][j]==3)
					dfs(nxt,j,e[now][j]);
		}
		for(int j=0;j<4;j++)
		{
			int X=x+dx[j];
			int Y=y+dy[j];
			int nxt=X*m+Y,now=x*m+y;
			vis[now]=true;qwq=now;
			if(0<=nxt&&nxt<n*m)
			{
				if(e[now][j]>=2)
					dfs(nxt,j,e[now][j]);
				else
					if(e[now][j])
						vis[nxt]=true;
			}
		}
		for(int j=0;j<n*m;j++)
			if(j!=qwq)
				ans+=vis[j]*pk(qwq,j);
		write(ans);
	}
	return;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=read();
	while(T--)solve();
	return 0;
}
