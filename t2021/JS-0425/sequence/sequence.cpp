#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long dp[31][140072];
int countlk(int n){
	int cntlk=0;
	while(n){
		cntlk+=(n%2);
		n/=2;
	}
	return cntlk;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	long long a[m+1];
	for(int i=0;i<=m;i++){
		cin>>a[i];
	}
	for(int i=0;i<=m;i++){
		dp[1][1<<i]=a[i];
	}
	for(int i=2;i<=n;i++){
		for(int j=0;j<=131071;j++){
			for(int k=0;k<=m;k++){
				dp[i][j+(1<<k)]+=(dp[i-1][j]*a[k])%mod;
				dp[i][j+(1<<k)]%=mod;
			}
		}
	}
	long long ans=0;
	for(int i=0;i<=131071;i++){
		if(countlk(i)<=k){
			ans+=dp[n][i];
			ans%=mod;
		}
	}
	cout<<ans;
	return 0;
}
/*
Things to check:
1. freopen
2. read twice ~~code ones,,debuh forever~~
3. for dp: any more dimensions? what does it mean? how to transfer?
4. keep your code clumsy but easy to understand.
5. check:i++ or j++?
6. if you feel bad,just write brute force and try to make it quicker
7. write every problem: just brute force for T3,T4
*/

