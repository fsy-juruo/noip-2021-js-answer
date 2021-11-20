#include<bits/stdc++.h>
using namespace std;
struct Node{
	int col,lv;
	Node(){}
	Node(int a,int b){col=a;lv=b;}
	friend bool operator==(Node a,Node b)
	{
		return a.col==b.col&&a.lv==b.lv;
	}
	friend bool operator<(Node a,Node b)
	{
		if(a.lv==0)return true;
		return a.col!=b.col&&a.lv<=b.lv;
	}
};
string h[100001],l[100001];
vector<Node> a[100001];
vector<bool> vis[100001];
int sum,ttx,tty;int n,m,q;
void dfs(int x,int y)
{
	if(vis[x][y])return;
	vis[x][y]=true;sum++;if(!(a[x][y]==Node(0,0))&&!(x==ttx&&y==tty))return;
	if(y-1>0&&h[x][y-1]=='3'&&a[x][y-1]<a[ttx][tty])dfs(x,y-1);
	if(x-1>0&&l[x-1][y]=='3'&&a[x-1][y]<a[ttx][tty])dfs(x-1,y);
	if(y+1<=m&&h[x][y]=='3'&&a[x][y+1]<a[ttx][tty])dfs(x,y+1);
	if(x+1<=n&&l[x][y]=='3'&&a[x+1][y]<a[ttx][tty])dfs(x+1,y);
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;i++)a[i].clear(),vis[i].clear();
		for(int i=1;i<=n;i++)
			for(int j=0;j<=m;j++)
				a[i].push_back(Node(0,0)),vis[i].push_back(false);
		for(int i=1;i<=n;i++)
			cin>>h[i],h[i]="#"+h[i];
		for(int i=1;i<n;i++)
			cin>>l[i],l[i]="#"+l[i];
		if(n*m<=5000&&q<=2000)
		{
			for(int i=1;i<=q;i++)
			{
				int col,lv,x,y;scanf("%d%d%d%d",&col,&lv,&x,&y);
				sum=0;a[x][y]=Node(col,lv);
				if(y-1>0&&h[x][y-1]=='1'&&a[x][y-1]<a[x][y])sum++,vis[x][y-1]=true;
				if(x-1>0&&l[x-1][y]=='1'&&a[x-1][y]<a[x][y])sum++,vis[x-1][y]=true;
				if(y+1<=m&&h[x][y]=='1'&&a[x][y+1]<a[x][y])sum++,vis[x][y+1]=true;
				if(x+1<=n&&l[x][y]=='1'&&a[x+1][y]<a[x][y])sum++,vis[x+1][y]=true;
				for(int j=y-1;j>=1;j--)
					if(h[x][j]=='2')
					{
						vis[x][j]=true;
						if(a[x][j]==Node(0,0))
							sum++;
						else
						{
							sum+=(a[x][j]<a[x][y]);
							break;
						}
						
					}
					else break;
				for(int j=y+1;j<=m;j++)
					if(h[x][j-1]=='2')
					{
						vis[x][j]=true;
						if(a[x][j]==Node(0,0))
							sum++;
						else
						{
							sum+=(a[x][j]<a[x][y]);
							break;
						}
					}
					else break;
				for(int j=x-1;j>=1;j--)
					if(l[j][y]=='2')
					{
						vis[j][y]=true;
						if(a[j][y]==Node(0,0))
							sum++;
						else
						{
							sum+=(a[j][y]<a[x][y]);
							break;
						}
					}
					else break;
				for(int j=x+1;j<=n;j++)
					if(l[j-1][y]=='2')
					{
						vis[j][y]=true;
						if(a[j][y]==Node(0,0))
							sum++;
						else
						{
							sum+=(a[j][y]<a[x][y]);
							break;
						}
					}
					else break;
				ttx=x,tty=y;dfs(x,y);
				printf("%d\n",sum-1);
				for(int i=1;i<=n;i++)vis[i].clear();
				for(int i=1;i<=n;i++)
					for(int j=0;j<=m;j++)
						vis[i].push_back(false);
			}
		}
		else
			for(int i=1;i<=q;i++)
			{
				int col,lv,x,y;scanf("%d%d%d%d",&col,&lv,&x,&y);
				a[x][y]=Node(col,lv);
				sum=0;
				if(y-1>0&&h[x][y-1]!='0'&&a[x][y-1]<a[x][y])sum++;
				if(x-1>0&&l[x-1][y]!='0'&&a[x-1][y]<a[x][y])sum++;
				if(y+1<=m&&h[x][y]!='0'&&a[x][y+1]<a[x][y])sum++;
				if(x+1<=n&&l[x][y]!='0'&&a[x+1][y]<a[x][y])sum++;
				printf("%d\n",sum);
			}
	} 
	return 0;
}
