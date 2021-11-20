#include <bits/stdc++.h>
#define ll long long
const ll P=998244353;
ll read()
{   int f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return x*f;
}
ll n,m,k;
ll v[110],a[50],rider[3100],nowk,vice[3100];
ll ans,V;
int fra[33];
bool nice(int k)
{
	memset(vice,0,sizeof vice);
	nowk=0;
//	for(int i=1;i<=n;i++)
//		printf("%d ",a[i]);
//		puts("");
	for(int i=0;i<=m*n;i++)
	{
		vice[i]+=rider[i];
		if(!vice[i]) continue;
//		printf("%d %d ",i,vice[i]);
		while(vice[i]>1)
		{
			vice[i]-=2;
			vice[i+1]++;
		}
		if(vice[i]%2==1) nowk++;
//		printf("nowk%d ",nowk);
		if(nowk>k) 
		{
//			printf("no\n");
			return false;
		}
	}
//	puts("");
	
	return true;
}
ll toki()
{
	ll sum=1,s;
	ll nn=n,odd=-1;
//	printf("%d\n",nn);
	while(nn)
	{
		odd++;
//		printf("%d ",rider[odd]);
		if(!rider[odd]) continue;
		s=1;
		for(int i=1;i<=rider[odd];i++)
		{	
			s*=(nn--)%P;
//			printf("s%d ",s);
		}
		ll fr=fra[rider[odd]];
		ll p=(s/fr);
//		if(s%fr!=0) printf("dd");
//		printf("p%d ",p);
		sum=(sum*p)%P;
		if(nn==rider[odd]) break;
//		printf("sum%d ",sum);
//		if(sum>=P) sum-=P;
	}
//	printf("%lld\n",sum);
	return sum;
}
void hadaraku()
{
	V=1;
	for(int i=1;i<=n;i++)
	{
		
		V=(V*v[a[i]])%P;
//		printf("%lld ",V);
//		if(V>=P) V%=P;
	}
//	puts("");
	ll t=toki();
//	printf("%d\n",t);
	V=(V*t)%P;
	ans=(ans+V)%P;
}
void forma(int x)
{
	if(x==n+1)
	{
		if(nice(k))
			hadaraku();
		return;
	}
	for(int i=a[x-1];i<=m;i++)
	{
		if(i!=a[x-1]) rider[a[x]]--;
		a[x]=i;
		rider[i]++;
		forma(x+1);
	}
	rider[m]--;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();
	m=read();
	k=read();
	fra[1]=1;
	for(int i=2;i<=30;i++)
	{
		fra[i]=(fra[i-1]*i)%P;
//		printf("%lld\n",fra[i]);
	}
	for(int i=0;i<=m;i++)
	{
		v[i]=read();
	}
	forma(1);
	printf("%lld",ans);
	return 0;
}
/*
5 1 1
8768756 3453567
8 9 4
8 3 4 3 3 2 1 0 5 2

*/
