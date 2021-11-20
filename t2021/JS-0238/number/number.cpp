#include<bits/stdc++.h>
using namespace std;
int T,n;
bool un_ava[10000001];
bool p(int x){
	while(x!=0){
		if(x%10==7)return false;
		x/=10;
	}
	return true;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=10000001;++i){
		if(!un_ava[i]){
			if(!p(i)){
				for(int j=1;i*j<=10000001;++j)
					un_ava[i*j]=true;
			}
		}
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(un_ava[n])printf("-1\n");
		else{
			++n;
			while(un_ava[n])++n;
			printf("%d\n",n);			
		}
	}
	return 0;
}
