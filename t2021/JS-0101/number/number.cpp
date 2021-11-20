#include<bits/stdc++.h>
using namespace std;
const int M1 = 1e6, M2 = 1e5, M3 = 1e4, M4 = 1e3, M5 = 1e2, M6 = 10;
const int MAXN = 1e7 + 6, M = 6e6 + 7;
template <typename T>
void read(T &x)
{
	T f = 1; x = 0;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
	for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
	x *= f;
}
template <typename T>
void write(T x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	char ch = char(x % 10 + 48);
	if (x < 10) putchar(ch);
	else {
		write(x / 10);
		putchar(ch);
	}
}
template <typename T>
void writeln(T x)
{
	write(x);
	putchar('\n');
}
int f[M], cnt = 0;
bool hash1[MAXN];
int fr[MAXN];
void build()
{
	for (int i1 = 0; i1 <=9; i1++)
	{
	for (int i2 = 0; i2 <= 9; i2++)
	{
	for (int i3 = 0; i3 <= 9; i3++)
	{
	for (int i4 = 0; i4 <= 9; i4++)
	{
	for (int i5 = 0; i5 <= 9; i5++)
	{
	for (int i6 = 0; i6 <= 9; i6++)
	{
	for (int i7 = 0; i7 <= 9; i7++)
	{
		if (i1 == 7 || i2 == 7 || i3 == 7 || i4 == 7 || i5 == 7 || i6 == 7 || i7 == 7)
		{
			int num = i1 * M1 + i2 * M2 + i3 * M3 + i4 * M4 + i5 * M5 + i6 * M6 + i7;
			hash1[num] = 1;
			cnt++;
			f[cnt] = num;
		}	
	}
	}
	}
	}
	}
	}
	}
}
int t, n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	build();
	for (int i = 1; i <= cnt; i++)
	{
		for (int j = 2; j <= (MAXN - 1) / f[i]; j++)
		{
			hash1[f[i] * j] = 1;
		}	
	}	
	int las = 1e7 + 1;
	for (int i = 1e7; i >= 1; i--)
	{
		if (!hash1[i])
		{
			fr[i] = las;
			las = i;
		}
	}
	read(t);
	while (t--)
	{
		read(n);
		if (hash1[n]) writeln(-1);
		else writeln(fr[n]);
	}
	return 0;
}
