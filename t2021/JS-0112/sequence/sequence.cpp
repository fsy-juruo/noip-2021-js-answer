#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int P = 998244353;
template <typename T> inline void rd(T &x)
{
	x = 0; int f = 1; char ch = 0;
	for(;!isdigit(ch); ch = getchar()) if(ch == '-') f = -f;
	for(; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + ch - 48;
}
template <typename T> inline void write(T x)
{
	if(x < 0) {putchar('-'); write(-x); return;}
	if(x <= 9){putchar(x + 48); return;}
	write(x / 10); putchar(x % 10 + 48);
}
template <typename T> inline void writeln(T x) {write(x); puts("");}

ll Qpow(ll x,int y)
{
	ll base = x; ll ret = 1;
	while(y)
	{
		if(y & 1) ret = (ret * base) % P;
		base = (base * base) % P;
		y = y >> 1;
	}
	return ret;
}

int k,n,w[105],m,lg[105];
ll v[105];
map <vector<int>, int> vis;

namespace Subtask1
{
	vector <int> q,qq;
	ll ans = 0;
	ll C(ll n, ll m)
	{
		ll fz = 1, fm = 1;
		for(int i = n, cnt = 1; cnt <= m; ++cnt,--i) fz = (fz * i) % P;
		for(int j = 1; j <= m; ++j) fm = (fm * j) % P;
		return fz * Qpow(fm, P - 2);
	}
	bool chk(int x)
	{
		int cnt = 0;
		while(x)
		{
			if(x & 1) ++cnt;
			x = x >> 1;
		}
		return (cnt <= k);
	}
	ll calc()
	{
		int cnt = 1; ll ret = 1; ll val = 1;
		vector <int> qqq = qq; val = v[qqq[0]];
		for(int i = 1; i < qqq.size(); ++i)
		{
			val = (val * v[qqq[i]]) % P;
			if(qqq[i] != qqq[i - 1])
			{
				ret = (ret * C(n - i + cnt, cnt)) % P;
				cnt = 1;
			}
			else ++cnt;
		}
		return ret * val % P;
	}
	void dfs(int x)
	{
		if(x >= n)
		{
	//		ll tmp = 0;
			qq = q;
			sort(qq.begin(), qq.end());
			for(int i = 0; i < q.size(); ++i)
			{
	//			tmp += q[i] * w[q[i]];
				if(q[i] > m) return;
			}
			if(vis[qq]) return;
			vis[qq] = 1;
//			for(int i = 0; i < q.size(); ++i) cout << q[i] << " ";
//			cout << endl;
			ans = (ans + calc()) % P;
			return;
		}
		for(int i = 0; i < q.size(); ++i)
		{
			if(!q[i]) continue;
			--q[i]; q.push_back(q[i]);
			dfs(x + 1);
			++q[i]; q.pop_back();
		}
	}
	void work(int x,int sp)
	{
		q.clear();
		int cnt = 0;
		if(sp == 1) q.push_back(x);
		else
		{
			while(x)
			{
				if(x & 1) q.push_back(cnt);
				x = x >> 1;
				++cnt;
			}
		}
		dfs(q.size());
	}	
	void solve()
	{
		for(int i = n; i <= n * (1 << m); ++i)
		{
			if(chk(i))
			{
				work(i,0);
			}
		}
		writeln(ans);
	}
	void spc()
	{
		for(int i = 0; i <= m + lg[n]; ++i)
		{
			if(i < 10 && (1 << i) < n) continue;
			work(i, 1);
		}
		writeln(ans);
	}
}

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	rd(n); rd(m); rd(k);
	for(int i = 0; i <= m; ++i) rd(v[i]);
	for(int i = 0; i <= m; ++i) w[i] = i;
	for(int i = 1; i <= 100; ++i) lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
	if(m <= 12) Subtask1::solve();
	else if(k == 1) Subtask1::spc();
	return 0;
}


