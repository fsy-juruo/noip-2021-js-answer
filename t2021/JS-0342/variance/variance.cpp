#include<bits/stdc++.h>
using namespace std;
int n,a[1007],b[1007];
double sum,var,ans=0x7ffffffff;
void inp()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
}
void ave()
{
	for(int i=1;i<=n;i++) sum+=a[i];
	sum/=n;
}
void vari()
{
	for(int i=1;i<=n;i++)
		b[i]=pow(a[i]-sum,2);
	for(int i=1;i<=n;i++) var+=b[i];
	var/=n;
}
int main()
{
	inp();
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	//cout<<0<<endl;
	ave();
	vari();
	ans=min(ans,var);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j+i<=n;j++)
		{
			int k=j+i-1;
			double mem=a[k];
			a[k]=a[k-1]+a[k+1]-a[k];
		    ave();
		    vari();
		    ans=min(var,ans);
		    a[k]=mem;
		}
		
	}
	cout<<ans*n*n<<endl;
	return 0;
	
}
