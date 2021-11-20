#include<bits/stdc++.h>
using namespace std;
int t,x,a[1001005],v[10001000],fitt[1001005],cnt=1;
int ef(int l,int r,int mb)
{

	while(l+1<r)
	{
  	  int mid=(l+r)/2;
	  if(fitt[mid]>mb)r=mid;
	  else l=mid;
	}
	return l;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>a[k];
		//n=max(n,a[k]);
	}
	for(int i=1;i<=10000100;i++)
	{
		if(v[i]==0) {
			if(i%10==7||(i%100)/10==7||(i%1000)/100==7||(i%10000)/1000==7||(i%100000)/10000==7||(i%1000000)/100000==7||(i%10000000)/1000000==7)
			{
				for(int j=1;(i*j)<=10000100;j++)
				  v[i*j]=1;
			}
		
		else {fitt[cnt]=i;cnt++;
		}
		}
	}	
	for(int k=1;k<=t;k++)
	{
		if(v[a[k]]==1)cout<<-1<<endl;
		else{
			cout<<fitt[ef(1,cnt,a[k])+1]<<endl;
		}
	}
	return 0;
}

