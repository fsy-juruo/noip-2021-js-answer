#include <bits/stdc++.h>
using namespace std;

bool p[12000000], seven[12000000];

int t[200005], MaxT = 0, cnt = 0, T, ans[1000005], ans2[10000005], e = 0, f[10000005];

bool digit(char c)
{
	return c >= '0' && c <= '9';
}

inline int Max(register int x, register int y)
{
	return x > y ? x : y;
}

inline int read()
{
	char c = getchar();
	register int x = 0;
	while (digit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return x;
}

inline void write(register int x)
{
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}

bool check(register int x)
{
	while (x)
	{
		if (x % 10 == 7) return 1;
		x /= 10;
	}
	return 0;
}

void init(int x)
{
	for (register int i = 1; i <= x; ++i)
	{
		seven[i] = check(i);
		p[i] = seven[i];
		if (seven[i]) f[++e] = i;
	}
	for (register int i = 1; i <= e; ++i)
		for (register int j = f[i] + f[i]; j <= x; j += f[i])
				p[j] = 1;
	for (register int i = 1; i <= x; ++i)
		if (!p[i]) ans[++cnt] = i;
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	T = read();
	for (int i = 1; i <= T; ++i)	
	{
		t[i] = read();
		MaxT = Max(MaxT, t[i]);
	}
	if (MaxT <= 80) init(MaxT + 15);
	else if (MaxT <= 800) init(MaxT + 115);
	else if (MaxT <= 8000) init(MaxT + 1015);
	else if (MaxT <= 80000) init(MaxT + 10015);
	else if (MaxT <= 800000) init(MaxT + 100015);
	else if (MaxT <= 8000000) init(MaxT + 1000015);
	else init(MaxT + 100015);
	cnt = 1;
	for (register int i = 1; i <= MaxT; ++i)
	{
		while (ans[cnt] <= i) cnt++;
		ans2[i] = ans[cnt];
	}
	for (register int i = 1; i <= T; ++i)
	{
		if (p[t[i]]) putchar('-'), putchar('1');
		else write(ans2[t[i]]);
		putchar('\n');
	}
	return 0;
}

