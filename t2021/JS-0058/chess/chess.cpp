#include<bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
const int MAXN = 5000 + 10;
const int MAXM =  + 10;

inline int fread(void){
	char ch = getchar(); int ret = 0, op = 1;
	for(; !isdigit(ch) && ch != '-'; ch = getchar());
	if(ch == '-') op = -1;
	else ret = ch - '0';
	ch = getchar();
	for(; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	return ret * op;
}

int n, m, q;
vector<int>a[MAXN], b[MAXN];
char str[MAXN];
inline void init(void){
	n = fread(), m = fread(), q = fread();
	for(int i = 1; i <= n; ++ i) a[i].clear(), b[i].clear();
	for(int i = 1; i <= n; ++ i){
		scanf("%s", str + 1); a[i].push_back(-1);
		for(int j = 1; j <= m - 1; ++ j) a[i].push_back(str[j] - '0');
	}
	for(int i= 1; i < n; ++ i){
		scanf("%s", str + 1); b[i].push_back(-1);
		for(int j = 1; j <= m; ++ j) b[i].push_back(str[j] - '0');
	}
	
}

vector<int>vis[MAXN][5], v[MAXN];
vector<pair<int, int> >mp[MAXN];
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
#define check(x, y) (x >= 1 && x <= n && y >= 1 && y <= m)
inline int Type(int x, int y, int tp){
	int now;
	if(tp == 0)
		now = a[x][y];
	if(tp == 1) now = a[x][y - 1];
	if(tp == 2) now = b[x][y];
	if(tp == 3) now = b[x - 1][y]; 
	if(now == 2 && tp <= 1) return 4;
	if(now == 2 && tp >= 2) return 5;
	return now;  
}
struct Point{
	int x, y, s; 
	Point(){x = y = s = 0; }
	Point(int _x, int _y, int _s) : x(_x), y(_y), s(_s) {}
};
queue<Point>Q; 
int BFS(int col, int lv, int x, int y){
	int ret = 0; 
	for(int i = 1; i <= n; ++ i) for(int t = 0; t < 6; ++ t) vis[i][t].clear(), vis[i][t].resize(m + 1); 
	for(int i = 1; i <= n; ++ i) v[i].clear(), v[i].resize(m + 1); 
	Q.push(Point(x, y, 0));
	while(!Q.empty()){
		auto now = Q.front(); Q.pop();
		if(mp[now.x][now.y].first == col || mp[now.x][now.y].second > lv) continue;
		if(vis[now.x][now.s][now.y]) continue;
		vis[now.x][now.s][now.y] = 1; 
		ret += (!v[now.x][now.y]); v[now.x][now.y] = 1; 
		if(mp[now.x][now.y].first + col == 3 && mp[now.x][now.y].second <= lv) continue;
		for(int i = 0; i < 4; ++ i){
			int xx = now.x + dx[i], yy = now.y + dy[i];
			if(!check(xx, yy) || Type(now.x, now.y, i) == 0) continue;
			if(now.s == 0 && Type(now.x, now.y, i) == 1) Q.push(Point(xx, yy, 1));
			if((!now.s || now.s == 4) && Type(now.x, now.y, i) == 4){
				Q.push(Point(xx, yy, 4));
			} 
			if((!now.s || now.s == 5) && Type(now.x, now.y, i) == 5) Q.push(Point(xx, yy, 5));
			if((!now.s || now.s == 3) && Type(now.x, now.y, i) == 3) Q.push(Point(xx, yy, 3)); 
		}
	}
	while(!Q.empty()) Q.pop();
	return ret;
	
}
inline void work(void){
	for(int i = 1; i <= n; ++ i) mp[i].clear(), mp[i].resize(m + 1);
	int col, lv, x, y;
	for(int i = 1; i <= q; ++ i){
		col = fread() + 1, lv = fread(), x = fread(), y = fread();
		printf("%d\n", BFS(col, lv, x, y) - 1);
		mp[x][y] = make_pair(col, lv); 
	}
}

int main(){
	freopen("chess.in", "r", stdin); freopen("chess.out", "w", stdout); 
int T = fread();
	while(T--)
	init(), work();
	fclose(stdin); fclose(stdout);
	return 0;
}

