#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
#define rep(i,j,k) for(int (i)=(j);(i)<=(k);(i)++)
#define rap(i,j,k) for(int (i)=(j);(i)<(k);(i)++)
#define per(i,j,k) for(int (i)=(j);(i)>=(k);(i)--)
#define sit set<int>::iterator
#define mit map<int,int>::iterator
#define pb push_back
#define pii pair<int,int>
#define mpr make_pair
typedef long long ll;
int T,n,m,q;
char h[5005][5005],s[5005][5005];
int c[5005][5005],l[5005][5005];
bool vis[5005][5005],ok[5005][5005];
bool can_be_on(int x,int y,int col,int lv) {
	if(!l[x][y]) return 1;
	return c[x][y] != col && l[x][y] <= lv;
}
void dfs(int x,int y,int col,int lv) {
	//printf("%d %d %d %d\n",x,y,col,lv);
	if(vis[x][y]) return;
	vis[x][y] = 1;
	if(x > 1 && s[x - 1][y] == '3' && can_be_on(x - 1, y, col, lv)) {
		if(!l[x - 1][y]) dfs(x - 1, y, col, lv);else ok[x - 1][y] = 1;
	}
	if(x < n && s[x][y] == '3' && can_be_on(x + 1, y, col, lv)) {
		if(!l[x + 1][y]) dfs(x + 1, y, col, lv);else ok[x + 1][y] = 1;
	}
	if(y > 1 && h[x][y - 1] == '3'&& can_be_on(x, y - 1, col, lv)) {
		if(!l[x][y - 1]) dfs(x, y - 1, col, lv);else ok[x][y - 1] = 1;
	}
	if(y < m && h[x][y] == '3'&& can_be_on(x, y + 1, col, lv)) {
		if(!l[x][y + 1]) dfs(x, y + 1, col, lv);else ok[x][y + 1] = 1;
	}
}
const int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
const int Dx[4] = {-1,0,0,0}, Dy[4] = {0,0,-1,0};
void solve()
{
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,n) scanf("%s",h[i]+1);
	rep(i,1,n - 1) scanf("%s",s[i]+1);
	rep(i,1,q) {
		int col,lv,x,y;
		scanf("%d%d%d%d",&col,&lv,&x,&y);
		c[x][y] = col;
		l[x][y] = lv;
		ok[x][y] = 1;
		rep(p,0,3) if((p == 0 && x != 1) || (p == 1 && x != n) || (p == 2 && y != 1) || (p == 3 && y != m)) {
			char ch = (p <= 1 ? s[x + Dx[p]][y + Dy[p]] : h[x + Dx[p]][y + Dy[p]]);
			if(ch == '1') {
				if(can_be_on(x + dx[p], y + dy[p], col, lv)) ok[x + dx[p]][y + dy[p]] = 1;
			}
			if(ch == '2') {
				int nx = x + dx[p], ny = y + dy[p];
				while(nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
				
					if(!can_be_on(nx, ny, col ,lv)) break;
					ok[nx][ny] = 1;
					if(l[nx][ny]) break;
					char ch = (p <= 1 ? s[nx + Dx[p]][ny + Dy[p]] : h[nx + Dx[p]][ny + Dy[p]]);
				if(ch != '2') break;
					nx += dx[p];ny += dy[p];
				}
			}
			if(ch == '3') {
				if(!l[x + dx[p]][y + dy[p]]) dfs(x + dx[p], y + dy[p], col, lv);
				else if(can_be_on(x + dx[p], y + dy[p], col, lv)) ok[x + dx[p]][y + dy[p]] = 1;
			}
		}
		int ans = 0;
		rep(i,1,n) rep(j,1,m) ans += ok[i][j] | vis[i][j];
		printf("%d\n",ans - 1);
		rep(i,1,n) rep(j,1,m) ok[i][j] = vis[i][j] = 0;
	}
	rep(i,1,n) rep(j,1,m) h[i][j] = s[i][j] = l[i][j] = c[i][j] = 0;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
