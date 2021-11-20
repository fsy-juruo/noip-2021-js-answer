#include <bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x)
{
	int f = 1; x = 0; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}
template <typename T> inline void write(T x)
{
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> inline void writeln(T x) { write(x); putchar('\n'); } 
const int N = 12000005;
bool vis[N];
int Next[N];
inline bool check(int num)
{
	while (num)
	{
		if (num % 10 == 7) return 0;
		num /= 10;
	}
	return 1;
}
inline void sieve(int n)
{
	for (int i = 1; i <= n; i++)
	if (!vis[i] && !check(i))
	{
		vis[i] = 1;
		for (int j = i * 2; j <= n; j += i) vis[j] = 1;
	}
	for (int i = n; i >= 1; i--) 
	if (!vis[i]) Next[i] = i;
	else Next[i] = Next[i + 1];
}
int main()
{
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	int T;
	read(T);
	sieve(N - 5);
	while (T--)
	{
		int x;
		read(x);
		if (vis[x]) puts("-1");
		else writeln(Next[x + 1]);
	}
	return 0;
}
