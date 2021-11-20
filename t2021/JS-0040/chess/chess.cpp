#include <bits/stdc++.h>
using namespace std;

int Q,n,m,q,ans,col[10005],lv[10005];
char ch[100005];
int g1[5005][5005],g2[5005][5005],vis[10005],flag[10005];
int ee,h[200005],nex[200005*8],to[200005*8];

int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9') { if(ch=='-') f = -f; ch = getchar(); }
	while(ch>='0' && ch<='9') { x = (x<<3)+(x<<1)+ch-'0'; ch = getchar(); }
	return f*x;
}

void write(int x)
{
	if(x==0)
	{
		putchar('0'); return;
	}
	if(x<0) putchar('-'), x = -x;
	int len=0,sk[50];
	while(x) sk[++len] = x%10, x /= 10;
	while(len) putchar(sk[len]+'0'), len--;
}

void init_()
{
	memset(col,0,sizeof(col));
	memset(h,0,sizeof(h)), ee = 0;
}

int zh(int x,int y)
{
	return (x-1)*m+y;
}

bool legal(int x,int y)
{
	if(col[y]==0) return 1;
	if(col[x]==col[y]) return 0;
	if(lv[x]>=lv[y]) return 1;
	else return 0;
}

void bfs(int sx,int sy)
{
	memset(vis,0,sizeof(vis));
	queue<pair<int,int> > q;
	q.push(make_pair(sx,sy)), vis[zh(sx,sy)] = 1;
	while(!q.empty())
	{
		int x=q.front().first,y=q.front().second; q.pop();
		if(y<m && g1[x][y]==3 && legal(zh(sx,sy),zh(x,y+1)))
		{
			flag[zh(x,y+1)] = 1;
			if(!vis[zh(x,y+1)] && col[zh(x,y+1)]==0)
				vis[zh(x,y+1)] = 1, q.push(make_pair(x,y+1));
		}
		if(y>1 && g1[x][y-1]==3 && legal(zh(sx,sy),zh(x,y-1)))
		{
			flag[zh(x,y-1)] = 1;
			if(!vis[zh(x,y-1)] && col[zh(x,y-1)]==0)
				vis[zh(x,y-1)] = 1, q.push(make_pair(x,y-1));
		}
		if(x<n && g2[x][y]==3 && legal(zh(sx,sy),zh(x+1,y)))
		{
			flag[zh(x+1,y)] = 1;
			if(!vis[zh(x+1,y)] && col[zh(x+1,y)]==0)
				vis[zh(x+1,y)] = 1, q.push(make_pair(x+1,y));
		}
		if(x>1 && g2[x-1][y]==3 && legal(zh(sx,sy),zh(x-1,y)))
		{
			flag[zh(x-1,y)] = 1;
			if(!vis[zh(x-1,y)] && col[zh(x-1,y)]==0)
				vis[zh(x-1,y)] = 1, q.push(make_pair(x-1,y));
		}
	}
}

void subtask1()
{
	ans = 0;
	for(int i=1;i<=n&&scanf("%s",ch+1);i++)
		for(int j=1;j<m;j++)
			g1[i][j] = ch[j]-'0';
	for(int i=1;i<n&&scanf("%s",ch+1);i++)
		for(int j=1;j<=m;j++)
			g2[i][j] = ch[j]-'0';
	while(q--)
	{
		memset(flag,0,sizeof(flag));
		ans = 0;
		int c=read()+1,v=read(),x=read(),y=read();
		col[zh(x,y)] = c, lv[zh(x,y)] = v;
		if(y<m && g1[x][y]==1 && legal(zh(x,y),zh(x,y+1))) //1
			flag[zh(x,y+1)] = 1;
		if(y>1 && g1[x][y-1]==1 && legal(zh(x,y),zh(x,y-1)))
			flag[zh(x,y-1)] = 1;
		if(x<n && g2[x][y]==1 && legal(zh(x,y),zh(x+1,y)))
			flag[zh(x+1,y)] = 1;
		if(x>1 && g2[x-1][y]==1 && legal(zh(x,y),zh(x-1,y)))
			flag[zh(x-1,y)] = 1;
		int nx=x,ny=y; //2
		while(ny<m)
		{
			if(g1[nx][ny]==2 && legal(zh(x,y),zh(nx,ny+1)))
				flag[zh(nx,ny+1)] = 1;
			else break;
			ny++;
			if(col[zh(nx,ny)]) break;
		}
		nx = x, ny = y;
		while(nx<n)
		{
			if(g2[nx][ny]==2 && legal(zh(x,y),zh(nx+1,ny)))
				flag[zh(nx+1,ny)] = 1;
			else break;
			nx++;
			if(col[zh(nx,ny)]) break;
		}
		nx = x, ny = y;
		while(ny>1)
		{
			if(g1[nx][ny-1]==2 && legal(zh(x,y),zh(nx,ny-1)))
				flag[zh(nx,ny-1)] = 1;
			else break;
			ny--;
			if(col[zh(nx,ny)]) break;
		}
		nx = x, ny = y;
		while(nx>1)
		{
			if(g2[nx-1][ny]==2 && legal(zh(x,y),zh(nx-1,ny)))
				flag[zh(nx-1,ny)] = 1;
			else break;
			nx--;
			if(col[zh(nx,ny)]) break;
		}
		bfs(x,y); //3
		for(int i=1;i<=n*m;i++)
			ans += flag[i];
		write(ans); puts("");
	}
}

void addedge(int x,int y)
{
	nex[++ee] = h[x], to[ee] = y, h[x] = ee;
}

void subtask2()
{
	for(int i=1;i<=n&&scanf("%s",ch+1);i++)
		for(int j=1;j<m;j++)
			if(ch[j]=='1')
				addedge(zh(i,j),zh(i,j+1)), addedge(zh(i,j+1),zh(i,j));
	for(int i=1;i<n&&scanf("%s",ch+1);i++)
		for(int j=1;j<=m;j++)
			if(ch[j]=='1')
				addedge(zh(i,j),zh(i+1,j)), addedge(zh(i+1,j),zh(i,j));
	while(q--)
	{
		ans = 0;
		int c=read()+1,v=read(),x=read(),y=read();
		col[zh(x,y)] = c, lv[zh(x,y)] = v;
		for(int i=h[zh(x,y)];i;i=nex[i])
			if(legal(zh(x,y),to[i]))
				ans++;
		write(ans); puts("");
	}
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	Q = read();
	while(Q--)
	{
		n = read(), m = read(), q = read();
		init_();
		if(n*m<=10000)
			subtask1();
		else
			subtask2();
	}
	
	return 0;
}
