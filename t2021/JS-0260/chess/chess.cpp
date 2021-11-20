#include<bits/stdc++.h>
using namespace std;
int t,n,m,q,cnt;
int eatx;
int eaty;
int d[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
string s;
struct chess{
	int sta;
	int rank;
	int wu;
	int wd;
	int wl;
	int wr;
	bool flag;
	bool res;
}a[5005][5005];
struct che{
	int col;
	int lev;
	int x;
	int y;
}b[200005];
void dfs(int x,int y,int col,int lev,int way,int dire)
{ 
	if(a[x][y].sta!=-1)
	{
		if(a[x][y].sta==col||a[x][y].rank>lev)
		  return;
		else
		{
			eatx=x;
		    eaty=y;
		    a[x][y].res=1;
		    return;
		}	  
	}
	a[x][y].res=1;
	if(way==1)
	  return;
	if(way==2)
	{
		if(dire==0&&a[x][y].wu==2)
		  dfs(x-1,y,col,lev,2,0);
		if(dire==1&&a[x][y].wl==2)
		  dfs(x,y-1,col,lev,2,1);
		if(dire==2&&a[x][y].wd==2)
		  dfs(x+1,y,col,lev,2,2);
		if(dire==3&&a[x][y].wr==2)
		  dfs(x,y+1,col,lev,2,3);
	}
	if(way==3)
	{
		a[x][y].flag=1;
		if(a[x][y].wu==3&&!a[x-1][y].flag)
			dfs(x-1,y,col,lev,3,dire);
		if(a[x][y].wl==3&&!a[x][y-1].flag)
			dfs(x,y-1,col,lev,3,dire);
		if(a[x][y].wd==3&&!a[x+1][y].flag)
			dfs(x+1,y,col,lev,3,dire);
		if(a[x][y].wr==3&&!a[x][y+1].flag)
			dfs(x,y+1,col,lev,3,dire);	  
	}
}
void solve(int x,int y,int col,int lev)
{
	if(a[x][y].wu!=0)
	  dfs(x-1,y,col,lev,a[x][y].wu,0);
	if(a[x][y].wl!=0)
	  dfs(x,y-1,col,lev,a[x][y].wl,1);
	if(a[x][y].wd!=0)
	  dfs(x+1,y,col,lev,a[x][y].wd,2);
	if(a[x][y].wr!=0)
	  dfs(x,y+1,col,lev,a[x][y].wr,3);
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&t);
	for(int p=1;p<=t;p++)
	{
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;i++)
	    	for(int j=1;j<=m;j++)
	    	{
	    		a[i][j].rank=-1;
	    		a[i][j].sta=-1;
	    		a[i][j].wd=a[i][j].wu=a[i][j].wl=a[i][j].wr=0;
			}
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			for(int j=0;j<s.size();j++)
			{
				a[i][j+1].wr=s[j]-'0';
				a[i][j+2].wl=s[j]-'0';
			}
		}
		for(int i=1;i<n;i++)
		{
			cin>>s;
			for(int j=0;j<s.size();j++)
			{
				a[i][j+1].wd=s[j]-'0';
				a[i+1][j+1].wu=s[j]-'0';
			}
		}	
		for(int i=1;i<=q;i++)
		{
			eatx=eaty=0;
			for(int j=1;j<=n;j++)
		 	   for(int k=1;k<=m;k++)
		  	      a[j][k].res=0;
			scanf("%d%d%d%d",&b[i].col,&b[i].lev,&b[i].x,&b[i].y);
			cnt=0;
			solve(b[i].x,b[i].y,b[i].col,b[i].lev);
			a[b[i].x][b[i].y].res=0;
			for(int j=1;j<=n;j++)
		  	    for(int k=1;k<=m;k++)
		        	if(a[j][k].res)
		      			cnt++;
			printf("%d\n",cnt);
			if(eatx!=0)
			{
				a[eatx][eaty].rank=-1;
				a[eatx][eaty].sta=-1;
			}
			a[b[i].x][b[i].y].sta=b[i].col;
			a[b[i].x][b[i].y].rank=b[i].lev;
		}
	}
	
	return 0;
}

