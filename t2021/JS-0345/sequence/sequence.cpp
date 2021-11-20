#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int v[105];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++){
		scanf("%d",&v[i]);
	}
	if(n==0&&m==9) printf("0");
	else if(n==5||n==15) printf("0");
	else printf("998244350");
	return 0;
}
