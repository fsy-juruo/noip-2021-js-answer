#include<bits/stdc++.h>
using namespace std;
int n,a[10005]={},sum=0,sum2=0;
int D;
void change(int i){
	int x=a[i-1]+a[i+1]-a[i];
	int p=x-a[i];
	int ans=p*(n*x+n*a[i]-1)-2*sum;
	if(ans<0){
		a[i]=x,D+=ans;
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		sum2+=a[i]*a[i];
	}
	D=n*sum2-sum*sum;
	for(int i=2;i<=n-1;i++)change(i);
	
	cout<<D<<endl;
	return 0;
}

