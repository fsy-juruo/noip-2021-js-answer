#include<bits/stdc++.h>

using namespace std;

const int N=1e7+10;//gai

int T,a[N],nex[N],tmp;

bool check(int z){
	while(z){
		if(z%10==7) return true;
		z/=10;
	}
	return false;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=N;i++){
		if(a[i]==1) continue;
		if(check(i)){
			for(int j=1;j*i<=N;j++){
				a[i*j]=1;
			}
		}
	}
	for(int i=N;i>=1;i--){
		if(tmp==0&&a[i]==0){
			tmp=i;
		}
		else if(a[i]==0){
			nex[i]=tmp;
			tmp=i;
		}
	}
	while(T--){
		int now;
		scanf("%d",&now);
		if(a[now]==1) printf("%d\n",-1);
		else printf("%d\n",nex[now]);
	}
	return 0;
}
