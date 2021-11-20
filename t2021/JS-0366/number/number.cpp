#include <bits/stdc++.h>
using namespace std;
const int MAXN=100000;
int t,a,ans;
bool p(int x)
{
	while(x>0)
	{
		if((x%10)==7) return 1;
		x=x/10;
	}
	return 0;
}
bool p2(int x)
{
	int k=2;
	while(x>1)
	{
		while(x%k==0)
		{
			if(p(k)==1) return 1;
			if(p(x/k)==1) return 1;
			x=x/k;
		} 
		k++;
	}
	return 0;
}
bool prim(int x)
{
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0) return 1;
	}
	return 0;
}
int sol(int x)
{
	for(int i=x+1;i<=MAXN;i++)
	{
		if((prim(i)==0)&&(p(i)==0))
		{
			return i;
		}
	else	if((p(i)==0)&&(p2(i)==0))
		{
			return i;
		}
	}
	return x;
}
int main()
{
	freopen("number.in","r",stdin);
 	freopen("number.out","w",stdout);
	cin>>t;
 	for(int i=1;i<=t;i++)
 	{
 		cin>>a;
 		if(p(a)==1) cout<<"-1";
 		else 
		{
			if(p2(a)==1) cout<<"-1";
			else
			{
				cout<<sol(a);
			}
		}
		cout<<endl;
	}
 	return 0;
}

