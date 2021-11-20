#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main()
{freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int T,x,i=1,b=1,c,d,e,f=0,m;
	cin>>T;
	cout<<-1;
	m=T;
	if (i!=m)
	{a[i]=x;cin>>x;i++;}
	if (i<=0)
	 	{c=7;d=70;
		if (a[b]/10==7&&a[b]%10==7)
	        {cout<<-1<<' ';b++;}
	  	if (a[b]%7==0)
	        {cout<<-1<<' ';b++;}
	  	if (a[b]>0)
	        {if (c<=a[b])
			       if (a[b]%c!=0)
			          c=c+10;
					else cout<<-1<<' ';}
	  	if (a[b]>=70)
	        {if (d<=79)
	            if (a[b]%d!=0)
	                d++;
	            else cout<<-1<<' ';} 
		else (e=a[b]+1);
	  	{if (c!=a[b])
		    {c=7;d=70;
				{if (e/10==7&&e%10==7)
	        		e++;
	  			if (e%7==0)
	       			e++;
	  			if (e>0)
	       		 	{if (c<=e)
				   		if (e%c!=0)
				          	c=c+10;
						else e++;}
	  			if (e>=70)
	       		 	{if (d!=79)
	       		     	if (e%d!=0)
	       	      		d++;
	         		   	else e++;} 
	         	else {cout<<e<<' ';}
		  		}
		    }
	    }
}
return 0;}
