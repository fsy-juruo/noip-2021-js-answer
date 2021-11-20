#include <bits/stdc++.h>
using namespace std;
int n,ans=0x3f3f3f3f;
int a[10],stp[20];
void dfs(int p){
	if(p==20){
		int tp[10];
		double sum=0,av;
		for(int i=1;i<=n;i++){
			tp[i]=a[i];
		}
		for(int i=1;i<p;i++){
			tp[stp[i]]=tp[stp[i]-1]+tp[stp[i]+1]-tp[stp[i]];
		}
		for(int i=1;i<=n;i++){
			sum+=tp[i];
		}
		av=sum/n;
		sum=0;
		for(int i=1;i<=n;i++){
			sum+=pow(1.0*tp[i]-av,2);
		}
		ans=min(ans,int(sum*n));
		return;
	}
	for(int i=2;i<n;i++){
		stp[p]=i;
		dfs(p+1);
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
/*
4
1 2 4 6
*/
