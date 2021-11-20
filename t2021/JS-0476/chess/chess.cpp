#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int s=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		s=(s<<3)+(s<<1)+(c^48);
		c=getchar();
	}
	return s;
}
inline void print(int x)
{
	if(x>=10)
	{
		print(x/10);
	}
	putchar(x%10+'0');
	return ;
}
struct node
{
	int x,y;
	int dir;
	int type;
};
bool st;
int T;
int n,m,q;
int t1,t2,x,y;
string s;
int dx[5]={0,-1,0,1,0};
int dy[5]={0,0,-1,0,1};
int col[5005][5005];
int lv[5005][5005];
int a[5005][5005];
int b[5005][5005];
bool vis[5005][5005];
bool ed;
void bfs()
{
	int ans=0;
	queue<node> q;
	node temp;
	temp.x=x,temp.y=y,temp.type=-1;
	temp.dir=-1;
	q.push(temp);
	vis[x][y]=1;
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		if(t.type==1) continue;
		for(int i=1;i<=4;i++)
		{
			int nx=t.x+dx[i];
			int ny=t.y+dy[i];
			if(nx<1||nx>n||ny<1||ny>m) continue;
			if(vis[nx][ny]==1) continue;
			if(t.type!=-1)
			{
				switch(i)
				{
					case 1:
					{
						if(b[nx][ny]!=t.type||b[nx][ny]==0) continue;
						if(t.type==2&&t.dir!=i) continue;
						if(col[nx][ny]!=-1&&lv[nx][ny]!=-1)
						{
							if(t1!=col[nx][ny]&&t2>=lv[nx][ny])
							{
								vis[nx][ny]=1;
								ans++;
							}
							continue;
						}
						vis[nx][ny]=1;
						q.push((node){nx,ny,1,b[nx][ny]});
						ans++;
						break;
					}
					case 2:
					{
						if(a[nx][ny]!=t.type||a[nx][ny]==0) continue;
						if(t.type==2&&t.dir!=i) continue;
						if(col[nx][ny]!=-1&&lv[nx][ny]!=-1)
						{
							if(t1!=col[nx][ny]&&t2>=lv[nx][ny])
							{
								vis[nx][ny]=1; 
								ans++;
							}
							continue;
						}
						vis[nx][ny]=1;
						q.push((node){nx,ny,2,a[nx][ny]});
						ans++;
						break;
					}
					case 3:
					{
						if(b[t.x][t.y]!=t.type||b[t.x][t.y]==0) continue;
						if(t.type==2&&t.dir!=i) continue;
						if(col[nx][ny]!=-1&&lv[nx][ny]!=-1)
						{
							if(t1!=col[nx][ny]&&t2>=lv[nx][ny])
							{
								vis[nx][ny]=1;
								ans++;
							}
							continue;
						}
						vis[nx][ny]=1;
						q.push((node){nx,ny,3,b[t.x][t.y]});
						ans++;
						break;
					}
					case 4:
					{
						if(a[t.x][t.y]!=t.type||a[t.x][t.y]==0) continue;
						if(t.type==2&&t.dir!=i) continue;
						if(col[nx][ny]!=-1&&lv[nx][ny]!=-1)
						{
							if(t1!=col[nx][ny]&&t2>=lv[nx][ny])
							{
								vis[nx][ny]=1; 
								ans++;
							}
							continue;
						}
						vis[nx][ny]=1;
						q.push((node){nx,ny,4,a[t.x][t.y]});
						ans++;
						break;
					}
					default:break;
				}
			}
			else
			{
				switch(i)
				{
					case 1:
					{
						if(b[nx][ny]==0) continue;
						if(col[nx][ny]!=-1&&lv[nx][ny]!=-1)
						{
							if(t1!=col[nx][ny]&&t2>=lv[nx][ny])
							{
								vis[nx][ny]=1;	 
								ans++;
							}
							continue;
						}
						vis[nx][ny]=1;
						q.push((node){nx,ny,1,b[nx][ny]});
						ans++;
						break;
					}
					case 2:
					{
						if(a[nx][ny]==0) continue;
						if(col[nx][ny]!=-1&&lv[nx][ny]!=-1)
						{
							if(t1!=col[nx][ny]&&t2>=lv[nx][ny])
							{
								vis[nx][ny]=1;
								ans++;
							}
							continue;
						}
						vis[nx][ny]=1;
						q.push((node){nx,ny,2,a[nx][ny]});
						ans++;
						break;
					}
					case 3:
					{
						if(b[t.x][t.y]==0) continue;
						if(col[nx][ny]!=-1&&lv[nx][ny]!=-1)
						{
							if(t1!=col[nx][ny]&&t2>=lv[nx][ny])
							{
								vis[nx][ny]=1;
								ans++;
							}
							continue;
						}
						vis[nx][ny]=1;
						q.push((node){nx,ny,3,b[t.x][t.y]});
						ans++;
						break;
					}
					case 4:
					{
						if(a[t.x][t.y]==0) continue;
						if(col[nx][ny]!=-1&&lv[nx][ny]!=-1)
						{
							if(t1!=col[nx][ny]&&t2>=lv[nx][ny])
							{
								vis[nx][ny]=1;
								ans++;
							}
							continue;
						}
						vis[nx][ny]=1;
						q.push((node){nx,ny,4,a[t.x][t.y]});
						ans++;
						break;
					}
					default:break;
				}
			}
		}
	}	
	print(ans);
	puts("");
	return ;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read(),m=read(),q=read();
		memset(col,-1,sizeof(col));
		memset(lv,-1,sizeof(lv));
		memset(a,-1,sizeof(a));
		memset(b,-1,sizeof(b));
		for(int i=1;i<=n;i++)
		{
			cin>>s;	
			for(int j=1;j<m;j++)
			{
				a[i][j]=s[j-1]-'0';
			}
		}
		for(int i=1;i<n;i++)
		{
			cin>>s;
			for(int j=1;j<=m;j++)
			{
				b[i][j]=s[j-1]-'0';	
			}	
		}
		while(q--)
		{
			memset(vis,0,sizeof(vis));
			t1=read(),t2=read(),x=read(),y=read();
			col[x][y]=t1;
			lv[x][y]=t2;
			bfs();
		}		
	}
	return 0;
}
