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

const int N = 1e7 + 5, M = 1e7;
int T, len/*, front, rear*/, a[N];
//pair < int, bool > q[N];
bool vis[N], seven[N];
long long tmp;
//1405229
//inline bool Check(int x)
//{
//	while (x)
//	{
//		if (x % 10 == 7) return 1;
//		x /= 10;
//	}
//	return 0;
//}

inline void bfs()
{
//	front = 1;
//	rear = 0;
//	for (register int i = 1; i <= 9; ++i)
//		q[++rear] = make_pair(i, i == 7);
//	while (front <= rear)
//	{
//		for (register int i = 0; i <= 9; ++i)
//		{
//			int tx = (q[front].first << 1) + (q[front].first << 3) + i;
//			if (tx <= M) q[++rear] = make_pair(tx, q[front].second | (i == 7));
//		}
//		++front;
//	}
	seven[7] = 1;
	for (register int i = 10; i <= M; ++i)
		seven[i] = seven[i / 10] | (i % 10 == 7);
//	q[1] = 7;
//	vis[7] = 1;
//	while (front <= rear)
//	{
//		for (register int i = 1; i <= 9; ++i)
//		{
//			int tx = (q[front] << 1) + (q[front] << 3) + i;
//			if (tx <= M)
//			{
//				
//			}
//		}
//		++front;
//	}
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
//	freopen("b.cpp", "w", stdout);
//	for (register int i = 1; i <= M; ++i)
//		if (Check(i))
//			for (register int j = 1; (tmp = (long long)i * j) <= M; ++j)
//				vis[tmp] = 1;
//	for (register int i = 1; i <= M; ++i)
//		if (!vis[i]) ++len/*, printf(","), write(i)*/;
////	putchar(10);
//	writeln(len);
//	return 0;
	bfs();
//	for (register int i = 1; i <= rear; ++i)
//		if (q[i].second) ++len;
//	writeln(M - len);
	for (register int i = 1; i <= M; ++i)
		if (/*q[i].second*/seven[i])
			for (register int j = 1; (tmp = (long long)i * j) <= M; ++j)
				vis[tmp] = 1;
	for (register int i = 1; i <= M; ++i)
		if (!vis[i])
		{
			a[++len] = i;
//			++len/*, printf(","), write(i)*/;
		}
////	putchar(10);
//	writeln(len);
//	for (register int i = 1e7 + 1; i <= M; ++i)
//		if (!vis[i])
//		{
//			writeln(i), puts("more");
//			break;
//		}
//	for (register int i = M; i; --i)
//		if (!vis[i])
//		{
//			writeln(i);
//			puts("less");
//			break;
//		}
//	return 0;
	read(T);
	while (T--)
	{
		int x;
		read(x);
		if (x == 9999998)
		{
			puts("10000001");
			continue;
		}
		if (x == 9999999 || x == 10000000)
		{
			puts("-1");
			continue;
		}
		if (vis[x])
		{
			puts("-1");
			continue;
		}
		writeln(*upper_bound(a + 1, a + len + 1, x));
//		int ans = *lower_bound(a + 1, a + len + 1, x);
//		if (ans == x) puts("-1");
//		else writeln(ans);
	}
	return 0;
}
/*
7,14,17,21,27,28
*/
