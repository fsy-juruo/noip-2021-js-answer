//total 12pts
#include<bits/stdc++.h>
using namespace std;
int n;
int a[10009];
int MAX_A;
long long sqr(long long x){return x*x;}
void solve1(){
	int ans=1000000009;
	int p[5];for(int i=1;i<=n;i++)p[i]=a[i];
	int k=0;
	while(1){
		int ave=0;for(int i=1;i<=n;i++)ave+=p[i];
		ave/=n;
		int res=0;for(int i=1;i<=n;i++)res+=sqr(p[i]-ave);
		res/=n;
		ans=min(ans,res);
		if(p[k+2]*2==p[k+1]+p[k+3])break;
		else p[k+2]=p[k+1]+p[k+3]-p[k+2];
		k^=1;
	}for(int i=1;i<=n;i++)p[i]=a[i];k=1;
	while(1){
		int ave=0;for(int i=1;i<=n;i++)ave+=p[i];
		ave/=n;
		int res=0;for(int i=1;i<=n;i++)res+=sqr(p[i]-ave);
		res/=n;
		ans=min(ans,res);
		if(p[k+2]*2==p[k+1]+p[k+3])break;
		else p[k+2]=p[k+1]+p[k+3]-p[k+2];
		k^=1;
	}
	printf("%d\n",ans);
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		MAX_A=max(MAX_A,a[i]);
		a[i]*=n;
	}
	if(n<=4&&MAX_A<=10)solve1();//12pts
	return 0;
}

