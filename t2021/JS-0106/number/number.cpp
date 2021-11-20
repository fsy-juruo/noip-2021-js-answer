#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
int t,n,nxt[200050];
bool v[10000005];
inline void pre(){
	for(int i=7;i<=200020;i++){
		if(v[i]) continue;
		int k=i; bool o=false;
		while(k>0){
			if(k%10==7){
				o=true; break;
			}
			k/=10;
		}
		if(o){
			for(int j=i;j<=200020;j+=i) v[j]=true;
		}
	}
}
int check(int x){
	for(int i=1;i<=7;i++){
		if(!v[x+i]) return x+i;
	}
} 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	pre();
	int p=1,q;
	while(p<=200020){
		q=p,p++;
		while(v[p]==true) p++;
		nxt[q]=p;
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(v[n]==1){
			printf("-1\n");
			continue;
		}
		printf("%d\n",nxt[n]);
	}
	return 0;
}
