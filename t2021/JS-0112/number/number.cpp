#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template <typename T> inline void rd(T &x)
{
	x = 0; int f = 1; char ch = 0;
	for(;!isdigit(ch); ch = getchar()) if(ch == '-') f = -f;
	for(; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + ch - 48;
}
template <typename T> inline void write(T x)
{
	if(x < 0) {putchar('-'); write(-x); return;}
	if(x <= 9){putchar(x + 48); return;}
	write(x / 10); putchar(x % 10 + 48);
}
template <typename T> inline void writeln(T x) {write(x); puts("");}

int T,n,nxt[10000008];
bool hs[10000008];

bool chk(int x)
{
	while(x)
	{
		if(x % 10 == 7) return 1;
		x /= 10;
	}
	return 0;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	rd(T);
	for(int i = 1; i <= 10000001; ++i)
	{
		if(chk(i))
		{
			for(int j = 1; j * i <= 10000001; ++j) hs[j * i] = 1;
		}
	}
	int tmp = 0;
	for(int i = 1; i <= 10000001; ++i)
	{
		if(!hs[i])
		{
			nxt[tmp] = i;
			tmp = i;
		}
	}
	while(T--)
	{
		rd(n);
		if(hs[n])
		{
			puts("-1");
			continue;
		}
		writeln(nxt[n]);
	}
	return 0;
}

