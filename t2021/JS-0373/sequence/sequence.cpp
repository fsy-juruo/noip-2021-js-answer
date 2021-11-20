#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m,k,v[15],a[15],s,i;
	cin>>n>>m>>k;
	for(i=0;i<=m;i++)
		cin>>v[i];

/*	for(i=1;i<=t;i++)	cin>>x[i];
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
*/	
	return 0;
}
