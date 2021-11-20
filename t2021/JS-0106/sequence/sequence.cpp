#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,m,k,sum,cnt,t,ans,c[305][305];
int v[105],a[105];
bool check(int s){
	sum=0,cnt=0;
	while(s>0){
		if(s%2==1) sum++,a[cnt]++;
		s/=2;
		cnt++;
	}
	if(sum>k) return false;
	return true;
}
int ksm(int a,int b){
	int ret=1;
	a%=mod;
	while(b){
		if(b&1) ret=(ret*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ret%mod;
}
int calc2(){
	int res=1,u=n;
	for(int i=m;i>0;i--){
		if(a[i]){
			res=(res*c[u][a[i]])%mod;
			u-=a[i];
		}
		if(u==0) break;
	}
	return res%mod;
}
void calc(){
	int mul=1;
	for(int i=0;i<=m;i++){
		if(a[i]) mul=(mul*ksm(v[i],a[i])%mod);
	}
	ans=(ans+mul*calc2()%mod+mod)%mod;
}
void dfs(int t){
	if(t>n) return; 
	if(t==n){
		calc(); return;
	}
	for(int i=m;i>0;i--){
		if(a[i]>0){
			a[i]--,a[i-1]+=2;
			dfs(t+1);
			a[i]++,a[i-1]-=2;
		}
	}
}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	c[0][0]=1;
	for(int i=1;i<=300;i++){
		c[i][0]=1,c[i][i]=1;
		for(int j=1;j<i;j++){
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=0;i<=m;i++){
		scanf("%lld",&v[i]);
	}
	int l=n,r=n*ksm(2,k),s,t;
	for(int i=l;i<=r;i++){
		memset(a,0,sizeof(a));
		s=i;
		if(!check(s)) continue;//printf("%lld\n",i);
		t=sum; //cout<<cnt<<endl;
		for(int j=cnt;j>m;j--){
			if(a[j]>0){
				a[j-1]+=2*a[j]; t+=a[j]; a[j]=0;
			}
		}
		if(t>n) continue;
		dfs(t);
	}
	printf("%lld\n",ans);
	return 0;
}
