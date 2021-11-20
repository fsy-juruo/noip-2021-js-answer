#include<bits/stdc++.h>
using namespace std;
int a[10001];
bool min(int a,int b)
{
	if((a>b)||(a==b))
		return 0;
	if(a<b)
		return 1;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	double n,s=0,sum=0,eqo=0,eq=0,ss,tot,t,tt,tott,original=0,originall=0;
	cin>>n;	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	eqo=sum/n;
	for(int i=1;i<=n;i++)
	{
		original+=(eqo-a[i])*(eqo-a[i]);
	}
	originall=original/n;
	//////////////////////////////////
	for(int j=2;j<=n-1;j++)
	{
		t=tott;
		ss=a[j];
		a[j]=a[j-1]+a[j+1]-a[j];
		s+=sum-ss+a[j];
		sum=sum-ss+a[j];
		eq=s/n;
		for(int k=1;k<=n;k++)
		{
			tot+=(eq-a[k])*(eq-a[k]);
		}
		tott=tot/n;
		if(min(tott,t))//tot<t
			tt=tott;
		else
			tt=t;
	}
	if(min(tt,originall))
		cout<<tot*n*n<<endl;
	else
		cout<<originall*n*n<<endl;
}

