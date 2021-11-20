#include<bits/stdc++.h>
using namespace std;
int n,a[15000];
double ans;
double T=0.99998,t=2000;
double sum(){
	int i,x=0;
	double s=0;
	for(i=1;i<=n;i++){
		x+=a[i];
	}
	for(i=1;i<=n;i++){
		s+=(n*a[i]-x)*(n*a[i]-x);
	}
	s/=n;
	return s;
}
int main(){
	freopen("varriance.in","r",stdin);
	freopen("varriance.out","w",stdout);
	int x,p,i,l;
	srand(rand()+1243);
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	l=ans=sum();
	while(t>1e-7){
		t*=T;
		p=rand()%n;
		if(p>1){
			a[p]=a[p-1]+a[p+1]-a[p];
		}else{
			continue;
		}
		x=sum();
		if(ans<x){
			if(exp(t)>(rand()%3)*exp(1)*(1*l*1.0/x)){
				a[p]=a[p-1]+a[p+1]-a[p];
			}else{
				p=rand()%n;
				if(p>1){
					a[p]=a[p-1]+a[p+1]-a[p];
				}
				p=rand()%n;
				if(p>1){
					a[p]=a[p-1]+a[p+1]-a[p];
				}
				p=rand()%n;
				if(p>1){
					a[p]=a[p-1]+a[p+1]-a[p];
				}
			}
		}else{
			ans=x;
		}
		l=x;
	}
	cout<<ans<<endl;
	return 0;
}
