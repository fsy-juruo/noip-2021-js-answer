#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<n;i++)
#define forn(i,a,b) for(int i=a;i<=b;i++)
#define fore(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define m_p make_pair
using namespace std;
const int N=5010;
int n,m,q;
string s1[N],s2[N];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool vis[N][N],vis2[N][N];
int col[N][N],lv[N][N];
bool in(int x,int y){
	return x>=1&&y>=1&&x<=n&&y<=m;
}
int rd(int x,int y,int tx,int ty){
	if(ty==y+1)return s1[x][y]-'0';
	if(tx==x+1)return s2[x][y]-'0';
	if(tx==x-1)return s2[x-1][y]-'0';
	if(ty==y-1)return s1[x][y-1]-'0';
}
void dfs_s(int x,int y,int d,int cl,int Lv){//dfs_straight
	vis[x][y]=1;
	int tx=x+dx[d],ty=y+dy[d];
	if(!in(tx,ty))return;
	if(rd(x,y,tx,ty)!=2)return;
	if(col[tx][ty]==cl)return;
	if(col[tx][ty]+cl==1&&Lv<lv[tx][ty])return;
	if(col[tx][ty]+cl==1&&Lv>=lv[tx][ty]){
		vis[tx][ty]=1;
		return;
	}
	dfs_s(tx,ty,d,cl,Lv);
}
void dfs(int x,int y,int cl,int Lv){
	vis2[x][y]=1;vis[x][y]=1;
	rep(i,4){
		int tx=x+dx[i],ty=y+dy[i];
		if(!in(tx,ty))continue;
		if(rd(x,y,tx,ty)!=3)continue;
		if(col[tx][ty]==cl)continue;
		if(col[tx][ty]+cl==1&&Lv<lv[tx][ty])continue;
		if(col[tx][ty]+cl==1&&Lv>=lv[tx][ty]){
			vis2[tx][ty]=1;vis[tx][ty]=1;
			continue;
		}
		if(vis2[tx][ty])continue;
		dfs(tx,ty,cl,Lv);
	}
}
void solve1(){
	memset(col,-1,sizeof(col));
	forn(i,1,n){
		cin>>s1[i];s1[i]='*'+s1[i];
	}
	forn(i,1,n-1){
		cin>>s2[i];s2[i]='*'+s2[i];
	}
	while(q--){
		memset(vis,0,sizeof(vis));memset(vis2,0,sizeof(vis2));
		int cl,Lv,x,y;
		cin>>cl>>Lv>>x>>y;
		col[x][y]=cl;
		lv[x][y]=Lv;
		rep(i,4){
			int tx=x+dx[i],ty=y+dy[i];
			if(!in(tx,ty))continue;
			if(rd(x,y,tx,ty)!=1)continue;
			if(col[tx][ty]==cl)continue;
			if(col[tx][ty]+cl==1&&Lv<lv[tx][ty])continue;
			vis[tx][ty]=1;
		}
		rep(i,4){
			dfs_s(x,y,i,cl,Lv);
		}
		dfs(x,y,cl,Lv);
		int ans=0;
		forn(i,1,n){
			forn(j,1,m){
				if(i==x&&j==y)continue;
				if(vis[i][j])ans++;
			}
		}
		cout<<ans<<"\n";
	}
}
void solve2(){
	int colL[n+5][m+5],lvV[n+5][m+5];
	forn(i,1,n){
		cin>>s1[i];s1[i]='*'+s1[i];
	}
	forn(i,1,n-1){
		cin>>s2[i];s2[i]='*'+s2[i];
	}
	while(q--){
		int cl,Lv,x,y;
		cin>>cl>>Lv>>x>>y;
		if(cl==0)cl=-1;
		colL[x][y]=cl;
		lvV[x][y]=Lv;
		int ans=0;
		rep(i,4){
			int tx=x+dx[i],ty=y+dy[i];
			if(!in(tx,ty))continue;
			if(rd(x,y,tx,ty)!=1)continue;
			if(colL[tx][ty]==cl)continue;
			if(colL[tx][ty]+cl==0&&Lv<lvV[tx][ty])continue;
			ans++;
		}
		cout<<ans<<"\n";
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);	
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>q;
		if(n*m<=5000)solve1();
		else solve2();
	}
	return 0;
}
