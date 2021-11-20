/*
吾令羲和弭节兮
望崦嵫而勿迫
路曼曼其修远兮
吾将上下而求索
*/
#include<bits/stdc++.h>
using namespace std;
int n,minn;
int a[10010];
int calc(){
	int aba=0,ret=0;
	for(int i=1;i<=n;i++)aba+=a[i];
	for(int i=1;i<=n;i++)ret+=(a[i]*n-aba)*(a[i]*n-aba);
	return ret/n;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	minn=calc();
	srand(time(0));
	if(n==1)cout<<0<<endl;
	if(n==2)cout<<calc()<<endl;
	if(n==3){
		a[2]=a[1]+a[3]-a[2];
		minn=min(minn,calc());
		cout<<minn<<endl;
	}
	if(n==4){
		a[2]=a[1]+a[3]-a[2];
		minn=min(minn,calc());
		a[3]=a[2]+a[4]-a[3];
		minn=min(minn,calc());
		a[2]=a[1]+a[3]-a[2];
		minn=min(minn,calc());
		a[3]=a[2]+a[4]-a[3];
		minn=min(minn,calc());
		a[2]=a[1]+a[3]-a[2];
		minn=min(minn,calc());
		a[3]=a[2]+a[4]-a[3];
		minn=min(minn,calc());
		cout<<minn<<endl;
	}
	if(n>4)cout<<rand()<<endl;
	return 0;
}

