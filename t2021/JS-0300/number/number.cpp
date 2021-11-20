#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int T,x[N];
bool st[N*2];
int maxx;
void init(){
	for(int i=1;i<=maxx;i++){
		bool flag=false;
		int tmp=i;
		while(tmp>1){
			if(tmp%10==7){
				flag=true;
				break;
			}
			tmp/=10;
		}
		if(flag){
			for(int k=1;i*k<=maxx;k++){
				st[i*k]=true;
			}
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d",&x[i]);
		maxx=max(maxx,x[i]);
	}
	maxx=maxx+maxx/2;
	init();
	for(int i=1;i<=T;i++){
		if(st[x[i]]) puts("-1");
		else{
			x[i]++;
			while(st[x[i]]) x[i]++;
			printf("%d\n",x[i]);
		}
	}
	return 0;
}

