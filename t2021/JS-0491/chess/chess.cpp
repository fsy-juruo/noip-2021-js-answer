#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1}; 

struct chess_t {
	int col, lv;
	chess_t() { lv = col = -1; }
	chess_t(int col_, int lv_) : lv(lv_), col(col_) { }
};

vector<vector<int>> re, ce;
vector<vector<chess_t>> A;
int N, M, Q;

struct node {
	int x, y, cnt;
};

bool inside(int x, int y) { return 0 <= x && x < N && 0 <= y && y < M; } 
int edge_type(int x, int y, int d) {
	if (dx[d] == -1) return ce[x-1][y];
	else if (dx[d] == 1) return ce[x][y];
	else if (dy[d] == -1) return re[x][y-1];
	else return re[x][y];
}

vector<vector<array<int,2>>> vis;
int calc(int sx, int sy) {
	int ans = 0;
	queue<node> que;
//	cerr << "S " << sx << " " << sy << '\n';
	que.push({sx,sy,0});
	
	auto add_que = [&](int x, int y, int cnt) {
		if (!vis[x][y][cnt]) {
			que.push({x,y,cnt});
			vis[x][y][cnt] = 1;
		}
	};
	
	while (que.size()) {
		node u = que.front(); que.pop();
		int x = u.x, y = u.y;
//		cerr << x << " " << y << '\n'; 
		for (int d = 0; d < 4; d++) {
			int nx = x+dx[d], ny = y+dy[d];
			if (!inside(nx,ny)) continue;
			if (A[nx][ny].col == -1) {
				int t = edge_type(x, y, d);
				if (t == 3) add_que(nx, ny, (t==1)+u.cnt); // , cerr << "V " << nx << ',' << ny << '\n';
			}
			else if (A[nx][ny].col != A[sx][sy].col && A[nx][ny].lv < A[sx][sy].lv){
				int t = edge_type(x, y, d);
				if (t == 3) vis[nx][ny][0] = 1; // , cerr << "V " << nx << ',' << ny << '\n';
			}
		}
	}
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			if (vis[i][j][0] || vis[i][j][1]) {
//				cerr << i << ',' << j << '\n';
//			}
//		}
//	}
//	cerr << "=========\n";
//	cerr<< ans << '\n';
	
	for (int i = sx; i > 0; i--) {
		int nx = i-1, ny = sy;
		if (ce[i-1][sy] == 2 && (A[nx][ny].col == -1 || (A[nx][ny].col == A[sx][sy].col && A[nx][ny].lv < A[sx][sy].lv))) { 
			vis[nx][ny][0] = 1;
		}
		else break;
	}
	for (int i = sx; i < N-1; i++) {
		int nx = i+1, ny = sy;
		if (ce[i][sy] == 2 && (A[nx][ny].col == -1 || (A[nx][ny].col == A[sx][sy].col && A[nx][ny].lv < A[sx][sy].lv))) {
			vis[nx][ny][0] = 1;
		}
		else break;
	}
//	cerr << "FUCK\n";
	for (int j = sy; j > 0; j--) {
		int nx = sx, ny = j-1;
		if (re[sx][j-1] == 2 && (A[nx][ny].col == -1 || (A[nx][ny].col == A[sx][sy].col && A[nx][ny].lv < A[sx][sy].lv))) {
			vis[nx][ny][0] = 1;
		}
		else break;
	}
	for (int j = sy; j < M-1; j++) {
		int nx = sx, ny = j+1;
		if (re[sx][j] == 2 && (A[nx][ny].col == -1 || (A[nx][ny].col == A[sx][sy].col && A[nx][ny].lv < A[sx][sy].lv))) {
			vis[nx][ny][0] = 1;
		}
		else break;
	}
	for (int d = 0; d < 4; d++) {
		int nx = sx+dx[d], ny = sy+dy[d];
		if (inside(nx,ny) && edge_type(sx,sy,d) == 1 && (A[nx][ny].col == -1 || (A[nx][ny].col == A[sx][sy].col && A[nx][ny].lv < A[sx][sy].lv))) vis[nx][ny][0] = 1;
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) ans += vis[i][j][0]==1 || vis[i][j][1] == 1;
	return ans;
}

void solve() {
	cin >> N >> M >> Q;
	vis = vector<vector<array<int,2>>>(N, vector<array<int,2>>(M,{0,0}));
	A = vector<vector<chess_t>>(N, vector<chess_t>(M));
	re = vector<vector<int>>(N, vector<int>(M-1));
	ce = vector<vector<int>>(N-1, vector<int>(M));
	for (int i = 0; i < N; i++) {
		string foo; cin >> foo;
		for (int j = 0; j < M-1; j++) re[i][j] = foo[j] - '0';
	}
	for (int i = 0; i < N-1; i++) {
		string foo; cin >> foo;
		for (int j = 0; j < M; j++) ce[i][j] = foo[j] - '0';
	}
	while (Q--) {
		int col, lv, x, y;
		cin >> col >> lv >> x >> y;
		--x, --y;
		A[x][y] = chess_t(col, lv);
		int ans = calc(x, y);
//		cout << ans << '\n';
		A[x][y] = chess_t();
	}
}

int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) solve(); 
	return 0;
}
