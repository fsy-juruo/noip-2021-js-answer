#include<bits/stdc++.h>
using namespace std;
inline int read(){
	   int x=0,f=1;char ch=getchar();
	   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	   while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	   return x*f;
}
int mod=998244353;
int fac[100010],invfac[100010],v[100010],us[100010];
int power(int a,int b){
	int ans=1%mod;
	for(;b;b>>=1){
		if(b&1){
			ans=(long long)ans*a%mod;
		}
		a=(long long)a*a%mod; 
	}
	return ans;
}
void pre_work(){
	fac[1]=1,fac[0]=1;
	for(int i=2;i<=100010;i++){
		fac[i]=(long long)fac[i-1]*i%mod;
	}
	invfac[100010]=power(fac[100010],mod-2);
	for(int i=100010-1;i>=1;i--){
		invfac[i]=(long long)invfac[i+1]*(i+1)%mod; 
	}
	return ;
}
int C(int n,int m){
	return (long long)fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
int n,m,k,maxn=0;
int check(int x){
	int a,cnt;
	while(x){
		a=x%2;
		if(a==1){
			cnt++;
		}
		x/=2;
	}
	return cnt;
}
void dfs(int x,int k1){
	int ans=0,cnt=0;
	if(x==m+1){
		int num=n;
		for(int i=0;i<=m;i++){
			ans+=(long long)us[i]*power(2,i)%mod;
		}
		if(check(ans)<=k){
			for(int i=0;i<=m;i++){
				cnt+=(long long)power(v[i],us[i])*C(num,us[i])%mod;
				num-=us[i];
			}
			maxn=(long long)(maxn+cnt)%mod;
		}
		return ;
	}
	if(x==m){
		us[x]=k1;
		dfs(x+1,0);
		return ;
	}
	for(int i=0;i<=k1;i++){
		us[x]=i;
		dfs(x+1,k1-i);
	}
	return ;
}
int main(){
  freopen("sequence.in","r",stdin);
  freopen("sequence.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=0;i<=m;i++){
		v[i]=read();
	}
	pre_work();
	dfs(0,n);
	cout<<maxn<<endl;
	return 0;
}

