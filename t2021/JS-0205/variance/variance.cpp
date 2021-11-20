#include<bits/stdc++.h>
using namespace std;
int n,num[10010],pj,ans=1e9+7,vis[10010];
int get_c(int jz)
{
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		int tmp=((num[i]*n)-jz);
		tot+=(tmp*tmp);
	}
	tot/=n;
	return tot;
}
void dfs(int jz,int tot)
{
	ans=min(ans,get_c(jz));
	for(int i=2;i<n;i++)
	{
		if(vis[i]==1)continue;
		if(num[i-1]+num[i+1]-num[i]!=num[i])
		{
			int tmp=pj-num[i];
			num[i]=num[i-1]+num[i+1]-num[i];
			tmp+=num[i];
			vis[tot]=1;
			dfs(tmp,tot+1);
			vis[tot]=0;
			num[i]=num[i-1]+num[i+1]-num[i];
		}
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
		pj+=num[i];
	}
	dfs(pj,0);
	cout<<ans<<endl;
	return 0;
}
