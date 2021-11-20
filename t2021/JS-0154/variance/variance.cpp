#include<bits/stdc++.h>
using namespace std;
#define MAX 10005
typedef long long ll;
#define mapa make_pair
#define fir first
#define sec second
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
#define SIZE(X) int((X).size())

int read()
{
	int ret = 0; char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
	return ret;
}
void write(int x)
{
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
void writesp(int x) {write(x); putchar(' ');}
void writeln(int x) {write(x); putchar('\n');}

int n, m;
vector<int> a[MAX];
int t[MAX], ans;
bool vis[MAX];

int calc()
{
	int x = 0, y = 0;
	for(int i = 1;i <= n;++i) x = x + t[i] * t[i], y = y + t[i];
	return n * x - y * y;
}

bool check(int p)
{
	for(int i = 1;i <= n;++i)
		if(t[i] != a[i][p])
			return false;
	return true;
}

void dfs(int beacon, int last)
{
	bool flag;
//	writeln(beacon);
	for(int i = 2;i < n;++i)
	{
		if(i != last && a[i][beacon] * 2 != a[i - 1][beacon] + a[i + 1][beacon])
		{
			flag = true;
			for(int j = 1;j <= n;++j) t[j] = a[j][beacon];
			t[i] = a[i - 1][beacon] + a[i + 1][beacon] - a[i][beacon];
			for(int i = 0;i <= m;++i)
				if(check(i))//È«ÏàµÈ 
				{
					flag = false;
					break;
				}
			if(flag)
			{
				int gary = calc();
				if(gary < ans) ans = gary;
				for(int i = 1;i <= n;++i) a[i].push_back(t[i]);
				++m;
				dfs(m, i);
			}
		}
	}
}

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n = read(); m = 0;
	for(int i = 1;i <= n;++i) t[i] = read(), a[i].push_back(t[i]);
	ans = calc();
	dfs(0, 0);
	writeln(ans);
	return 0;
}
