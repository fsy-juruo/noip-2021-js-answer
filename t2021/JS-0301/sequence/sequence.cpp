#include<bits/stdc++.h>
using namespace std;
int value=0;
int a[100005],s[100005];
int n,m,k;
int MOD=998244353;
int dig(int x){
	int ans=0;
	while(x>0){
		if(x%2==1) ans++;
		x=x/2;
	}
	return ans;
}
void dfs(int dep){
	if(dep>n){
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=(1<<s[i]);
		}
		if(dig(sum)<=k){
			int cnt=1;
			for(int i=1;i<=n;i++){
				cnt=cnt*a[s[i]]%MOD;
			}
			value+=cnt;
			value=value%MOD;
		}
		return;
	}
	for(int i=0;i<=m;i++){
		s[dep]=i;
		dfs(dep+1);
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++) cin>>a[i];
	dfs(1);
	cout<<value%MOD<<endl;
	return 0;
}

