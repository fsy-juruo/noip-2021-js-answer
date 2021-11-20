#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10;
int n;
int ans=1e8;
int a[maxn],t[100000000];
int su(){
	int cnt=a[2];
	for(int i=3;i<n;i++){
		cnt=cnt*10+a[i];
	}
	return cnt;
}
int cou(){
	int sum;
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=(a[i]*n-sum)*(a[i]*n-sum);
	}
	return cnt/n;
}
void dfs(){
//	for(int i=1;i<=n;i++) printf("%d",a[i]);
//	printf("\n");
	ans=min(ans,cou());
	for(int i=2;i<n;i++){
		a[i]=a[i+1]+a[i-1]-a[i];
		if(t[su()]==1) return;
		t[su()]=1;
		dfs();
		a[i]=a[i+1]+a[i-1]-a[i];
	}
}

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	t[su()]=1;
	dfs();
	printf("%d",ans);
	return 0;
}

