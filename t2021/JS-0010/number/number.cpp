#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const double eps=1e-9;
typedef long long ll;
bool can[10000005];
const int len=10000000;
int nxt[10000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=len+1;i++){
		int cur=i;can[i]=1;
		while(cur){
			if(cur%10==7)can[i]=0;
			cur/=10;
		}
	}
	for(int i=1;i<=len+1;i++)if(!can[i]){
		for(int j=i+i;j<=len+1;j+=i)can[j]=0;
	}
	memset(nxt,-1,sizeof nxt);
	for(int i=len;i>=1;i--){
		if(can[i+1])nxt[i]=i+1;
		else nxt[i]=nxt[i+1];
	}
	int t;scanf("%d",&t);
	while(t--){
		int x;scanf("%d",&x);
//		cerr<<x<<" "<<can[x]<<endl;
		if(!can[x])printf("-1\n");
		else printf("%d\n",nxt[x]);
	}
	return 0;
}
