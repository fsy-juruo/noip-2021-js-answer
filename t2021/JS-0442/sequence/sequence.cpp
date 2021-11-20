/* 
数列（sequence）
【题目描述】
给定整数 n, m, k，和一个长度为 m + 1 的正整数数组 v0, v1, · · · , vm。
对于一个长度为 n，下标从 1 开始且每个元素均不超过 m 的非负整数序列 {ai}，我
们定义它的权值为 va1 × va2 × · · · × van。
当这样的序列 {ai} 满足整数 S = 2^a1 + 2^a2 + · · · + 2^an 的二进制表示中 1 的个数不
超过 k 时，我们认为 {ai} 是一个合法序列。
计算所有合法序列 {ai} 的权值和对 998244353 取模的结果。
【输入格式】
从文件 sequence.in 中读入数据。
输入的一行是三个整数 n, m, k。
第二行 m + 1 个整数，分别是 v0, v1, · · · , vm。
【输出格式】
输出到文件 sequence.out 中。
仅一行一个整数，表示所有合法序列的权值和对 998244353 取模的结果。
k<=n<=30 m<=100*/
#include<stdio.h>
#include<time.h>
#define mod 998244353
#define N 32
#define K 32
#define M 128
typedef long long ll;
ll value[M];
ll jilu[128][32];//2^i-1 j个元素 
ll dp[128][128][32]; //第i位 前有j个1 这j个数用了k个元素 
#define jia(x1,x2)		((ll)((x1)+(x2))%mod)
#define jian(x1,x2)		((ll)((x1)-(x2)+mod)%mod)
#define cheng(x1,x2)	((ll)((x1)*(x2))%mod)
#define cheng2(x) ((ll)(x<<1)%mod)
ll power(ll di,ll zhi){
	ll ans=1;
	while(zhi>0){
		ans=(zhi&1)?cheng(ans,di):ans;
		di=cheng(di,di);
		zhi>>=1;
	}
	return ans;
}
#define ni(x)	power((x),mod-2) 
#define chu(x1,x2)   	(cheng((x1),ni((x2))))
int main(){
	//input
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;++i){
		scanf("%d",value+i);
	}
	//calc dp
	jilu[0][0]=1;
	for(int i=1;i!=128;++i){
		jilu[i][1]=value[i-1];
		for(int j=1;j<=n;++j){
			for(int g=1;g!=j;++g){
				jilu[i][j]=jia(jilu[i][j],cheng(jilu[i-1][j-g],jilu[i-1][g]));
			}
		}
	}
	for(int i=0;i!=128;++i){
		dp[i][0][0]=1;
	}
	for(int i=1;i<=100;++i){
		for(int j=1;j<=i&&j<=n;++j){
			for(int g=1;g<=32;++g){
				dp[i][j][g]=dp[i-1][j][g];
				for(int h=1;h<=g;++h){
					dp[i][j][g]=jia(cheng(dp[i-1][j-1][g-h],jilu[i][h]),dp[i][j][g]);
				}
			}
		}
	}
	//calc
	ll ans=0;
	int i=3;
	for(int j=1;j<=k;++j){
		ans=jia(ans,dp[i][j][n]);
	}
	printf("%lld",ans);
	return 0;
}
