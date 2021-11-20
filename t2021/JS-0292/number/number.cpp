#include<bits/stdc++.h>
using namespace std;
bool e[10000050];
bool p(int x){
	while(x){
		if(x%10==7) return 1;
		x/=10;
	}
	return 0;
}
void Work(){
	for(int i=1;i<=10000010;i++){
		if(e[i]==0) continue;
		if(i%7==0) e[i]=0;
		if(p(i)){
			for(int j=i;j<=10000010;j+=i)
				e[j]=0;
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t,n;
	memset(e,1,sizeof(e));
	scanf("%d",&t);
	Work();
	while(t--){
		scanf("%d",&n);
		if(e[n]==0){
			printf("-1\n");
			continue;
		}
		for(int i=n+1;;i++){
			if(e[i]){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
