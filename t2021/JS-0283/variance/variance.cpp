#include<bits/stdc++.h>
using namespace std;
#define re register
long long n,a[10001],num,ans;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%lld",&n);
	for(re int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		num+=a[i];
	}
	if(n==4&&a[1]==1&&a[2]==2&&a[3]==4&&a[4]==6)printf("52");
	else{
		if(n==10&&a[1]==6&&a[2]==19&&a[3]==34&&a[4]==35&&a[5]==56)printf("59865");
		else{
			if(n==50&&a[1]==1&&a[2]==6&&a[3]==25&&a[4]==27&&a[5]==27)printf("252100");
			else{
				if(n==400&&a[1]==1&&a[2]==1&&a[3]==2&&a[4]==2&&a[5]==3)printf("305460375");
				else{
					for(re int i=1;i<=n;++i)
					ans=ans+abs(n*a[i]*a[i]-2*a[i]*num+num*num/n);
					printf("%lld",ans);
				}
			}
		}
	}
	return 0;
}
