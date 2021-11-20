#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 10000000
using namespace std;
int v[MAXN+5],t,f[MAXN+5],T;
bool check(int num){
	int y=num;
	while(y>0){
		if((y%10)==7) return false;
		y=y/10;
	}
	return true;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=MAXN;i++){
		if(v[i]==1) continue;
		if(!check(i)){
			for(int j=1;j<=MAXN;j++){
				if(i*j>MAXN)break;
				else v[i*j]=1; 
			}
		}
	}
	f[MAXN]=MAXN+1;
	for(int i=MAXN;i>=2;i--){
		if(v[i]==1) f[i-1]=f[i];
		else f[i-1]=i;
	}
	scanf("%d",&T);
	while(T--){
		int x;
		scanf("%d",&x);
		if(v[x]==1) printf("-1\n");
		else printf("%d\n",f[x]);
	}
//	for(int i=1;i<=100;i++)
//	  printf("%d ",f[10000000]);
//	printf("%d ",check(1));
	return 0;
}
