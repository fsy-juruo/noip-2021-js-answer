#include<bits/stdc++.h>
using namespace std;
					int f[1000006][3];
					bool zou[1001][1001];
					char tu[1001][1001][4];
		//1ÉÏ£¬2ÏÂ£¬3×ó£¬4ÓÒ 
		int tuu[1001][1001];
void read(int &x)
{
	x=0;
	int y=1;
	char a=getchar();
	while(a>'9'||a<'0')
	{
		if(a=='-')y=-1;
		a=getchar();
	}
	while(a<='9'&&a>='0')
	{
		x*=10;
		x+=a-'0';
		a=getchar();
	}
	x*=y;
}
int n,m,q;
int T;
int x,y,lv,col;
int dx[5]={0,-1,1,0,0},dy[5]={0,0,0,-1,1};
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	read(T);
	for(int t=1;t<=T;++t)
	{
		read(n),read(m),read(q); 
		memset(tu,0,sizeof(tu));
		memset(tuu,0,sizeof(tu));
		for(int i=1;i<=n;++i)
		for(int j=1;j<=m-1;++j)
		tu[i][j][4]=getchar(),tu[i][j+1][3]=tu[i][j][4];
		for(int i=1;i<=n-1;++i)
		for(int j=1;j<=m;++j)
		tu[i][j][2]=getchar(),tu[i][j+1][1]=tu[i][j][2];
		for(int i=1;i<=q;++i)
		{
			int ans=0;
			read(col),read(lv),read(x),read(y);	
			tuu[x][y]=col*y;
			for(int jjj=1;jjj<5;++jjj)
			if(!tuu[x+dx[jjj]][y+dy[jjj]]&&(x+dx[jjj]>0)&&(x+dx[jjj]<=m)&&(y+dy[jjj]>0)&&(y+dy[jjj]<=n))
			{
				if(tu[x][y][jjj]=='1')
				{
					if(tuu[x+dx[jjj]][y+dy[jjj]]==0)
					{
						ans++;
						continue;
					}
					if(tuu[x][y]*tuu[x+dx[jjj]][y+dy[jjj]]<0&&abs(tuu[x][y])>abs(tuu[x+dx[jjj]][y+dy[jjj]]))
					ans++;
				}
				if(tu[x][y][jjj]=='2')
				{
					if(dx[jjj]!=0)
					{
						int c=x+dx[jjj];
						while(tuu[c][y]==0)
						{
							ans++;
							c+=dx[jjj];
						}
						if(tuu[x][y]*tuu[x+dx[jjj]][y+dy[jjj]]<0&&abs(tuu[x][y])>abs(tuu[x+dx[jjj]][y+dy[jjj]]))
						ans++;
					}
					else
					{
						int c=y+dy[jjj];
						while(tuu[x][c]==0)
						{
							ans++;
							c+=dy[jjj];
						}
						if(tuu[x][y]*tuu[x+dx[jjj]][y+dy[jjj]]<0&&abs(tuu[x][y])>abs(tuu[x+dx[jjj]][y+dy[jjj]]))
						ans++;
					}
				}
				if(tu[x][y][jjj]=='3')
				{
					

					memset(zou,0,sizeof(zou));
					int front,rear;
					front=1,rear=1;
					f[front][0]=x,f[front][1]=y;
					while(front<=rear)
					{
						int sx=f[front][0],sy=f[front][1];
						zou[sx][sy]=true;
						for(int i=0;i<4;++i)
						{
							int tx=sx+dx[i],ty=sy+dy[i];
							if(!zou[tx][ty]&&tu[tx][ty][i]=='3'&&(x+dx[jjj]>0)&&(x+dx[jjj]<=m)&&(y+dy[jjj]>0)&&(y+dy[jjj]<=n))
							{
								f[++rear][0]=tx,f[rear][1]=ty;
								ans++;
							}
						}
						front++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

