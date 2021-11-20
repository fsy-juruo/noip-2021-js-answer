#include <bits/stdc++.h>
#define FILE
using namespace std;
typedef long long ll;
const string FILENAME = "number";
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
const int M = 10000019;
int ok[M + 5];
int nxt[M + 5];
const int h[9] = {0,1,2,3,4,5,6,8,9}; 
void init()
{
	for (int i1 = 0;i1 < 9;++i1)
	for (int i2 = 0;i2 < 9;++i2)
	for (int i3 = 0;i3 < 9;++i3)
	for (int i4 = 0;i4 < 9;++i4)
	for (int i5 = 0;i5 < 9;++i5)
	for (int i6 = 0;i6 < 9;++i6)
	for (int i7 = 0;i7 < 9;++i7)
	ok[h[i1]*1000000+h[i2]*100000+h[i3]*10000+h[i4]*1000+h[i5]*100+h[i6]*10+h[i7]] = 1;
	for (int i = 0;i <= 19;++i)
		 ok[10000000+i] = 1;
	ok[10000007] = ok[10000017] = 0;
	for (int i = 1;i <= M;++i)
	{
		if (ok[i] == 0)
		{
			for (int j = i + i;j <= M;j += i)
				ok[j] = 2;
		}
	}
	int pre = 0;
	for (int i = 1;i <= M;++i)
	{
		if (ok[i] == 1) nxt[pre] = i, pre = i;
	}
}
void go()
{
	int x;read(x);
	if (ok[x] != 1) puts("-1");
	else printf("%d\n", nxt[x]);
}
int main()
{
#ifdef FILE
	freopen((FILENAME+".in").c_str(), "r", stdin);
	freopen((FILENAME+".out").c_str(), "w", stdout);
#endif
	init();
    int T = read<int>();
    while (T--) go();
	return 0;
}

