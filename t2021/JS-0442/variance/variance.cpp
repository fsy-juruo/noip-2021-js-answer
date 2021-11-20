#include<stdio.h>
#include<time.h>
long long a[10001],n;
long long variance(){
	long long sum=0;
	for(register int i=0;i!=n;++i){
		sum+=a[i];
	}
	long long ans=0;
	for(register int i=0;i!=n;++i){
		ans+=(a[i]*n-sum)*(a[i]*n-sum);
	}
	return ans/n;
}
long long yuan;
void run(int posi){
	int packup=a[posi];
	a[posi]=a[posi+1]+a[posi-1]-a[posi];
	long long tmp=variance();
	if(yuan<tmp){
		a[posi]=packup;
	}else{
		yuan=tmp;
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%lld",&n);
	for(int i=0;i!=n;++i){
		scanf("%lld",a+i);
	}
	yuan=variance();
	while(clock()<900){
		for(int i=1;i<n-1;++i){
			run(i);
			run(n-i-1);
		}
	}
	printf("%lld",variance());
	return 0;
}
