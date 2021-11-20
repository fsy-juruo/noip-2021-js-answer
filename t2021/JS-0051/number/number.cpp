#include<bits/stdc++.h>
#define N 12000010
using namespace std;
int used[N],nxt[N],t,n,last,maxn;

inline int ch(int x){
	int d=x;
	while(x){
		d=x%10;
		if(d==7) return 1;
		x/=10;
	}
	return 0;
}

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>t;
	if(t<=10000) maxn=300000;
	else maxn=10500000;
	memset(used,0,sizeof used);
	for(int i=1;i<=maxn;i++){
		if(used[i]) continue;
		if(ch(i)){
			for(int j=i;j<=maxn;j+=i){
				//if(j>10500000) continue;
				used[j]=1;
			}
		}
		else{
			nxt[last]=i;
			last=i;
		}
	}
	for(int i=1;i<=t;i++){
		scanf("%d\n",&n);
		if(used[n]) cout<<-1<<endl;
		else cout<<nxt[n]<<endl;
	}
	return 0;
}
