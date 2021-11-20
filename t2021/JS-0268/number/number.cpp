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

const int N = 2e5;
bool iss[N * 2], isss[N * 2];
vector < int > v;
int prime[N * 2];
int T, n;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for (int i = 1; i <= N; i++)
	{
		int x = i;
		do
		{
			if (x % 10 == 7)
			{
				iss[i] = 1;
				isss[i] = 1;
				v.push_back(i);
				break;
			}
			x /= 10;
		}
		while (x);
	}
	for (int i = 1; i <= N; i++)
	{
		if (iss[i] && !isss[i]) v.push_back(i);
		for (int j = 0; j < v.size(); j++)
		{
			if (v[j] * i > N || (prime[i] <= v[j] && prime[i] != 0)) break;
			iss[v[j] * i] = 1;
			prime[v[j] * i] = v[j];
		}
	}
	read(T);
	while (T--)
	{
		read(n);
		if (iss[n]) 
		{
			writeln(-1);
			continue;	
		}
		for (int i = n + 1; i <= N; i++) 
		{
			if (!iss[i])
			{
				writeln(i);
				break;
			}
		}
	 } 
	return 0;
}

