#include<bits/stdc++.h>
using namespace std;
int a[10010],b[10010];
int n,ans=INT_MAX;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=2;i<n;i++){
		for(int j=1;j<=n;j++)a[j]=b[j];
		for(int j=n-1;j>i;j--){
			while(j<n&&a[j-1]+a[j+1]-a[j]>a[j]){
				a[j]=a[j-1]+a[j+1]-a[j];
				j++;
			}
		}
		for(int j=2;j<i;j++){
			while(j>1&&a[j-1]+a[j+1]-a[j]<a[j]){
				a[j]=a[j-1]+a[j+1]-a[j];
				j--;
			}
		}
		double sum=0,an=0;
		for(int j=1;j<=n;j++){
			sum+=a[j];
		}
		if(abs(a[i-1]+a[i+1]-a[i]-sum/n)<abs(a[i]-sum/n)){
			a[i]=a[i-1]+a[i+1]-a[i];
			sum=0;
			for(int j=1;j<=n;j++){
				sum+=a[j];
			}
		}
		for(int j=1;j<=n;j++){
			double s=a[j]-sum/n;
			an+=s*s;
		}
		ans=min(ans,int(an*n));
	}
	cout<<ans<<endl;
	return 0;
}

