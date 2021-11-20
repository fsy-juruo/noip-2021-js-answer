#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
int read(){
	int num = 0,w = 1;
	char c = 0;
	while(c < '0' || c > '9'){if(c == '-')w = -1;c = getchar();}
	while(c >= '0' && c <= '9'){num = num * 10 + c - '0';c = getchar();}
	return num * w;
}

const int N = 40,M = 110,mod = 998244353;

LL n,m,K;
LL v[M];
int a[N];
LL res;
int cnt[M];

int get(int x)
{
	int qwq = 0;
	while(x)
	{
		qwq += (x & 1);
		x >>= 1;
	}
	return qwq;
}

bool check()
{
	int S = 0;
	for(int i = 1; i <= n; i ++)
		S += pow(2,a[i]);
	if(n <= S && S <= n * pow(2,m) && get(S) <= K)
		return true;
	return false;
}

void dfs(int dep)
{
	if(dep == n + 1)
	{
		
		if(check())
		{
			//for(int i = 1; i <= n; i ++) cout<<a[i]<<' ';
			//cout<<endl;
			LL sum = 1;
			for(int i = 1; i <= n; i ++)
				sum = sum * v[a[i]] % mod;
			res = (res + sum) % mod;
		}
		return ;
	}
	for(int i = 0; i <= m; i ++)
	{
		a[dep] = i;
		dfs(dep + 1); 
	}
}

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
		
	n = read(),m = read(),K = read();
	for(int i = 0; i <= m; i ++) v[i] = read();
	
	dfs(1);

	cout<<res<<endl;
	
	return 0;
}

