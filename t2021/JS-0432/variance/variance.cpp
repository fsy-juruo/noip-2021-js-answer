#include <bits/stdc++.h>
using namespace std;

template < typename T >
inline void read(T &x)
{
	bool flg = x = 0;
	char c;
	while ((c = getchar()) < 48 || c > 57)
		flg |= (c == '-');
	do
		x = (x << 1) + (x << 3) + (c ^ 48);
	while ((c = getchar()) > 47 && c < 58);
	if (flg) x = -x;
}

int OUTPUT[45];

template < typename T >
inline void write(T x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	int len = 0;
	do
	{
		OUTPUT[++len] = x % 10 | 48;
		x /= 10;
	}while (x);
	while (len)
		putchar(OUTPUT[len--]);
}

template < typename T >
inline void writesp(T x)
{
	write(x);
	putchar(32);
}

template < typename T >
inline void writeln(T x)
{
	write(x);
	putchar(10);
}

const int N = 1e4 + 5;
int n, ans = 2e9/*, tot*/, a[N];
vector < int > v;
set < vector < int > > st;

void dfs(/*int lst = 1*/)
{
//	puts("ok");
	v.erase(v.begin(), v.end());
	for (register int i = 2; i < n; ++i)
		v.push_back(a[i]);
	if (st.find(v) != st.end()) return;
	st.insert(v);
//	bool no = 1;
//	for (register int i = 2; i < n; ++i)
//	{
//		if (i == lst) continue;
//		if (a[i] != a[i - 1] + a[i + 1] - a[i])
//		{
//			no = 0;
//			break;
//		}
//	}
//	if (no) return;
//	for (register int i = 1; i < n; ++i)
//		writesp(a[i]);
//	writeln(a[n]);
	int s1 = 0, s2 = 0;
	for (register int i = 1; i <= n; ++i)
		s1 += a[i], s2 += a[i] * a[i];
	ans = min(ans, s2 * n - /*((s1 * s1) << 1) +*/ s1 * s1);
//	writeln(s2 * n - ((s1 * s1) << 1) + s1 * s1);
//	++tot;
//	vector < int > tmp = v;
	for (register int i = 2; i < n; ++i)
//	if (i != lst)
	if (a[i] != a[i - 1] + a[i + 1] - a[i])
	{
		int tmp = a[i];
		a[i] = a[i - 1] + a[i + 1] - a[i];
		dfs(/*i*/);
		a[i] = tmp;
	}
}

int main()
{
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	read(n);
	for (register int i = 1; i <= n; ++i)
		read(a[i]);
	dfs();
	writeln(ans);
//	writeln(tot);
	return 0;
}

