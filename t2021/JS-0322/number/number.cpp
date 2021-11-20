#include<bits/stdc++.h>
using namespace std;
int a[10000007];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=10000000;i++)
	{

		if(a[i]==0)
		{
			int y=i;
			while(y!=0)
			{
				if(y%10==7)
				{
					int x=1;
					while(x*i<=10000000)
					{
						a[i*x]=1;
						x++;
					}
					break;
				}
				y/=10;
			}
		}
	}
	int T,x;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		scanf("%d",&x);
		if(a[x]==1)
		{
			cout<<-1<<endl;
		}
		else
		{
			x++;
			while(a[x]==1)
			{
				x++;
			}
			cout<<x<<endl;
		}
	}
	return 0;
}
