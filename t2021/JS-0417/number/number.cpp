#include<bits/stdc++.h>
using namespace std;
const int N=1e7+1e6;
bool p[N+10];
int T,nxt[N+10];
bool check(int x){
	while(x){
		if(x%10==7) return 1;
		x/=10;
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=N;i++){
		if(check(i)){
			for(int j=i;j<=N;j+=i) p[j]=1;
		}
	}
	for(int i=N;i>=1;i--){
		if(!p[i]) nxt[i]=i;
		else nxt[i]=nxt[i+1];
	}
	scanf("%d",&T);
	while(T--){
		int x;
		scanf("%d",&x);
		if(p[x]) printf("-1\n");
		else printf("%d\n",nxt[x+1]);
	}
	return 0;
}
