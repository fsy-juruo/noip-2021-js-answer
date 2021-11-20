#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back

using namespace std;

int ri()
{
	char c=getchar();
	int ret=0;
	while(c<'0'||c>'9') c=getchar();
	while('0'<=c&&c<='9')
	{
		ret=ret*10+c-'0';
		c=getchar();
	}
	return ret;
}

char rc()
{
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	return c;
}

int t,n,m,q;
string in;
vector <vector <int> > l,r,u,d,vis,vis2;
vector <vector <pii> > obj;
vector <int> tmp;
vector <pii> tmp2;
int col,lv,x,y,ans;
bool good;

int check(int xx,int yy)
{
	if(obj[xx][yy].fi==-1) return 1;
	if(obj[xx][yy].fi!=col&&obj[xx][yy].se<=lv) return 1;
	return 0;
}

void dfs(int xx,int yy)
{
	vis2[xx][yy]=1;
	if(l[xx][yy]==3&&vis2[xx][yy-1]==-1&&check(xx,yy-1)==1)
	{
		vis2[xx][yy-1]=1;
		if(obj[xx][yy-1].fi==-1) dfs(xx,yy-1);
	}
	if(r[xx][yy]==3&&vis2[xx][yy+1]==-1&&check(xx,yy+1)==1)
	{
		vis2[xx][yy+1]=1;
		if(obj[xx][yy+1].fi==-1) dfs(xx,yy+1);
	}
	if(u[xx][yy]==3&&vis2[xx-1][yy]==-1&&check(xx-1,yy)==1)
	{
		vis2[xx-1][yy]=1;
		if(obj[xx-1][yy].fi==-1) dfs(xx-1,yy);
	}
	if(d[xx][yy]==3&&vis2[xx+1][yy]==-1&&check(xx+1,yy)==1)
	{
		vis2[xx+1][yy]=1;
		if(obj[xx+1][yy].fi==-1) dfs(xx+1,yy);
	}
}

void solveBF()
{
	rep(qn,q)
	{
		col=ri();lv=ri();x=ri();y=ri();--x;--y;
		obj[x][y]=mpr(col,lv);
		if(good)
		{
			ans=0;
			if(l[x][y]==1) if(check(x,y-1)) ++ans;
			if(r[x][y]==1) if(check(x,y+1)) ++ans;
			if(u[x][y]==1) if(check(x-1,y)) ++ans;
			if(d[x][y]==1) if(check(x+1,y)) ++ans;
			printf("%d\n",ans);
			continue;
		}
		vis.clear();vis2.clear();
		rep(i,n) vis.pb(tmp),vis2.pb(tmp);
		ans=0;
		if(l[x][y]==1) if(check(x,y-1)) vis[x][y-1]=1;
		if(r[x][y]==1) if(check(x,y+1)) vis[x][y+1]=1;
		if(u[x][y]==1) if(check(x-1,y)) vis[x-1][y]=1;
		if(d[x][y]==1) if(check(x+1,y)) vis[x+1][y]=1;
		int xx=x,yy=y;
		while(true)
		{
			if(l[xx][yy]!=2||check(xx,yy-1)==0) break;
			--yy;
			vis[xx][yy]=1;
			if(obj[xx][yy].fi>-1) break;
		}
		xx=x;yy=y;
		while(true)
		{
			if(r[xx][yy]!=2||check(xx,yy+1)==0) break;
			++yy;
			vis[xx][yy]=1;
			if(obj[xx][yy].fi>-1) break;
		}
		xx=x;yy=y;
		while(true)
		{
			if(u[xx][yy]!=2||check(xx-1,yy)==0) break;
			--xx;
			vis[xx][yy]=1;
			if(obj[xx][yy].fi>-1) break;
		}
		xx=x;yy=y;
		while(true)
		{
			if(d[xx][yy]!=2||check(xx+1,yy)==0) break;
			++xx;
			vis[xx][yy]=1;
			if(obj[xx][yy].fi>-1) break;
		}
		dfs(x,y);
		rep(i,n) rep(j,m) if(vis[i][j]==1||vis2[i][j]==1) ++ans;
		printf("%d\n",ans-1);
	}
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	t=ri();
	rep(tn,t)
	{
		n=ri();m=ri();q=ri();
		l.clear();r.clear();u.clear();d.clear();vis.clear();vis2.clear();obj.clear();
		tmp.clear();rep(i,m) tmp.pb(-1);tmp2.clear();rep(i,m) tmp2.pb(mpr(-1,-1));
		rep(i,n) l.pb(tmp),r.pb(tmp),u.pb(tmp),d.pb(tmp),vis.pb(tmp),vis2.pb(tmp),obj.pb(tmp2);
		good=true;
		rep(i,n)
		{
			in="";
			rep(j,m-1) in.pb(rc());
			rep(j,m-1)
			{
				if(in[j]=='2'||in[j]=='3') good=false;
				r[i][j]=in[j]-'0';
				l[i][j+1]=in[j]-'0';
			}
		}
		rep(i,n-1)
		{
			in="";
			rep(j,m) in.pb(rc());
			rep(j,m)
			{
				if(in[j]=='2'||in[j]=='3') good=false;
				d[i][j]=in[j]-'0';
				u[i+1][j]=in[j]-'0';
			}
		}
		solveBF();
	}
	return 0;
}
