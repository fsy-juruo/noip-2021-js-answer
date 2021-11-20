#include <bits/stdc++.h>
using namespace std;
int a[10010];
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n;
	cin>>n;
	int fz=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		fz+=a[i];
	}
	int ans=0;
    for(int i=1;i<=n;i++)
    {
    	ans+=abs((a[i]*n-fz)*(a[i]*n-fz));
	}
	ans=ans/n;
	cout<<ans<<endl;
	return 0;
}

