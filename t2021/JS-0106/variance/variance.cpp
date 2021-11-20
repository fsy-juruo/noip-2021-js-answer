#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[10005],n;
signed main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int sum=0,mul=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	/*if(n<=4){
		
	}
	
	if(n%2==0){
		for(int i=n/2;i>1;i--){
		    if(a[i-1]+a[i+1]-a[i]>a[i]) a[i]=a[i-1]+a[i+1]-a[i];
	    }
	    for(int i=n/2+1;i<n;i++){
		    if(a[i-1]+a[i+1]-a[i]<a[i]) a[i]=a[i-1]+a[i+1]-a[i];
	    }
	}*/ 
	double av;
	for(int i=1;i<=n;i++){
		sum=0;
		for(int j=1;j<=n;j++){
		    sum+=a[j];
        }
		av=(double)((double)sum/(double)n);
		int k=lower_bound(a+1,a+n+1,av)-(a+1);
		int x=a[k-1]+a[k+1]-a[k],y=a[k]+a[k+2]-a[k+1];
		if(abs(a[k]-x)<abs(a[k]-y)){
			for(int j=k+1;j<n;j++){
			    if(a[j-1]+a[j+1]-a[j]<a[j]) a[j]=a[j-1]+a[j+1]-a[j];
		    }
			for(int j=k;j>1;j--){
			    if(a[j-1]+a[j+1]-a[j]>a[j]) a[j]=a[j-1]+a[j+1]-a[j];
		    }		    
		}
		else{
			for(int j=k;j>1;j--){
			    if(a[j-1]+a[j+1]-a[j]>a[j]) a[j]=a[j-1]+a[j+1]-a[j];
		    }
		    for(int j=k+1;j<n;j++){
			    if(a[j-1]+a[j+1]-a[j]<a[j]) a[j]=a[j-1]+a[j+1]-a[j];
		    }
		}
	/*	for(int j=k;j>1;j--){
			if(a[j-1]+a[j+1]-a[j]>a[j]) a[j]=a[j-1]+a[j+1]-a[j];
		}
		for(int j=k+1;j<n;j++){
			if(a[j-1]+a[j+1]-a[j]<a[j]) a[j]=a[j-1]+a[j+1]-a[j];
		}*/
	}
	sum=0;
    for(int i=1;i<=n;i++){
		sum+=a[i];
		mul=(mul+a[i]*a[i]);
	}
	int ans=n*mul-sum*sum;
	printf("%lld\n",ans);
	return 0;
}
