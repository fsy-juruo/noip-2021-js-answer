#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m,k;
	int v[10000];
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++){
		scanf("%d",&v[i]);
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*v[i]%998244353;
	}
	for(int i=1;i<=m;i++){
		ans=ans*i%998244353;
	}
	printf("%d",ans);
	return 0;
}
