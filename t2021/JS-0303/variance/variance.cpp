#include<bits/stdc++.h>
using namespace std;

int n,a[10005];
double s=0,ss=0,sss=0,ms=0;   //FC PFH  H

void fi(long long l,int j)
{
	if(l>1000000)
	{
		return;
	}
	for(int i=j;i<n&&i>1;i++)
	{
		ms=(ss-a[i]*a[i]+(a[i-1]+a[i+1]-a[i])*(a[i-1]+a[i+1]-a[i]))*n-((sss+a[i-1]+a[i+1]-2*a[i])*(sss+a[i-1]+a[i+1]-2*a[i]));
		if(ms<s)  
		{
			double qss=ss,qsss=sss;    int k=a[i];
			s=ms;
			ss=ss-(a[i]*a[i])+(a[i-1]+a[i+1]-a[i])*(a[i-1]+a[i+1]-a[i]);
			sss=sss+a[i-1]+a[i+1]-2*a[i];
			a[i]=a[i-1]+a[i+1]-a[i];
			
			fi(l++,j++);
			j--;
			fi(l++,j--);
			a[i]=k;   ss=qss;  sss=qsss;
		}
	}
}

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ss+=(a[i]*a[i]);
		sss+=a[i];
	}
	s=ss*n-(sss*sss);
	fi(1,2);
    cout<<s<<endl;
    
	return 0;
}
