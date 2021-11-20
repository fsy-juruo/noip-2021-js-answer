#include<bits/stdc++.h>
using namespace std;

#define M 200001

bool check(int a){
	while(a){
		if(a%10==7) return 1;
		a/=10;
	}
	return 0;
}

bool dp[M]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T,x,tmp;
	for(int i=7;i<M;i++){
		if(dp[i]) continue;
		if(check(i)){
			for(int j=i;j<M;j+=i){
				dp[j]=1;
			}
		}
	}
	scanf("%d",&T);
	if(T>10001) 
		for(int i=M;i<10000001;i++){
			if(dp[i]) continue;
			if(check(i)){
				for(int j=i;j<M;j+=i){
					dp[j]=1;
				}
			}
		}
	
	while(T--){
		scanf("%d",&x);
		if(dp[x]) printf("-1\n");
		else{
			for(int i=x+1;;i++){
				if(!dp[i]){
					printf("%d\n",i);
					break;
				}
			}
		}
	}
	return 0;
}
