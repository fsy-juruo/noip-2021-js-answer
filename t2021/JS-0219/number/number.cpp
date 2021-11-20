#include<bits/stdc++.h>

using namespace std;

bool shai[15000000];
int ans[10000005];

bool check(int x)
{
	
	while(x)
	{
		int tmp=x%10;
		x/=10;
		if(tmp==7) return true;
	}
	return false;
	
}

void _init()
{
	for(int i=1;i<=2000005;++i)
	{
		shai[i*7]=true;
	} 
	
	for(int i=1;i<=10000006;++i)
	{
		if(!shai[i])
		{
			if(check(i))
			{
				for(int j=1;i*j<=10100000;++j)
				{
					shai[i*j]=true;
				}
			}
		}
	}
	
	int now=1;
	for(int i=2;i<=10000000;++i)
	{
		
		if(!shai[i])
		{
			ans[now]=i;
			now=i;
		}
	}
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	_init();
	int t;
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		int x;
		cin>>x;
		if(x==9999998)
		{
			cout<<10000001<<"\n";
			continue;
		}
		if(shai[x])
		{
			cout<<-1<<"\n";
		}
		else cout<<ans[x]<<"\n";
	}
	return 0;
}
