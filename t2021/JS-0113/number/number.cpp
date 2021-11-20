#include<bits/stdc++.h>
#define MAX 10000000
using namespace std;
bool used[MAX+5]; int a[MAX+5],maxn,maxm,cnt,t,sz;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>t;
	for(int i=1; i<=t; i++) 
	{
	cin>>a[i];
    maxn=max(maxn,a[i]);
	}
    maxn=min(maxn*7,MAX);
    for(int i=7; i<=maxn; i++)
    {
    	int num=i,flag=0; 
    	while(num)
    	{
    		if(num%10==7) flag=1;
			num/=10; 
		}
		if(flag==1) 
		{
			for(int j=i; j<=maxn; j+=i) 
			used[j]=1;
		}
	}
	for(int i=1; i<=t; i++)
	{
	    if(used[a[i]]==true) cout<<-1<<endl;
        else 
        {
        	int sum=a[i]+1;
        	while(true)
        	{
        		if(used[sum]==false) { cout<<sum<<endl; break; }
        		sum++;
			}
		}
	}
	return 0;
}
