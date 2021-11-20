#include <cstdio>
#include <cctype>
#include <algorithm>
#define MAXN 10005
typedef long long ll;
using namespace std;
ll n,a[MAXN],res;
int vis[MAXN];
ll calc(){
	int sum=0,res=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		res+=n*a[i]*a[i];
	}
	res+=sum*sum;
	for(int i=1;i<=n;i++){
		res-=2*a[i]*sum;
	}
	return res;
}
void dfs(int x,int y){
	if(x+1>8)return;
	for(int i=2;i<=n-1;i++){
		if(!vis[i]&&a[i]!=a[i+1]+a[i-1]-a[i]){
			int t=a[i];
			a[i]=a[i+1]+a[i-1]-a[i];
			/*for(int j=1;j<=n;j++){
				printf("%lld ",a[j]);
			}
			printf("\n");*/
			ll ct=calc();
			if(ct>res&&n>8){
				continue;
			}
			res=min(res,ct);
			vis[i]=1;
			int m1=vis[i-1];
			int m2=vis[i+1];
			vis[i-1]=vis[i+1]=0;
			dfs(x+1,i);
			vis[i-1]=m1;
			vis[i+1]=m2;
			vis[i]=0;
			a[i]=t;
		}
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	res=calc();
	dfs(0,0);
	printf("%lld\n",res);
	return 0;
}
