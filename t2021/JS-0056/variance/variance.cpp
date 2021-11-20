/*
SA is not a joke!
---Zzzyt
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define INF 1000000007

int n;
int a[10005];

mt19937 rng;
uniform_real_distribution<double> dist(0,1);

bool genposs(double p){
	return dist(rng)<=p;
}

void solver1(){
	ll sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
	}
	ll cur=0;
	for(int i=0;i<n;i++){
		ll tmp=(a[i]*n-sum);
		cur+=tmp*tmp;
	}
	cur/=n;
	ll ans=cur;
	for(int t=0;;t++){
		double p=max(pow(2,-t/100.0),0.05);
//		cerr<<p<<endl;
		int cnt=0;
		for(int i=1;i<n-1;i++){
			ll dx=a[i-1]+a[i+1]-2*a[i];
			ll delta=dx*(2*n*a[i]-2*sum+(n-1)*dx);
//			cerr<<delta<<endl;
			if(delta<0||genposs(p)){
				cnt++;
				a[i]+=dx;
				sum+=dx;
				
				cur+=delta;
				ans=min(ans,cur);
			}
		}
//		cerr<<cur<<endl;
//		cerr<<cnt<<endl;
		if(t>=1000&&cnt==0&&genposs(0.2))break;
	}
	printf("%lld\n",ans);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	freopen("variance.in","r",stdin);
#ifndef ZZZYT
	freopen("variance.out","w",stdout);
#endif
//	for(int i=0;i<100;i++){
//		cerr<<dist(rng)<<endl;
//	}
//	return 0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	solver1();
	return 0;
}

