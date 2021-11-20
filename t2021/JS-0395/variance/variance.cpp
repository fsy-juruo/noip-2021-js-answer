#include<bits/stdc++.h>
using namespace std;
double a[1100];
int main()
{
	freopen("variance.in","r",stdin);
    freopen("variance.out","w",stdout);
	int n;
	double k,ans,sum,num;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
 for(int i=1;i<=n;i++)
	  {
	  	ans+=a[i];
	  }
	  for(int i=1;i<=n;i++)
	  {
	  	sum+=(a[i]-ans/4)*(a[i]-ans/4);
	  }
	  num=n*sum;
	  cout<<(int)num;
} 
/*
4
1 2 4 6
*/ 
