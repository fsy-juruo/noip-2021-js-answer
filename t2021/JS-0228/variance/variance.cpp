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
const int N = 10010;
ll n, a[N], b[N];
double aver = 0.0, ans = 0.0, minn = 1e10;
set<double> st;
int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	read(n);
	for(int i = 1; i <= n; i ++ ) read(a[i]);
	while(1) {
		memcpy(b, a, sizeof a);
		for(int i = 2; i <= n - 1; i ++ )
			a[i] = a[i - 1] + a[i + 1] - a[i];
		aver = 0.0, ans = 0.0;
		for(int i = 1; i <= n; i ++ ) aver += a[i];
		aver /= n;
		for(int i = 1; i <= n; i ++ )
			ans += (a[i] - aver) * (a[i] - aver);
		ans *= n;
		#ifdef debug
		for(int i = 1; i <= n; i ++ ) cout << a[i] << " ";
		cout << endl << ans << endl << endl;
		#endif
		if(abs(minn - ans) <= 1e-6) break;
		minn = min(minn, ans);
	} 
	printf("%.0lf", minn);
	return 0;
}

