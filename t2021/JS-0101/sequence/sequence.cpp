#include<bits/stdc++.h>
using namespace std;
const long long P = 998244353;
template <typename T>
void read(T &x)
{
	T f = 1; x = 0;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
	for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
	x *= f;
}
long long qpow(long long a, long long x)
{
	long long l = a, ret = 1;
	for (; x; x >>= 1)
	{
		if (x & 1)
		{
			ret *= l;
			ret %= P;
		}
		l *= l; l %= P;
	}
	return ret;
}
long long A[135], v[107][135], ans = 0;
int n, m, k;
bool check(long long num)
{
	int ret = 0;
	while (num)
	{
		if (num & 1) ret++;
		num >>= 1;
		if (ret > k) return false;
	}
	return true;
}
void dfs(long long pos, long long num, long long tag, int cnt, long long w)
{
	int sk = (int)log2(num);
	if (sk <= pos && !check(num)) return ;
	if (pos > m)
	{
		if (check(num))
		{
			long long T = A[n] * qpow(tag, P - 2) % P * w % P;
			ans += T; ans %= P;
		}
		return ;
	}
	if (pos == m)
	{
		int i = n - cnt;		
		long long wp = w;
		wp *= v[pos][i]; wp %= P;
		long long pr1, pr2;
		pr1 = (1 << pos); pr1 %= P; pr1 *= (long long)(i); pr1 %= P; pr1 += num; pr1 %= P;
		pr2 = tag * A[i]; pr2 %= P;
		dfs(pos + 1, pr1, pr2, cnt + i ,wp);
	}
	else {
		for (int i = 0; i <= n - cnt; i++)
		{
			long long wp = w;
			wp *= v[pos][i]; wp %= P;	
			long long pr1, pr2;
			pr1 = (1 << pos); pr1 %= P; pr1 *= (long long)(i); pr1 %= P; pr1 += num; pr1 %= P;
			pr2 = tag * A[i]; pr2 %= P;
			dfs(pos + 1, pr1, pr2, cnt + i ,wp);
		}
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n); read(m); read(k);	
	A[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		A[i] = A[i - 1] * (long long) i;
		A[i] %= P;
	}
	for (int i = 0; i <= m; i++)
		read(v[i][1]);
	for (int i = 0; i <= m; i++)
	{
		v[i][0] = 1;
		for (int j = 2; j <= n; j++)
			{
				v[i][j] = v[i][j - 1] * v[i][1];
				v[i][j] %= P;
			}
	}
	dfs(0, 0, 1, 0, 1);
	cout << ans << '\n';
	return 0;
}
