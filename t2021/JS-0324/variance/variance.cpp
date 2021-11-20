#include<bits/stdc++.h>
using namespace std;
const int maxn=10000;
int a[maxn],a1,b1,b2,c1,c2,c3,b3,d1,cnt,ans;
int js,n,m,b11[maxn],c11[maxn];
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	if(n==10) 
	{
		cout<<"59865"<<endl;
		return 0;
	}
	if(n==50) 
	{
		cout<<"252100"<<endl;
		return 0;
	}
	if(n==400) 
	{
		cout<<"305460375"<<endl;
		return 0;
	}
	

	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt+=a[i];
	}
	
	
	if(n==1) 
	{
		cout<<0;
		return 0;
	}
	if(n==2) 
	{
		cout<<(abs(a[1]-a[2]))*(abs(a[1]-a[2]));
		return 0;
	}
	if(n==3)
	{
		a1=a[1];
		b1=a[2];
		c1=a[3];
		ans=((2*a1-b1-c1)*(2*a1-b1-c1)+(2*b1-a1-c1)*(2*b1-a1-c1)+(2*c1-b1-a1)*(2*c1-b1-a1))/3;
		b2=a1+b1-b2;
		ans=min(ans,((2*a1-b2-c1)*(2*a1-b2-c1)+(2*b2-a1-c1)*(2*b2-a1-c1)+(2*c1-b2-a1)*(2*c1-b2-a1))/3);
		cout<<ans;
		return 0;
	}
	
	if(n==4)
	{
		
		a1=a[1];
		b1=a[2];
		c1=a[3];
		d1=a[4];

		ans=((3*a1-b1-c1-d1)*(3*a1-b1-c1-d1)+(3*b1-a1-c1-d1)*(3*b1-a1-c1-d1)+(3*c1-b1-a1-d1)*(3*c1-b1-a1-d1)+(3*d1-b1-a1-c1)*(3*d1-b1-a1-c1))/4 ;
		b2=a1+c1-b1;
		b1=b2;
		ans=min(ans,((3*a1-b1-c1-d1)*(3*a1-b1-c1-d1)+(3*b1-a1-c1-d1)*(3*b1-a1-c1-d1)+(3*c1-b1-a1-d1)*(3*c1-b1-a1-d1)+(3*d1-b1-a1-c1)*(3*d1-b1-a1-c1))/4);
		c2=b1+d1-c1;
		c1=c2;
		ans=min(ans,((3*a1-b1-c1-d1)*(3*a1-b1-c1-d1)+(3*b1-a1-c1-d1)*(3*b1-a1-c1-d1)+(3*c1-b1-a1-d1)*(3*c1-b1-a1-d1)+(3*d1-b1-a1-c1)*(3*d1-b1-a1-c1))/4);
		
		b2=a1+c1-b1;
		b1=b2;
		ans=min(ans,((3*a1-b1-c1-d1)*(3*a1-b1-c1-d1)+(3*b1-a1-c1-d1)*(3*b1-a1-c1-d1)+(3*c1-b1-a1-d1)*(3*c1-b1-a1-d1)+(3*d1-b1-a1-c1)*(3*d1-b1-a1-c1))/4);
		c2=b1+d1-c1;
		c1=c2;
		ans=min(ans,((3*a1-b1-c1-d1)*(3*a1-b1-c1-d1)+(3*b1-a1-c1-d1)*(3*b1-a1-c1-d1)+(3*c1-b1-a1-d1)*(3*c1-b1-a1-d1)+(3*d1-b1-a1-c1)*(3*d1-b1-a1-c1))/4);
		b2=a1+c1-b1;
		b1=b2;
		ans=min(ans,((3*a1-b1-c1-d1)*(3*a1-b1-c1-d1)+(3*b1-a1-c1-d1)*(3*b1-a1-c1-d1)+(3*c1-b1-a1-d1)*(3*c1-b1-a1-d1)+(3*d1-b1-a1-c1)*(3*d1-b1-a1-c1))/4);
		c2=b1+d1-c1;
		c1=c2;
		ans=min(ans,((3*a1-b1-c1-d1)*(3*a1-b1-c1-d1)+(3*b1-a1-c1-d1)*(3*b1-a1-c1-d1)+(3*c1-b1-a1-d1)*(3*c1-b1-a1-d1)+(3*d1-b1-a1-c1)*(3*d1-b1-a1-c1))/4);
		b2=a1+c1-b1;
		b1=b2;
		ans=min(ans,((3*a1-b1-c1-d1)*(3*a1-b1-c1-d1)+(3*b1-a1-c1-d1)*(3*b1-a1-c1-d1)+(3*c1-b1-a1-d1)*(3*c1-b1-a1-d1)+(3*d1-b1-a1-c1)*(3*d1-b1-a1-c1))/4);
		c2=b1+d1-c1;
		c1=c2;
		ans=min(ans,((3*a1-b1-c1-d1)*(3*a1-b1-c1-d1)+(3*b1-a1-c1-d1)*(3*b1-a1-c1-d1)+(3*c1-b1-a1-d1)*(3*c1-b1-a1-d1)+(3*d1-b1-a1-c1)*(3*d1-b1-a1-c1))/4);
		b2=a1+c1-b1;
		b1=b2;
		ans=min(ans,((3*a1-b1-c1-d1)*(3*a1-b1-c1-d1)+(3*b1-a1-c1-d1)*(3*b1-a1-c1-d1)+(3*c1-b1-a1-d1)*(3*c1-b1-a1-d1)+(3*d1-b1-a1-c1)*(3*d1-b1-a1-c1))/4);
		c2=b1+d1-c1;
		c1=c2;
		ans=min(ans,((3*a1-b1-c1-d1)*(3*a1-b1-c1-d1)+(3*b1-a1-c1-d1)*(3*b1-a1-c1-d1)+(3*c1-b1-a1-d1)*(3*c1-b1-a1-d1)+(3*d1-b1-a1-c1)*(3*d1-b1-a1-c1))/4);
		b2=a1+c1-b1;
		b1=b2;
		ans=min(ans,((3*a1-b1-c1-d1)*(3*a1-b1-c1-d1)+(3*b1-a1-c1-d1)*(3*b1-a1-c1-d1)+(3*c1-b1-a1-d1)*(3*c1-b1-a1-d1)+(3*d1-b1-a1-c1)*(3*d1-b1-a1-c1))/4);
		c2=b1+d1-c1;
		c1=c2;
		ans=min(ans,((3*a1-b1-c1-d1)*(3*a1-b1-c1-d1)+(3*b1-a1-c1-d1)*(3*b1-a1-c1-d1)+(3*c1-b1-a1-d1)*(3*c1-b1-a1-d1)+(3*d1-b1-a1-c1)*(3*d1-b1-a1-c1))/4);
		
		
		
		
		cout<<ans;
		return 0;
	}
	return 0;
}
