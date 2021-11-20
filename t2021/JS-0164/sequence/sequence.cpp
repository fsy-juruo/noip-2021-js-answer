#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=998244353;
int n,m,k; int a[101];
ll v[101],ans;
ll read(){
	ll sum=0; bool flag=false; char c;
	c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') flag=true;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		sum=(sum*10)+c-'0';
		c=getchar();
	}
	if(flag) return -sum;
	else return sum;
}
int con(int a,int b)
{
	int sum1=1,sum2=1;
	for(int i=1;i<=b;i++)
	{
		sum1*=(a-i+1);
		sum2*=i;
	}
	return sum1/sum2;
}
void dfs(int q,int dep,int j)
{
	if(dep*m<q) return ;
	if(dep<0) return;
	if(q==0)
	{
		ll sum=1,t=n;
		for(int i=0;i<=m;i++)
		{
			sum*=pow(v[i],a[i])*con(t,a[i]);
			t-=a[i];
			sum%=M;
		}
		ans+=sum;
		ans%=M;
		return ;
	}
	for(int i=j;i<=k;i++)
	{
		a[i]++; a[0]--;
		dfs(q-i,dep-1,i);
		a[i]--; a[0]++;
	}
}
void find(int s,ll e,int w)
{
	for(ll i=s;i<=e;i++)
	{
		int z=0,k=0,t=0; ll j=i;
		while(j) 
		{
			z+=(j&1);
			k+=(j&1)*t;
			t++;
			j>>=1;
		}
		if(z<=w) dfs(k,n,1);
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++) v[i]=read();
	a[0]=n;
    find(n,n*(pow(2,m)),k);
	cout<<ans%M<<endl;
	return 0;
}
