#include <bits/stdc++.h>
#define M 1005
using namespace std;
int n,a[M],ans=1e9;

void cal(int x){
	int b[M];
//	printf("%d:",x);
	int summ=0,an=0;
	for(int i=n;i>=1;--i){
		b[i]=a[i];
		if(x&1)
			b[i]=a[i-1]+a[i+1]-a[i];
		summ+=b[i];
		x=x>>1;
//		printf("%d ",b[i]);
	}
	for(int i=1;i<=n;++i) an+=(b[i]*n-summ)*(b[i]*n-summ);
	ans=min(ans,an);
//	puts("");
}

void solve(int ls,int lo,int inx){
	if((ls>>1)<lo) return;
	if(!ls && !lo) cal(inx); 
	else if(!lo){
		inx=inx<<ls;
		solve(0,0,inx);
	}
	else if(inx&1)
		solve(ls-1,lo,inx<<1);
	else{
		solve(ls-1,lo,inx<<1);
		solve(ls-1,lo-1,(inx<<1)+1);
	}
} 

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=0;i<=n/2;++i){
		solve(n-1,i,0);
	}
	printf("%d",ans/n);
	return 0;
}
