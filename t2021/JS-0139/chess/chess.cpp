#include<bits/stdc++.h>
using namespace std;
bool st;
int T;
int n,m,q,lv,col,r,l;
int mp[5005][5005];
int ph[5005][5005],py[5005][5005];
int vis[5005][5005];
char c[5005];
bool ed;
int dx[5]={0,1,0,-1,0};
int dy[5]={0,0,1,0,-1}; 
bool check(int x,int y,int xx,int yy,int p)
{
	if(xx<1||xx>n||yy<1||yy>m)
		return false;
	if(x==xx)
	{
		if(y>yy)
		{
			int t=y;
			y=yy;
			yy=t;
		}
		if(ph[x][y]==p)return true; 
	}
	if(y==yy)
	{
		if(x>xx)
		{
			int t=x;
			x=xx;
			xx=t;
		}
		if(py[x][y]==p)return true; 
	}
	return false;
}
bool cp(int x,int y,int v)
{
	if(mp[x][y]*v<0&&abs(v)>=abs(mp[x][y]))return true;
	return false;
}
int dfs(int x,int y,int v)
{
	int s=0;
	vis[x][y]=1;
	for(int i=1;i<=4;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		if(vis[xx][yy])continue;
		if(check(x,y,xx,yy,3))
		{
			if(mp[xx][yy])
			{
				if(cp(xx,yy,v))s+=1,vis[xx][yy]=1;
			}
			else 
				s+=dfs(xx,yy,v);
		}
	}
	s++;
	return s;
}
int ct(int l,int r)
{
	int ss=0;
	for(int i=1;i<=4;i++)
	{
		int x=l,y=r;
		while(1)
		{
			int xx=x+dx[i],yy=y+dy[i];
			if(!check(x,y,xx,yy,2))break;
			if(mp[xx][yy])
			{
				if(cp(xx,yy,mp[l][r])&&!vis[xx][yy])ss++;
				break;
			}
			x=xx,y=yy; 
			if(!vis[xx][yy])ss++;
		}
	}
	return ss;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>T;
	while(T--)
	{
		//cout<<(&ed-&st)/1024.0/1024.0; 
		memset(mp,0,sizeof(mp));
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",&c);
		for(int j=0;j<m-1;j++)
			ph[i][j+1]=c[j]-'0';
	}
	for(int i=1;i<n;i++)
	{
		scanf("%s",&c);
		for(int j=0;j<m;j++)
			py[i][j+1]=c[j]-'0';
	}
	for(int i=1;i<=q;i++)
	{
		int ss=0;
		scanf("%d%d%d%d",&col,&lv,&r,&l);
		if(col==0)col=-1;
		mp[r][l]=col*lv;
		ss+=dfs(r,l,lv);ss-=1;int dd=ss;
		/*for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)cout<<vis[i][j];
			cout<<endl;
		}*/
		for(int i=1;i<=4;i++)
		{
			int xx=r+dx[i],yy=l+dy[i];
			if(check(r,l,xx,yy,1)&&(cp(xx,yy,lv)||!mp[xx][yy])&&!vis[xx][yy])
				ss++;
		} 
		//vis[r][l]=1;
		ss+=ct(r,l);
		if(dd==0)
			vis[r][l]=0;
		else
			memset(vis,0,sizeof(vis));
		printf("%d\n",ss);
	}
	}
	return 0;
}
/*
2
2 3 4
22
33
123
0 2 1 2
0 1 2 1
1 2 1 3
0 3 2 2
3 2 3
3
1
3
32
32
0 2 1 2
1 2 3 2
0 1 2 2

*/
