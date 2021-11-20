/*
	long long / unsigned / BigInteger
	8:30 ~ 13:00
	Think twice, code once. Think once, debug forever!
	After re, resubmmit id.txt.
	Yes! Pa!
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define hrp(i, a, b) for(int i = a; i <= b; i++)
#define rev(i, a, b) for(int i = a; i >= b; i--)
#define D(x) cerr<<#x<<": "<<x<<endl;
using namespace std;
typedef pair<long long, long long> pii;
const long long U = 105;
long long w[U], n, minn, g;
void dfs(int depth)
{
	if (depth > g) return;
	
	vector<pii> v;
	long long aver = 0;
	v.clear();
	rep(i, 0, n) aver += w[i];
	aver /= n;
	rep(i, 1, n-1)
	{
		long long after = w[i-1]+w[i+1]-w[i], be1 = abs(w[i]-aver), af1 = abs(after-(aver+(after-w[i])/n));
		if (after != w[i] && be1-af1 > 0) v.push_back(pii(be1-af1, i));
	}
	if (v.empty()) return;
	sort(v.begin(), v.end(), greater<pii>());
	
	rep(i, 0, v.size())
	{
		long long after = w[v[i].second-1]+w[v[i].second+1]-w[v[i].second], m = 0, be = w[v[i].second];
		long long cp[U]; memcpy(cp, w, sizeof(w));
		aver += (after-w[v[i].second])/n;
		w[v[i].second] = after;
		rep(i, 0, n) m += (aver-w[i])*(aver-w[i]);
		minn = min(m, minn);
		dfs(depth+1);
		memcpy(w, cp, sizeof(cp));
	}
}
int main(void)
{
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);

	long long t; cin>>n;
	rep(i, 0, n) cin>>w[i], w[i] *= n, t += w[i];
	t /= n;
	rep(i, 0, n) minn += (t-w[i])*(t-w[i]);

	g = 20; dfs(0);
	
	cout<<minn/n<<endl;

	return 0;
}
/*
10 6 27 42 55 55 56 57 63 80 99
 */

