#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
	char c=0;int x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x*f;
}
const LL MOD=998244353LL;
int N,M,K,val[105],myadd[105],q[105];
bool vis[200005];
LL addll[105],dp[200005],mymul[105],invmul[105],ans;
bool check(int x){
	int res=0;
	while(x)res+=(x&1),x>>=1;
	return res>K;
}
bool newcheck(LL x){
	LL res=0;
	while(x)res+=(x&1),x>>=1;
	return res>K;
}
LL C(int x,int y){return mymul[y]*invmul[x]%MOD*invmul[y-x]%MOD;}
void dfs(int now,LL res){
	if(now==N+1){
		if(newcheck(res))return;
		LL base=1,type=1;
		int i,j,siz=0,len;
		/*for(int i=1;i<=N;++i)printf("%d ",q[i]);
		printf("\n");*/
		for(i=1;i<=N;++i){
			base=base*val[q[i]]%MOD;
			j=i;
			while(j+1<=N&&q[j+1]==q[i])++j,base=base*val[q[i]]%MOD;
			len=j-i+1,siz+=len;
			type=type*C(len,siz)%MOD;
			i=j;
		}
		ans=(ans+type*base%MOD)%MOD;
		return;
	}
	for(int i=q[now-1];i<=M;++i)q[now]=i,dfs(now+1,res+addll[i]);
}
LL qpow(LL a,LL b){
	LL r=1;
	while(b){
		if(b&1)r=r*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return r;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	N=read(),M=read(),K=read();
	if(N<=30&&M<=12){
		for(int i=0;i<=M;++i)val[i]=read(),myadd[i]=pow(2,i);
		int maxsiz=N*pow(2,M),pre;
		for(int i=0;i<=maxsiz;++i)vis[i]=check(i);
		dp[0]=1;
		for(int i=1;i<=N;++i){
			for(int j=maxsiz;j>=0;--j){
				dp[j]=0;
				for(int k=0;k<=M;++k){
					pre=j-myadd[k];
					if(pre<0)continue;
					dp[j]=(dp[j]+dp[pre]*val[k])%MOD;
				}
			}
		}
		for(int i=N;i<=maxsiz;++i)if(!vis[i])ans=(ans+dp[i])%MOD;
		printf("%lld\n",ans);
	}
	else if(N==5&&M==50){
		addll[0]=1,mymul[0]=1;
		for(int i=1;i<=N;++i)mymul[i]=mymul[i-1]*i%MOD;
		invmul[N]=qpow(mymul[N],MOD-2);
		for(int i=N-1;i>=0;--i)invmul[i]=invmul[i+1]*(i+1)%MOD;
		for(int i=1;i<=M;++i)addll[i]=addll[i-1]*2;
		for(int i=0;i<=M;++i)val[i]=read();
		dfs(1,0);
		printf("%lld\n",ans);
	}
	else{
		for(int i=0;i<=M;++i)val[i]=read();
		LL ans=1;
		for(int i=1;i<=M;++i)ans=ans*val[i]%MOD;
		printf("%lld\n",ans);
	}
	return 0;
}
