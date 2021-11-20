#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=410,inf=0x7f7f7f7f;
int a[N],b[N];
int n;
LL sum1,sum2,ans=inf;
void dfs(int i){
	if(i==n){
		ans=min(ans,n*sum2-sum1*sum1);
		return;
	} 
	int another=a[i-1]+a[i+1]-a[i];
	if(a[i]==another) dfs(i+1);
	else
		if(a[i]>another){
			if(a[i]*n<=sum1) dfs(i+1);
			else
				if(another*n>=sum1){
					sum1+=(another-a[i]),sum2+=(another*another-a[i]*a[i]);
					a[i]=another;
					dfs(i+1);
					a[i]=b[i];
					sum1-=(another-a[i]),sum2-=(another*another-a[i]*a[i]);
				} 
			else{
				dfs(i+1);
				sum1+=(another-a[i]),sum2+=(another*another-a[i]*a[i]);
				a[i]=another;
				dfs(i+1);
				a[i]=b[i];
				sum1-=(another-a[i]),sum2-=(another*another-a[i]*a[i]);
			}
		}
		else{
			if(a[i]*n>=sum1) dfs(i+1);
			else
				if(another*n<=sum1){
					sum1+=(another-a[i]),sum2+=(another*another-a[i]*a[i]);
					a[i]=another;
					dfs(i+1);
					a[i]=b[i];
					sum1-=(another-a[i]),sum2-=(another*another-a[i]*a[i]);
				} 
			else{
				dfs(i+1);
				sum1+=(another-a[i]),sum2+=(another*another-a[i]*a[i]);
				a[i]=another;
				dfs(i+1);
				a[i]=b[i];
				sum1-=(another-a[i]),sum2-=(another*another-a[i]*a[i]);
			}	
		}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum2+=a[i]*a[i],sum1+=a[i],b[i]=a[i];
	dfs(2);
	printf("%lld",ans);
	return 0;
}
