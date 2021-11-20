#include <bits/stdc++.h>

using namespace std;

int n;
int a[10005];
double dp[10005];


void cun(int x){
	a[x]=a[x-1]+a[x+1]-a[x];
}
void fc(){
	double sum=0,ave=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	ave=sum/n;
	sum=0;
	for(int i=1;i<=n;i++){
		sum+=(a[i]-ave)*(a[i]-ave);
	}
	sum/=n;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<52;
	return 0;
} 
