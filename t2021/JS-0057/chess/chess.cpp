//start:12:16
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,qs;
const int N=5005;
struct node{
	int x,y,dir;
};
vector < int > c[N],val[N],ty[4][N],vis[N],used[4][N];
//int c[N][N],v[N][N],ty[N][N][4],vis[N][N],used[N][N][4];//change it to vector
const int da[]={-1,0,1,0};
const int db[]={0,1,0,-1};
bool inmap(int x,int y){
	return x<=n && x>=1 && y<=m && y>=1;
} 
int bfs(int x,int y,int col,int lv){
	queue < node > q;
	c[x][y]=col;val[x][y]=1e9;
	int ans=0;
	for (int i=0;i<=3;i++){
		int tmp=ty[i][x][y];
		if (tmp==0) continue;
		int ii=x+da[i],jj=y+db[i];
		if (!inmap(ii,jj)) continue;
		used[i][ii][jj]=true;
		if (c[ii][jj]>=0){
			if (c[ii][jj]!=col && val[ii][jj]<lv) vis[ii][jj]=true;
			continue;
		}
//		cout << i << ' ' << tmp << endl;
		if (tmp==2) q.push((node){x+da[i],y+db[i],i});
		else if (tmp==3) q.push((node){x+da[i],y+db[i],4}); 
		vis[ii][jj]=true;
	}
	while (!q.empty()){
		int u=q.front().x,v=q.front().y,w=q.front().dir;
		q.pop();
//		cout << u << ' ' << v << ' ' << w << endl;
		for (int i=0;i<=3;i++){
			int ii=u+da[i],jj=v+db[i];
			if (!inmap(ii,jj)) continue;
			int tmp=ty[i][u][v];
			if (used[i][ii][jj]) continue;
			used[i][ii][jj]=true;
			if (tmp<=0) continue;
			if (c[ii][jj]>=0){
				if (c[ii][jj]!=col && val[ii][jj]<lv) vis[ii][jj]=true;
				continue;
			}
			if (tmp==2 && w==i){
				q.push((node){ii,jj,i});
				used[i][ii][jj]=true;
			}
			if (tmp==3 && w==4){
				q.push((node){ii,jj,i});
				used[i][ii][jj]=true;
			}
		}
	}
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (vis[i][j]) ans++;
	val[x][y]=lv;
	return ans;
}
void work_24(){
	cin >> n >> m >> qs;
	for (int i=0;i<=n+1;i++){
		c[i].resize(m+2);
		for (int j=0;j<=m+1;j++) c[i][j]=-1;
		for (int j=0;j<=3;j++){
			ty[j][i].resize(m+2);
		}
		val[i].resize(m+2);
		for (int j=0;j<=m+1;j++) val[i][j]=0;
	}
	for (int i=1;i<=n;i++){
		string st;cin >> st;
		for (int j=1;j<m;j++){
			ty[1][i][j]=st[j-1]-'0';
			ty[3][i][j+1]=st[j-1]-'0';
		}
	}
	for (int i=1;i<n;i++){
		string st;cin >> st;
		for (int j=1;j<=m;j++){
			ty[2][i][j]=ty[0][i+1][j]=st[j-1]-'0';
		}
	}
//	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++){
//		for (int p=0;p<=3;p++) cout << ty[p][i][j] << ' ';cout << endl;
//	}
	for (int i=1;i<=qs;i++){
		int u,v,col,lv;
		cin >> u >> v >> col >> lv;
		vis[i].resize(m+2);
		for (int j=0;j<=3;j++){
			used[j][i].resize(m+2);
			for (int p=0;p<=m+1;p++) used[j][i][p]=false;
		}
		for (int j=0;j<=m+1;j++) vis[i][j]=0;
		cout << bfs(u,v,col,lv) << endl;
	}
}
signed main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int cas;cin >> cas;
	while (cas--) work_24();
	return 0;
}
