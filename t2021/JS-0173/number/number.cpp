#include<bits/stdc++.h>
using namespace std;
const int N=1e7+1e3+5;
int a[6000005],sz,b[N],c[N],q,t,ans;
bool check(int x){
	int y;while(x){y=x%10;if(y==7) return 1;x=x/10;}
	return 0;
}
int main( ){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int x=0,y=0;cin>>t;
	for(int i=1;i<=1e7+1e3;i++) if(check(i)) a[++sz]=i;
	for(int i=1;i<=sz;i++){
		for(int j=a[i];j<=1e7+1e3;j+=a[i]) b[j]=1;
	}
	for(int i=0;i<=1e7+1e3;i++){
		if(!b[i]) c[++x]=i;
	}
	for(int i=1;i<=t;i++){
		scanf("%d",&q);
		if(q==0){puts("1");continue;}
		ans=lower_bound(c+1,c+x+1,q)-c;
		if(c[ans]!=q){puts("-1");continue;}
		printf("%d\n",c[ans+1]);
	}
	return 0;
}
