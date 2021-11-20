#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
template<typename T> inline void read(T &F) {
	F = 0; int R = 1; char CH = getchar();
	for(; !isdigit(CH); CH = getchar()) if(CH == '-') R = -1;
	for(; isdigit(CH); CH = getchar()) F = F * 10 + CH - 48;
	F = F * R;
}
inline void file(string str) {
	freopen((str + ".in").c_str(), "r", stdin);
	freopen((str + ".out").c_str(), "w", stdout);
}
const int N = 1e4 + 10;
int ai[N], n, pi[N], ci[N]; LL f[N];
int main() {
	file("variance");
	read(n);
	for(int i = 1; i <= n; i++) read(pi[i]);
	for(int i = 1; i < n; i++) ai[i] = pi[i + 1] - pi[i];
	for(int i = 1; i < n; i++) pi[i] = i;
	LL res = LONG_LONG_MAX; n--; int tot = 0;
	do {
		if(tot * n > 100000000) break;
		LL s = 0;
		for(int i = 1; i <= n; i++)
			f[i] = f[i - 1] + ai[pi[i]], s += f[i];
		LL ans = 0;
		for(int i = 0; i <= n; i++)
			ans += (s - (n + 1) * f[i]) * (s - (n + 1) * f[i]);
		if(ans < res) res = ans;
		tot++;
	} while(next_permutation(pi + 1, pi + n + 1));
	cout << res / (n + 1) << endl;
	return 0;
}

