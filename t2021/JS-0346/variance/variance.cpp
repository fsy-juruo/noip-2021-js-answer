#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define MAXN 10003
int n;
LL a[MAXN],presum,nowsum,sum2,s,quitsum,ds;
double midlr;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		nowsum+=a[i];sum2+=a[i]*a[i];
	}
	s=n*sum2-nowsum*nowsum;
	midlr=(double)nowsum/n;
	presum=nowsum;
	bool p=true,pp=true;LL nxta=0;
	
	while(p)
	{
		p=false;
		for(int i=2;i<n;++i)
		{
			presum=nowsum;nxta=a[i-1]+a[i+1]-a[i];
			quitsum=presum-a[i];nowsum=quitsum+nxta;
			ds=n*(nxta*nxta-a[i]*a[i])-(nowsum*nowsum-presum*presum);
			if(abs(a[i]-midlr)>abs(nxta-midlr)){
				s+=ds;p=true;a[i]=nxta;pp=true;
			}
			else// if((a[i]+nxta==2*midr)&&pp)
			nowsum=presum;
		}
		for(int i=n-1;i>1;--i)
		{
			presum=nowsum;nxta=a[i-1]+a[i+1]-a[i];
			quitsum=presum-a[i];nowsum=quitsum+nxta;
			ds=n*(nxta*nxta-a[i]*a[i])-(nowsum*nowsum-presum*presum);
			if(abs(a[i]-midlr)>abs(nxta-midlr)){
				s+=ds;p=true;a[i]=nxta;pp=true;
			}
			else nowsum=presum;
		}
	}
	
	p=true;
	while(p)
	{
		p=false;
		for(int i=2;i<n;++i)
		{
			presum=nowsum;nxta=a[i-1]+a[i+1]-a[i];
			quitsum=presum-a[i];nowsum=quitsum+nxta;
			ds=n*(nxta*nxta-a[i]*a[i])-(nowsum*nowsum-presum*presum);
			if(ds<0){
				s+=ds;p=true;a[i]=nxta;
			}
			else nowsum=presum;
		}
		for(int i=n-1;i>1;--i)
		{
			presum=nowsum;nxta=a[i-1]+a[i+1]-a[i];
			quitsum=presum-a[i];nowsum=quitsum+nxta;
			ds=n*(nxta*nxta-a[i]*a[i])-(nowsum*nowsum-presum*presum);
			if(ds<0){
				s+=ds;p=true;a[i]=nxta;
			}
			else nowsum=presum;
		}
	}
	cout<<s<<endl;
}
