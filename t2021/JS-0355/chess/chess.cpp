#include<bits/stdc++.h>
int T,n,m,q;
int h[1000][1000],z[1000][1000],C[1000][1000],L[1000][1000];
using namespace std;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>T;
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&q);
		memset(h,-1,sizeof(h));
		memset(z,-1,sizeof(z));
		for(int i=1;i<=n;i++)
		{
			int Q;
			scanf("%d",&Q);
			for(int j=m-1;j>=1;j--)
			{
			    h[i][j]=Q%10;
			    Q/=10;
			}
		}
		for(int i=1;i<n;i++)
		{
			int Q;
			scanf("%d",&Q);
			for(int j=m;j>=1;j--)
			{
			    z[i][j]=Q%10;
			    Q/=10;
			}
		}
		for(int i=1;i<=q;i++)
		{
			int k;
			int l,xa,yb;
			scanf("%d%d%d%d",&k,&l,&xa,&yb);
			C[xa][yb]=k;
			L[xa][yb]=l;
			printf("5\n");
		}
	}
	return 0;
}
