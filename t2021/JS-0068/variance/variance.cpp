#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const int base=131,maxn=1e4+10;
int n;
int a[maxn];
int ans=INT_MAX;
ll bases[maxn];
ll hasht()
{
	ll hs=0;
	bases[0]=1;
	for(int i=1;i<=n;i++)
	{	
		bases[i]=bases[i-1]*base;
		hs+=a[i]*bases[i];	
		//cout<<bases[i]<<" ";
	}
	//cout<<endl;
	return hs;
}
map<ll,bool> h;
void dfs(ll hash,int sum,int pf)
{
	ans=min(ans,pf*n-sum*sum);
	//cout<<sum<<" "<<pf<<endl;
	for(int i=2;i<n;i++)
	{
		ll hash1=hash;
		int sum1=sum,pf1=pf;
		hash1-=(ll)a[i]*bases[i];
		sum1-=a[i];
		//cout<<sum1<<" "<<a[i]<<endl;
		pf1-=a[i]*a[i];
		a[i]=a[i-1]+a[i+1]-a[i];
		hash1+=(ll)a[i]*bases[i];
		sum1+=a[i];
		pf1+=a[i]*a[i];
		//cout<<sum1<<" "<<a[i]<<endl;	
		if(h[hash1])
		{
			goto A;
		}
		h[hash1]=true;
		dfs(hash1,sum1,pf1);
		A:
		a[i]=a[i-1]+a[i+1]-a[i];
	}
}
int main()
{
	int sum=0,pf=0;
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
		pf+=a[i]*a[i];
	}
	ll tmp=hasht();
	//cout<<tmp<<endl;
	h[tmp]=true;
	//cout<<pf*n-sum*sum<<endl;
	//system("pause");
	dfs(tmp,sum,pf);
	cout<<ans;
}
/*
4
1 2 4 6
*/

