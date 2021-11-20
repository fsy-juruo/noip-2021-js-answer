#include <bits/stdc++.h>
using namespace std;

const int N=1e4+1;
int n,a[N],s,S,d;

int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
		s+=a[i]; S+=a[i]*a[i];
	} d=n*S-s*s;
	for(int i=1;i<=n*10;i++) {
		bool f=0;
		int ss=s,SS=S,D=d,k=0;
		for(int j=2;j<n;j++) {
//			if(a[i]*2==a[i-1]+a[i+1]) continue;
			int sss=s+a[j-1]+a[j+1]-2*a[j];
			int SSS=S-a[j]*a[j]+(a[j-1]+a[j+1]-a[j])*(a[j-1]+a[j+1]-a[j]);
			int DD=n*SSS-sss*sss;
//			printf("!%d %d %d %d\n",j,sss,SSS,DD);
			if(DD<=D) ss=sss,SS=SSS,D=DD,k=j;
		}
		if(!k) break;
		s=ss; S=SS; d=D; a[k]=a[k-1]+a[k+1]-a[k];
//		printf("%d %d %d %d %d\n",i,k,d,s,S);
//		for(int j=1;j<=n;j++) printf("%d ",a[j]); puts("");
	} printf("%d\n",d);
	return 0;
}

