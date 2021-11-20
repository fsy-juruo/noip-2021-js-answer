/*
Can't do, but nice problem indeed
---Zzzyt
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define INF 998244353

int n,m,k;
ll v[105];

//4096*30=122880
#define MAXN 122900

ll dp[35][MAXN+10];

void solver1(){
	dp[0][0]=1;
	int mx=100;
	for(int i=1;i<=n;i++){
		mx+=(1<<m);
//		cerr<<mx<<endl;
		for(int j=0;j<=m;j++){
			int jj=(1<<j);
			for(int s=jj;s<=mx;s++){
				dp[i][s]+=v[j]*dp[i-1][s-jj];
				dp[i][s]%=INF;
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=MAXN;i++){
		int cnt=0;
		int x=i;
		while(x){
			cnt+=x&1;
			x>>=1;
		}
		if(cnt<=k){
			ans+=dp[n][i];
			if(ans>=INF)ans-=INF;
		}
	}
	printf("%lld\n",ans%INF);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	freopen("sequence.in","r",stdin);
#ifndef ZZZYT
	freopen("sequence.out","w",stdout);
#endif
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++){
		scanf("%lld",v+i);
	}
	solver1();
	return 0;
}

