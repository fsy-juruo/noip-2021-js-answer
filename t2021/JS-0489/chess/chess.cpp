#include<bits/stdc++.h>
using namespace std;
const int maxn=3005;
const int inf=0x3f3f3f3f;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int n,m,q;
int hg[maxn][maxn],lb[maxn][maxn];
int nwcol,nwlv,nwx,nwy;
int vis[maxn][maxn],ky[maxn][maxn];
int dx[10]={0,0,1,-1};
int dy[10]={1,-1,0,0};
struct node{
	int col,lv;
}a[maxn][maxn];
bool check(int xx,int yy)
{
	if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
		return true;
	return false;
}
int ans=0;
void dfs(int nx,int ny,int zt,int flg2)
{
//	cout<<nx<<" "<<ny<<" "<<zt<<" "<<flg2<<endl;
	if(zt==-1)
	{
		for(int i=0;i<=3;i++)
		{
			int fx=nx+dx[i],fy=ny+dy[i];
			if(check(fx,fy)==false)
				continue;
			int lu;
			if(i==0)
				lu=hg[nx][ny];
			else if(i==1)
				lu=hg[fx][fy];
			else if(i==2)
				lu=lb[nx][ny];
			else
				lu=lb[fx][fy];
			
			int cmc=0;
			if(a[fx][fy].lv!=0)
			{
				if(a[fx][fy].col==nwcol)
					continue;
				if(a[fx][fy].lv>nwlv)
					continue;
				cmc=1;
			}
				
			if(lu==0)
				continue;
			else if(lu==1)
			{
				if(ky[fx][fy]==0)
				{
					ky[fx][fy]=1;
					ans++;
				}
			}
			else if(lu==2)
			{
				if(ky[fx][fy]==0)
				{
					ky[fx][fy]=1;
					ans++;
				}
				if(cmc==1)
					continue;
				dfs(fx,fy,2,i);
			}
			else if(lu==3)
			{
				if(ky[fx][fy]==0)
				{
					ky[fx][fy]=1;
					ans++;
				}
				if(cmc==1)
					continue;
				vis[fx][fy]=1;
				dfs(fx,fy,3,0);
				vis[fx][fy]=0;
			}
		}
	}
	else if(zt==2)
	{
		int fx=nx+dx[flg2],fy=ny+dy[flg2];
		if(check(fx,fy)==false)
			return ;
		int lu;
		if(flg2==0)
			lu=hg[nx][ny];
		else if(flg2==1)
			lu=hg[fx][fy];
		else if(flg2==2)
			lu=lb[nx][ny];
		else
			lu=lb[fx][fy];
		
		int cmc=0;
		if(a[fx][fy].lv!=0)
		{
			if(a[fx][fy].col==nwcol)
				return ;
			if(a[fx][fy].lv>nwlv)
				return ;
			cmc=1;
		}
		
		if(lu!=2)
			return ;
		if(ky[fx][fy]==0)
		{
			ky[fx][fy]=1;
			ans++;
		}
		if(cmc==1)
			return ;
		dfs(fx,fy,2,flg2);
	}
	else if(zt==3)
	{
		for(int i=0;i<=3;i++)
		{
			int fx=nx+dx[i],fy=ny+dy[i];
			if(check(fx,fy)==false)
				continue;
			int lu;
			if(i==0)
				lu=hg[nx][ny];
			else if(i==1)
				lu=hg[fx][fy];
			else if(i==2)
				lu=lb[nx][ny];
			else
				lu=lb[fx][fy];
			
			int cmc=0;
			if(a[fx][fy].lv!=0)
			{
				if(a[fx][fy].col==nwcol)
					continue;
				if(a[fx][fy].lv>nwlv)
					continue;
				cmc=1;
			}
			
			if(lu!=3)
				continue;
			if(vis[fx][fy]==1)
				continue ;
				
			if(ky[fx][fy]==0)
			{
				ky[fx][fy]=1;
				ans++;
			}
			if(cmc==1)
				continue;
			vis[fx][fy]=1;
			dfs(fx,fy,3,0);
			vis[fx][fy]=0;
		}
	}
}
void init()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			vis[i][j]=0;
			ky[i][j]=0;
		}
	}
}
void INIT()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j].col=0;
			a[i][j].lv=0;
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int t=read();
	string s;
	//记得清空 否则两行泪 
	while(t--)
	{
		n=read();m=read();q=read();
		INIT();
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			for(int j=0;j<s.size();j++)
				hg[i][j+1]=s[j]-'0';
		}
		for(int i=1;i<=n-1;i++)
		{
			cin>>s;
			for(int j=0;j<s.size();j++)
				lb[i][j+1]=s[j]-'0';
		}
		for(int qq=1;qq<=q;qq++)
		{
			init();
			nwcol=read();nwlv=read();nwx=read();nwy=read();
			ans=0;
			vis[nwx][nwy]=1;
			dfs(nwx,nwy,-1,0);
			printf("%d\n",ans);
			a[nwx][nwy].col=nwcol;
			a[nwx][nwy].lv=nwlv;
		}
	}
	return 0;
}

