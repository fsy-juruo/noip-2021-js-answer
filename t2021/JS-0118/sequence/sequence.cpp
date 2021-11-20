#include<bits/stdc++.h>
using namespace std ;
template<typename T> void read(T &x){
	x = 0 ; int flag = 1 ;
	char c = getchar() ;
	while(!isdigit(c)){
		if(c=='-')
			flag = -1 ;
		c = getchar() ;
	}
	while(isdigit(c)){
		x = x * 10 + c - '0' ;
		c = getchar() ;
	}
	x = x*flag ;
}
int n,m,k ;
const int maxn = 1000 ;
long long p[maxn] ;
int v[maxn],a[maxn] ;
long long lowbit(long long x){
	return x&(-x) ;
}
bool check(){
	long long ret = 0 ,sum = 0 ;
	for(int i = 1 ; i <= n ; i++)
		ret+=p[a[i]] ;
	while(ret>0){
		int t = lowbit(ret) ;
		ret-=t ; sum++ ;
	}
	return sum<=k ;
}
const long long mod = 998244353 ;
long long ans ;
long long ji[maxn] ;
int ok ;
long long sol(){
	long long ret = 1 ;
	for(int i = 1 ; i <= n ; i++)
		ret = ret*(long long)v[a[i]]%mod ;
	return ret ;
}
void Dfs(int dep){
//	cout<<dep<<endl ;
	if(dep==n+1){
		if(check()){
			//cout<<1<<endl ;
			long long q = sol() ;
			long long k1 = 1 , k2 = 1;
			a[0] = -1 ;
			for(long long i = 1 ; i <= n ; i++){
				if(a[i]==a[i-1])k2++ ;
				else k1 = k1*ji[k2]%mod,k2 = 1 ;
				k1 = k1*i%mod ;
			}
			a[0] = 1 ;
			k1 = k1*ji[k2]%mod ;
			ans = (ans+k1*q%mod)%mod ;
		}
		return ;
	}
	for(int i = a[dep-1]+ok ; i <= m ; i++)
		a[dep] = i ,Dfs(dep+1) ;
}
long long qm(long long x,long long num){
	long long ret = 1 ;
	while(num>0){
		if(num%2==1)
			ret = ret*x%mod ;
		x = x*x%mod;
		num = num/2 ;
	}
	return ret ;
}
int main(){
	freopen("sequence.in","r",stdin) ;
	freopen("sequence.out","w",stdout) ;
	read(n) ; read(m) ; read(k) ;
	if(n==k)ok = 1 ;
	for(int i = 0 ; i <= m ; i++)read(v[i]) ;
	ji[0] = 1 ;
	for(int i = 1 ; i <= 30 ; i++)ji[i] = ji[i-1]*qm(i,mod-2)%mod ;
	p[0] = 1 ;
	for(int i = 1 ; i <= m ; i++)p[i]=p[i-1]*2 ;
	Dfs(1) ;
	printf("%lld\n",ans) ;
	
	return 0 ;
}

