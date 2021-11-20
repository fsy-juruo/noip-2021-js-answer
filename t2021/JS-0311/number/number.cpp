#include<bits/stdc++.h>
using namespace std;
const int N=1e7+100,M=2*1e5+100;
int n,m;
int a[M],sz=0;
bool c[N];
inline bool check(int x)
{
	while(x)
	{
		if(x%10==7) return true;
		x/=10;
	}
	return false;
}
inline void expand(int x)
{
	for(register int i=1;i*x<=sz;++i)
		c[i*x]=1;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t;
	cin>>t;
	for(register int i=1;i<=t;++i)
	{
		scanf("%d",&a[i]);
		sz=max(sz,a[i]);
	}
	
	for(register int i=1;i<=sz;++i)
	{
		if(c[i]) continue;
		else if(i%7==0) expand(i);
		else if(check(i)) expand(i);
	}
	
	for(register int i=1;i<=t;++i)
	{
		int ask=a[i];
		if(c[ask]) puts("-1");
		else {
			int j=ask+1;
			while(c[j]&&j<=sz) ++j;
			if(j<=sz) printf("%d\n",j);
			else {
				while(j%7==0 || check(j)) ++j;
				printf("%d\n",j);
			}
		}
	}
	
	return 0;
}


