#include<bits/stdc++.h>
using namespace std;
int T,n,h[10000100],a[1000100],nex[10000100];
int judge(int x)
{
	while (x!=0)
	{
		if (x%10==7)return 1;
		x/=10;
	}
	return 0;
}
void era(int s,int x)
{
	for (int i=s;i<=x;i++)
	{
		if (h[i]==1)continue;
		else
		{
			if (judge(i))
			{
				for (int j=1;j<=x/i;j++)h[j*i]=1;
			}
			else
			{
				for (int j=i-1;j>=1;j--)
				{
					nex[j]=i;
					if (h[j]==0) break;
				}
			}
		}
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>T;
	int maxn=1;
	for (int i=1;i<=T;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	era(1,maxn*2);
	for (int i=1;i<=T;i++)
	{
		n=a[i];
		if (h[n]==1)
		{
			cout<<-1<<endl;
			continue;
		}
		else cout<<nex[n]<<endl;
	}
	return 0;
}
