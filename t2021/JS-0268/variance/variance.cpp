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

const int N = 1e4 + 5;
long long ans, last, sm;
long double last1;
int n, a[N];
bool change[N];

long long calc()
{
	long long anss = 0, sum = 0;
	for (int i = 1; i <= n; i++) anss += a[i] * a[i], sum += a[i];
	anss = anss * n - sum * sum;
	last1 = sum * 1.0 / n;
	sm = sum;
	return anss;
}

void SA()
{
	long double T = 1000.0, minT = 1e-10, changeT = 0.9994;
	while (T > minT)
	{
		int x = rand() % n + 1;
		if (x == 1 || x == n) continue;
		if (change[x] && (!change[x - 1]) && (!change[x + 1])) continue;
		int ax = a[x];
		a[x] = a[x + 1] + a[x - 1] - a[x];
		if ((a[x] < ax && ax < last) || (a[x] > ax && ax > last))
		{
		//	if ((long double)(exp(abs(a[x] - ax)) / T) > (long double) (rand() * 1.0 / RAND_MAX))
		//	{
				a[x] = ax;
				continue;
		//	}
		}
		long long sum = ans - n * ax * ax + n * a[x] * a[x] - (a[x] - ax) * (a[x] - ax) - 2 * sm * (a[x] - ax);
		if (sum < ans) ans = sum, last = last1, change[x] = 1, sm = sm + a[x] - ax;
		else if ((long double)(exp(ans - sum) / T) < (long double)(rand() * 1.0 / RAND_MAX)) ans = sum, last = last1, change[x] = 1, sm = sm + a[x] - ax;
		else a[x] = ax;
		T *= changeT;
	}
}

int main()
{
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	srand(time(NULL));
	srand(19260817);
	srand(20060331);
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	ans = calc();
	last = last1;
	SA();
	SA();
	SA();
	SA();
	SA();
	writeln(ans);
	return 0;
}

