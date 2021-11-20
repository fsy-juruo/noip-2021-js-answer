#include<bits/stdc++.h>
using namespace std;
const int N=10000010;
int t,ne[N];
bool noo[N];
bool check(int x){
	while(x){
		if(x%10==7) return true;
		x/=10;
	}
	return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=N;i++){
		if(noo[i]) continue;    
		if(check(i)){
			noo[i]=1;
			int upp=N/i;
			for(int j=2;j<=upp;j++)
				if(!noo[j]) noo[j*i]=1;
		}
		else
			for(int j=i-1;j>=1;j--)
				if(!noo[j]){
					ne[j]=i;
					break;
				}
	}
	while(t--){
		int x;
		scanf("%d",&x);
		if(noo[x]) puts("-1");
		else printf("%d\n",ne[x]);
	}
	return 0;
}
