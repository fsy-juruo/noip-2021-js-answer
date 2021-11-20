#include<bits/stdc++.h>
using namespace std;

long long T,x,last,out[10010000];
long long l[10010000];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>T;
	if(T <= 10000)
	{
		l[0] = 1;
		l[7] = 1;
		for(long long i = 1;i <= 4 * 1e5;i++)
		{
			if(i * 10 + 7 <= 4 * 1e5)
			l[i * 10 + 7] = 1;
			if(l[i] == 1)
			{
				for(int j = 0;j <= 9 && i * 10 + j <= 4 * 1e5;j++)
					l[i * 10 + j] = 1;
				for(int j = 2;j * i <= 4 * 1e5;j++)
				if(l[j * i] == 0)
					l[j * i] = 2;
			}
		}
		
		for(long long i = 4 * 1e5;i >= 0;i--)
		{
			if(l[i] == 0)
			{
				out[i] = last;
				last = i;
			}
			else out[i] = -1;
		}
		
		for(long long i = 1;i <= T;i++)
		{
			cin>>x;
			cout<<out[x]<<endl;
		}
	}
	else
	{
		l[0] = 1;
		l[7] = 1;
		for(long long i = 1;i <= 1e7 + 10;i++)
		{
			if(i * 10 + 7 <= 1e7 + 10)
			l[i * 10 + 7] = 1;
			if(l[i] == 1)
			{
				for(int j = 0;j <= 9 && i * 10 + j <= 1e7 + 10;j++)
					l[i * 10 + j] = 1;
				for(int j = 2;j * i <= 1e7 + 10;j++)
				if(l[j * i] == 0)
					l[j * i] = 2;
			}
		}
		
		for(long long i = 1e7 + 10;i >= 0;i--)
		{
			if(l[i] == 0)
			{
				out[i] = last;
				last = i;
			}
			else out[i] = -1;
		}
		
		for(long long i = 1;i <= T;i++)
		{
			cin>>x;
			cout<<out[x]<<endl;
		}
	}
	
	
	return 0;
}

