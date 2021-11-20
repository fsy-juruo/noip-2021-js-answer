#include<bits/stdc++.h>
using namespace std;
int n,a[1005],maxn;
map <pair<int,int> , bool > w;
void change(int x){
	int temp=a[x+1]+a[x-1]-a[x];
	a[0]+=temp-a[x];
	a[n+1]-=a[x]*a[x];
	a[n+1]+=temp*temp;
	a[x]=temp;
}
void dfs(){
	int y=n*a[n+1]-a[0]*a[0];
	maxn=min(maxn,y);
	for(int i=2;i<=n-1;i++){
		change(i);
		if(w[make_pair(a[0],a[n+1])]==0){
			w[make_pair(a[0],a[n+1])]=1;
			dfs();
		}
		change(i);
	}
	return;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[0]+=a[i];
		a[n+1]+=a[i]*a[i];
	}
	maxn=n*a[n+1]-a[0]*a[0];
	if(n<=10) dfs();
	else{
		int mid=n/2;
		int ans=0;
		for(int j=1;maxn!=ans;j++){
			ans=maxn;
			for(int i=2;i<=n-1;i++){
				change(i);
				if(n*a[n+1]-a[0]*a[0]>maxn) change(i);
				else maxn=n*a[n+1]-a[0]*a[0];
			}
		}
	}
	printf("%d\n",maxn);
	return 0;
}
