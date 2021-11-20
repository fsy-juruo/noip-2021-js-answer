#include <bits/stdc++.h>
using namespace std;

int n,a[10010],i,ans=2e9,tran1,tran2,sum1=0,sum2=0;

void change(int x){
    sum1=sum1-a[x]*a[x]+(a[x-1]+a[x+1]-a[x])*(a[x-1]+a[x+1]-a[x]);
	sum2=sum2-2*a[x]+a[x-1]+a[x+1];
	a[x]=a[x-1]+a[x+1]-a[x];
}

int fc(int a[]){
	return n*sum1-sum2*sum2;
}

void ch(int x){
	tran1=sum1-a[x]*a[x]+(a[x-1]+a[x+1]-a[x])*(a[x-1]+a[x+1]-a[x]);
	tran2=sum2-2*a[x]+a[x-1]+a[x+1];
	if(n*tran1-tran2*tran2<ans){
		ans=n*tran1-tran2*tran2;
		change(x);
	}
}

int main(){
	freopen("variance.in","r",stdin);freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++){
	  scanf("%d",&a[i]);
	  sum1+=a[i]*a[i];
	  sum2+=a[i];
	}
	if(n==1||n==2){
		cout<<fc(a)<<endl;
	}
	else if(n==3){
		ans=fc(a);
		change(2);
		ans=min(ans,fc(a));
		cout<<ans<<endl;
	}
	else if(n==4){
		ans=fc(a);
		change(2);
		ans=min(ans,fc(a));
		change(3);
		ans=min(ans,fc(a));
		change(2);
		ans=min(ans,fc(a));
		change(3);
		ans=min(ans,fc(a));
		change(2);
		ans=min(ans,fc(a));
		cout<<ans<<endl;
	}
	else{
		for(int k=1;k<=n;k++){
			for(int i=2;i<=n-1;i++){
				ch(i);
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
