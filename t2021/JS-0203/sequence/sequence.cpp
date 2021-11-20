#include<bits/stdc++.h>
using namespace std;
long long n,m,k,v[110],ans,a[33],jc[33];
const long long mo=998244353;
long long ksm(long long x,long long y)
{
	if(y==1) return x;
	long long he=ksm(x,y/2);
	if(y%2==0) return he*he%mo;
	return x*he%mo*he%mo;
}
void baoli(int x)
{
	if(x>n)
	{
		int len=n,f=1;
		int b[33];
		for(int i=1;i<=n;i++) b[i]=a[i];
		while(f==1)
		{
			f=0;sort(b+1,b+n+1);int llen=len;
			for(int i=1;i<llen;i++) 
			{
				if(b[i]==777) continue;
				if(b[i]==b[i+1])
				{
					b[i]++;b[i+1]=777;len--;f=1;
				}
			}	
		}
		if(len<=k)
		{
			long long lans=1,di=1,tot[110];
			for(int i=1;i<=n;i++) lans=lans*v[a[i]]%mo;
			for(int i=0;i<=m;i++) tot[i]=0;
			for(int i=1;i<=n;i++) tot[a[i]]++;
			for(int i=0;i<=m;i++) di=di*jc[tot[i]]%mo;
			lans=lans*jc[n]%mo*ksm(di,mo-2)%mo;
			ans=(ans+lans)%mo;
		} 
		return;
	}
	for(int i=a[x-1];i<=m;i++) 
	{
		a[x]=i;baoli(x+1);
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout); 
	cin>>n>>m>>k;ans=0;a[0]=0;
	for(int i=0;i<=m;i++) cin>>v[i];
	jc[0]=1;
	for(int i=1;i<=n;i++) jc[i]=jc[i-1]*i%mo;
	baoli(1);
	cout<<ans<<endl;
	return 0;
}

