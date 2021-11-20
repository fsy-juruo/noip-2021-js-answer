#include <bits/stdc++.h>
using namespace std;
int n;
int a[10010];
long long ans;
long long fc(int t[]){
	int sum=0;
	long long sum2=0;
	for(int i=1;i<=n;++i)
		sum+=t[i];
	for(int i=1;i<=n;++i)
		sum2+=(n*t[i]-sum)*(n*t[i]-sum);
	return sum2/n;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	srand(time(0));
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	ans=fc(a);
	for(int i=1;i<=1e6;++i){
	ans=min(ans,fc(a));
	int j=rand()%(n-2)+2;
	a[j]=(a[j-1]+a[j+1]-a[j]);
	}
	printf("%lld",ans);
	return 0;
}

