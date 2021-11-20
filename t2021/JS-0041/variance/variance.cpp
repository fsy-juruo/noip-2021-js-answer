#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
using namespace std;
int n;
int a[105];
ll dp[105][75][4005];
int pre[105];
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	ll ans=1e18;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=20){
		for(int i=n;i>=2;i--) a[i]-=a[i-1];
		sort(a+2,a+n+1);
		reverse(a+2,a+n+1);
		for(int msk=0;msk<(1<<(n-1));msk++){
			int b[25];b[1]=a[1];int l=1,r=n+1;
			for(int i=2;i<=n;i++)
				if(msk&(1<<(i-2))){
					l++;b[l]=a[i];
				}
				else{
					r--;b[r]=a[i];
				}
			for(int i=2;i<=n;i++)
				b[i]+=b[i-1];
			ll nans=0,sum=0;
			for(int i=1;i<=n;i++) sum+=b[i];
			for(int i=1;i<=n;i++)
				nans+=(ll)(n*b[i]-sum)*(ll)(n*b[i]-sum);
			ans=min(ans,nans/n);
		}
		printf("%lld\n",ans);
		return 0;
	}
	if(n<=100){
		vector<int> o;o.pb(a[1]);
		for(int i=2;i<=n;i++) o.pb(a[i]-a[i-1]);
		sort(o.begin(),o.end());
		reverse(o.begin(),o.end());
		pre[0]=a[1];
		for(int i=1;i<(int)o.size();i++)
			pre[i]=pre[i-1]+o[i];
		memset(dp,127,sizeof(dp));
		dp[0][a[1]][a[1]+a[n]]=a[1]*a[1]+a[n]*a[n];
		for(int i=0;i<n-2;i++)
			for(int j=0;j<=70;j++)
				for(int k=0;k<=4000;k++){
					if(dp[i][j][k]>1e18) continue;
					//add_left
					dp[i+1][j+o[i+1]][k+j+o[i+1]]=min(dp[i+1][j+o[i+1]][k+j+o[i+1]],dp[i][j][k]+(ll)(j+o[i+1])*(ll)(j+o[i+1]));
					//add_right
					dp[i+1][j][k+a[n]-pre[i+1]+j]=min(dp[i+1][j][k+a[n]-pre[i+1]+j],(ll)dp[i][j][k]+(a[n]-pre[i+1]+j)*(ll)(a[n]-pre[i+1]+j));
				}
		for(int j=0;j<=70;j++)
			for(int k=0;k<=4000;k++)
				if(dp[n-2][j][k]<1e18)
					ans=min(ans,dp[n-2][j][k]*n-(ll)k*(ll)k);
		printf("%lld\n",ans);
	}
	return 0;
}
//int overflow
//memset
//out of bound
//corner cases
//big testcase
