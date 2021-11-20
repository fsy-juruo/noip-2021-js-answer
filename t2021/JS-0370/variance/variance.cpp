#include<bits/stdc++.h>
using namespace std;
int n,a[10002],ans;
double sum=0,b[10002],sum1,sum2;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	if(n==1)
		cout<<"0";
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if(n==2){
		ans=2*((a[1]-sum/2)*(a[1]-sum/2)+(a[2]-sum/2)*(a[2]-sum/2));
	}
	if(n==3){
		b[1]=3*((a[1]-sum/3)*(a[1]-sum/3)+(a[2]-sum/3)*(a[2]-sum/3)+(a[3]-sum/3)*(a[3]-sum/3));
		a[2]=a[1]+a[3]-a[2];
		sum1=(a[1]+a[2]+a[3])/3;
		b[2]=3*((a[1]-sum1/3)*(a[1]-sum1/3)+(a[2]-sum1/3)*(a[2]-sum1/3)+(a[3]-sum1/3)*(a[3]-sum1/3));
		if(b[1]>b[2])
			ans=b[2];
		else
			ans=b[1];
	}
	if(n!=1&&n!=2&&n!=3){
		for(int i=1;i<=n;i++)
			sum2+=(a[i]-sum/n)*(a[i]-sum/n);
		ans=n*sum2;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
