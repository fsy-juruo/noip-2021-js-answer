#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll read()
{
	ll k,f=1;
	char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') f=-1;
	k=c^48;
	while((c=getchar())>='0'&&c<='9')
	k=(k<<3)+(k<<1)+(c^48);
	return k*f;
}
void put(ll k)
{
	if(k<0) putchar('-'),k=~k+1;
	if(k>9) put(k/10);
	putchar(k%10+'0');
}
const ll M=20000000;
bool pd[M+520],pd2[M+520];
ll nex[M+520];
ll minn[M+520];
ll min2[M+520];
ll sl[M+520],cnt;
ll pl[M+520];
ll q[200520],maxn;
ll s[M+520],ct;
bool is_prime[20060520];
ll prime[20060520],tot;
void xxs()
{
	memset(is_prime,1,sizeof(is_prime));
	for(ll i=2;i<=20000000;i++)
	{
		if(is_prime[i]) prime[++tot]=i,minn[i]=tot;
		for(ll j=1;j<=minn[i]&&i*prime[j]<=20000000;j++)
		{
			is_prime[i*prime[j]]=0;
			minn[i*prime[j]]=j;
		}
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	xxs();
	ll T=read();
	for(ll i=1;i<=T;i++) q[i]=read(),maxn=max(maxn,q[i]);
	memset(pd,1,sizeof(pd));
	memset(pd2,1,sizeof(pd2));
	pd[7]=0;
	maxn=min(10000001ll,maxn*2);
	for(ll i=10;i<=maxn;i++)
	{
		pd[i]=i%10==7?0:pd[i/10];
	}
	memset(min2,0,sizeof(min2));
	for(ll i=1;i<=maxn;i++)
	{
		if(!pd[i]&&pd2[i]) minn[i]=tot;
		pd[i]=pd[i]&pd2[i];
		if(pd[i]) sl[++cnt]=i,pl[i]=cnt;
		if(!pd[i]) s[++ct]=i;
		if(pd[i]&&is_prime[i])
		{
			for(ll j=1;j<=ct&&i*s[j]<=maxn;j++) pd2[i*s[j]]=0,minn[i*s[j]]=minn[i];
		}
		if(!pd[i])
		{
			for(ll j=1;j<=minn[i]&&i*prime[j]<=maxn;j++) pd2[i*prime[j]]=0;
		}
	}
	for(ll i=1;i<=T;i++)
	{
		if(!pl[q[i]]) puts("-1");
		else put(sl[pl[q[i]]+1]),putchar('\n');
	}
	return 0;
}
