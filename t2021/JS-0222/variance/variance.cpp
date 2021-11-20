#include<bits/stdc++.h>
using namespace std;
#define int long long
inline void read(int &x)
{
	x=0;
	int f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-48;
		c=getchar();
	}
	x*=f;
}

const int maxn = 1e4+7;
const int inf = 0x7fffffff;
//long long?
int n,ans,mi,mx;
int a[maxn],ns[maxn],sav[maxn],p[maxn],out[maxn];

int calc()
{
	int res = 0;
	int sm = 0,ava = 0;
	for(int i=1;i<=n;++i)
		sm+=ns[i];
//	if(sm%n!=0)
//		cout<<"orz"<<sm<<endl;
	ava=sm/n;
	for(int i=1;i<=n;++i)
	{
		res+=(ns[i]-ava)*(ns[i]-ava);
	}
//	if(res%n!=0)
//		cout<<"fk"<<res<<endl;
	res/=n;
	return res;
}

signed main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
	ans=inf;     
	mi=inf;
	for(int i=1;i<=n;++i)
		read(sav[i]),a[i]=sav[i]*n,mi=min(mi,a[i]),mx=max(mx,a[i]);
	for(int ava=mi;ava<=mx;++ava)
	{
		for(int i=1;i<=n;++i)
			ns[i]=a[i];
		bool can=1;
		while(can)
		{
			can=0;
			for(int i=2;i<n;++i)
				if(abs(ns[i-1]+ns[i+1]-ns[i]-ava)<abs(ns[i]-ava))
					ns[i]=ns[i-1]+ns[i+1]-ns[i],can=1;
		}
		int na = calc();
		if(na<ans)
		{
			ans=na;
			out[0]=ava;
			for(int i=1;i<=n;++i)
				out[i]=ns[i];	
		}
	}
	/*for(int ct=2;ct<n-1;++ct)
	{
		for(int i=1;i<=n;++i)
			ns[i]=a[i];
		bool can=1;
		while(can)
		{
			can=0;
			for(int i=2;i<=ct;++i)
				if(ns[i-1]+ns[i+1]-ns[i]>ns[i])
					ns[i]=ns[i-1]+ns[i+1]-ns[i],can=1;
//			for(int i=1;i<=n;++i)
//				cout<<ns[i]<<" ";
//			cout<<endl;
		}
		can=1;
		if(ns[ct]<a[ct])
			cout<<"holy ct:"<<ct<<" "<<ns[ct]<<" "<<a[ct]<<endl;
		int rec = ns[ct];
		ns[ct] = a[ct];
		while(can)
		{
			can=0;
			for(int i=ct+1;i<n;++i)
				if(ns[i-1]+ns[i+1]-ns[i]<ns[i])
					ns[i]=ns[i-1]+ns[i+1]-ns[i],can=1;
		}
		ns[ct]=rec;
		int na = calc();
		if(na<ans)
		{
			ans=na;
			out[0]=ct;
			for(int i=1;i<=n;++i)
				out[i]=ns[i];	
		}
	}*/
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

