//start:11:10
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int N=1e4+100;
int a[N],b[N],c[N],d[N];
int minv=1e15;
void calc(){
	c[1]=a[1];
	int ave=c[1];
	for (int i=1;i<n;i++){
		c[i+1]=c[i]+a[b[i]+1]-a[b[i]];
		ave+=c[i+1];
	}
	ave/=n;
	int res=0;
	for (int i=1;i<=n;i++) res+=(c[i]-ave)*(c[i]-ave);
	res/=n;
//	for (int i=1;i<n;i++) cout << b[i] << ' ';cout << "  ";
//	for (int i=1;i<=n;i++) cout << c[i] << ' ';cout << endl;
//	cout << res << ' ' << ave << endl;
	if (res<minv){
		minv=res;
		for (int i=1;i<n;i++) d[i]=a[b[i]+1]-a[b[i]];
	}
}
void work_20(){
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) a[i]*=n;
	for (int i=1;i<n;i++) b[i]=i;
	do{
		calc();
	}while (next_permutation(b+1,b+n));
	cout << minv << endl;
//	for (int i=1;i<n;i++) cout << d[i] << ' ';cout << endl;
}
double dp[605][605];
int s[N];
int get_num(double x){
	memset(dp,10,sizeof(dp));
	dp[0][0]=0;
	for (int i=1;i<n;i++) for (int j=1;j<=s[i-1];j++){
		dp[i][j+c[i]]=min(dp[i-1][j],(-j-c[i]-x)*(-j-c[i]-x));
		dp[i][j]=min(dp[i][j],dp[i-1][j]+(s[i]-j-x)*(s[i]-j-x));
	}
	double minv=1e9;
	for (int i=1;i<=s[n-1];i++) minv=min(minv,dp[n][i]);
	return minv*n;
}
void work_68(){
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<n;i++) c[i]=c[i+1]-c[i];
	sort(c+1,c+n);
	for (int i=1;i<=n-1;i++) s[i]=s[i-1]+c[i];
	int ans=1e18;
	for (int i=-s[n]*n;i<=s[n]*n;i++) ans=min(ans,get_num(1.0*i/n));
	cout << ans << endl;
} 
signed main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	work_20();
	return 0; 
}
