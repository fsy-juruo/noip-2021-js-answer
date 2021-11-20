#include<bits/stdc++.h>
using namespace std;
int t,x,nxt[10000002],lt,N=10000001;
bool hf[10000002];
bool issv(int u){
	while(u!=0){
		if(u%10==7)return 1;
		u/=10;
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	lt=1;
	for(int i=1;i<=N;i++){
		if(hf[i])continue;
		if(issv(i)){
			hf[i]=1;
			for(int j=i+i;j<=N;j+=i)hf[j]=1;
		}
		else{
			nxt[lt]=i;
			lt=i;
		}
	}
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&x);
		if(hf[x])printf("-1\n");
		else printf("%d\n",nxt[x]);
	}
	return 0;
}
