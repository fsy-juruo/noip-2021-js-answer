#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
#define mp make_pair
typedef long long ll;
template <class T>
T read(T& x) {
	x = 0; T sign = 1, ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') { sign = -1, ch = getchar(); }
	while(isdigit(ch)) {
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	x *= sign;
	return x;
}
int T, n, m, q;
namespace Sub1 {
	const int dx[] = {0, -1, 1, 0, 0};
	const int dy[] = {0, 0, 0, -1, 1};
	const int N = 5010;
	// color: 0: no; 1: black; 2: white
	char s[N];
	struct node {
		short dir[5], color;
		#define up dir[1]
		#define down dir[2]
		#define left dir[3]
		#define right dir[4]
		int level;
	};
	vector<node> tp[N];
	ll h(int x, int y) { return (ll)(x) * 100000 + y; }
	void solve(int color, int level, int sx, int sy) {
		unordered_map<ll, short> st;
		// 1. normal road.
		for(int i = 1; i <= 4; i ++ )
			if(tp[sx][sy].dir[i] == 1) {
				int tx = sx + dx[i], ty = sy + dy[i];
				if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
				if(tp[tx][ty].color) {
					if(tp[tx][ty].color != color
					&& tp[tx][ty].level <= level)
						st[h(tx, ty)] = 1;
				} else st[h(tx, ty)] = 1;
			}
		// 2. straight road.
		for(int i = 1; i <= 4; i ++ ) {
			if(tp[sx][sy].dir[i] != 2) continue;
			int xx = sx, yy = sy;
			while(1 <= xx && xx <= n && 1 <= yy && yy <= m) {
				xx += dx[i]; yy += dy[i];
				if(!(1 <= xx && xx <= n && 1 <= yy && yy <= m))
					break;
				if(tp[xx][yy].color) {
					if(tp[xx][yy].color != color
					&& tp[xx][yy].level <= level) {
						#ifdef debug
						cout << "#2: xx == " << xx << ", yy == " << yy << endl;
						#endif
						st[h(xx, yy)] = 2;
					}
					break;
				}
				#ifdef debug
				cout << "#2: xx == " << xx << ", yy == " << yy << endl;
				#endif
				st[h(xx, yy)] = 2;
			}
		}
		#ifdef debug
		cout << "1, 2: complete!\n";
		#endif
		// 3. casual road.
		queue<PII> Q;
		Q.push(mp(sx, sy));
		while(!Q.empty()) {
			int xx = Q.front().first, yy = Q.front().second;
			#ifdef debug
			cout << "#3: front: " << xx << ", " << yy << endl;
			#endif
			Q.pop();
			for(int i = 1; i <= 4; i ++ ) {
				if(tp[xx][yy].dir[i] != 3) continue;
				int tx = xx + dx[i], ty = yy + dy[i];
				#ifdef debug
				cout << "tx: " << tx << ", ty: " << ty << endl;
				#endif
				if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
				if(tp[tx][ty].color) {
					if(tp[tx][ty].color != color
					&& tp[tx][ty].level <= level)
						st[h(tx, ty)] = 3;
				} else if(st[h(tx, ty)] != 3) {
					st[h(tx, ty)] = 3;
					Q.push(mp(tx, ty));
				}
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i ++ )
			for(int j = 1; j <= m; j ++ )
				if((i != sx || j != sy) && st.find(h(i, j)) != st.end() && st[h(i, j)]) {
					#ifdef debug
					cout << "i: " << i << ", j: " << j << endl;
					#endif
					ans ++ ;
				}
		printf("%d\n", ans);
	}
	int main() {
		for(int i = 1; i <= n; i ++ ) tp[i].clear();
		for(int i = 1; i <= n; i ++ ) tp[i].resize(m + 11);
		for(int i = 1; i <= n; i ++ ) {
			scanf(" %s", s + 1);
			for(int j = 1; j <= m - 1; j ++ ) {
				tp[i][j].right = s[j] - '0';
				tp[i][j + 1].left = s[j] - '0';
			}
		}
		for(int i = 1; i <= n - 1; i ++ ) {
			scanf(" %s", s + 1);
			for(int j = 1; j <= m; j ++ ) {
				tp[i][j].down = s[j] - '0';
				tp[i + 1][j].up = s[j] - '0';
			}
		}
		#ifdef debug
		for(int i = 1; i <= n; i ++ )
			for(int j = 1; j <= m; j ++ )
				printf("i: %d; j: %d; left: %d; right: %d; up: %d; down: %d\n", i, i, tp[i][j].left, tp[i][j].right, tp[i][j].up, tp[i][j].down);
		#endif
		for(int i = 1; i <= q; i ++ ) {
			int c = 0, lv = 0, x = 0, y = 0;
			read(c); read(lv); read(x); read(y); c ++ ;
			solve(c, lv, x, y);
			tp[x][y].color = c; tp[x][y].level = lv;
		}
		return 0;
	}
}
namespace Sub2 {
	const int dx[] = {0, -1, 1, 0, 0};
	const int dy[] = {0, 0, 0, -1, 1};
	char s[200010];
	map<PII, vector<int> > e;
	map<PII, int> color, level;
	int main() {
		for(int i = 1; i <= n; i ++ ) {
			scanf(" %s", s + 1);
			for(int j = 1; j <= m - 1; j ++ ) {
				e[mp(i, j)].push_back(4);
				e[mp(i, j + 1)].push_back(3);
			}
		}
		for(int i = 1; i <= n - 1; i ++ ) {
			scanf("%s", s + 1);
			for(int j = 1; j <= m; j ++ ) {
				e[mp(i, j)].push_back(2);
				e[mp(i, j + 1)].push_back(1);
			}
		}
		for(int i = 1; i <= q; i ++ ) {
			int col = 0, lv = 0, x = 0, y = 0;
			read(col); read(lv); read(x); read(y);
			int res = 0;
			for(unsigned i = 0; i < e[mp(x, y)].size(); i ++ ) {
				int dd = e[mp(x, y)][i];
				int tx = x + dx[dd], ty = y + dy[dd];
				if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
				if(color[mp(tx, ty)]) {
					if(color[mp(tx, ty)] != col
					&& level[mp(tx, ty)] <= lv) res ++ ;
				} else res ++ ;
			}
			printf("%d\n", res);
			color[mp(x, y)] = col;
			level[mp(x, y)] = lv;
		}
		return 0;
	}
}
int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	read(T);
	while(T -- ) {
		read(n); read(m); read(q);
		if(n <= 5000 && m <= 5000 && q <= 2000) {
			Sub1::main();
			continue;
		}
		else Sub2::main(); // #7 #8
	}
	return 0;
}

