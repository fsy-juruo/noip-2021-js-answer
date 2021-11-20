#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define inf 1000000007
using namespace std;
const int mxn=100005;
typedef long long ll;
typedef pair<int,int> pi;
inline int read()
{
	char c=getchar();
	int f=1;
	while(!isdigit(c))
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	int x=0;
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
pi qp[5005][5005];
short hn[5005][5005],sh[5005][5005];
bool v[5005][5005],v2[5005][5005];
int n,m,q;
int ans,pre,dir;
int c,lv;
inline bool in(int x,int y)
{
	return x>=0 && y>=0 && x<n && y<m;
}
void solv(int x,int y,int cm)
{
	if(pre==3 && v2[x][y]) return;
	//cout<<x+1<<" "<<y+1<<endl;
	if(pre==-1)
	{
		v2[x][y]=1;
		if(x-1>=0 && sh[x-1][y]!=0)
		{
			pre=sh[x-1][y];
			solv(x-1,y,1);
		}
		if(y-1>=0 && hn[x][y-1]!=0)
		{
			pre=hn[x][y-1];
			solv(x,y-1,2);
		}
		if(x+1<n && sh[x][y]!=0)
		{
			pre=sh[x][y];
			solv(x+1,y,3);
		}
		if(y+1<m && hn[x][y]!=0)
		{
			pre=hn[x][y];
			solv(x,y+1,4);
		}
	}
	else
	{
		if(qp[x][y].se!=0)
		{
			if(qp[x][y].fi!=c && lv>=qp[x][y].se)
				v[x][y]=1;
			return;
		}
		v[x][y]=1;
		if(pre==1) return;
		else if(pre==2)
		{
			if(cm==1 && x-1>=0 && sh[x-1][y]==2)
				solv(x-1,y,1);
			if(cm==2 && y-1>=0 && hn[x][y-1]==2)
				solv(x,y-1,2);
			if(cm==3 && x+1<n && sh[x][y]==2)
				solv(x+1,y,3);
			if(cm==4 && y+1<m && hn[x][y]==2)
				solv(x,y+1,4);
		}
		else
		{
			v2[x][y]=1;
			if(cm!=3 && x-1>=0 && sh[x-1][y]==3)
				solv(x-1,y,1);
			if(cm!=4 && y-1>=0 && hn[x][y-1]==3)
				solv(x,y-1,2);
			if(cm!=1 && x+1<n && sh[x][y]==3)
				solv(x+1,y,3);
			if(cm!=2 && y+1<m && hn[x][y]==3)
				solv(x,y+1,4);
		}
	}
}
inline void in(short a[],int len)
{
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	for(int i=0;i<len;i++)
	{
		a[i]=c-'0';
		c=getchar();
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T=read();
	while(T--)
	{
		memset(qp,0,sizeof(qp));
		n=read(),m=read(),q=read();
		for(int i=0;i<n;i++)
			in(hn[i],m-1);
		for(int i=0;i<n-1;i++)
			in(sh[i],m);
		while(q--)
		{
			memset(v,false,sizeof(v));
			memset(v2,false,sizeof(v2));
			c=read(),lv=read();
			int x=read(),y=read();
			x--,y--;
			ans=0;pre=-1;
			qp[x][y]=mp(c,lv);
			solv(x,y,-1);
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
					if(v[i][j]) ans++;
			cout<<ans<<endl;
		}
	}
	return 0;
}


