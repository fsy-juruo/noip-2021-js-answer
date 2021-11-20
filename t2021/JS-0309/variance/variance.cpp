#include<bits/stdc++.h>
using namespace std;
int a[10001],n;
long long int ans=1e18,S=0,FS=0,FC;
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x;
}
void dp(int h){
	if(h==1)	return;
	if(h==n){
		FC=FS*n-S*S;
		ans=(ans>FC?FC:ans);
		return;
	}
	if(a[h-1]+a[h+1]-a[h]>a[h-1]){
		int a1=a[h];
		a[h]=a[h-1]+a[h+1]-a[h];
		S=S-a1+a[h];
		FS=FS-a1*a1+a[h]*a[h];
		dp(h+1);
		S=S+a1-a[h];
		FS=FS+a1*a1-a[h]*a[h];
		a[h]=a1;
	}
	dp(h+1);
	return;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		S+=a[i];
		FS+=(a[i]*a[i]);
	}
	dp(2);
	printf("%lld",ans);
	return 0;
}
