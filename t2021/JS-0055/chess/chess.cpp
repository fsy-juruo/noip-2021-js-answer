/*
dog pear fruit fake win like ant
seven eagle fire bat pen take juice
*/
#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;
vector<vector<int> >L,R,U,D;
vector<vector<pair<int,int> > >G;
int n,m,q;
vector<vector<int> >used;
int ans;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
inline void dfs(int x,int y,int col,int lv){
	if(x<1 or y<1 or x>n or y>m)return;
	if(used[x][y])return;
	if(G[x][y]!=mp(0,0)){
		if(G[x][y].first!=col and G[x][y].second<=lv)ans+=1-used[x][y];
		used[x][y]=1;
		return;
	}
	ans+=1-used[x][y];
	used[x][y]=1;
	for(int i=0;i<4;++i){
		int tx=x+dx[i],ty=y+dy[i];
		if(i==0 and D[x][y]==3)dfs(tx,ty,col,lv);
		if(i==1 and R[x][y]==3)dfs(tx,ty,col,lv);
		if(i==2 and U[x][y]==3)dfs(tx,ty,col,lv);
		if(i==3 and L[x][y]==3)dfs(tx,ty,col,lv);
	}
}
inline void force(int col,int lv,int x,int y){
	used.clear();ans=0;
	used.resize(n+5);
	for(int i=0;i<n+5;++i)used[i].resize(m+5);
	//up
	int tp;
	if(U[x][y]==3)dfs(x-1,y,col,lv);
	if(D[x][y]==3)dfs(x+1,y,col,lv);
	if(L[x][y]==3)dfs(x,y-1,col,lv);
	if(R[x][y]==3)dfs(x,y+1,col,lv);
	if(U[x][y]==2){
		int ty=y;
		for(int tx=x-1;tx>0;--tx){
			if(G[tx][ty]==mp(0,0))ans+=1-used[tx][ty];
			else{
				if(G[tx][ty].first!=col and G[tx][ty].second<=lv)ans+=1-used[tx][ty];
				used[tx][ty]=1;
				break;
			}
			used[tx][ty]=1;
			if(U[tx][ty]!=2)break;
		}
	}
	if(D[x][y]==2){
		int ty=y;
		for(int tx=x+1;tx<=n;++tx){
			if(G[tx][ty]==mp(0,0))ans+=1-used[tx][ty];
			else{
				if(G[tx][ty].first!=col and G[tx][ty].second<=lv)ans+=1-used[tx][ty];
				used[tx][ty]=1;
				break;
			}
			used[tx][ty]=1;
			if(D[tx][ty]!=2)break;
		}
	}
	if(L[x][y]==2){
		int tx=x;
		for(int ty=y-1;ty>0;--ty){
			if(G[tx][ty]==mp(0,0))ans+=1-used[tx][ty];
			else{
				if(G[tx][ty].first!=col and G[tx][ty].second<=lv)ans+=1-used[tx][ty];
				used[tx][ty]=1;
				break;
			}
			used[tx][ty]=1;
			if(L[tx][ty]!=2)break;
		}
	}
	if(R[x][y]==2){
		int tx=x;
		for(int ty=y+1;ty<=m;++ty){
			if(G[tx][ty]==mp(0,0))ans+=1-used[tx][ty];
			else{
				if(G[tx][ty].first!=col and G[tx][ty].second<=lv)ans+=1-used[tx][ty];
				used[tx][ty]=1;
				break;
			}
			used[tx][ty]=1;
			if(R[tx][ty]!=2)break;
		}
	}
	if(U[x][y]==1){
		if(G[x-1][y]==mp(0,0))ans+=1-used[x-1][y];
		else if(G[x-1][y].first!=col and G[x-1][y].second<=lv)ans+=1-used[x-1][y];
	}
	if(D[x][y]==1){
		if(G[x+1][y]==mp(0,0))ans+=1-used[x+1][y];
		else if(G[x+1][y].first!=col and G[x+1][y].second<=lv)ans+=1-used[x+1][y];
	}
	if(L[x][y]==1){
		if(G[x][y-1]==mp(0,0))ans+=1-used[x][y-1];
		else if(G[x][y-1].first!=col and G[x][y-1].second<=lv)ans+=1-used[x][y-1];
	}
	if(R[x][y]==1){
		if(G[x][y+1]==mp(0,0))ans+=1-used[x][y+1];
		else if(G[x][y+1].first!=col and G[x][y+1].second<=lv)ans+=1-used[x][y+1];
	}
	if(used[x][y])--ans;
	cout<<ans<<'\n';
	G[x][y]=mp(col,lv);
}
inline void solve(){
	cin>>n>>m>>q;
	L.clear(),R.clear(),U.clear(),D.clear(),G.clear();
	L.resize(n+5),R.resize(n+5),U.resize(n+5),D.resize(n+5),G.resize(n+5);
	for(int i=0;i<n+5;++i)L[i].resize(m+5),R[i].resize(m+5),D[i].resize(m+5),U[i].resize(m+5),G[i].resize(m+5);
	for(int i=1;i<=n;++i){
		string s;cin>>s;
		for(int j=1;j<m;++j)R[i][j]=s[j-1]-'0',L[i][j+1]=s[j-1]-'0';
	}
	for(int i=1;i<n;++i){
		string s;cin>>s;
		for(int j=1;j<=m;++j)D[i][j]=s[j-1]-'0',U[i+1][j]=s[j-1]-'0';
	}
	int tq=q;
	for(;q--;){
		int col,lv,x,y;cin>>col>>lv>>x>>y;
		force(col,lv,x,y);
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;cin>>T;
	for(;T--;)solve();
	return 0;
}
