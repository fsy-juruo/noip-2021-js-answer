/*I love Chtholly forever!*/
#include<cstdio>
using namespace std;
const long long MOD=998244353;
long long f[105][35][35][70],n,m,cnt,v[105],F[100],inv[100],ans;
long long pow(long long a,long long b){
	long long ans=1;
	while(b){
		if(b&1)ans=(ans*a)%MOD;
		a=(a*a)%MOD;
		b=b>>1;
	}
	return ans;
}
void init(){
	F[0]=1;
	for(long long i=1;i<=2*n;i++)F[i]=(F[i-1]*i)%MOD;
	inv[2*n]=pow(F[2*n],MOD-2);
	for(long long i=2*n-1;i>=0;i--)inv[i]=(inv[i+1]*(i+1))%MOD;	
}
long long C(long long n,long long m){
	return F[n]*inv[m]%MOD*inv[n-m]%MOD;
}
long long calc(long long num){
	long long cnt=0;
	while(num){
		if((num&1)==1)cnt++;
		num=num>>1;
	}
	return cnt;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&cnt);
	init();
	for(long long i=0;i<=m;i++)
	scanf("%lld",&v[i]),v[i]%=MOD;
//	for(long long i=0;i<=n;i++)
	f[0][0][0][0]=1;
	for(long long i=0;i<=m;i++)//考虑到数字 i 
	for(long long j=0;j<=n;j++)//目前已经放了 j 个数 
	for(long long k=0;k<=cnt;k++)//之前就有 k 个 1(不算 s 中的 1) 
	for(long long l=0;l<=n;l++){//当前这个数 i 放了 l 个 
		if(l+j>n)continue;
		for(long long s=0;s<=(1<<6)-1;s++){//最前端为 s 
			f[i+1][j+l][k+(s&1)][(s>>1)+l]=(f[i+1][j+l][k+(s&1)][(s>>1)+l]+((f[i][j][k][s]*pow(v[i],l))%MOD*C(j+l,l))%MOD)%MOD;
		}
	}
	for(long long s=0;s<=(1<<6)-1;s++)
	for(long long i=0;i<=cnt-calc(s);i++)
	ans=(ans+f[m+1][n][i][s])%MOD;
	printf("%lld\n",ans);
	return 0;
}
/*
I love Chtholly!
I love Chtholly!
I love Chtholly!
*/
