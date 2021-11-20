#include<bits/stdc++.h>
using namespace std;
struct node {
	int col,lv;
} a[105][105];
int ans,T,n,m,q,col,lv,fx,fy;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int dfx[] = {0,0,0,-1};
int dfy[] = {0,0,-1,0};
bool vis[105][105][4];
char o[3][105][105];
void dfs(int x,int y,int _col,int d) {
	if(vis[x][y][_col]) return;
	if(a[x][y].lv) {
		if(a[x][y].col != col && a[x][y].lv <= lv)
			vis[x][y][_col] = 1;
		return;
	}
	vis[x][y][_col] = 1;
	int nx,ny,co;
	for(int k = 0; k < 4; ++k) {
		nx = x + dx[k];
		ny = y + dy[k];
		co = o[!dy[k]][x + dfx[k]][y + dfy[k]] - '0';
		if(!nx || !ny || nx > n || ny > m || !co) continue;
		if(co == 1 && !_col) dfs(nx,ny,1,-1);
		if(co == 2) {
			if(!_col) dfs(nx,ny,co,!dy[k]);
			else if(_col == 2 && d == !dy[k]) dfs(nx,ny,2,d);
		}
		if(co == 3 && (!_col || _col == 3)) dfs(nx,ny,3,-1);
	}
}
int main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin >> T;
	while(T--) {
		cin >> n >> m >> q;
		memset(a,0,sizeof a);
		for(int i = 1; i <= n; ++i) scanf("%s",o[0][i] + 1);
		for(int i = 1; i < n; ++i) scanf("%s",o[1][i] + 1);
		while(q--) {
			cin >> col >> lv >> fx >> fy;
			memset(vis,0,sizeof vis);
			ans = 0;
			dfs(fx,fy,0,-1);
			for(int i = 1; i <= n; ++i)
				for(int j = 1; j <= m; ++j)
					for(int k = 0; k < 4; ++k)
						if(vis[i][j][k]) {
							++ans;
							break;
						}
			cout << ans - 1 << endl;
			a[fx][fy].col = col;
			a[fx][fy].lv = lv;
		}
	}
	return 0;
}
