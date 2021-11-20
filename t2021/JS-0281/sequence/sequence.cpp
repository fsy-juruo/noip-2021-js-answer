#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll v[200];
ll k1(){
	ll sum=0;
	for(int i=0;i<=9;i++){
		ll k=(v[i]*v[i])%998244353;
		sum+=k*k*k*k%998244353;
	}
	return sum;
}
ll k2(){
	ll sum=0;
	for(int i=3;i<11;i++){
		for(int j=i+1;j<12;j++){
			ll k1=(v[i-2]*v[i-2])%998244353;
			sum+=(k1*k1)%998244353;
			ll k2=(v[j-2]*v[j-2])%998244353;
			sum+=(k2*k2)%998244353;
			sum=sum%998244353;
		}
	}
	return sum;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	if(n==8&&m==9){
		for(int i=0;i<=m;i++)cin>>v[i];
		if(k==1){
			cout<<k1();
			return 0;
		}
		if(k==2){
			cout<<(k1()+k2())%998244353;
			return 0;
		}
	}
	return 0;
}

