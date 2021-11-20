#include<bits/stdc++.h>
using namespace std;
long long v[105];
long long dp1[2][1<<16];
const long long MOD=998244353;
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<=m;i++){
		scanf("%lld",v+i);
	}
	dp1[0][0]=1;
	for(int i=0,ii=1;i<n;i++,ii^=1){
		for(int j=0;j<=(1<<m)*(i+1);j++){
			dp1[ii][j]=0;
			for(int k=0;k<=m;k++){
				if((1<<k)>j) continue;
				dp1[ii][j]+=dp1[ii^1][j-(1<<k)]*v[k]%MOD;
				if(dp1[ii][j]>=MOD) dp1[ii][j]-=MOD;
			}
		}
	}
	long long ans=0;
	for(int i=0,ii=n%2;i<=(1<<m)*n;i++){
		if(__builtin_popcount(i)>k) continue;
		ans+=dp1[ii][i];
		if(ans>=MOD) ans-=MOD; 
	}
	cout<<ans;
	return 0;
}
