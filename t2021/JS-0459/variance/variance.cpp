#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+10;
int a[MAXN+10];
int n,s;
int f(int i){
	int dlt=a[i-1]+a[i+1]-2*a[i];
	return -2*s*dlt + 2*n*dlt*a[i] + n*dlt*dlt - dlt*dlt;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int cur=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s+=a[i];
	}
	for(int i=1;i<=n;i++)
		cur=cur+(a[i]*n-s)*(a[i]*n-s);
	cur/=n;
	for(int i=1;i<=n;i++){
		for(int j=2;j<n;j++){
			j=rand()%(n-2)+2;
			int t=f(j);
		//	cout<<j<<' '<<f(j)<<endl;
			if(t<0){
				a[j]=a[j+1]+a[j-1]-a[j];
				s+=a[j+1]+a[j-1]-2*a[j];
				cur+=t;
			}
		}
	}
	printf("%d",cur);
	return 0;
}
