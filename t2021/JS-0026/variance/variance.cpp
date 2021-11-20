#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[10005],b[10005],ans=1e9;
vector<int>ord;
int num[22],cur[22];
void dfs(int x){
	if(x==n-1){
		int S=0,ret=0;
		for(int i=1;i<n;i++)S+=b[i],ret+=b[i]*b[i]*n;
		ret+=S*S;
		for(int i=0;i<n;i++)ret-=2*S*b[i];
		ans=min(ans,ret);
		return;
	}
	for(int i=0;i<=20;i++)if(cur[i]<num[i]){
		cur[i]++,b[x+1]=b[x]+i;
		dfs(x+1);
		cur[i]--;
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=n;i;i--)a[i]-=a[1];
	for(int i=n;i;i--)a[i]-=a[i-1];
	for(int i=1;i<n;i++)a[i]=a[i+1];
	if(n<=10){
		for(int i=1;i<n;i++)ord.push_back(i);
		do{
			int S=0,ret=0;
			for(int i=1;i<n;i++)b[i]=b[i-1]+a[ord[i-1]],S+=b[i],ret+=b[i]*b[i]*n;
			ret+=S*S;
			for(int i=0;i<n;i++)ret-=2*S*b[i];
			ans=min(ans,ret);
		}while(next_permutation(ord.begin(),ord.end()));
		printf("%d",ans);
		return 0;
	}
	for(int i=1;i<n;i++)num[a[i]]++;
	dfs(0);
	printf("%d",ans);
	return 0;
}
