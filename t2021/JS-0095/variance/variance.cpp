#include<bits/stdc++.h>
using namespace std;
const int MAXN=10010;
double aver;
int n,sum,a[MAXN];
int mintot=0x3f3f3f3f;
int fangcha(){
	double sum=0,tot=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	aver=sum*1.0/n;
	for(int i=1;i<=n;i++){
		tot+=n*1.0*(a[i]-aver)*(a[i]-aver);
	}
	return (int)tot;
}
void dfs(int k){
	if(k>8){
		mintot=min(mintot,fangcha());
		return;
	}
	for(int i=2;i<n;i++){
		int y=a[i];
		a[i]=a[i-1]+a[i+1]-a[i];
		dfs(k+1);
		a[i]=y;
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(1);
	printf("%d",mintot);
	return 0;
}
/*
4
1 2 4 6
*************
10
6 19 34 35 56 63 82 82 83 99

*/

