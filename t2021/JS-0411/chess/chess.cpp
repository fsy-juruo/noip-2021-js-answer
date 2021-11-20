#include <bits/stdc++.h>
#define PA pair<int,int>
#define MP make_pair
#define fi first
#define se second
using namespace std;
const int maxl=5005;

int read(){
	int s=0,w=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-')  w=-w;ch=getchar();}
	while (ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^'0');ch=getchar();}
	return s*w;
}
int n,m,q,ans;
int u[maxl][maxl],d[maxl][maxl],l[maxl][maxl],r[maxl][maxl],lev[maxl][maxl],c[maxl][maxl];
bool vis[maxl][maxl],p[maxl][maxl];
vector<PA> ve;

bool ok(int x,int y,int xx,int yy){
	if (!c[xx][yy])  return true;
	if (x==xx&&y==yy)  return true; 
	if (c[xx][yy]==c[x][y]||lev[xx][yy]>lev[x][y])  return false;
	return true;
}

namespace ducati{
	void get_all_in(){
		n=read(),m=read(),q=read();
		for (int i=1;i<=n;i++){
			for (int j=1;j<m;j++){
				char x;cin>>x;
				r[i][j]=x-'0';
			}
			for (int j=2;j<=m;j++)  l[i][j]=r[i][j-1];
		}
		for (int i=1;i<n;i++){
			for (int j=1;j<=m;j++){
				char x;cin>>x;
				d[i][j]=x-'0';
			}
			for (int j=1;j<=m;j++)  u[i+1][j]=d[i][j];
		}
	}
	void dfs(int x,int y,int rx,int ry){
		if (p[x][y]||ok(rx,ry,x,y)==0)  return;
		
		p[x][y]=1,ve.push_back(MP(x,y));
		if (!vis[x][y])  ans++;
		
		if (d[x][y]==3)  dfs(x+1,y,rx,ry);
		if (u[x][y]==3)  dfs(x-1,y,rx,ry);
		if (l[x][y]==3)  dfs(x,y-1,rx,ry);
		if (r[x][y]==3)  dfs(x,y+1,rx,ry);
	}
	void move1(int x,int y){
		if (l[x][y]==1&&ok(x,y,x,y-1))  vis[x][y-1]=1;
		if (r[x][y]==1&&ok(x,y,x,y+1))  vis[x][y+1]=1;
		if (u[x][y]==1&&ok(x,y,x-1,y))  vis[x-1][y]=1;
		if (d[x][y]==1&&ok(x,y,x+1,y))  vis[x+1][y]=1;
	}
	void move2(int x,int y){
		for (int i=y+1;i<=m;i++){
			if (r[x][i-1]==2&&lev[x][i]==0)  vis[x][i]=1;
			else if (r[x][i-1]==2&&lev[x][i]<=lev[x][y]&&c[x][i]!=c[x][y]) {vis[x][i]=1;break;}
			else break;
		}
		for (int i=y-1;i>=1;i--){
			if (l[x][i+1]==2&&lev[x][i]==0)  vis[x][i]=1;
			else if (l[x][i+1]==2&&lev[x][i]<=lev[x][y]&&c[x][i]!=c[x][y]) {vis[x][i]=1;break;}
			else break;
		}
		for (int i=x-1;i>=1;i--){
			if (u[i+1][y]==2&&lev[i][y]==0)  vis[i][y]=1;
			else if (u[i+1][y]==2&&lev[i][y]<=lev[x][y]&&c[i][y]!=c[x][y]) {vis[i][y]=1;break;}
			else break;
		}
		for (int i=x+1;i<=n;i++){
			if (d[i-1][y]==2&&lev[i][y]==0)  vis[i][y]=1;
			else if (d[i-1][y]==2&&lev[i][y]<=lev[x][y]&&c[i][y]!=c[x][y]) {vis[i][y]=1;break;}
			else break;
	 }
	}
	void move3(int x,int y){
		ans=0;
		for (int i=1;i<=m;i++){
			if (vis[x][i])  ans++;
		}
		for (int i=1;i<=n;i++){
			if (vis[i][y])  ans++;
		}
		dfs(x,y,x,y);
		printf("%d\n",ans-1);
	}
	void clear(int x,int y){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++)  vis[i][j]=p[i][j]=0;
		}
		ve.clear();
	}
	void answer_queries(){
		while (q--){
			int col=read()+1,l=read(),x=read(),y=read();
			lev[x][y]=l,c[x][y]=col;
			move1(x,y),move2(x,y),move3(x,y),clear(x,y);
		}
	}
	void clear_all(){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				u[i][j]=0;
				d[i][j]=0;
				l[i][j]=0;
				r[i][j]=0;
				lev[i][j]=0;
				vis[i][j]=0;
				c[i][j]=0;
				p[i][j]=0;
			}
		}
	}
	void solve(){
		get_all_in(),answer_queries(),clear_all();
	}
}

signed main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	int T=read();
	while (T--)  ducati::solve();
	
	return 0;
}
