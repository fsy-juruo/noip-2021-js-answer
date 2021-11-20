#include<bits/stdc++.h>
using namespace std;
int cnt,prime[20000010];
bool notprime[20000010];
int T;
bool existseven(int x){
	while(x){
		if(x%10==7) return true;
		x/=10;
	}
	return false;
}
int x[200010];
int maxn;
int MAXN;
void seek(){
	for(int i=1;i<=MAXN-10;i++){
		if(existseven(i)) notprime[i]=true;
		if(!notprime[i]){
			prime[++cnt]=i;
		}
		for(int j=1;i*j<=MAXN-10;j++){
			if((notprime[i])||(notprime[j])) notprime[i*j]=true;
			if(i%j==0&&notprime[j]) break;
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	int remain=T;
	for(int i=1;i<=T;i++){
		scanf("%d",&x[i]);
		maxn=max(maxn,x[i]);
	}
	MAXN=max(maxn+10000,min(maxn*2,10000011));
	seek();
	for(int i=1;i<=remain;i++){
		if(notprime[x[i]]) printf("-1\n");
		else {
			int pos=upper_bound(prime+1,prime+cnt+1,x[i])-prime;
			printf("%d\n",prime[pos]);
		}
	}
	return 0;
}
