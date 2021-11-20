#include<bits/stdc++.h>
using namespace std;
int n,m,k,q=998244353;
long long ans;
int v[105],t[1000]={0},t1[1000];
bool check()
{
	memset(t1,0,sizeof(t1));
	int num=0;
	for(int i=0;i<=m;i++)
	{
		t1[i]=t[i];
	}
	for(int i=0;i<=m+n;i++)
	{
		num+=t1[i]%2;
		//cout<<t1[i]<<endl;
		t1[i+1]+=t1[i]/2;
		//cout<<num<<endl;
		if(num>k) return 0;
	}
	return 1;
}
void dfs(int step,long long sum)
{
	if(step>n)
	{
		//cout<<endl;
		if(check()){
		//	cout<<sum<<endl;
			ans=((ans%q)+(sum%q))%q;
		}
		return;
	}
	for(int i=0;i<=m;i++)
	{
		t[i]++;
		dfs(step+1,((v[i]%q)*sum%q)%q);
		t[i]--;
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++)
	{
		scanf("%d",v+i);
	}
	dfs(1,1);
	printf("%lld",ans);
	return 0;
}
