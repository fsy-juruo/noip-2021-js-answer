#include<bits/stdc++.h>
#define mod 998244353ll
using namespace std;

int n,m,k;
long long ans_s;
long long v[110];

long long pow_2[110];

void init() {
	pow_2[0]=1;
	
	for(int i=1;i<=100;i++) {
		pow_2[i]=pow_2[i-1]*2%mod;
	}
}

bool check(int o) {
	int cnt=0;
	
	while(o) {
		cnt+=o%2;
		o/=2;
	}
	
	return cnt<=k;
}

void work(int dep,int sum,long long num) {
	if (dep>n) {
		if (check(sum)) {
			ans_s=(ans_s+num)%mod;
		}
		
		return;
	}
	
	for(int i=0;i<=m;i++) {
		work(dep+1,sum+pow_2[i],(num*v[i])%mod);
	}
}

int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	init();
	
	cin>>n>>m>>k;
	
	for(int i=0;i<=m;i++) {
		cin>>v[i];
	}
	
	work(1,0,1);
	
	cout<<ans_s;
	
	return 0;
}

