#include<bits/stdc++.h>
using namespace std;
int a[210000],ans[210000];
bool checky(int n)//pd 7 youwu
{
	int q;
	while(n>0)
	{
	   q=n%10;
	   if(q==7)
	   {
	   	return false;
	   }
	   n=n/10;
	 } 
	 return true;
}
bool divid(int m)
{
	if(m<=2)
	{
		return true;
	}
	for(int j=2;j<=m;j++)
	{
		if(m%j==0)
		{
			int q=m/j;
			if(!checky(j)||!(checky(q)))
			{
			return false;
		     }
		  else
		  divid(m/j);
		}

	 } 
	 		return true;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}


	for(int i=0;i<n;i++)
      	{
	  	if((!checky(a[i]))||(a[i]%7==0)||(!divid(a[i])))
		     {
		    ans[i]=-1;
	         }
	         
	        int m=1;
	        if(ans[i]!=-1)
			{
	         for( int j=a[i]+1;m==1;j++)
	    	{
		        if((checky(j))&&(divid(j)))
		        {
		          ans[i]=j;
	            	m=0;
	                }
	}
}
}
	for(int i=0;i<n;i++)
	{
	cout<<ans[i]<<endl;;
    }
	return 0;
}
/*
4
6
33
69
300
*/
