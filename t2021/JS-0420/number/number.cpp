#include <bits/stdc++.h>
#define maxn 10000002
using namespace std;
inline int read()
{
	int X = 0; bool f = false; char ch = getchar();
	while (ch > '9' || ch < '0') {f |= ch == '-'; ch = getchar();}
	while (ch <= '9' && ch >= '0') {X = (X << 3) + (X << 1) + (ch ^ 48); ch = getchar();}
	return f ? -X : X;
}
inline void write(int X)
{
	if (X == 0) {putchar('0'); return;}
	if (X < 0) {putchar('-'); X = -X;}
	short num[16], cnt = 0;
	while (X) {num[++cnt] = X % 10; X /= 10;}
	while (cnt) putchar(num[cnt--] ^ 48);
	return;
}
int legal_num[maxn + 1], is_legal_num[maxn + 1], cnt;
void init()
{
	int tenth = 1, x;
	for (int i = 1; i <= 7; ++i)
	{
		for (int j = 1; j <= maxn / 10; ++j)
		{
			x = (7 * tenth) + (j % tenth) + (j / tenth * 10 * tenth);
			for (int k = 1; x * k <= maxn; ++k) is_legal_num[x * k] = -1;
		}
		tenth = (tenth << 3) + (tenth << 1);
	}
	for (int i = 1; i <= maxn; ++i)
	{
		if (i * 7 <= maxn) is_legal_num[i * 7] = -1;
		if (is_legal_num[i] != -1) {legal_num[++cnt] = i; is_legal_num[i] = cnt;}
	}
	legal_num[0] = -1;
	return;
}
int T, x;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	init();
	T = read();
	for (int i = 1; i <= T; ++i) {x = read(); write(legal_num[is_legal_num[x] + 1]); putchar('\n');}
	return 0;
}
