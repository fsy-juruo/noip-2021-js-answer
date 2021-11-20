#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i <= (b); ++i)
#define DF(i, a, b) for (int i = (a); i >= (b); --i)
#define SZ(x) (int)x.size() - 1
#define all(x) x.begin(), x.end()

using namespace std;
template <typename T> inline void read(T& x) {
	x = 0; int f = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	x *= f;
}
template <typename T> inline void write(T x) {
	if (x < 0) { putchar('-'); x *= -1; }
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
template <typename T> inline void writes(T x) { write(x); putchar(' '); }
template <typename T> inline void writeln(T x) { write(x); puts(""); }
template <typename T> inline void chkmax(T& x, T y) { x = max(x, y); }
template <typename T> inline void chkmin(T& x, T y) { x = min(x, y); }

const int N = 2e5 + 10;
vector <pair<int, int>> v[N];
int s, col[N], lv[N];
int h[N];
queue <int> q;
void work(int x, int y, int a, int b) {
	while (1) {
//		cout << x << endl;
		bool flag = false;
		for (pair <int, int> i: v[x])
			if (i.second == 2 && i.first == x + y) {
				flag = true;
				break;
			}
		if (flag) {
			x += y;
			if (!col[x] || (a >= lv[x] && b != col[x])) h[x] = 1, s++;
			if (col[x]) return;
		} else return;
	}
}
void work2(int x, int a, int b) {
	q.push(x);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (pair <int, int> i: v[x]) {
			if (i.second != 3) continue;
			if (h[i.first] != 2) {
				if (!col[i.first] || (a >= lv[i.first] && b != col[i.first])) {
					if (!h[i.first]) {
//						cout << x << "->" << i.first << endl;
						h[i.first] = 2, s++;
					}
					if (!col[i.first]) q.push(i.first);
				}
			}
		}
	}
}

int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	int _; read(_);
	while (_--) {
		int n, m, q; read(n); read(m); read(q);
		F(i, 1, n * m) v[i].clear(), col[i] = lv[i] = 0;
		F(i, 1, n) {
			F(j, 1, m - 1) {
				char ch = getchar();
				for (; !isdigit(ch); ch = getchar());
				int x = (i - 1) * m + j, y = (i - 1) * m + j + 1;
				if (ch != '0') {
					v[x].push_back(make_pair(y, ch - '0'));
					v[y].push_back(make_pair(x, ch - '0'));
				}
			}
		}
		F(i, 1, n - 1) {
			F(j, 1, m) {
				char ch = getchar();
				for (; !isdigit(ch); ch = getchar());
				int x = (i - 1) * m + j, y = i * m + j;
				if (ch != '0') {
					v[x].push_back(make_pair(y, ch - '0'));
					v[y].push_back(make_pair(x, ch - '0'));
				}
			}
		}
		if (n * m <= 5000) {
			while (q--) {
				s = 0;
				int col, lv, x, y; read(col); read(lv); read(x); read(y); col++;
				F(i, 1, n * m) h[i] = 0;
				h[(x - 1) * m + y] = 2;
				for (pair <int, int> i: v[(x - 1) * m + y])
					if (i.second == 1) {
						if (!::col[i.first] || (::col[i.first] != col && lv >= ::lv[i.first])) {
							if (!h[i.first]) h[i.first] = 1, s++;
						}
					}
				work((x - 1) * m + y, -1, lv, col);
				work((x - 1) * m + y, 1, lv, col);
				work((x - 1) * m + y, -m, lv, col);
				work((x - 1) * m + y, m, lv, col);
//				return 0;
//				cout << s << endl;
				work2((x - 1) * m + y, lv, col);
				writeln(s);
//				cout << s << endl;
//				F(i, 1, n * m) {
//					if (h[i]) {
//						cout << ::col[i] << " " << ::lv[i] << " " << h[i] << " " << (i - 1) / m << " " << i - (i - 1) / m * m << endl;
//					}
//				}
				::col[(x - 1) * m + y] = col; ::lv[(x - 1) * m + y] = lv;
			}
		}
	}
	return 0;
}

