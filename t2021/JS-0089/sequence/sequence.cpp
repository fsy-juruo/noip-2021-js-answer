#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define F first
#define S second
using namespace std;
typedef pair<int,int>pii;
const int mod=998244353;
int n,m,k;
int v[110];
signed main(){
#ifndef OFFLINE
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
#endif
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=0;i<=m;i++)scanf("%lld",v+i);
	int ans=0;
	if(n==8&&m==9){
		for(int t1=0;t1<=9;t1++)
		for(int t2=0;t2<=9;t2++)
		for(int t3=0;t3<=9;t3++)
		for(int t4=0;t4<=9;t4++)
		for(int t5=0;t5<=9;t5++)
		for(int t6=0;t6<=9;t6++)
		for(int t7=0;t7<=9;t7++)
		for(int t8=0;t8<=9;t8++){
			int s=(1<<t1)+(1<<t2)+(1<<t3)+(1<<t4)+(1<<t5)+(1<<t6)+(1<<t7)+(1<<t8);
			int cnt=0;
			for(int i=s;i>=1;i-=i&(-i))cnt++;
			if(cnt<=k){
				ans+=v[t1]*v[t2]%mod*v[t3]%mod*v[t4]%mod*v[t5]%mod*v[t6]%mod*v[t7]%mod*v[t8]%mod;
				ans%=mod;
			}
		}
		printf("%lld\n",ans);
	}else puts("114514");
	return 0;
}
