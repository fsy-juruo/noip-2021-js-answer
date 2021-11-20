#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mem(x, v, s) memset(x, v, sizeof(x[0]) * (s))
#define cpy(x, y, s) memcpy(x, y, sizeof(x[0]) * (s))
#define pii pair <int, int>
#define gc getchar()
#define pc(x) putchar(x)
bool Mbe;

inline int read() {
	int x = 0, sgn = 0; char s = gc;
	while(!isdigit(s)) sgn |= s == '-', s = gc;
	while(isdigit(s)) x = x * 10 + s - '0', s = gc;
	return sgn ? -x : x;
}
void rprint(int x) {if(x >= 10) rprint(x / 10); pc(x % 10 + '0');}
void print(int x) {if(x < 0) pc('-'), x = -x; rprint(x);}

const int N = 1e4 + 5;
const int V = 600 + 5;
void cmin(int &x, int y) {if(x > y) x = y;}
void cmax(int &x, int y) {if(x < y) x = y;}
void cmin(ll &x, ll y) {if(x > y) x = y;}

int n, a[N];
namespace BF {
	int s[N], id[N];
	void solve() {
		int ans = 2e9;
		for(int i = 1; i < n; i++) s[i] = a[i + 1] - a[i], id[i] = i;
		do {
			int sum = 0, sqs = 0, pre = 0;
			for(int i = 1; i < n; i++) {
				pre += s[id[i]];
				sum += pre, sqs += pre * pre;
			} ans = min(ans, n * sqs - sum * sum);
		} while(next_permutation(id + 1, id + n));
		cout << ans << endl;
	}
}

namespace BF2 {
	int s[N];
	void solve() {
		int ans = 2e9;
		for(int i = 1; i < n; i++) s[i] = a[i + 1] - a[i];
		sort(s + 1, s + n);
		for(int i = 0; i < 1 << n - 1; i++) {
			int sum = 0, sqs = 0, pre = 0;
			for(int j = n - 1; j; j--)
				if(i >> j - 1 & 1)
					pre += s[j], sum += pre, sqs += pre * pre;
			for(int j = 1; j < n; j++)
				if((i >> j - 1 & 1) == 0)
					pre += s[j], sum += pre, sqs += pre * pre;
			ans = min(ans, n * sqs - sum * sum);
		} cout << ans << endl;
	}
}

namespace BF3 {
	const int V = 75;
	const int B = V * V;
	const int inf = 1e9;
	
	int f[2][V][B << 1], s[N], ss[N];
	void solve() {
		int ori = n, ans = 2e9;
		for(int i = 1; i < n; i++) s[i] = a[i + 1] - a[i];
		sort(s + 1, s + n);
		for(int i = 1, nn = 0; i < n; i++) {
			if(s[i]) s[++nn] = s[i];
			if(i == n - 1) n = nn;
		}
		for(int i = 1; i <= n; i++) ss[i] = ss[i - 1] + s[i];
		mem(f, 0x3f, 2), f[0][0][B] = 0;
		for(int i = 1, p = 0, q = 1; i <= n; i++, swap(p, q)) {
			mem(f[q], 0x3f, ss[i] + 1);
			for(int j = 0; j <= ss[i - 1]; j++)
				for(int k = 0; k < B << 1; k++)
					if(f[p][j][k] < inf) {
						int lft = -j - s[i], rt = ss[i - 1] - j + s[i];
						if(k + lft >= 0) cmin(f[q][j + s[i]][k + lft], f[p][j][k] + lft * lft);
						if(k + rt < B << 1) cmin(f[q][j][k + rt], f[p][j][k] + rt * rt);
					}
		}
		for(int i = 0; i < V; i++)
			for(int j = 0; j < B << 1; j++) if(f[n & 1][i][j] < inf) {
				int rj = j - B;
				cmin(ans, ori * f[n & 1][i][j] - rj * rj);
			}
		cout << ans << endl;
	}
}

namespace BF4 {
	const int V = 300 + 5;
	const int B = V * 12;
	const ll inf = 1e18;
	
	ll f[2][V][B << 1];
	int s[N], ss[N];
	void solve() {
		ll ori = n, ans = 1e18;
		for(int i = 1; i < n; i++) s[i] = a[i + 1] - a[i];
		sort(s + 1, s + n);
		for(int i = 1, nn = 0; i < n; i++) {
			if(s[i]) s[++nn] = s[i];
			if(i == n - 1) n = nn;
		}
		for(int i = 1; i <= n; i++) ss[i] = ss[i - 1] + s[i];
		mem(f, 0x3f, 2), f[0][0][B] = 0;
		for(int i = 1, p = 0, q = 1; i <= n; i++, swap(p, q)) {
			mem(f[q], 0x3f, min(V, ss[i] + 1));
			for(int j = 0; j <= min(V - 1, ss[i - 1]); j++)
				for(int k = 0; k < B << 1; k++) {
					ll v = f[p][j][k];
					if(v < inf) {
						int lft = -j - s[i], rt = ss[i - 1] - j + s[i];
						if(k + lft >= 0 && j + s[i] < V) cmin(f[q][j + s[i]][k + lft], v + lft * lft);
						if(k + rt < B << 1) cmin(f[q][j][k + rt], v + rt * rt);
					}
				}
		}
		for(int i = 0; i < V; i++)
			for(ll j = 0; j < B << 1; j++) if(f[n & 1][i][j] < inf) {
				int rj = j - B;
				cmin(ans, ori * f[n & 1][i][j] - rj * rj);
			}
		cout << ans << endl;
	}
}

bool Med;
int main() {
	fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
	int t = clock();
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n <= 10) BF :: solve(), exit(0);
	if(n <= 20) BF2 :: solve(), exit(0);
	if(n <= 50 || a[n] <= 50) BF3 :: solve(), exit(0);
	BF4 :: solve();
	return cerr << "Time : " << clock() - t << endl, 0;
}

/*
20
1 3 6 10 15 21 33 46 48 99 101 122 156 178 196 233 255 278 296 300
*/
