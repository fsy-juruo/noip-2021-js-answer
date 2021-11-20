#include<bits/stdc++.h>
using namespace std;
 
int chec(int q)   
{
	int fff=1;
	while(q>0)
	{
		int j=q%10;
		if(j==7)
		{
			fff=0;
			break;
		}
		q/=10;
	}
	return fff;
}
 
int check(long long w)
{
	int ff=1;
	if(w%7==0)
	{
		ff=0;
		return ff;
	}
    else 
    {
	    for(int i=1;i*i<=w;i++)
	    {
		    if(w%i==0)
		    {
			    if((chec(i)==0)||(chec(w/i)==0))  
			    {
				    ff=0;
				    break;
		        }
		    }
	    }
	return ff;
    }
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
	    long long x;
		cin>>x;
	    if(check(x)==1)  
		{
			long long l=x;
		     while(l++)
		     {
		     	if(check(l)==1)
		     	{
		     		cout<<l<<endl;
		     		break;
		     	}
			 }
		} 
		else   cout<<"-1"<<endl;
	}
	
	return 0;
}





   
