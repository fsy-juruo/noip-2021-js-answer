#include<bits/stdc++.h>
using namespace std;
int t,n,m,q,a[5001][5001],b[5001][5001],c[5001][5001][2],x,y,has[5001][5001],ans,col,lv;
char ww;
void dfs1(int xx,int yy,int colo,int nc)
{
	if(xx>1)
	{
		if(b[xx-1][yy]==1&&c[xx-1][yy][nc]==0&&c[xx-1][yy][1-nc]<=c[x][y][nc])
		{
			ans++;
		}
	}
	if(xx<n)
	{
		if(b[xx][yy]==1&&c[xx+1][yy][nc]==0&&c[xx+1][yy][1-nc]<=c[x][y][nc])
		{
			ans++;
		}
	}
	if(yy>1)
	{
		if(a[xx][yy-1]==1&&c[xx][yy-1][nc]==0&&c[xx][yy-1][1-nc]<=c[x][y][nc])
		{
			ans++;
		}
	}
	if(yy<m)
	{
		if(a[xx][yy]==1&&c[xx][yy+1][nc]==0&&c[xx][yy+1][1-nc]<=c[x][y][nc])
		{
			ans++;
		}
	}
}
void dfs3(int xx,int yy,int colo,int nc,int z,int q)
{
//	cout<<xx<<' '<<yy<<endl;
	has[xx][yy]=colo;
	if(xx>1)
	{
		if(b[xx-1][yy]==3&&c[xx-1][yy][nc]==0&&c[xx-1][yy][1-nc]<=c[z][q][nc]&&has[xx-1][yy]!=colo)
		{
			ans++;
			if(c[xx-1][yy][1-nc]==0)
			{
				dfs3(xx-1,yy,colo,nc,z,q);
			}
			
		}
	}
	if(xx<n)
	{
		if(b[xx][yy]==3&&c[xx+1][yy][nc]==0&&c[xx+1][yy][1-nc]<=c[z][q][nc]&&has[xx+1][yy]!=colo)
		{
			ans++;
				if(c[xx+1][yy][1-nc]==0)
			{
				dfs3(xx+1,yy,colo,nc,z,q);
			}
		}
	}
	if(y>1)
	{
		if(a[xx][yy-1]==3&&c[xx][yy-1][nc]==0&&c[xx][yy-1][1-nc]<=c[z][q][nc]&&has[xx][yy-1]!=colo)
		{
	
			ans++;
				if(c[xx][yy-1][1-nc]==0)
			{

				dfs3(xx,yy-1,colo,nc,z,q);
			}
		}
	}
	if(y<m)
	{
		if(a[xx][yy]==3)
		if(a[xx][yy]==3&&c[xx][yy+1][nc]==0&&c[xx][yy+1][1-nc]<=c[z][q][nc]&&has[xx][yy+1]!=colo)
		{
			ans++;
			if(c[xx][yy+1][1-nc]==0)
			{
				dfs3(xx,yy+1,colo,nc,z,q);
			}
		}
	}
}
int main()
{
  freopen("chess.in","r",stdin);
  freopen("chess.out","w",stdout);
 	cin>>t;
 	for(int i=1;i<=t;i++)
	{
	 	cin>>n>>m>>q;
	 	for(int j=1;j<=n;j++)
	 	{
	 		for(int k=1;k<m;k++)
			{
			 	cin>>ww;
			 	a[j][k]=ww-'0';
			} 
		 }
		 for(int j=1;j<n;j++)
		 {
		 	for(int k=1;k<=m;k++)
		 	{
		 		cin>>ww;
		 		b[j][k]=ww-'0';
			 }
		 }
		 for(int j=1;j<=n;j++)
		 {
		 	for(int k=1;k<=m;k++)
		 	{
		 		c[j][k][0]=0;
		 		c[j][k][1]=0;
		 		has[j][k]=0;
			 }
		 }
		 for(int j=1;j<=q;j++)
		 {
		 	ans=0;
		 	cin>>col>>lv>>x>>y;
		 	c[x][y][col]=lv+1;
		 	dfs1(x,y,j,col);
		 	for(int k=x-1;k>=1;k--)
		 	{
		 		if(b[k][y]==2&&c[k][y][col]==0&&c[k][y][1-col]<=c[x][y][col])
				{
					ans++;
					has[k][y]=j;
					if(c[k][y][1-col]>0)
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
			for(int k=x+1;k<=n;k++)
			{
				if(b[k-1][y]==2&&c[k][y][col]==0&&c[k][y][1-col]<=c[x][y][col])
				{
					ans++;
					has[k][y]=j;
					if(c[k][y][1-col]>0)
					{
						break;
					}
				}
				else
				{
					break;
				}
				
			}
			for(int k=y-1;k>=1;k--)
			{
				if(a[x][k]==2&&c[x][k][col]==0&&c[x][k][1-col]<=c[x][y][col])
				{
					ans++;
					has[x][k]=j;
					if(c[x][k][1-col]>0)
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
			for(int k=y+1;k<=m;k++)
			{
				if(a[x][k-1]==2&&c[x][k][col]==0&&c[x][k][1-col]<=c[x][y][col])
				{
					ans++;
					has[x][k]=j;
					if(c[x][k][1-col]>0)
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
		 	dfs3(x,y,j,col,x,y);
		 	cout<<ans<<endl;
		 }
	} 
  return 0;
}