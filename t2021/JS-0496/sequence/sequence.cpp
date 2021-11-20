#include<bits/stdc++.h>
#define N 105
#define M 998244353

using namespace std;

int n, m, k;
int v[N];
long long ans;
bool b[N];
int tag[N];
int result[N];

int C[105][105];

void init()
{
	for(int i=0; i<=105; i++) C[i][0]=1, C[i][i]=1;
	for(int i=2; i<=105; i++)
		for(int j=1; j<i; j++)
			C[i][j] = (C[i-1][j]+C[i-1][j-1])%M;
}

long long Pow(long long a, int b)
{
	int res = 1;
	for(int i=1; i<=b; i++)
		res = (res*a)%M;
	return res%M;
}

void dfs(int x, int t, int cnt, long long res)
{
//	for(int i=1; i<=x; i++) printf("%d ", result[i]); printf("\n");
//		for(int i=1; i<=x+3; i++) printf("%d ", b[i]); printf("\n");
//		for(int i=1; i<=x+3; i++) printf("%d ", tag[i]);printf("\n\n");
	
	if(tag[x] && result[x]!=0)
	{
		tag[x+1] += tag[x]/2;
		b[x] = tag[x]%2;
		cnt += tag[x]%2;
	}
	
	if(t==0)
	{
		if(tag[x+1])
		{
			int tmp=tag[x+1], c=0;
			while(tmp) c+=tmp%2, tmp/=2;
			tag[x+1] = 0;
			if(cnt+c>k) return;
		}
//		for(int i=1; i<=x+3; i++) printf("%d ", b[i]); printf("\n");
//		for(int i=1; i<=x+3; i++) printf("%d ", tag[i]);printf("\n\n");
//		printf("qwq\n");
		
//		for(int i=1; i<=x; i++) printf("%d ", result[i]);printf("\n");
		long long tmp=1;
		int nn=n;
		for(int i=1; i<x; i++)
			tmp=(tmp*C[nn][result[i]])%M, nn-=result[i];
		
		ans = (ans+res*tmp)%M;
		return;
	}
	if(x>m)
	{
		tag[x+1] = b[x+1] = 0;
		return;
	}
	
	for(int i=0; i<=t; i++)
	{
		result[x+1] = i;
		tag[x+1] += i;
		dfs(x+1, t-i, cnt, ((res%M)*Pow(v[x], i))%M);
		tag[x+1]-=i, b[x+1]=0, result[x+1]=0;
	}
}

int calc(int x)
{
	int res = 0;
	while(x) res+=x%2, x/=2;
	return res;
}

void dfs2(int x, int res)
{
	if(x == n)
	{
		int t = 0;
		for(int i=1; i<=n; i++)
			t += pow(2, result[i]);
		t = calc(t);
		if(t <= k)
		{
//			for(int i=1; i<=n; i++) printf("%d ", result[i]);printf("\n");
			ans += res;
		}
		return;
	}
	
	for(int i=0; i<=m; i++)
	{
		result[x+1] = i;
		dfs2(x+1, res*v[i]);
		result[x+1] = 0;
	}
}

int main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	
	init();
	
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0; i<=m; i++) scanf("%d", &v[i]);
	
	if(n<=5 && m<=5) dfs2(0, 1);
	else dfs(0, n, 0, 1);
	
	printf("%lld", ans%M);
	
	return 0;
}
/*
5 2 2
4 4 4
*/
