#include <bits/stdc++.h>
using namespace std;
char l[5005][5005],r[5005][5005],u[5005][5005],d[5005][5005];
char col[5005][5005];
int lv[5005][5005],w[5005][5005],ans,n,m,q,x,y;
int dx[]={0,0,0,1,-1};
int dy[]={0,1,-1,0,0};
int read1()
{
	char cc=getchar();
	while(!(cc>=48&&cc<=57))
	{
		if(cc=='-')
		{
			break;
		}
		cc=getchar();
	}
	bool f=false;
	int s=0;
	if(cc=='-')
	{
		f=true;
	}
	else
	{
		s=cc-48;
	}
	while(1)
	{
		cc=getchar();
		if(cc>=48&&cc<=57)
		{
			s=s*10+cc-48;
		}
		else
		{
			break;
		}
	}
	if(f==true)
	{
		s=-s;
	}
	return s;
}
bool pd(int u,int v)
{
	if(u>=1&&u<=n&&v>=1&&v<=m)
	{
		return true;
	}
	return false;
}
bool cmp(int u1,int v1,int u2,int v2)
{
	if(col[u2][v2]=='0')
	{
		return true;
	}
	if(col[u1][v1]!=col[u2][v2]&&lv[u1][v1]>=lv[u2][v2])
	{
		return true;
	}
	else
	{
		return false;
	}
}
void D1(int u,int v)
{
	if(pd(u,v)&&cmp(x,y,u,v))
	{
		ans=ans+w[u][v];
		w[u][v]=0;
	}
}
char ask(int u1,int v1,int u2,int v2)
{
	if(u2==u1+1)
	{
		return d[u1][v1];
	}
	else if(u2==u1-1)
	{
		return u[u1][v1];
	}
	else if(v2==v1+1)
	{
		return r[u1][v1];
	}
	else if(v2==v1-1)
	{
		return l[u1][v1];
	}
}
void D2(int u,int v,int dx,int dy)
{
	if(pd(u,v))
	{
		if(col[u][v]!='0')
		{
			if(cmp(x,y,u,v))
			{
		    	ans=ans+w[u][v];
		    	w[u][v]=0;
		    }
			return;
		}
		else 
		{
			ans=ans+w[u][v];
			w[u][v]=0;
			if(ask(u,v,u+dx,v+dy)=='2')
			{
		    	D2(u+dx,v+dy,dx,dy);
		    }
		}
	}
	else
	{
		return;
	}
}
void bfs(int i,int j)
{
	for(int k=1;k<=4;k++)
	{
		int u=i+dx[k],v=j+dy[k];
		if(pd(u,v)&&ask(i,j,u,v)=='3'&&w[u][v]==1)
		{
			if(col[u][v]!='0')
			{
				if(cmp(x,y,u,v))
				{
			    	ans=ans+w[u][v];
			    	w[u][v]=0;
			    }
			}
			else
			{
				ans=ans+w[u][v];
				w[u][v]=0;
				bfs(u,v);
			}
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>q;
		for(int i=0;i<=n+1;i++)
		{
			for(int j=0;j<=m+1;j++)
			{
				l[i][j]=r[i][j]=u[i][j]=d[i][j]=col[i][j]='0';
				lv[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			string tmp;
			cin>>tmp;
			for(int j=1;j<=m-1;j++)
			{
				r[i][j]=tmp[j-1];
				l[i][j+1]=tmp[j-1];
			}
		}
		for(int i=1;i<=n-1;i++)
		{
			string tmp;
			cin>>tmp;
			for(int j=1;j<=m;j++)
			{
				u[i+1][j]=tmp[j-1];
				d[i][j]=tmp[j-1];
			}
		}
		for(int t=1;t<=q;t++)
		{
			for(int i=0;i<=n+1;i++)
			{
				for(int j=0;j<=m+1;j++)
				{
					w[i][j]=1;
				}
			}
			int c,l;
			c=read1();
			l=read1();
			x=read1();
			y=read1();
			col[x][y]=char(c+'1');
			lv[x][y]=l;
			ans=0;
			bfs(x,y);
			for(int i=1;i<=4;i++)
			{
				int u=x+dx[i];
				int v=y+dy[i];
				char opt=ask(x,y,u,v);
				if(opt=='1')
				{
					D1(u,v);
				}
				else if(opt=='2')
				{
					D2(u,v,dx[i],dy[i]);
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
//32 points
/*
1
3 3 5
13
22
23
010
233
0 1 2 3
1 2 2 1
1 3 1 2
0 2 3 2
1 3 2 2

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
