#include<bits/stdc++.h>
using namespace std;

int n,m,k;
long long v[105],ans;
inline int count(int x){
	int cnt=0;
	while(x){
		cnt+=x%2;
		x/=2;
	}
	return cnt;
}
void dfs(int x,int s,long long vn){
	if(x==n+1){
		if(count(s)<=k){
			ans=(ans+vn)%998244353;
		}
	}else{
		for(int i=0;i<=m;i++){
			dfs(x+1,s+pow(2,i),(vn*v[i])%998244353);
		}
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);	
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++){
		cin>>v[i];
		v[i]%=998244353;
	}
	dfs(1,0,1);
	cout<<ans%998244353<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
