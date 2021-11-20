#include<bits/stdc++.h>
using namespace std;
long long read()
{
	long long k=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=(k<<1)+(k<<3)+c-'0';
		c=getchar();
	}

	return k*f;
}

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n;
	n=read();
	int a[10050];
	for(int i=1;i<=n;i++)a[i]=read();
	long long ans=9982443530;
	long long tot=0;
	long long sig=0;
	for(int i=1;i<=n;i++)tot+=a[i];
	for(int i=1;i<=n;i++)sig+=pow(a[i]*n-tot,2);
	sig/=n;
	ans=min(ans,sig);
	if(n>4)
	{
		cout<<ans;
		return 0;
	}
	int b[10050];
	memcpy(b,a,sizeof(b));
	for(int i=1;i<=100000;i++)
	{
		a[2+i%2]=a[1+i%2]+a[3+i%2]-a[2+i%2];
		tot=sig=0;
		for(int i=1;i<=n;i++)tot+=a[i];
		for(int i=1;i<=n;i++)sig+=pow(a[i]*n-tot,2);
		sig/=n;
		ans=min(ans,sig);
	}
	memcpy(a,b,sizeof(b));
	for(int i=1;i<=100000;i++)
	{
		a[2+(1-i%2)]=a[1+(1-i%2)]+a[3+(1-i%2)]-a[2+(1-i%2)];
		tot=sig=0;
		for(int i=1;i<=n;i++)tot+=a[i];
		for(int i=1;i<=n;i++)sig+=pow(a[i]*n-tot,2);
		sig/=n;
		ans=min(ans,sig);
	}
	cout<<ans;
	return 0;
}

