#include<bits/stdc++.h>
using namespace std;
int n,a[10001];
double _av,ans;
bool vis[100001];
double v(){
	double _sum=0;
	_av=0;
	for(int i=1;i<=n;++i)
		_av+=a[i];
	_av/=n;
	for(int i=1;i<=n;++i)
		_sum+=(a[i]-_av)*(a[i]-_av);
	return _sum*n;
}
void go(){
	ans=min(ans,v());
	for(int i=2;i<n;++i){
		int o_ai=a[i],n_ai=a[i-1]+a[i+1]-a[i];
		if(n_ai!=a[i]){
			a[i]=n_ai;
			int po=0;
			for(int i=1;i<=n;++i)
				po=(po*3+a[i]*7)%46337;
			if(!vis[po]){
				vis[po]=true;
				go();
			}
			a[i]=o_ai;
		}
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	ans=v();
	go();
	printf("%d\n",int(ans));
	return 0;
}
