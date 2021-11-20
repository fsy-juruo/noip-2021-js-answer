#include<bits/stdc++.h>
using namespace std;

int p(int x)
{
	while(x>=0)
	{
		if(x<10&&x!=7) return 0;
	    if(x%10==7)  return 1;
	    x=x/10;
	}
    
	
}
int q(int x)
{
	for(int y=1;y<x;y++)
	{
		if(p(y)==1&&x%y==0) return 1;
	
	}
}		

int main( )
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	int x,T,a[200007];
	int i;
	cin>>T;
	for(i=1;i<=T;i++)
		cin>>a[i];
		
	for( i=1;i<=T;i++)
	{
	    x=a[i];
	    if(q(x)==1||p(x)==1) 
		{
			cout<<"-1"<<endl;
			continue;
		}
        else 
            x++;
	        while(q(x)==1||p(x)==1) x++;
	    cout<<x<<endl;	
    	    
	}

	return 0;
}
