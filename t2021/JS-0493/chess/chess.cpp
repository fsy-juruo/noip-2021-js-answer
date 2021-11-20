#include<bits/stdc++.h>
using namespace std;
inline int f_read(void)
{
	int x=0,y=1;
	char c=getchar();
	while(c!='-'&&(c>'9'||c<'0'))
		c=getchar();
	if(c=='-')
		y=-1,c=getchar();
	while(c>='0'&&c<='9')
		x=x*10+c-'0',c=getchar();
	return x*y;
}
inline void f_write(int x)
{
	if(x==0)
	{
		putchar('0');
		return ;
	}
	if(x<0)
		putchar('-'),x=-x;
	string xx="";
	while(x)
		xx=xx+char(x%10+'0'),x/=10;
	for(int i=xx.size()-1;i>=0;i--)
		putchar(xx[i]); 
	return ;
}
int T,n,m,q,col,lvl,sx,sy,ans;
vector<string> r1,r2;
vector<vector<bool>> c,u,u2;
vector<vector<int>> lv;
string r;
inline void dfs(int x,int y,int rtp,int dir)
{
//	cout<<x<<' '<<y<<' '<<rtp<<' '<<dir<<" ##\n";
	if(x>0)//up 
	{
		int tp=r2[x-1][y]-'0';
		if(tp==1&&rtp==-1)
		{
			if((lv[x-1][y]==0||c[x-1][y]!=col&&lv[x-1][y]<=lvl))
				u[x-1][y]=true;
		}
		if(tp==2&&(rtp==2||rtp==-1))
		{
			if(rtp==-1||dir==1)
			{
				if((lv[x-1][y]==0||c[x-1][y]!=col&&lv[x-1][y]<=lvl))
				{
					u[x-1][y]=true;
					if(!c[x-1][y]!=col&&lv[x-1][y]<=lvl)
						dfs(x-1,y,2,1);
				}
			}
		}
		if(tp==3&&(rtp==3||rtp==-1))
		{
			if(!u2[x-1][y])
			{
				if((lv[x-1][y]==0||c[x-1][y]!=col&&lv[x-1][y]<=lvl))
				{
					u2[x-1][y]=true;
					u[x-1][y]=true;
					if(!c[x-1][y]!=col&&lv[x-1][y]<=lvl)
					dfs(x-1,y,3,-1);
				}
			}
		}
	}
//	cout<<"CHECK up\n";
	if(x<n-1)//down
	{
		int tp=r2[x][y]-'0';
		if(tp==1&&rtp==-1)
		{
			if((lv[x+1][y]==0||c[x+1][y]!=col&&lv[x+1][y]<=lvl))
				u[x+1][y]=true;
		}
		if(tp==2&&(rtp==2||rtp==-1))
		{
			if(rtp==-1||dir==2)
			{
				if((lv[x+1][y]==0||c[x+1][y]!=col&&lv[x+1][y]<=lvl))
				{
					u[x+1][y]=true;
					if(!c[x+1][y]!=col&&lv[x+1][y]<=lvl) 
					dfs(x+1,y,2,2);
				}
			}
		}
		if(tp==3&&(rtp==3||rtp==-1))
		{
			if(!u2[x+1][y])
			{
				if((lv[x+1][y]==0||c[x+1][y]!=col&&lv[x+1][y]<=lvl))
				{
					u2[x+1][y]=true;
					u[x+1][y]=true;
					if(!c[x+1][y]!=col&&lv[x+1][y]<=lvl)
						dfs(x+1,y,3,-1);
				}
			}
		}
	}
//	cout<<"CHECK down\n";
	if(y>0)//left
	{
		int tp=r1[x][y-1]-'0';
		if(tp==1&&rtp==-1)
		{
			if((lv[x][y-1]==0||c[x][y-1]!=col&&lv[x][y-1]<=lvl))
				u[x][y-1]=true;
		}
		if(tp==2&&(rtp==2||rtp==-1))
		{
			if(rtp==-1||dir==3)
			{
				if((lv[x][y-1]==0||c[x][y-1]!=col&&lv[x][y-1]<=lvl))
				{
					u[x][y-1]=true;
					if(!(c[x][y-1]!=col&&lv[x][y-1]<=lvl))
						dfs(x,y-1,2,3);
				}
			}
		}
		if(tp==3&&(rtp==3||rtp==-1))
		{
			if(!u2[x][y-1])
			{
				if((lv[x][y-1]==0||c[x][y-1]!=col&&lv[x][y-1]<=lvl))
				{
					u2[x][y-1]=true;
					u[x][y-1]=true;
					if(!(c[x][y-1]!=col&&lv[x][y-1]<=lvl))
						dfs(x,y-1,3,-1);
				}
			}
		}
	}
//	cout<<"CHECK left\n";
	if(y<m-1)//right
	{
		int tp=r1[x][y]-'0';
		if(tp==1&&rtp==-1)
		{
			if((lv[x][y+1]==0||c[x][y+1]!=col&&lv[x][y+1]<=lvl))
				u[x][y+1]=true;
		}
		if(tp==2&&(rtp==2||rtp==-1))
		{
			if(rtp==-1||dir==4)
			{
				if((lv[x][y+1]==0||c[x][y+1]!=col&&lv[x][y+1]<=lvl))
				{
					u[x][y+1]=true;
					if(!c[x][y+1]!=col&&lv[x][y+1]<=lvl)
						dfs(x,y+1,2,4);
				}
			}
		}
		if(tp==3&&(rtp==3||rtp==-1))
		{
			if(!u2[x][y+1])
			{
				if((lv[x][y+1]==0||c[x][y+1]!=col&&lv[x][y+1]<=lvl))
				{
					u2[x][y+1]=true;
					u[x][y+1]=true;
					if(! c[x][y+1]!=col&&lv[x][y+1]<=lvl) 
					dfs(x,y+1,3,-1);
				}
			}
		}
	}
//	cout<<"CHECK right\n";
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=f_read();
	while(T--)
	{
		n=f_read();
		m=f_read();
		vector<int> zero;
		zero.clear();
		for(int i=0;i<m+5;i++)
			zero.push_back(0);
		for(int i=0;i<n+5;i++)
			lv.push_back(zero);
		vector<bool> zro;
		zro.clear(); 
		for(int i=0;i<m+5;i++)
			zero.push_back(0);
		for(int i=0;i<n+5;i++)
		{
			c.push_back(zro);
			u.push_back(zro);
			u2.push_back(zro);
		}
		q=f_read();
		r1.clear();
		r2.clear();
		for(int i=1;i<=n;i++)
		{
			r="";
			for(int j=1;j<m;j++)
				r+=getchar();
			getchar();
			r1.push_back(r);
		}
		for(int i=1;i<n;i++)
		{
			r="";
			for(int j=1;j<=m;j++)
				r+=getchar();
			getchar();
			r2.push_back(r);
		}
		while(q--)
		{
			col=f_read();
			lvl=f_read();
			sx=f_read();
			sy=f_read();
			sx--;
			sy--;
			c[sx][sy]=col;
			lv[sx][sy]=lvl;
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
					u[i][j]=0,u2[i][j]=0;
			ans=0;
			u2[sx][sy]=true;
			dfs(sx,sy,-1,-1);
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
					ans+=u[i][j];
			f_write(ans);
			putchar('\n');
		}
	}
	return 0;
}

