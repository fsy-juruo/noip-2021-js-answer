#include<bits/stdc++.h>
using namespace std;
int t,n,sum;
bool key;
bool work(int x)
{
	int xx;
	while(x!=0)
	{
		xx=x%10;
	    x/=10;
	    if(xx==7)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>t;
    while(t--)
    {
    	sum=0;
    	scanf("%d",&n);
    	if(work(n)==false)continue;
    	for(int i=2;i*i<=n;i++)
    	{
    		if(n%i==0)
    		   if(work(n/i)==false||work(i)==false)
    			  sum++;
		}
		if(sum!=0)
		{
			printf("-1\n");
			continue;
		}
		while(1)
			{
				key=0;
				n++;
				if(work(n)==false)continue;
		        for(int i=2;i*i<=n;i++)
		    	{
		    		if(n%i==0)
		    			if(work(n/i)==false||work(i)==false)
		    			{
		    				key=1;
		    				break;
						}				
				}
				if(key==0)
				{
					printf("%d\n",n);
					break;
				}		
			}
	}
	return 0;
}

