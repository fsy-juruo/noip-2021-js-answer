#include<bits/stdc++.h>
using namespace std;
bool st;
int t;
bool sev[10000002]={false};
int nxt[10000002]={0};
bool ed;
bool check(int x){
	int xx=x;
	while(xx){
		if(xx%10==7) return true;
		xx/=10;
	}
	return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=10000000;i++){
		if(sev[i]==true) continue;
		if(check(i)){
			for(int j=i;j<=10000000;j+=i){
				sev[j]=true;
			}
		}
	}
	int p=0;
	for(int i=1;i<=10000000;i++){
		if(!sev[i]){
			nxt[p]=i;
			p=i;
		}
		else nxt[i]=-1;
	}
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		int x;
		scanf("%d",&x);
		printf("%d\n",nxt[x]);
	}
	return 0;
}

