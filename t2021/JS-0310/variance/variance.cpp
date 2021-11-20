#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
LL read(){
	LL num = 0,w = 1;
	char c = 0;
	while(c < '0' || c > '9'){if(c == '-')w = -1;c = getchar();}
	while(c >= '0' && c <= '9'){num = num * 10 + c - '0';c = getchar();}
	return num * w;
}

const LL INF = 1e18;
const int N = 4e2 + 50;

LL n;
LL a[N];
LL sum,sum2;
LL minn = INF;
LL b[N];
int oi[1 << 22];
int tt = 2;

void OI()
{
	oi[2] ++;
	int hh = 2;
	while(oi[hh] == 2)
	{
		oi[hh + 1] ++,oi[hh ++] = 0;
		if(hh == tt + 1) tt ++;
	}
}

void dfs(int dep)
{
	if(dep == n)
	{
		sum = 0,sum2 = 0;
		for(int i = 1; i <= n; i ++)
			sum += b[i],sum2 += b[i] * b[i];
		minn = min(minn,n * sum2 - sum * sum);
		//cout<<n * sum2 - sum * sum<<endl;
		return ;
	}
	int now = a[dep];
	b[dep] = b[dep - 1] + b[dep + 1] - b[dep];
	dfs(dep + 1);
	b[dep] = now;
	dfs(dep + 1);
}

void rdfs(int dep)
{
	if(dep == 1)
	{
		sum = 0,sum2 = 0;
		for(int i = 1; i <= n; i ++)
			sum += b[i],sum2 += b[i] * b[i];
		minn = min(minn,n * sum2 - sum * sum);
		//cout<<n * sum2 - sum * sum<<endl;
		return ;
	}
	int now = a[dep];
	b[dep] = b[dep - 1] + b[dep + 1] - b[dep];
	dfs(dep - 1);
	b[dep] = now;
	dfs(dep - 1);
}

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	
	n = read();
	for(int i = 1; i <= n; i ++) cin>>a[i],sum += a[i],sum2 += a[i] * a[i],b[i] = a[i];
	//minn = min(minn,n * sum2 - sum * sum);
	
	/*while(tt < n)
	{
		OI();
		for(int i = 2; i < n; i ++)
		{
			if(oi[i])
			{
				int now = b[i],derta;
				b[i] = b[i - 1] + b[i + 1] - b[i];
				//for(int j = 1; j <= n; j ++) cout<<b[j]<<' ';
				//cout<<endl;
				derta = now - b[i];
				sum -= derta,sum2 = sum2 + derta * derta - 2 * derta * now;
				minn = min(minn,n * sum2 - sum * sum);
			}
		}
	}
	*/
	
	dfs(2);
	rdfs(n - 1);
	
	cout<<minn<<endl;
	
	return 0;
}
/*
10
6 19 34 35 56 63 82 82 83 99
*/
/*

*/
