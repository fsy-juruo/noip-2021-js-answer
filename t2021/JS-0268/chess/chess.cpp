#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template < typename T > const T maxx(T a, T b)
{
	return a > b ? a : b;
}
#define max(a, b) maxx(a, b)
template < typename T > const T minx(T a, T b)
{
	return a > b ? b : a;
}
#define min(a, b) minx(a, b)
/*long long operator %(long long a, long long b)
{
	return a > b * b ? a % b : a;
}
*/
/*int operator %(int a, int b)
{
	return a > b ? a % b : a;
}
*/

template < typename T >
inline const void read(T &x)
{
	bool flag = x = 0;
	char c;
	while ((c = getchar()) < 48 || c > 57) flag |= c == '-';
	do
		x = (x << 1) + (x << 3) + (c ^ 48);
	while ((c = getchar()) >  47 && c < 58);
	if (flag) x = -x;
}

int OUTPUT[100];
template < typename T >
inline const void write(T x)
{
	if (x < 0)
	{
		x = -x;
		putchar('-');
	}
	unsigned short SIZE = 0;
	do
	{
		OUTPUT[++SIZE] = x % 10 | 48;
		x /= 10;
	}while (x);
	while (SIZE) putchar(OUTPUT[SIZE--]);
}

template < typename T >
inline const void writeln(T x)
{
	write(x);
	putchar(10);
}

template < typename T >
inline const void writesp(T x)
{
	write(x);
	putchar(32);
}

//__gnu_pbds::priority_queue < int , less < int > > q;
//tree < int , null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > t;

const int N = 10005;
int vis[N][N], col[N], lv[N];
int colnow, lvnow;
int n, T, m, q;
int a[N][N];
bool v[N][N];
int x[N], y[N];

bool calc(int x, int y)
{
	if (vis[x][y] == 0) return true;
	if (col[vis[x][y]] != colnow && lv[vis[x][y]] <= lvnow) return true;
	return false;
}

bool calc2(int x, int y)
{
	if (vis[x][y] && col[vis[x][y]] != colnow && lv[vis[x][y]] <= lvnow) return true;
	return false;
}

void dfs1(int x, int y)
{
	if (x + 1 <= n && (a[2 * x][2 * y - 1] == 1) && calc(x + 1, y)) v[x + 1][y] = 1;
	if (x - 1 >= 1 && (a[2 * x - 2][2 * y - 1] == 1) && calc(x - 1, y)) v[x - 1][y] = 1;
	if (y - 1 >= 1 && (a[2 * x - 1][2 * y - 2] == 1) && calc(x, y - 1)) v[x][y - 1] = 1;
	if (y + 1 <= n && (a[2 * x - 1][2 * y] == 1) && calc(x, y + 1)) v[x][y + 1] = 1;
}

void dfs2(int x, int y)
{
	int tx = x, ty = y;
	while (1)
	{
		if ((tx + 1 > n) || (a[2 * tx][2 * ty - 1] != 2) || (!calc(tx + 1, ty))) break;
		v[tx + 1][ty] = 1;
		if (calc2(tx + 1, ty)) break;
	}
	
	tx = x, ty = y;
	while (1)
	{
		if ((tx - 1 < 1) || ((a[2 * tx - 2][2 * ty - 1] != 2) || (!calc(tx - 1, ty)))) break;
		v[tx - 1][ty] = 1;
		if (calc2(tx - 1, ty)) break;
	}
	tx = x, ty = y;
	while (1)
	{
		if ((ty - 1 < 1) || ((a[2 * tx - 1][2 * ty - 2] != 2) || (!calc(tx, ty - 1)))) break;
		v[tx][ty - 1] = 1;
		if (calc2(tx, ty - 1)) break;
	}
	tx = x, ty = y;
	while (1)
	{
		if ((ty + 1 > n) || ((a[2 * tx - 1][2 * ty] != 2) || (!calc(tx, ty + 1)))) break;
		v[tx][ty + 1] = 1;
		if (calc2(tx, ty + 1)) break;
	}
}

void dfs3(int x, int y)
{
	if (v[x][y]) return;
	v[x][y] = 1;
	if (calc2(x, y)) return;
	int tx = x, ty = y;
	if ((tx + 1 <= n) && (a[2 * tx][2 * ty - 1] == 3) && calc(tx + 1, ty)) dfs3(tx + 1, ty);
	if ((tx - 1 >= 1) && (a[2 * tx - 2][2 * ty - 1] == 3) && calc(tx - 1, ty)) dfs3(tx - 1, ty);
	if ((ty - 1 >= 1) && (a[2 * tx - 1][2 * ty - 2] == 3) && calc(tx, ty - 1)) dfs3(tx, ty - 1);
	if ((ty + 1 <= n) && (a[2 * tx - 1][2 * ty] == 3) && calc(tx, ty + 1)) dfs3(tx, ty + 1);	
}

int main()
{
	freopen("chess.in","r", stdin);
	freopen("chess.out", "w", stdout);
	read(T);
	while (T--)
	{
		read(n);read(m);read(q);
		if (n * m <= 5000)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= m - 1; j++)
				{
					a[i * 2 - 1][j * 2] = getchar() - '0';
				}
				getchar();
			}
			for (int i = 1; i <= n - 1; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					a[i * 2][j * 2 - 1] = getchar() - '0';
				}
				getchar();
			}
		/*	for (int i = 1; i <= 2 * n - 1; i++)
			{
				for (int j = 1; j <= 2 * m - 1; j++)
					writesp(a[i][j]);
				putchar(10);
			}*/
				
			for (int i = 1; i <= q; i++)
			{
				memset(v, 0, sizeof(v));
				read(col[i]);read(lv[i]);read(x[i]);read(y[i]);
				colnow = col[i], lvnow = lv[i];
				vis[x[i]][y[i]] = i;
				dfs1(x[i], y[i]);
				dfs2(x[i], y[i]);
				dfs3(x[i], y[i]);
				long long ans = 0;
				for (int i = 1; i <= n; i++)
					for (int j = 1; j <= m; j++)
						if (v[i][j]) ans++;
				writeln(ans);
			}
		}
	 } 
	return 0;
}
/*
1
3 3 5
13
22
23
010
233
0 1 2 3
*/
