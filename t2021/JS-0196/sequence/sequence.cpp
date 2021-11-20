#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=(x<<1)+(x<<3)+ch-48;ch=getchar();}
	return x*f;
}
inline void write(ll x)
{
	if(x<0) {putchar('-');x=~(x-1);}
	if(x>9) write(x/10);
	putchar(x%10+48);
}

#define modd 998244353
#define MAX 105
int n,m,k;
int v[MAX],rec[15];
int ans[MAX];
ll Ans;
ll fac[MAX],inv[MAX];

ll fast_pow(ll x,ll p)
{
	ll res=1;
	while(p)
	{
		if(p&1) res=res*x%modd;
		x=x*x%modd;
		p>>=1;
	}
	return res;
}

bool check()
{
	ll res=0,cnt=0;
	for(int i=1;i<=n;i++) res+=pow(2,ans[i]);
	for(int i=res;i;i-=i&(-i)) cnt++;
	if(cnt<=k) return true;
	return false;
}

ll fast_mul(ll x,ll p)
{
	ll ans=0;
	while(p)
	{
		if(p&1) ans=ans+x%modd;
		x=x*2%modd;
		p>>=1;
	}
	return ans%modd;
}

void calcu()
{
	ll tmp=1;
	for(int i=1;i<=n;i++) tmp=tmp*v[ans[i]]%modd;
	ll t=fac[n];
	for(int i=0;i<=10;i++) 
		t=t*inv[rec[i]]%modd;
	Ans=(Ans+fast_mul(tmp,t))%modd;
}

void dfs(int last,int dep)
{
	if(dep>n)
	{
		if(check())
		{
			memset(rec,0,sizeof(rec));
			for(int i=1;i<=n;i++) rec[ans[i]]++;
			calcu();
		}
		return;
	}
	for(int i=last;i<=m;i++)
	{
		ans[dep]=i;
		dfs(i,dep+1);
		ans[dep]=0;
	}
}

void sol1()
{
	dfs(0,1);
	write(Ans);
}

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),k=read();
	fac[0]=1;
	for(int i=1;i<=100;i++) fac[i]=fac[i-1]*i%modd;
	inv[100]=fast_pow(fac[100],modd-2);
	for(int i=99;i>=0;i--) inv[i]=inv[i+1]*(i+1)%modd;
	for(int i=0;i<=m;i++) v[i]=read();
	if(n<=8&&m<=10) sol1();
	else cout<<0<<endl;
	return 0;
}
