#include <bits/stdc++.h>
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

map < vector<int>, bool> mp;
int ans = 2147483647,n,a[105];
vector <int> q;

void calc()
{
	int sum = 0;
	for(int i = 1; i <= n; ++i) sum += q[i] * q[i];
	sum *= n;
	int tmp = 0;
	for(int j = 1; j <= n; ++j) tmp += q[j];
	sum -= tmp * tmp;
	ans = min(ans, sum);
}
void dfs()
{
	for(int i = 2; i < n; ++i)
	{
		q[i] = q[i - 1] + q[i + 1] - q[i];
		if(!mp[q])
		{
			calc();
			mp[q] = 1;
			dfs();
		}
		q[i] = q[i - 1] + q[i + 1] - q[i];
	}
}

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	rd(n); q.push_back(0);
	for(int i = 1; i <= n; ++i)
	{
		rd(a[i]); q.push_back(a[i]);
	}
	dfs();
	cout << ans << endl;
	return 0;
}


