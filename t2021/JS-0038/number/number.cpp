#include<bits/stdc++.h>
using namespace std;

const int N=1e7+5;
int T;
int ok1[N+5],ok2[N+5],nxt[N+5];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ok1[0]=1;
	for(int i=1;i<=N;i++) if(i%10!=7&&ok1[i/10]) ok1[i]=1;
	for(int i=1;i<=N;i++) ok2[i]=1;
	for(int i=1;i<=N;i++) if(ok2[i]&&!ok1[i]) for(int j=i;j<=N;j+=i) ok2[j]=0;
	for(int i=N;i>=1;i--) if(ok2[i+1]) nxt[i]=i+1;else nxt[i]=nxt[i+1];
	scanf("%d",&T);
	while(T--){
		int x;
		scanf("%d",&x);
		if(!ok2[x]) puts("-1");
		else printf("%d\n",nxt[x]);
	}
	return 0;
}
