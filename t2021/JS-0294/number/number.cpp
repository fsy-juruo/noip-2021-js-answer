#include<bits/stdc++.h>
using namespace std;
int n=200001,f[200005],cnt=1;
bool check[200001];
inline bool _7ch(int x){
	int d;
	while(x){
		d=x%10;
		if(d==7)return false;
		x/=10;
	}
	return true;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=n;++i)check[i]=1;
	for(int i=1;i<=n;++i){
		if(check[i]!=1)continue;
		check[i]=_7ch(i);
		if(!check[i]){
			for(int j=2;j*i<=n;++j)check[i*j]=0;
		}
	}
	for(int i=1;i<=n;++i)if(check[i])f[cnt++]=i;
	int t;
	scanf("%d",&t);
	for(int i=1,x;i<=t;++i){
		scanf("%d",&x);
		int dx=upper_bound(f+1,f+cnt+1,x)-f;
//		printf("%d ",f[dx]);
		if(x!=f[dx-1])printf("-1\n");
		else	printf("%d\n",f[dx]);
	}
	return 0;
}
/*
EDGNB!!!!!!!!
我们是冠军
*/
