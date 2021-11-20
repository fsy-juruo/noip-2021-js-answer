#include <bits/stdc++.h>
using namespace std;
int nyq(int x)
{
	int cnt=1;
	while(x!=0)
	{
		//cout<<cnt<<endl;
		//cnt++;
		if( x%10==7 )
		{
			return 1;
		}
		x/=10;
	}
	return 0;
}
int ly(int x) //判断是否含7,如果含7, 返回真 
{
	//int cnt=1;
	for(int i=1;i<=x;i++)
	{
		if( x%i==0 )
		{
			int y;
			y=x/i;
			while( y!=0 )
			{
				if( y%10==7 )
				{
					return 1;
				}
				y/=10;
			}
		}
	}
	return 0;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int r;
		cin>>r;
		if( nyq(r) || ly(r) )
		{
			cout<<"-1"<<endl;
		}
		else
		{
			int z=0;
			z=r+1;
			while(true)
			{
				if( nyq(z) || ly(z) )
				{
				    z++;
			    }
				else
				{
					cout<<z<<endl;
					break;
				} 
			}
		}
	}
	cout<<endl;
	return 0;
}
/*
4
6
33
69
300
*/

