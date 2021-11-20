//ÏéÈğÓùÃâ 
#include<bits/stdc++.h>
using namespace std;
int f[10000001];
bool judge(int x)
{
	while(x!=0)
	{
		if(x%10==7)
		{
			return 1;
		}
		x=x/10;
	}
	return 0;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int g=0;
	for(int i=1;i<=10000001;i++)
	{
		if(judge(i)==1)
		{
			if(f[i]==0)
			{
				f[i]=-1;
				for(int j=i*2;j<=10000001;j+=i)
				{
					f[j]=-1;
				}
			}
		}
		if(f[i]==0)
		{
			f[g]=i;
			g=i;
		}
	}
	f[10000001]=10000010;
	int T;
	cin>>T;
	int a;
	for(int i=1;i<=T;i++)
	{
		cin>>a;
		cout<<f[a]<<endl;
	}
	return 0;
} 
