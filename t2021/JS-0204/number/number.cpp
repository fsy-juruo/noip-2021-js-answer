#include<bits/stdc++.h>
using namespace std;
int siz=10000000;
int t;
int n;
int las;
int nxt[10000005];
bool v[10000005]; 
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	for(int i=7;i<=siz;i++)
	{
		if(v[i]==1)continue;
		int x=i;
		while(x)
		{
			if(x%10==7)
			{
				for(int j=i;j<=siz;j+=i)
				{
					v[j]=1;
				}
				break;
			}
			x/=10;
		}
	}
	if(siz==10000000)v[10000001]=0;
	else v[200002]=0;
	for(int i=1;i<=siz+2;i++)
	{
		if(v[i]==0)
		{
			nxt[las]=i;
			las=i;
		}
	}
	cin>>t;
	for(int k=0;k<t;k++)
	{
		cin>>n;
		if(v[n]==1)cout<<"-1\n";
		else cout<<nxt[n]<<"\n";
	}
	return 0;
}
