#include<bits/stdc++.h>
using namespace std;
const int N=1e7+3;
int n,f[N],ans[N],x;
bool check(int x)
{
	while(x)
	{
		if(x%10==7)return true;
		x=x/10;
	}
	return false;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=N;i++)
	{
		if(f[i]==1)continue;
		if(i%7==0)f[i]=1;
		if(check(i))
		{
			f[i]=1;
			for(int j=1;i*j<=N;j++)
				f[i*j]=1;
		}
	}
	for(int i=N-1;i>=1;i--)
	{
		if(f[i+1]==0)ans[i]=i+1;
		else ans[i]=ans[i+1];
	}
	cin>>n;
	//cout<<ans[10000000];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(f[x]==1)printf("-1\n");
		else printf("%d\n",ans[x]);
	}
	return 0; 
}
