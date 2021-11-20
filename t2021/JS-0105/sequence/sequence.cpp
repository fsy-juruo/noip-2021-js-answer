#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define fn "sequence"
const LL p=998244353;
const LL MAXN=35;
const LL MAXM=110;
LL n,m,k,v[MAXM],satori[MAXN],koishi[MAXN],dp[MAXM][MAXN][MAXN][MAXN],val=1;

inline LL read(){
	LL xs=0,ys=1;char ss=getchar();
	while(ss<'0'||ss>'9'){if(ss=='-')ys=-1;ss=getchar();}
	while(ss>='0'&&ss<='9'){xs=xs*10+ss-'0';ss=getchar();}
	return xs*ys;
}

LL qsm(LL x,LL h){
	LL tmp=1;
	while(h){
		if(h&1) tmp=(tmp*x)%p;
		x=(x*x)%p;
		h>>=1;
	}
	return tmp;
}

LL check(LL kkk){
	LL tmp=0;
	while(kkk){
		if(kkk&1) ++tmp;
		kkk>>=1;
	}
	return tmp;
}

int main(){
	freopen(fn".in","r",stdin);
	freopen(fn".out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=0;i<=m;++i) v[i]=read();
	satori[0]=1;
	koishi[0]=1;
	satori[1]=1;
	koishi[1]=1;
	for(int i=2;i<=max(n+1,m+1);++i){
		satori[i]=(satori[i-1]*i)%p;
		koishi[i]=qsm(satori[i],p-2);
	}
	dp[0][0][0][0]=satori[n];
	for(int o=0;o<=m+1;++o){
		for(int i=0;i<=n;++i){
			for(int j=0;j<=k;++j){
				for(int kk=i;kk>=0;--kk){
//					cout<<o<<" "<<i<<" "<<j<<" "<<kk<<" "<<dp[o][i][j][kk]<<endl;
//					if(kk&1){
//						dp[o][i][j][kk-1]+=dp[o][i][j][kk];
//						continue;
//					}
					for(int l=0;i+l<=n;++l){
				//		cout<<l<<" "<<((dp[o][i][j][kk]*qsm(v[o],l)%p)*koishi[l]%p)<<endl;
				//		cout<<dp[o][i][j][kk]*v[o]%p<<endl;
				//		cout<<"  "<<o+1<<" "<<i+l<<" "<<j+((kk/2+l)&1)<<" "<<kk/2+l<<" "<<l<<" "<<dp[o][i][j][kk]*qsm(v[o],l)<<" "<<koishi[l]<<endl;
						dp[o+1][i+l][j+((kk/2+l)&1)][kk/2+l]=(dp[o+1][i+l][j+((kk/2+l)&1)][kk/2+l]+((dp[o][i][j][kk]*qsm(v[o],l)%p)*koishi[l]%p))%p;
//						else dp[o+1][i+l+1][j+(l&1)][kk/2+l]=(dp[o+1][i+l][j+(l&1)][kk/2+l]+(dp[o][i][j][kk]*v[o]%p))%p;
					}
				}
			}
		}
	}
	LL ans=0;
	for(int i=0;i<=k;++i){
		for(int j=0;j<=n;++j){
			if(i+check(j)<=k)ans=(ans+dp[m+1][n][i][j])%p;
		}
	}
	cout<<ans<<endl;
	return 0;
}

