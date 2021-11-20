#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,m,q;
vector<int>b[N],a[N],r[N],c[N],vis[N];
char s[N];
queue<int>qx,qy;
int ok(int vb,int va,int x,int y)
{
	if(b[x][y]==-1)
		return 1;
	else if(b[x][y]==vb)
		return 0;
	else if(a[x][y]>va)
		return 0;
	else
		return 2;
}
int cal(int x,int y)
{
	int vb=b[x][y],va=a[x][y],px,py;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			vis[i][j]=0;
	while(qx.size())
		qx.pop();
	while(qy.size())
		qy.pop();
	vis[x][y]=1;
	qx.push(x),qy.push(y);
	while(qx.size())
	{
		int i=qx.front(),j=qy.front(),z;
		qx.pop(),qy.pop();
		if(i&&r[i-1][j]==3&&!vis[i-1][j])
		{
			z=ok(vb,va,i-1,j);
			if(z)
				vis[i-1][j]=1;
			if(z==1)
				qx.push(i-1),qy.push(j);
		}
		if(i<n&&r[i][j]==3&&!vis[i+1][j])
		{
			z=ok(vb,va,i+1,j);
			if(z)
				vis[i+1][j]=1;
			if(z==1)
				qx.push(i+1),qy.push(j);
		}
		if(j&&c[i][j-1]==3&&!vis[i][j-1])
		{
			z=ok(vb,va,i,j-1);
			if(z)
				vis[i][j-1]=1;
			if(z==1)
				qx.push(i),qy.push(j-1);
		}
		if(j<m&&c[i][j]==3&&!vis[i][j+1])
		{
			z=ok(vb,va,i,j+1);
			if(z)
				vis[i][j+1]=1;
			if(z==1)
				qx.push(i),qy.push(j+1);
		}
	}
	if(x&&r[x-1][y]==1&&ok(vb,va,x-1,y))
		vis[x-1][y]=1;
	if(y&&c[x][y-1]==1&&ok(vb,va,x,y-1))
		vis[x][y-1]=1;
	if(x<n&&r[x][y]&&ok(vb,va,x+1,y))
		vis[x+1][y]=1;
	if(y<m&&c[x][y]&&ok(vb,va,x,y+1))
		vis[x][y+1]=1;
	px=x,py=y;
	while(1)
	{
		if(px>1&&r[px-1][py]==2)
		{
			int z=ok(vb,va,px-1,py);
			if(z==0)
				break;
			else if(z==2)
			{
				vis[px-1][py]=1;
				break;
			}
			else
				px--;
		}	
		else
			break;
		vis[px][py]=1;
	}
	px=x,py=y;
	while(1)
	{
		if(px<n&&r[px][py]==2&&ok(vb,va,px+1,py))
		{
			int z=ok(vb,va,px+1,py);
			if(z==0)
				break;
			else if(z==2)
			{
				vis[px+1][py]=1;
				break;
			}
			else
				px++;
		}	
		else
			break;
		vis[px][py]=1;
	}
	px=x,py=y;
	while(1)
	{
		if(py>1&&c[px][py-1]==2)
		{
			int z=ok(vb,va,px,py-1);
			if(z==0)
				break;
			else if(z==2)
			{
				vis[px][py-1]=1;
				break;
			}
			else
				py--;
		}	
		else
			break;
		vis[px][py]=1;
	}
	px=x,py=y;
	while(1)
	{
		if(py<m&&c[px][py]==2)
		{
			int z=ok(vb,va,px,py+1);
			if(z==0)
				break;
			else if(z==2)
			{
				vis[px][py+1]=1;
				break;
			}
			else
				py++;
		}	
		else
			break;
		vis[px][py]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans+=vis[i][j];
	return ans;
}
void sol()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<=n+1;i++)
	{
		b[i].resize(m+2);
		a[i].resize(m+2);
		r[i].resize(m+2);
		c[i].resize(m+2);
		vis[i].resize(m+2);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			b[i][j]=a[i][j]=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<m;j++)
			c[i][j]=s[j]-'0';
	}
	for(int i=1;i<n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			r[i][j]=s[j]-'0';
	}
	while(q--)
	{
		int vb,va,x,y;
		scanf("%d%d%d%d",&vb,&va,&x,&y);
		b[x][y]=vb;
		a[x][y]=va;
		printf("%d\n",cal(x,y)-1);
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}

