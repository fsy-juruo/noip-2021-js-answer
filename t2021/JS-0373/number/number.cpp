#include<bits/stdc++.h>
using namespace std;
int main()
{	int t,i,m,n,k,x[200005],fg1=0,fg2=0,fg3=0;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>t;
	for(i=1;i<=t;i++)	cin>>x[i];
	for(i=1;i<=t;i++,fg1=0,fg3=0)
	{
		for(m=x[i];fg1==0&&fg3==0;m++,fg2=0)
		{
			for(k=1;k<=m/2&&fg2==0;k++)
			{
				if(m%k==0)
				{
					for(n=m/k;n>6&&fg2==0;n/=10)
					{
						if(n%10==7)
						{
							fg2=1;
							if(m==x[i])
							{fg1=1;cout<<-1<<endl;}
						}
					} 
				} 
			}
		if(fg2==0&&m!=x[i]){fg3=1;cout<<m<<endl;}	
		}
	}
	return 0;
}
