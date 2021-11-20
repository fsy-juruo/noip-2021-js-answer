#include <bits/stdc++.h>
using namespace std;

const int N = 1e7+2;

int Q,n,f[N+5],s[N+5];

int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9') { if(ch=='-') f = -f; ch = getchar(); }
	while(ch>='0' && ch<='9') { x = (x<<3)+(x<<1)+ch-'0'; ch = getchar(); }
	return f*x;
}

bool legal(int x)
{
	if(x%7==0) return 0;
	while(x)
	{
		int d=x%10;
		if(d==7) return 0;
		x /= 10;
	}
	return 1;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=N;i++) f[i] = 1;
	for(int i=1;i<=N;i++)
	{
		if(legal(i) || f[i]==0) continue;
		f[i] = 0;
		for(int j=i+i;j<=N;j+=i)
			f[j] = 0;
	}
	for(int i=1;i<=N;i++)
		s[i] = s[i-1]+f[i];
	Q = read();
	while(Q--)
	{
		n = read();
		if(f[n]==0)
		{
			puts("-1"); continue;
		}
		int l=n+1,r=N,ans=-1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(s[mid]-s[n]>=1)
				ans = mid, r = mid-1;
			else
				l = mid+1;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
