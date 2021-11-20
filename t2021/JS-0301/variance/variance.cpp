#include<bits/stdc++.h>
using namespace std;
int a[100005];
int n;
int hashe[1000005];
int minn=INT_MAX;
int calc(){
	int cnt=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		cnt+=a[i];
	}
	for(int i=1;i<=n;i++){
		ans=ans+((n*a[i]-cnt)*(n*a[i]-cnt));
	}
	return ans;
}
void dfs(int dep){
	minn=min(minn,calc());
	cout<<calc()<<endl;
	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
	cout<<endl;     
	int x=0;
	for(int i=1;i<=n;i++){
		x=x*10+a[i];
	}
	hashe[x]=1;
	for(int i=2;i<=n-1;i++){
		x=0;
		int t=a[i];
		a[i]=a[i-1]+a[i+1]-a[i];
		for(int j=1;j<=n;j++){
			x=x*10+a[j];
		}
		if(hashe[x]==1){
			a[i]=t;
			continue;
		}
		else{
			hashe[x]=1;
			dfs(dep+1);
			a[i]=t;
		}
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//cout<<calc()<<endl;
	dfs(1);
	cout<<minn/n<<endl;
	return 0;
}

