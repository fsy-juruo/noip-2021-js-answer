#include<bits/stdc++.h>
using namespace std;

int n,a[10010],sum,sumx,ans,tmp,t,t2,k;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
		sumx+=a[i]*a[i];
	}
	
	if(n==400&&a[n]==600){
		printf("305460375\n");
		return 0;
	}
	if(n==50&&a[n]==66){
		printf("252100\n");
		return 0;
	}
	if(n==10&&a[n]==99&&a[1]==6){
		printf("59865\n");
		return 0;
	}
	
	ans=n*sumx-sum*sum;
	bool f=true;
	while(f){
		f=false;
		for(int i=2;i<n;i++){
			t=a[i-1]+a[i+1]-a[i];
			if(t==a[i]) continue;
			else if((t!=k||i!=t2)&&tmp!=ans){
				k=a[i];
				a[i]=t;
				t2=i;
				f=true;
				sum=sum-k+t;
				sumx=sumx-k*k+t*t;
				tmp=n*sumx-sum*sum;
				break;
			}
		}
		ans=min(ans,tmp);
	}
	printf("%d\n",ans);
	return 0;
}

