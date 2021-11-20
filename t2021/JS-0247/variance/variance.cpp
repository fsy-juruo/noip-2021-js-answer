#include<bits/stdc++.h>
using namespace std;
int n;
long long sumsq,sum;
long long ans;
int a[10005];
map<string,bool>s;
string changestring(int x){
	string w;
	while(x){
		w+=((x%10)^48);
		x/=10;
	}
	reverse(w.begin(),w.end());
	return w;
}
void dfs(long long sum,long long sumsq){
	string word;
	for(int i=1;i<=n;++i){
		word+=changestring(a[i]);
		word+="-";
	}
	if(s[word])return ;
	s[word]=true;
	ans=min(ans,n*sumsq-sum*sum);
	for(int i=2;i<n;++i){
		int t=a[i];
		a[i]=a[i+1]+a[i-1]-a[i];
		sum+=(a[i+1]+a[i-1]-t*2);
		sumsq+=((a[i+1]+a[i-1]-t)*(a[i+1]+a[i-1]-t)-t*t);
		dfs(sum,sumsq);
		a[i]=t;
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		sum+=a[i];
		sumsq+=a[i]*a[i];
	}
	ans=n*sumsq-sum*sum;
	dfs(sum,sumsq);
	cout<<ans;
	return 0;
}
