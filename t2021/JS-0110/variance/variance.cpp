#include <bits/stdc++.h>
#define FILE
using namespace std;
typedef long long ll;
const string FILENAME = "variance";
template <typename T>
void read(T &x)
{
	char c;bool f = 0;
	while (!isdigit(c = getchar())) f ^= (c == '-');
	x = (c ^ 48);
	while (isdigit(c = getchar())) x = (x << 3) + (x << 1) + (c ^ 48);
	if (f) x = -x;
}
template <typename T>
T read()
{
	T x;
	read(x);
	return x;
}
const int N = 10005;
int n, a[N], d[N], b[N];
ll ans = 1000000000000000000ll;
ll calc()
{
	ll res = 0, sum = 0;
	for (int i = 1;i < n;++i)
	{
		b[i] = b[i-1] + d[i];
		res += b[i] * b[i];
		sum += b[i];
	}
	return res = n * res - sum * sum;
}
void get(int &i, int &j)
{
	int k = 0;
	do 
	{
		i = rand() % (n - 1) + 1;
		j = rand() % (n - 1) + 1;
		++k;
	}while ((i == j || i + j == n || d[i] == d[j]) && k < 10);
}
void go()
{
	random_shuffle(d+1, d+n);
	double T = 10000.0, dt = 0.999;
	ll res = calc();
	while (T > 0.0001)
	{
		int i, j;get(i, j);
		swap(d[i], d[j]);
		ll cur = calc();
		if (cur > res && rand() < exp(T / (cur - res)) * RAND_MAX)
			swap(d[i], d[j]);
		else 
			res = cur;
		T *= dt;
	}
	ans = min(ans, res);
}
const int TIME = CLOCKS_PER_SEC * 0.85;
int main()
{
#ifdef FILE
	freopen((FILENAME+".in").c_str(), "r", stdin);
	freopen((FILENAME+".out").c_str(), "w", stdout);
#endif
	time_t start = clock();
	srand(time(NULL));
	read(n);
	if (n == 1) puts("0"), exit(0);
	for (int i = 1;i <= n;++i) read(a[i]), d[i-1] = a[i] - a[i-1];
	while (clock() - start < TIME) go();
	go();
	printf("%lld\n", ans);
	return 0;
}

