#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int n;
int a[N];
int sum1,sum2;
int ans;
void work1(){
	for(int i=1;i<=n-2;i++){
		int x=a[i+1],y=a[i]+a[i+2]-a[i+1];
		if(y==x) continue;
		sum1=sum1-x+y;
		sum2=sum2-x*x+y*y;
		ans=min(ans,sum2*n-sum1*sum1);
		sum1=sum1-y+x;
		sum2=sum2-y*y+x*x;
	}
}
void work2(){
	for(int i=1;i<=n-2;i++){
		int x=a[i+1],y=a[i]+a[i+2]-a[i+1];
		if(y==x) continue;
		sum1=sum1-x+y;
		sum2=sum2-x*x+y*y;
		ans=min(ans,sum2*n-sum1*sum1);
		a[i+1]=y;
		sum1=sum1-y+x;
		sum2=sum2-y*y+x*x;
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum1+=a[i];
		sum2+=a[i]*a[i];
	}
	ans=n*sum2-sum1*sum1;
	work1();
	work2();
	printf("%d\n",ans);
	return 0;
}
