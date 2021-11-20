#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,x,a[200001],p,c,b,k;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	c=7;
	while(c*(k+1)<=10000)
	{	
		k++;
		a[c*k]=1;
	}
	for(register int i=17;i<=10000;++i)
		if (a[i]==0)
		{
			p=0;
			b=i;
			while(b>0)
			{
				if (b%10==7)
   				{
					p=1;
					break;				
				}
				else
					b=b/10;
			}
			if (p==1)
				{
					c=i;
					k=0;
					a[i]=1;
					while(c*(k+1)<=10000)
					{
						k++;
						a[c*k]=1;					
					}
				}	
		}	
	
	scanf("%d",&t);
	for(register int i=1;i<=t;++i)
	{
		scanf("%d",&x);
		if (a[x]==1)
			cout<<"-1"<<endl;
		else
			for (register int j=x+1;j<=200000;++j)
			{
				if (a[j]==0)
				{
					cout<<j<<endl;
					break;
				}				
			}
	}
	return 0;
}

