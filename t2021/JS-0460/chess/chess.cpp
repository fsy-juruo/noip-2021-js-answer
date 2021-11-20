#include <bits/stdc++.h>
using namespace std;
int T;
int n,m,q;
char a[7005][7005][2];
int b[7005][7005];
int coll[100005],levl[100005],dx[100005],dy[100005];
void ling()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			b[i][j]=0;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		ling();
		cin>>n>>m>>q;
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m-1;k++)
				cin>>a[j][k][0];
		for(int j=1;j<=n-1;j++)
			for(int k=1;k<=m;k++)
				cin>>a[j][k][1];
		for(int j=1;j<=q;j++)
		{
			int ans=0;
			scanf("%d%d%d%d",&coll[j],&levl[j],&dx[j],&dy[j]);
			b[dx[j]][dy[j]]=j;
			int tx,ty;
			tx=dx[j],ty=dy[j];
			tx=dx[j]-1;
			if(tx>0&&ty>0&&tx<=n&&ty<=m)
			{
				if(a[tx][ty][1]=='1')
					if(b[tx][ty]==0)
						ans++;
					else 
						if(coll[b[tx][ty]]!=coll[j]&&levl[b[tx][ty]]<=levl[j])
							ans++;
				if(a[tx][ty][1]=='2')
					while(tx>1)
					{
						if(a[tx][ty][1]!='2')
							break;
						if(b[tx][ty]==0)
							ans++;
						else
						{
							if(coll[b[tx][ty]]!=coll[j]&&levl[b[tx][ty]]<=levl[j])
								ans++;
							break;
						}
						
						tx--;
					}
			}
			tx=dx[j],ty=dy[j]+1;
			if(tx>0&&ty>0&&tx<=n&&ty<=m)
			{
				if(a[dx[j]][dy[j]][0]=='1')
					if(b[tx][ty]==0)
						ans++;
					else 
						if(coll[b[tx][ty]]!=coll[j]&&levl[b[tx][ty]]<=levl[j])
							ans++;
				if(a[dx[j]][dy[j]][0]=='2')
				{
					while(ty<=m)
					{
						if(b[tx][ty]==0)
							ans++;
						else
						{
							if(coll[b[tx][ty]]!=coll[j]&&levl[b[tx][ty]]<=levl[j])
								ans++;
							break;
						}
						if(a[tx][ty][0]!='2')
							break;
						ty++;
					}
				}
			}
			tx=dx[j]+1,ty=dy[j];
			if(tx>0&&ty>0&&tx<=n&&ty<=m)
			{
				if(a[dx[j]][dy[j]][1]=='1')
					if(b[tx][ty]==0)
						ans++;
					else 
						if(coll[b[tx][ty]]!=coll[j]&&levl[b[tx][ty]]<=levl[j])
							ans++;
				if(a[dx[j]][dy[j]][1]=='2')
				{
					while(tx<=n)
					{
						if(b[tx][ty]==0)
							ans++;
						else
						{
							if(coll[b[tx][ty]]!=coll[j]&&levl[b[tx][ty]]<=levl[j])
								ans++;
							break;
						}
						tx++;
						if(a[tx][ty][1]!='2')
							break;
					}
				}
			}
			tx=dx[j],ty=dy[j]-1;
			if(tx>0&&ty>0&&tx<=n&&ty<=m)
			{
				if(a[tx][ty][0]=='1')
					if(b[tx][ty]==0)
						ans++;
					else 
						if(coll[b[tx][ty]]!=coll[j]&&levl[b[tx][ty]]<=levl[j])
							ans++;
				if(a[tx][ty][0]=='2')
				{
					while(ty>0)
					{
						if(a[tx][ty][0]!='2')
							break;
						if(b[tx][ty]==0)
							ans++;
						else
						{
							if(coll[b[tx][ty]]!=coll[j]&&levl[b[tx][ty]]<=levl[j])
								ans++;
							break;
						}
						ty--;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
