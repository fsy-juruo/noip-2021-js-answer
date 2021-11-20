#include<iostream>
#define mod 998244353
using namespace std;
long long seq[101];
int n,m,k,answer=0;
int countbit(int x)
{
	int bs=0;
	while(x)
	{
		x&=(x-1);
		bs++;
	}
	return bs;
}
void d(long long rest,long long sum,long long prod)
{
	if(rest==0)
	{
		if(countbit(sum)<=k)
			answer=(answer+prod)%mod;
		return;
	}
	for(int i=0;i<=m;i++)
		d(rest-1,sum+(1<<i),prod*seq[i]%mod);
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)
		cin>>seq[i];
	d(n,0,1);
	cout<<answer;
}
