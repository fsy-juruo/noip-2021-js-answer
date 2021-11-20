#include <bits/stdc++.h>
using namespace std;
const int MAXN=10000+5;
int a[MAXN];
int n,stp[MAXN];
int ans;
double rev;
double yi(){
	double E=0;
	for(int i=1;i<=n;i++)	E+=(double)a[i];
	return E/(double)n;
}
int D(){
	rev=yi();
	double cnt=0;
	for(int i=1;i<=n;i++)
		cnt+=(rev-a[i])*(rev-a[i]);
	return cnt*n;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	ans=D();
	if(n==3){
		a[2]=a[1]+a[3]-a[2];
		cout<<min(ans,D());
		return 0;
	}
	for(int i=2;i<=3;i++){
		a[i]=a[i-1]+a[i+1]-a[i];
		ans=min(ans,D());
		a[i]=a[i-1]+a[i+1]-a[i];
	}
	for(int i=2;i<=3;i++){
		a[i]=a[i-1]+a[i+1]-a[i];
	}
	ans=min(ans,D());
	for(int i=2;i<=3;i++){
		a[i]=a[i-1]+a[i+1]-a[i];
		ans=min(ans,D());
	}
	cout<<ans;
	return 0;
}
