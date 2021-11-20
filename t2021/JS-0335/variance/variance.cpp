#include<bits/stdc++.h>
using namespace std;
int main()
{   freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int i,s=0,n;
	unsigned long long ans=0;
	scanf("%d",&n);
	int a[n+2]={0};
	for (i=1;i<=n;i++) 
	{   scanf("%d",&a[i]);
		s+=a[i];
		ans+=a[i]*a[i];
	}
	ans=ans*n;
	ans=ans-s*s;
	cout<<ans;
	
	return 0;
	
}
