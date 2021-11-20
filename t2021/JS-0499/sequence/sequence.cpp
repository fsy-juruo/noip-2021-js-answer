#include<bits/stdc++.h>
using namespace std;
int v[105],n,m,k,path[105],f[105],ans=0;
const int mod=998244353;
int quick_pow(int x,int y){
	int ans=1;
	while(y){
		if(y&1)ans=1LL*ans*x%mod;
		x=1LL*x*x%mod;
		y>>=1;
	}
	return ans;
}
void dfs(int pos,int sum){
	if(pos==m+1){
//		for(int i=0;i<=m;i++)printf("%d ",path[i]);
//		printf("\n");
		int S=0;
		for(int i=0;i<=m;i++)S=(S+1LL*path[i]*quick_pow(2,i)%mod)%mod;
		int cnt=0;
		while(S){
			cnt+=(S&1);
			S>>=1;
		}
		if(cnt>k)return;;;
		int val=1;
		for(int i=0;i<=m;i++)val=1LL*val*quick_pow(v[i],path[i])%mod;
		int kd=f[n];
		for(int i=0;i<=m;i++)kd=1LL*quick_pow(f[path[i]],mod-2)*kd%mod;
		ans=(ans+1LL*kd*val%mod)%mod;
		return;
	}
	if(pos==m){
		path[pos]=n-sum;
		dfs(m+1,n);
	}
	else{
		for(int i=0;i<=n-sum;i++){
			path[pos]=i;
			dfs(pos+1,sum+i);
		}
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	f[0]=1;
	for(int i=1;i<=100;i++)f[i]=1LL*f[i-1]*i%mod;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++)scanf("%d",&v[i]);
	dfs(0,0);
	printf("%d",ans);
	return 0;
}
//Nan Fang Fei Lai Di Xiao Hong Yan Ya
// 6   3    3   2  3   5    6    1  6
//              ____
// .                                .
//Bu Luo Chang Jiang Bu Ya Bu Qi Fei
//                            .
//2  3 2   1     6   2. 3  5  1  6---
//   ___                _
//               .              
//Yao Shuo Qi Yi Shi Ga Da Mei Lin
// 5   6   5  3   5  5  6  1   6
//            _____
//                             .
//Wei Liao Meng Gu Ren Min Di Tu Di
// 1  6  1  5   6   2.  3  3  51 6---
//    ____              ====
//    .     .   .                .

//Bei Fang Fei Lai Di Da Hong Yan Ya
//Bu Luo Chang Jiang Bu Ya Bu Qi Fei
//Yao Shuo Zao Fan Shi Ga Da Mei Lin
//Wei Liao Meng Gu Ren Min Di Li Yi
