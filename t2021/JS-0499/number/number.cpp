#include<bits/stdc++.h>
using namespace std;
int t,N,x[200005],vis[10010005],ok[10010005],id[10010005],p=0;
bool check(int x){
	while(x){
		if(x%10==7)return true;
		x/=10;
	}
	return false;
}
void init(){
	for(int i=1;i<=N;i++)if(check(i) && vis[i]==0){
		vis[i]=1;
		for(int j=2;j*i<=N;j++)vis[i*j]=1;
	}
	for(int i=1;i<=N;i++)if(vis[i]==0){
		id[i]=p;
		ok[p++]=i;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)scanf("%d",&x[i]);
	N=0;
	for(int i=1;i<=t;i++)N=max(N,x[i]);
	N+=10000;
	init();
	for(int i=1;i<=t;i++){
		if(vis[x[i]]==1)printf("-1\n");
		else printf("%d\n",ok[id[x[i]]+1]);
	}
	return 0;
}
