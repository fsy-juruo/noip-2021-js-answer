#include<cstdio>
#include<cctype>
#include<cstring>
using namespace std;
int qr()
{
	int f=1,r=0;
	char ch;
	do
		ch=getchar();
	while (!isdigit(ch)&&ch!='-');
	if (ch=='-')
		f=-1;
	else
		r=ch-48;
	ch=getchar();
	while (isdigit(ch))
	{
		r=r*10+ch-48;
		ch=getchar();
	}
	return f*r;
}
struct node
{
	int u1,d2,l3,r4,colours,levels;
};
node a[200005];/*number=(row-1)*n+column*/
char strs[100005];
int n,m,dx[5]={0,-1,1,0,0},dy[5]={0,0,0,-1,1},
levs;
bool vis[4][200005],col;
int getnum(int rows,int columns)
{
	return (rows-1)*m+columns;
}
void dfs(int x,int y,int roadnum,int predir)
{
	int i,tx,ty;
	switch (roadnum)
	{
		case -1:
			for (i=1;i<=4;i++)
			{
				tx=x+dx[i];
				ty=y+dy[i];
				switch (i)
				{
					case 1:
						if ((a[getnum(x,y)].u1==1&&a[getnum(tx,ty)].levels==0)
						||(a[getnum(x,y)].u1&&a[getnum(tx,ty)].colours
						!=col&&vis[a[getnum(x,y)].u1][getnum(tx,ty)]==0
						&&levs>=a[getnum(tx,ty)].levels&&a[getnum(tx,ty)].levels))
							vis[0][getnum(tx,ty)]=vis[a[getnum(x,y)].u1][getnum(tx,ty)]=1;
						else
							if (a[getnum(x,y)].u1&&vis[a[getnum(x,y)].u1][getnum(tx,ty)]==0
							&&(a[getnum(tx,ty)].levels==0))
							{
								vis[0][getnum(tx,ty)]=vis[a[getnum(x,y)].u1][getnum(tx,ty)]=1;
								dfs(tx,ty,a[getnum(x,y)].u1,1);
							}
						break;
					case 2:
						if ((a[getnum(x,y)].d2==1&&a[getnum(tx,ty)].levels==0)
						||(a[getnum(x,y)].d2&&a[getnum(tx,ty)].colours
						!=col&&vis[a[getnum(x,y)].d2][getnum(tx,ty)]==0
						&&levs>=a[getnum(tx,ty)].levels&&a[getnum(tx,ty)].levels))
							vis[0][getnum(tx,ty)]=vis[a[getnum(x,y)].d2][getnum(tx,ty)]=1;
						else
							if (a[getnum(x,y)].d2&&vis[a[getnum(x,y)].d2][getnum(tx,ty)]==0
							&&(a[getnum(tx,ty)].levels==0))
							{
								vis[0][getnum(tx,ty)]=vis[a[getnum(x,y)].d2][getnum(tx,ty)]=1;
								dfs(tx,ty,a[getnum(x,y)].d2,2);
							}
						break;
					case 3:
						if ((a[getnum(x,y)].l3==1&&a[getnum(tx,ty)].levels==0)
						||(a[getnum(x,y)].l3&&a[getnum(tx,ty)].colours
						!=col&&vis[a[getnum(x,y)].l3][getnum(tx,ty)]==0
						&&levs>=a[getnum(tx,ty)].levels&&a[getnum(tx,ty)].levels))
							vis[0][getnum(tx,ty)]=vis[a[getnum(x,y)].l3][getnum(tx,ty)]=1;
						else
							if (a[getnum(x,y)].l3&&vis[a[getnum(x,y)].l3][getnum(tx,ty)]==0
							&&(a[getnum(tx,ty)].levels==0))
							{
								vis[0][getnum(tx,ty)]=vis[a[getnum(x,y)].l3][getnum(tx,ty)]=1;
								dfs(tx,ty,a[getnum(x,y)].l3,3);
							}
						break;
					case 4:
						if ((a[getnum(x,y)].r4==1&&a[getnum(tx,ty)].levels==0)
						||(a[getnum(x,y)].r4&&a[getnum(tx,ty)].colours
						!=col&&levs>=a[getnum(tx,ty)].levels&&vis[a[getnum(x,y)].r4][getnum(tx,ty)]==0
						&&a[getnum(tx,ty)].levels))
							vis[0][getnum(tx,ty)]=vis[a[getnum(x,y)].r4][getnum(tx,ty)]=1;
						else
							if (a[getnum(x,y)].r4&&vis[a[getnum(x,y)].r4][getnum(tx,ty)]==0
							&&(a[getnum(tx,ty)].levels==0))
							{
								vis[0][getnum(tx,ty)]=vis[a[getnum(x,y)].r4][getnum(tx,ty)]=1;
								dfs(tx,ty,a[getnum(x,y)].r4,4);
							}
						break;
				}
			}
			break;
		case 2:
			switch (predir)
			{
				case 1:
					for (i=x;i>=2;i--)
					{
						if (a[getnum(i,y)].u1==2)
						{
							if (a[getnum(i-1,y)].levels&&
							a[getnum(i-1,y)].colours
							!=col&&levs>=a[getnum(i-1,y)].levels
							&&vis[2][getnum(i-1,y)]==0)
							{
								vis[0][getnum(i-1,y)]=vis[2][getnum(i-1,y)]=1;
								break;
							}
							if (!a[getnum(i-1,y)].levels&&vis[2][getnum(i-1,y)]==0)
								vis[0][getnum(i-1,y)]=vis[2][getnum(i-1,y)]=1;
						}
						else
							break;
					}
					break;
				case 2:
					for (i=x;i<n;i++)
					{
						if (a[getnum(i,y)].d2==2)
						{
							if (a[getnum(i+1,y)].levels&&
							a[getnum(i+1,y)].colours
							!=col&&levs>=a[getnum(i+1,y)].levels
							&&vis[2][getnum(i+1,y)]==0)
							{
								vis[0][getnum(i+1,y)]=vis[2][getnum(i+1,y)]=1;
								break;
							}
							if (!a[getnum(i+1,y)].levels&&vis[2][getnum(i+1,y)]==0)
								vis[0][getnum(i+1,y)]=vis[2][getnum(i+1,y)]=1;
						}
						else
							break;
					}
					break;
				case 3:
					for (i=y;i>=2;i--)
					{
						if (a[getnum(x,i)].l3==2)
						{
							if (a[getnum(x,i-1)].levels&&
							a[getnum(x,i-1)].colours
							!=col&&levs>=a[getnum(x,i-1)].levels
							&&vis[2][getnum(x,i-1)]==0)
							{
								vis[0][getnum(x,i-1)]=vis[2][getnum(x,i-1)]=1;
								break;
							}
							if (!a[getnum(x,i-1)].levels&&vis[2][getnum(x,i-1)]==0)
								vis[0][getnum(x,i-1)]=vis[2][getnum(x,i-1)]=1;
						}
						else
							break;
					}
					break;
				case 4:
					for (i=y;i<m;i++)
					{
						if (a[getnum(x,i)].r4==2)
						{
							if (a[getnum(x,i+1)].levels&&
							a[getnum(x,i+1)].colours
							!=col&&levs>=a[getnum(x,i+1)].levels
							&&vis[2][getnum(x,i+1)]==0)
							{
								vis[0][getnum(x,i+1)]=vis[2][getnum(x,i+1)]=1;
								break;
							}
							if (!a[getnum(x,i+1)].levels&&vis[2][getnum(x,i+1)]==0)
								vis[0][getnum(x,i+1)]=vis[2][getnum(x,i+1)]=1;
						}
						else
							break;
					}
					break;
			}
			break;
		case 3:
			for (i=1;i<=4;i++)
			{
				tx=x+dx[i];
				ty=y+dy[i];
				switch (i)
				{
					case 1:
						if (a[getnum(x,y)].u1==3)
						{
							if (a[getnum(tx,ty)].colours
							!=col&&levs>=a[getnum(tx,ty)].levels&&vis[3][getnum(tx,ty)]==0
							&&a[getnum(tx,ty)].levels)
								vis[0][getnum(tx,ty)]=vis[3][getnum(tx,ty)]=1;
							else
								if (a[getnum(tx,ty)].levels==0&&vis[3][getnum(tx,ty)]==0)
								{
									vis[0][getnum(tx,ty)]=vis[3][getnum(tx,ty)]=1;
									dfs(tx,ty,3,1);
								}
						}
						break;
					case 2:
						if (a[getnum(x,y)].d2==3)
						{
							if (a[getnum(tx,ty)].colours
							!=col&&levs>=a[getnum(tx,ty)].levels&&vis[3][getnum(tx,ty)]==0
							&&a[getnum(tx,ty)].levels)
								vis[0][getnum(tx,ty)]=vis[3][getnum(tx,ty)]=1;
							else
								if (a[getnum(tx,ty)].levels==0&&vis[3][getnum(tx,ty)]==0)
								{
									vis[0][getnum(tx,ty)]=vis[3][getnum(tx,ty)]=1;
									dfs(tx,ty,3,2);
								}
						}
						break;
					case 3:
						if (a[getnum(x,y)].l3==3)
						{
							if (a[getnum(tx,ty)].colours
							!=col&&levs>=a[getnum(tx,ty)].levels&&vis[3][getnum(tx,ty)]==0
							&&a[getnum(tx,ty)].levels)
								vis[0][getnum(tx,ty)]=vis[3][getnum(tx,ty)]=1;
							else
								if (a[getnum(tx,ty)].levels==0&&vis[3][getnum(tx,ty)]==0)
								{
									vis[0][getnum(tx,ty)]=vis[3][getnum(tx,ty)]=1;
									dfs(tx,ty,3,3);
								}
						}
						break;
					case 4:
						if (a[getnum(x,y)].r4==3)
						{
							if (a[getnum(tx,ty)].colours
							!=col&&levs>=a[getnum(tx,ty)].levels&&vis[3][getnum(tx,ty)]==0
							&&a[getnum(tx,ty)].levels)
								vis[0][getnum(tx,ty)]=vis[3][getnum(tx,ty)]=1;
							else
								if (a[getnum(tx,ty)].levels==0&&vis[3][getnum(tx,ty)]==0)
								{
									vis[0][getnum(tx,ty)]=vis[3][getnum(tx,ty)]=1;
									dfs(tx,ty,3,4);
								}
						}
						break;
				}
			}
			break;
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T,i,j,q,sx,sy,ans;
	T=qr();
	while (T--)
	{
		n=qr();
		m=qr();
		q=qr();
		for (i=1;i<=n;i++)
		{
			scanf("%s",&strs);
			for (j=0;j<m-1;j++)
				a[getnum(i,j+1)].r4=a[getnum(i,j+2)].l3
				=strs[j]-48;
		}
		for (i=1;i<n;i++)
		{
			scanf("%s",&strs);
			for (j=0;j<m;j++)
				a[getnum(i,j+1)].d2=a[getnum(i+1,j+1)].u1
				=strs[j]-48;
		}
		for (i=1;i<=q;i++)
		{
			col=qr();
			levs=qr();
			sx=qr();
			sy=qr();
			a[(sx-1)*m+sy].levels=levs;
			a[(sx-1)*m+sy].colours=col;
			memset(vis,0,sizeof(vis));
			vis[1][getnum(sx,sy)]
			=vis[2][getnum(sx,sy)]
			=vis[3][getnum(sx,sy)]=1;
			dfs(sx,sy,-1,-1);
			ans=0;
			for (j=1;j<=n*m;j++)
				ans+=vis[0][j];
			printf("%d\n",ans);
		}
	}
	return 0;
}
