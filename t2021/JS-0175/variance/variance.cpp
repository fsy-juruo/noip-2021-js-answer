#include<bits/stdc++.h>
#define N 16
#define db double
using namespace std;
db a[N],ans=998244533;
int n;
bool mp[10001000];
inline bool check(){
	long long sum=0;
	for(int i=1;i<=n;++i)
	sum=(sum*110+(long long)a[i])%10000123;
	if(mp[sum])return 0;
	return mp[sum]=1;
}
inline void dfs(){
	//cout<<"true\n";
	db aver,fc;
	for(int i=1;i<=n;++i)aver+=a[i];
	aver/=(db)n;
	for(int i=1;i<=n;++i)fc+=(a[i]-aver)*(a[i]-aver);
	fc/=(db)n;
	ans=min(ans,fc);
	for(int i=2;i<n;++i){
		db k=a[i];
		a[i]=a[i-1]+a[i+1]-a[i];
		if(check()){
			dfs();
		}a[i]=k;
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lf",&a[i]);
	dfs();printf("%lld",(long long)(ans*n*n));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
