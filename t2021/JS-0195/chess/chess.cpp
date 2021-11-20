#include <bits/stdc++.h>
using namespace std;

const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};  //up down left right 0 1 2 3 
struct Zi {
	int col,lv;
};
const int MAXN=300,MAXNM=300,MAXQ=2000+10;
int T; int n,m,q;
char heng[MAXN][MAXN];
char zong[MAXN][MAXN];
Zi bd[MAXN][MAXN];

void init() {
	Zi emp; emp.col=emp.lv=-1;
	for(int i=0;i<MAXN;i++) {
		for(int j=0;j<MAXN;j++){
			bd[i][j]=emp;
		}
	}
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m-1;j++) {
			cin>>heng[i][j];
		}
	}
	for(int i=1;i<=n-1;i++) {
		for(int j=1;j<=m;j++) {
			cin>>zong[i][j];
		}
	}
}

int road(int x1,int y1,int x2,int y2) {
	if(x1==x2) {
		if(y1<y2) return heng[x1][y1];
		else return heng[x1][y2];
	}
	else if(y1==y2) {
		if(x1<x2) return zong[x1][y1];
		else return zong[x2][y1];
	}
	else cout<<"FUUUCCCKKKKKK"<<endl;
	return -1;
}

bool is_legal(int x,int y) {
	if(x<1||x>n||y<1||y>m) return false;
	else return true;
}

bool vis[MAXN][MAXN];
int dfs1(int x,int y,Zi z) {
	int ans=0;
	for(int i=0;i<4;i++) {
		int newx=x+dx[i],newy=y+dy[i];
		if(!is_legal(newx,newy)) continue;
		if(road(x,y,newx,newy)==1) {
			if(bd[newx][newy].col!=z.col&&bd[newx][newy].lv<z.lv) {
				if(vis[newx][newy]==false) {
					ans++; vis[newx][newy]=true;
				}
			}
		}
		else continue;
	}
	return ans;
}

int dfs2(int x,int y,Zi z,int dir) {
	int ans=0;
	int newx=x+dx[dir],newy=y+dy[dir];
	if(!is_legal(newx,newy)) return 0;
	int rout=road(x,y,newx,newy);
	if(rout!=2) return 0;
	if(bd[newx][newy].col==z.col) return 0;
	if(bd[newx][newy].lv>z.lv) return 0;
	//此后，新个点上只有等级小于等于自己的异色子或空格 
	if(bd[newx][newy].col==-1) {
		if(!vis[newx][newy]) {
			vis[newx][newy]=true;
			ans++;
		}
		dfs2(newx,newy,z,dir);
	}
	else {
		if(!vis[newx][newy]) {
			vis[newx][newy]=true;
			ans++;
		}
	}
	return ans;
}

struct Pos {
	int x,y;
};

int bfs3(int xxx,int yyy,Zi z) {
	int ans=0;
	Pos sss; sss.x=xxx; sss.y=yyy;
	bool trace[n+1][m+1]; for(int i=0;i<n+1;i++) for(int j=0;j<m+1;j++) trace[i][j]=false;
	queue <Pos> q;
	q.push(sss);
	while(!q.empty()) {
		Pos cur; cur=q.front(); q.pop();
		for(int i=0;i<4;i++) {
			Pos newp; newp.x=cur.x+dx[i];
			newp.y=cur.y+dy[i];
			if(!is_legal(newp.x,newp.y)) continue;
			if(trace[newp.x][newp.y]) continue;
			if(road(cur.x,cur.y,newp.x,newp.y)!=3) continue;
			if(bd[newp.x][newp.y].col==z.col) continue;
			if(bd[newp.x][newp.y].lv>z.lv) continue;
			trace[newp.x][newp.y]=true;
			if(bd[newp.x][newp.y].col==-1) {
				if(!vis[newp.x][newp.y]) {
					vis[newp.x][newp.y]=true;
					ans++;
					q.push(newp);
				}
			} else {
				if(!vis[newp.x][newp.y]) {
					vis[newp.x][newp.y]=true;
					
					ans++;
				}
			}
		}
	}
	return ans;
}


void solve() { int x,y; Zi z;
	for(int i=0;i<q;i++) {
		cin>>z.col>>z.lv; cin>>x>>y; 
		bd[x][y]=z;
		int ans=0;
		for(int i=0;i<n;i++) for(int j=0;j<=m;j++) vis[i][j]=false;
		//1
		ans+=dfs1(x,y,z);
//		cout<<ans<<endl;
		//2
		for(int i=0;i<4;i++) ans+=dfs2(x,y,z,i);
//		cout<<ans<<endl;
		//3
		ans+=bfs3(x,y,z);
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				if(vis[i][j]) {
					cout<<"("<<i<<","<<j<<")"<<" ";
				}
			}
		}
		cout<<endl;
		cout<<ans<<endl;
	}
}


int main() {
	ios::sync_with_stdio(false);
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>T;
	while(T--) {
		init();
		solve();
	}
	return 0;
}

























































