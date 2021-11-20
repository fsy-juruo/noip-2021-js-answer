/*
	long long / unsigned / BigInteger
	8:30 ~ 13:00
	Think twice, code once. Think once, debug forever!
	After re, resubmmit id.txt.
	Yes! Pa!
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(register int i = a; i < b; i++)
#define hrp(i, a, b) for(register int i = a; i <= b; i++)
#define rev(i, a, b) for(register int i = a; i >= b; i--)
#define D(x) cerr<<#x<<": "<<x<<endl;
using namespace std;
const int U = 200;
const int mod = 998244353;
int val[U];
int main(void)
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);

	int n, k, m, ans = 0;
	cin>>n>>m>>k;
	hrp(i, 0, m) cin>>val[i];
	
	hrp(a, 0, m) hrp(b, 0, m) hrp(c, 0, m) hrp(d, 0, m) hrp(e, 0, m) hrp(f, 0, m) hrp(g, 0, m) hrp(h, 0, m)
	{
		long long bits = (1<<a)+(1<<b)+(1<<c)+(1<<d)+(1<<e)+(1<<f)+(1<<g)+(1<<h);
		if (__builtin_popcount(bits) <= k)
		{
			long long t = val[a];
			t *= val[b]; t %= mod;
			t *= val[c]; t %= mod;
			t *= val[d]; t %= mod;
			t *= val[e]; t %= mod;
			t *= val[f]; t %= mod;
			t *= val[g]; t %= mod;
			t *= val[h]; t %= mod;
			ans += t;
			ans %= mod;
		}
	}
	
	cout<<ans<<endl;

	return 0;
}
/*
8 9 4
934258593 150407625 187068439 162292791 219945760 512449588 803393963 983648121 484675481 412407699

 */

