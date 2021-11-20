#include <bits/stdc++.h>
using namespace std;

const int N=16;
int n,st,mini=1e5,p,ans=1e9;
int a[N],b[N];

int GET(){
	int s=0,ret=0;
	for (int i=0;i<n;i++){
		s+=a[i];
	}
	for (int i=0;i<n;i++){
		ret+=(a[i]*a[i]*n-2*a[i]*s+s*s/n);
	}
	return ret;
}

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);	
	}
	st=a[0]+a[n-1];
	mini=1e5;
	while(1){	
		for (int i=1;i<n-1;i++){
			if(abs(a[i]*2-st)<mini){
				mini=abs(a[i]*2-st);
				p=i;
			}
		}
		int f=-1;
		for (int i=p;i>0;i--){
			if(abs((a[i+1]+a[i-1]-a[i])*2-st)<abs(a[i]*2-st)){
				a[i]=a[i+1]+a[i-1]-a[i];
				f=1;
			}
		}
		for (int i=p;i<n-1;i++){
			if(abs((a[i+1]+a[i-1]-a[i])*2-st)<abs(a[i]*2-st)){
				a[i]=a[i+1]+a[i-1]-a[i];
				f=1;
			}
		}
		if(f==-1) break;
		//printf("%d %d %d\n",p,st,now);
		ans=min(GET(),ans);
	}
	printf("%d",ans);
	return 0;
}
