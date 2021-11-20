#include<bits/stdc++.h>
using namespace std;
int n,a[10001],summ,ff,f,k=2,su,ans; 
int lzc(int r){
	int yy=a[r+1]-a[r]+a[r-1];
	return n*(yy*yy-a[r]*a[r])+summ*summ-(summ+yy-a[r])*(summ+yy-a[r]);
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		summ+=a[i]; 
		su+=a[i]*a[i];
	} 
	ans=su*n-summ*summ;
	while(ff==0){
		int p=lzc(k);
		if(p<0){
			a[k]=a[k-1]+a[k+1]-a[k];
			ans+=p;
			f=1;
		}
		if(k==n-1){
			k=2;
			ff=1-f;
			f=0;
		}else{
			k++;
		}
	}
	cout<<ans;
	return 0;
} 
