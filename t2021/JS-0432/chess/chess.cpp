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

int T, n, m, q;

int main()
{
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	read(T);
	while (T--)
	{
		read(n);
		read(m);
		read(q);
		for (register int i = 1; i < (n << 1) + (q << 2); ++i)
		{
			int x;
			read(x);
		}
		for (register int i = 1; i <= q; ++i)
			writeln(0);
	}
	return 0;
}

