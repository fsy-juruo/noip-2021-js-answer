#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
const int MOD=998244353,N=105;
int n,m,k,v[N];
LL ans;
inline int read(){
	int ss=0;char cc=getchar();bool ff=1;
	for(;!isdigit(cc);cc=getchar()) if(cc=='-') ff=0;
	for(;isdigit(cc);cc=getchar()) ss=(ss<<1)+(ss<<3)+cc-'0';
	return ff?ss:-ss;
}
int power1(int a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1) ans=(1LL*ans*a)%MOD;
		a=(1LL*a*a)%MOD;
	}
	return ans;
}
ULL power2(ULL a,int b){
	ULL ans=1;
	for(;b;b>>=1){
		if(b&1) ans=ans*a;
		a=a*a;
	}
	return ans;
}
int lowbit(int x){
	return x&-x;
}
bool check(ULL x){
	int sum=0;
	for(;x;x-=lowbit(x)){
		sum++;
		if(sum>k) return false;
	}
	return true;
}
void dfs(int x,int y,ULL ss,int val){
	if(y==n){
		if(check(ss)) ans=(ans+val)%MOD;
		return;
	}
	for(int i=0;i<=m;++i){
		if(i==x) continue;
		for(int j=1;j<=n-y;++j)
	        dfs(i,y+j,j*power2(2,i)+ss,(1LL*val*power1(v[i],j))%MOD);
	}
}
void sub(){
	
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=0;i<=m;++i) v[i]=read();
	for(int i=0;i<=m;++i)
	    for(int j=1;j<=n;++j)
	        dfs(i,j,j*power2(2,i),power1(v[i],j));
	printf("%lld\n",ans);
	return 0;
}
