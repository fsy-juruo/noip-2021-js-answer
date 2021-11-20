#include<bits/stdc++.h>
using namespace std;
int dp[90000003];
vector<vector<int> >v2;
vector<int>v1;
int n,a[10003],d[10003],tmp,maxa,mid,T2,T1,N;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)scanf("%d",a+i);
	maxa=a[n-1];N=n;
	for(int i=1;i<n;i++)
		if(a[i]-a[i-1])
			d[tmp++]=a[i]-a[i-1];
	n=tmp;
	sort(d,d+n);mid=n*maxa;
	T1=n*maxa*2+10;
	T2=T1*maxa+10;
	for(int i=0;i<90000003;i++)dp[i]=-1;
	dp[mid]=0;
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=sum;j++)
			for(int k=0;k<=2*mid;k++)
				if(dp[(i-1)*T2+j*T1+k]!=-1){
					if(dp[i*T2+j*T1+k-sum+j-d[i-1]]==-1||dp[i*T2+j*T1+k-sum+j-d[i-1]]>dp[(i-1)*T2+j*T1+k]+(sum-j+d[i-1])*(sum-j+d[i-1]));//R 
						dp[i*T2+j*T1+k-sum+j-d[i-1]]=dp[(i-1)*T2+j*T1+k]+(sum-j+d[i-1])*(sum-j+d[i-1]);
					if(dp[i*T2+(j+d[i-1])*T1+k+j+d[i-1]]==-1||dp[i*T2+(j+d[i-1])*T1+k+j+d[i-1]]>dp[(i-1)*T2+j*T1+k]+(j+d[i-1])*(j+d[i-1]));//L
						dp[i*T2+(j+d[i-1])*T1+k+j+d[i-1]]=dp[(i-1)*T2+j*T1+k]+(j+d[i-1])*(j+d[i-1]);
				}
		sum+=d[i-1];
	}
	long long ans=114514191981023333;
	for(int j=0;j<=sum;j++)
		for(int k=0;k<=2*mid;k++)
			if(dp[n*T2+j*T1+k]!=-1)
				ans=min(ans,1ll*N*dp[n*T2+j*T1+k]-1ll*(mid-k)*(mid-k));
	cout<<ans;
	return 0;
}//tourist bless me! 
