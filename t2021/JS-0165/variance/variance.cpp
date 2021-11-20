//WSQ
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
int n;
int a[10005];
int tot;
LL ans=1e18;
LL work(){
	double ret=0;
	double sum=0;
	for(int i=1;i<=n;i++)sum+=(double)a[i];
	sum/=n;
	for(int i=1;i<=n;i++)ret=ret+((double)a[i]-sum)*((double)a[i]-sum);
	return ret*n;
}
void dfs(int dep){
	ans=min(ans,work());
	if(dep>50||tot>4e6)return;
	for(int i=2;i<n;i++){
		tot++;
		int temp=a[i];
		a[i]=a[i+1]+a[i-1]-a[i];
		dfs(dep+1);
		a[i]=temp;
		
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
