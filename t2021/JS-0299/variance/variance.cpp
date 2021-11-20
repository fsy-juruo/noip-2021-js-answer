#include<bits/stdc++.h>
using namespace std;

const int MAXN=10005;

int n,c,x,ans=0x3f3f3f3f;
int a[MAXN];
int q[MAXN],f=true,flag=true;
double p,sum;

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	q[1]=1;
	q[n]=1;
	for(int i=1;i<=n;i++)  scanf("%d",&a[i]);
	while(f){
		for(int i=1;i<=n-2;i++){
			if(q[i+1]!=1)  a[i+1]=a[i]+a[i+2]-a[i+1];
//			for(int j=1;j<=n;i++)  printf("%d ",a[j]);
//			printf("\n");
			for(int j=1;j<=n;j++)  p+=a[j];
			p/=n;
			for(int j=1;j<=n;j++)  sum+=(a[j]-p)*(a[j]-p);
			sum*=n;
			ans=min(ans,int(sum));
			if(a[i]+a[i+2]%2==0)  if(a[i+1]==(a[i]+a[i+2])/2)  q[i+1]=1;
			if(a[i]+a[i+2]&2!=0)  if(a[i+1]==(a[i]+a[i+2])/2+1)  q[i+1]=1;
		}
		for(int i=1;i<=n;i++){
			if(q[i]!=1){
				flag=false;
				break;
			}
		}
		if(flag)  f=false;
	}
//	for(int i=1;i<=n;i++)  printf("%d ",a[i]);
	printf("%d\n",ans);
	return 0;
}
/*
4
1 2 4 6
*/
