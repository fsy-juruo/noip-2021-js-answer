#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int n,a[N];
int diff[N];
int temp[N];
int now[N];
bool vis[N];
int minn,ans[N];
void dfs(int pos){
	if(pos==n+1){
		int sum=0;
		for(int i=1;i<=n;i++){
			now[i]=now[i-1]+temp[i];
			sum+=now[i];
		}
		int res=0;
		for(int i=1;i<=n;i++){
			res+=(n*now[i]-sum)*(n*now[i]-sum);
		}
		res/=n;
		if(res<minn){
			minn=res;
			for(int i=1;i<=n;i++) ans[i]=temp[i];
		}
		return ;
	}
	for(int i=2;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=true;
		temp[pos]=diff[i];
		dfs(pos+1);
		vis[i]=false;
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) diff[i]=a[i]-a[i-1];
	temp[1]=diff[1];
	minn=0x7fffffff;
	dfs(2);
	printf("%d\n",minn);
	return 0;
}

