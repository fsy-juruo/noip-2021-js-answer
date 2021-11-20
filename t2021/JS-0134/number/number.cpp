#include<bits/stdc++.h>
using namespace std;
bool banned[20000005];
int nxt[20000005];
inline bool check(int x){
	while(x){
		int p=x%10;
		if(p==7) return 0;
		x/=10;
	}
	return 1;
} 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	const int N=20000002;
	for(int i=7;i<=N;i++){
		if(banned[i]) continue;
		if(check(i)) continue;
		for(int j=i;j<=N;j+=i){
			banned[j]=1;
		}
	}
	int la=1e9;
	for(int i=N;i;i--){
		nxt[i]=la;
		if(!banned[i]) la=i;
	}
	int T;
	scanf("%d",&T);
	while(T--){
		int x;
		scanf("%d",&x);
		if(banned[x]) printf("-1\n");
		else printf("%d\n",nxt[x]);
	}
	return 0;
}
