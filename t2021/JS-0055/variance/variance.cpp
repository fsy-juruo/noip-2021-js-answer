/*
dog pear fruit fake win like ant
seven eagle fire bat pen take juice
*/
#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;
const int mxn=1e5+5;
int n,m;
int a[mxn],ca[mxn];
int can[mxn];
ll sum,sqs;
inline void cg(int x){
	sum-=ca[x];
	sqs-=ca[x]*ca[x];
	ca[x]=ca[x-1]+ca[x+1]-ca[x];
	sum+=ca[x];
	sqs+=ca[x]*ca[x];
}
#define ld long double
ll ans=1145141919810;
inline void SA(){
	sum=0,sqs=0;
	for(int i=1;i<=n;++i)ca[i]=a[i],sum+=a[i],sqs+=a[i]*a[i];
	ll lst=n*sqs-sum*sum;
	for(ld T=300000;T>1e-7;T*=0.9998){
		int t=rand()%(n-2)+2;
		cg(t);
		ll cur=n*sqs-sum*sum;
		if(cur<lst){
			lst=cur;
			if(lst<ans)ans=lst;
			continue;
		}else{
			ll del=lst-cur;
			if(exp(-del/T)<rand())continue;
		}
		cg(t);
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	ios_base::sync_with_stdio(false);
	srand('zrmtcltcl');
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i],m=max(m,a[i]),ca[i]=a[i],sum+=a[i],sqs+=a[i]*a[i];
	for(int i=0;i<66;++i)SA();
	cout<<ans<<'\n';
	return 0;
}
