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

const int N = 1e7 + 5;
int nxt[N];
bool vis[N];

bool Med;
int main() {
	fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for(int i = 1; i < N; i++) if(!vis[i]) {
		int ok = 1, tmp = i;
		while(tmp) ok &= tmp % 10 != 7, tmp /= 10;
		if(ok) continue;
		for(int j = i; j < N; j += i) vis[j] = 1;
	}
	for(int i = N - 2; i; i--) nxt[i] = vis[i + 1] ? nxt[i + 1] : i + 1;
	int T; cin >> T;
	while(T--) {
		int x = read();
		if(vis[x]) print(-1), pc('\n');
		else print(nxt[x]), pc('\n');
	}
	return cerr << "Time : " << clock() << endl, 0;
}
