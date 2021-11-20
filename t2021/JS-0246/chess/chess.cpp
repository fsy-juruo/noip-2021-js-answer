#include<bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 5e3 + 10;

int l[N][N];
int h[N][N];
int qzh[N][N];
int n , m , q;
int T;
int vis[N][N];
int vht[N][N];
int cnt;

struct node{
	int col , lv , x , y;
} qz[N];
int ans;

template <typename T> inline void read(T &x) {
	T f = 1; char c = getchar(); x = 0;
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}

template <typename T> inline void chkmax(T &x , T y) {x = x > y ? x : y; }
template <typename T> inline void chkmin(T &x , T y) {x = x < y ? x : y; }

template <typename T> inline void print(T x) {
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> inline void write(T x , char c) {
	if (x < 0) {x = -x; putchar('-'); }
	print(x);
	putchar(c);
}

inline bool pk(int i , int j) {
	if (!j) return 1;
	if (qz[i].col == qz[j].col || qz[i].lv < qz[j].lv) return 0;
	return 1;
}

inline void dfs1(int x , int y , int num) {
	vis[x][y] = num;
	if (h[x - 1][y] == 1 && pk(num , qzh[x - 1][y])) {
		vis[x - 1][y] = num;
	}
	if (h[x][y] == 1 && pk(num , qzh[x + 1][y])) {
		vis[x + 1][y] = num;
	}
	if (l[x][y - 1] == 1 && pk(num , qzh[x][y - 1])) {
		vis[x][y - 1] = num;
	} 
	if (l[x][y] == 1 && pk(num , qzh[x][y + 1])) {
		vis[x][y + 1] = num;
	}
	return;
}

inline void dfs2(int x , int y , int num , int fx) {
	vis[x][y] = num;
	if (qzh[x][y] && qzh[x][y] != num) return;
	if (fx) {
		if (fx == 1) {
			if (h[x - 1][y] == 2 && pk(num , qzh[x - 1][y])) dfs2(x - 1 , y , num , fx);
		}
		else
		if (fx == 2) {
			if (h[x][y] == 2 && pk(num , qzh[x + 1][y])) dfs2(x + 1 , y , num , fx);
		}
		else 
		if (fx == 3) {
			if (l[x][y - 1] == 2 && pk(num , qzh[x][y - 1])) dfs2(x , y - 1 , num , fx);
		}
		else if (l[x][y] == 2 && pk(num , qzh[x][y + 1])) dfs2(x , y + 1 , num , fx);
		return;
	}
	if (h[x - 1][y] == 2 && pk(num , qzh[x - 1][y])) dfs2(x - 1 , y , num , 1);
	if (h[x][y] == 2 && pk(num , qzh[x + 1][y])) dfs2(x + 1 , y , num , 2);
	if (l[x][y - 1] == 2 && pk(num , qzh[x][y - 1])) dfs2(x , y - 1 , num , 3);
	if (l[x][y] == 2 && pk(num , qzh[x][y + 1])) dfs2(x , y + 1 , num , 4);
	return;
}

inline void dfs3(int x , int y , int num) {
	vis[x][y] = vht[x][y] = num;
	if (qzh[x][y] && qzh[x][y] != num) return;
	if (h[x - 1][y] == 3 && pk(num , qzh[x - 1][y]) && vht[x - 1][y] != num) dfs3(x - 1 , y , num);
	if (h[x][y] == 3 && pk(num , qzh[x + 1][y]) && vht[x + 1][y] != num) dfs3(x + 1 , y , num);
	if (l[x][y - 1] == 3 && pk(num , qzh[x][y - 1]) && vht[x][y - 1] != num) dfs3(x , y - 1 , num);
	if (l[x][y] == 3 && pk(num , qzh[x][y + 1]) && vht[x][y + 1] != num) dfs3(x , y + 1 , num);
}

int main() {

	freopen("chess.in" , "r" , stdin);
	freopen("chess.out" , "w" , stdout);

	read(T);
	
	while(T--) {
		read(n); read(m); read(q);
		for (int i = 1; i <= n; i++) {
			char ch;
			for (int j = 1; j < m; j++) {
				ch = getchar();
				l[i][j] = ch - '0';
			}
			ch = getchar();
		}
		for (int i = 1; i < n; i++) {
			char ch;
			for (int j = 1; j <= m; j++) {
				ch = getchar();
				h[i][j] = ch - '0';
			}
			ch = getchar();
		}
		
		for (int i = 0; i <= n + 1; i++) {
			l[i][0] = l[i][m] = 0;
		}
		for (int i = 0; i <= m + 1; i++) {
			h[0][i] = h[n][i] = 0;
		}
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				vis[i][j] = vht[i][j] = qzh[i][j] = 0;
			}
		}
		for (int i = 1; i <= q; i++) {
			read(qz[i].col); read(qz[i].lv); read(qz[i].x); read(qz[i].y);
			qzh[qz[i].x][qz[i].y] = i;
			ans = 0;
			dfs1(qz[i].x , qz[i].y , i);
			dfs2(qz[i].x , qz[i].y , i , 0);
			dfs3(qz[i].x , qz[i].y , i);
			for (int j = 1; j <= n; j++) 
				for (int k = 1; k <= m; k++) ans += (vis[j][k] == i) ? 1 : 0;
			write(ans - 1 , '\n');
		}
	}

	return 0;

}

