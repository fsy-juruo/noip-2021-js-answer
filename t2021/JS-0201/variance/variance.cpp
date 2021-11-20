#include<iostream>
#include<cstdio>
#include<random>
#include<cmath>
using namespace std;
int n,ans,xh,cns,T=200000;
int a[11000][10005]; int num[11000];
int jud(int j) {
	int x=0;
	for(int i=1; i<=n; i++)x+=(n*a[j][i]-num[j])*(n*a[j][i]-num[j]);
	return x/n; }
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	srand(0x992574); scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",a[0]+i);
	for(int i=1; i<=n; i++) num[0]+=a[0][i];
	ans=jud(0); cns=n*n/2;
	//printf("%d\n",ans);
	for(int i=1; i<=cns; i++) {
		num[i]=num[0];
		for(int j=1; j<=n; j++) a[i][j]=a[0][j]; }
	for(int j=1; j<=T/cns; j++)
		for(int i=1; i<=cns; i++) {
			xh=rand()%(n-3)+2;
			num[i]=num[i]+a[i][xh-1]+a[i][xh+1]-a[i][xh]-a[i][xh];
			a[i][xh]=a[i][xh-1]+a[i][xh+1]-a[i][xh]; ans=min(ans,jud(i)); }
	printf("%d",ans);
	return 0; }
