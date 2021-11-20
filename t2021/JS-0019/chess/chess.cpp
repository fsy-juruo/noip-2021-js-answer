#include<bits/stdc++.h>
#define mem(a,b) memset(a, b, sizeof(a))
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define per(i,b,a) for(int i = (b); i >= (a); i--)
#define PII pair<int, int>
#define fr first
#define sc second
#define N 200021
using namespace std;

int read(){
	int s = 0, w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') w = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') s = (s<<3) + (s<<1) + (ch^48), ch = getchar();
	return s*w;
}

struct query{
	int n, m, q;
	vector<vector<char> > a, b;
	vector<int> x, y, col, lv;
} Q[6];
int T;

namespace brute{
#define N 5050
	int n, m, q;
	char a[N][N], b[N][N];
	vector<PII> pos;
	bool vis[N][N][6];
	int col[N][N], lv[N][N];
	int X[4] = {0, 1, 0, -1}, Y[4] = {1, 0, -1, 0};
	int _, ans = 0;
	
	bool legal(int i, int j){
		return i > 0 && i <= n && j > 0 && j <= m;
	}
	int type(int x, int y, int dir){
		if(dir == 0) return Q[_].a[x][y] - '0';
		if(dir == 2) return Q[_].a[x][y-1] - '0';
		if(dir == 1) return Q[_].b[x][y] - '0';
		if(dir == 3) return Q[_].b[x-1][y] - '0';
	}
	
	void dfs(int x, int y, int c, int lvl, int dir){
		if(!legal(x, y)) return;
		if(lv[x][y] && (col[x][y] == c || lv[x][y] > lvl)) return;
		if(vis[x][y][dir+2]) return;
		//cout<<x<<","<<y<<" "<<c<<" "<<lvl<<" "<<dir<<endl;
		bool un = false;
		rep(d,0,5) un |= vis[x][y][d];
		if(!un) ans++, pos.push_back({x, y});
		vis[x][y][dir+2] = true;
		if(dir == -2) return;
		if(lv[x][y]) return;
		int l = (~dir) ? dir : 0, r = (~dir) ? dir : 3;
		rep(i,l,r){
			//cout<<x<<","<<y<<","<<i<<": "<<type(x, y, i)<<endl;
			if(type(x, y, i) != ((~dir) ? 2 : 3)) continue;
			dfs(x+X[i], y+Y[i], c, lvl, dir);
		}
	}
	
	void solve(){
		for(_ = 1; _ <= T; _++){
			n = Q[_].n, m = Q[_].m, q = Q[_].q;
			int x, y, c, lvl;
			rep(k,0,q-1){
				x = Q[_].x[k], y = Q[_].y[k], c = Q[_].col[k], lvl = Q[_].lv[k];
				//cout<<"{"<<x<<","<<y<<","<<c<<","<<lvl<<"}\n";
				col[x][y] = c, lv[x][y] = lvl;
				ans = 0;
				rep(i,0,3){
					int t = type(x, y, i);
					//cout<<x<<","<<y<<","<<i<<": "<<t<<endl;
					if(t == 1) dfs(x+X[i], y+Y[i], c, lvl, -2);
					else if(t == 2) dfs(x+X[i], y+Y[i], c, lvl, i);
					else if(t == 3) dfs(x+X[i], y+Y[i], c, lvl, -1);
				}
				cout<< ans <<endl;
				for(PII p : pos) rep(d,0,5) vis[p.fr][p.sc][d] = false;
				pos.clear();
 			}
 			mem(col, 0), mem(lv, 0);
		}
	}
}

int main(){
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	T = read();
	bool small = true;
	int n, m;
	rep(_,1,T){
		n = Q[_].n = read(), m = Q[_].m = read(), Q[_].q = read();
		small &= Q[_].n * Q[_].m <= 5000 && Q[_].q <= 2000;
		Q[_].a.resize(n+5, vector<char>(m+5));
		Q[_].b.resize(n+5, vector<char>(m+5));
		rep(i,1,n) scanf("%s", Q[_].a[i].begin()+1);
		rep(i,1,n-1) scanf("%s", Q[_].b[i].begin()+1);
		int i, j, c, l;
		rep(__,1,Q[_].q){
			c = read(), l = read(), i = read(), j = read();
			Q[_].x.push_back(i), Q[_].y.push_back(j), Q[_].col.push_back(c), Q[_].lv.push_back(l);
		}
	}
	brute::solve();
	return 0;
}
/*
1
3 3 5
12
22
23
010
233
0 1 2 3
1 2 2 1
1 3 1 2
0 2 3 2
1 3 2 2
*/





