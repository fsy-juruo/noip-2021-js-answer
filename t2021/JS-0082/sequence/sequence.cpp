#include<bits/stdc++.h>
#define int long long
#define mo 998244353
using namespace std;
int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if (c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int n,m,k,v[105],c[115],ans;
int jiechen[105],ni[105];
int qpow(int x){
	int ans=1,q=mo-2;
	while(q)
	{
		if (q&1) ans=ans*x%mo;
		q>>=1;
		x=x*x%mo;
	}
	return ans;
}
void dfs(int x,int d){
	if (x==0)
	{
		int e[115],s=0;
		for(int i=0;i<=m+10;i++)
			e[i]=c[i];
		for(int i=0;i<=m||e[i]!=0;i++)
		{
			e[i+1]+=e[i]/2;
			e[i]%=2;
			s+=e[i];
		}
		if (s<=k)
		{
			int ss=1;
			for(int i=0;i<=m;i++)
				for(int j=1;j<=c[i];j++)
					ss=(ss*v[i])%mo;
			ss=ss*jiechen[n]%mo;
//			cout<<n<<" "<<jiechen[n]<<endl;
//			cout<<ss<<endl;
			for(int i=0;i<=m;i++)
				ss=ss*ni[c[i]]%mo;
			ans=ans+ss;
			ans%=mo;
		}
		return;
	}
	if (d>m) return;
	for(int i=0;i<=x;i++)
	{
		c[d]=i;
		dfs(x-i,d+1);
		c[d]=0;
	}
}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=0;i<=m;i++) v[i]=read();
	jiechen[0]=1;
	ni[0]=1;
	for(int i=1;i<=100;i++)
	{
		jiechen[i]=jiechen[i-1]*i%mo;
		ni[i]=qpow(jiechen[i]);
	}
	dfs(n,0);
	cout<<ans<<endl;
	return 0;
}
/*
5 1 1
2 1
*/
