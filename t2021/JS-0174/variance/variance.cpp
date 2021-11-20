#include<bits/stdc++.h>
using namespace std;
int n,a[10005],ans=INT_MAX,dep;
void dfs(int mum,int las)
{
	if(dep==10000){cout<<ans<<endl;exit(0);}
	dep++;
	double now=0;
	for(int i=1;i<=n;i++)
	  now+=(a[i]-(double)mum/n)*(a[i]-(double)mum/n);
	now*=n;
	ans=min(ans,(int)now);
	for(int i=2;i<n;i++)
	  if(a[i-1]+a[i+1]!=2*a[i]&&i!=las){
	  mum=mum+a[i-1]+a[i+1]-2*a[i];
	  a[i]=a[i+1]+a[i-1]-a[i];
	  dfs(mum,i);
	  a[i]=a[i+1]+a[i-1]-a[i];
	  }
	return;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	int nn=0;
	for(int i=1;i<=n;i++)
	{
	  cin>>a[i];
	  nn+=a[i];	
	  }  
	dfs(nn,0);
	cout<<ans<<endl;
	return 0;
}

