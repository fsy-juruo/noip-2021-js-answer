#include<bits/stdc++.h>
using namespace std;
long long n,a[107],aev,minn;
void dfs(long long aevv,long long dep){
	for(int i=2;i<n&&dep<=n-2;i++){
		if(a[i]!=a[i-1]+a[i+1]-a[i]){
			a[i]=a[i-1]+a[i+1]-a[i];
			dfs(aevv+(-a[i-1]-a[i+1]+2*a[i])/n,dep+1);
			a[i]=a[i-1]+a[i+1]-a[i];
		}
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		sum+=(a[i]-aevv)*(a[i]-aevv);
	}
	minn=min(minn,sum/n);
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	minn=100000000;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]*=n;
		aev+=a[i];
	}
	aev/=n;
	dfs(aev,0);
	printf("%d",minn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

