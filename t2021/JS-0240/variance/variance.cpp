#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e5+5;
ll nums[maxn],num[maxn];
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n,ans=1e9;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>nums[i];	
	for(int i=1;i<=1e5;i++)
	{
		for(int j=0;j<n;j++)
			num[j]=nums[j];
		int cur=rand()%(n*n);
		for(int j=0;j<=cur;j++)
		{
			int rp=rand()%(n-2);
			rp++;
			num[rp]=num[rp+1]+num[rp-1]-num[rp];
		}
		int av=0,now=0;
		for(int i=0;i<n;i++)
			av+=num[i];
		for(int i=0;i<n;i++)
			now+=(av-num[i]*n)*(av-num[i]*n);
		ans=min(ans,now);
	}
	cout<<ans/n;
} 
