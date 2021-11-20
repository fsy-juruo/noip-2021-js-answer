#include<iostream>
#include<cstdio>
#include<unordered_map>
#define ll long long
ll n,a[10005],sqs=0,s=0;
ll p[15],ans=1e18,onum=0;
std::unordered_map<ll,bool> mp;
void dfs(ll num,ll nsqs,ll ns){
	if(mp[num]) return;
	mp[num]=1;
	if(nsqs*n-ns*ns<ans) ans=nsqs*n-ns*ns;
	for(int i=2;i<n;++i){
		int tn=a[i-1]+a[i+1]-a[i];
		int oi=a[i];
		a[i]=tn;
		dfs(num-oi*p[i-1]+tn*p[i-1],nsqs-oi*oi+tn*tn,ns+tn-oi);
		a[i]=oi;
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	p[0]=1;
	for(int i=1;i<=10;++i){
		p[i]=p[i-1]*41;
	}
	scanf("%lld",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		sqs+=a[i]*a[i];
		s+=a[i];
		onum+=a[i]*p[i-1];
	}
	dfs(onum,sqs,s);
//	while(true){
//		ll minn=1e18,mint,tc,tn;
//		for(int i=2,nn;i<n;++i){
//			nn=a[i-1]+a[i+1]-a[i];
//			tc=(nn*nn-a[i]*a[i])*n-((s+nn-a[i])*(s+nn-a[i])-s*s);
//			if(tc<minn){
//				minn=tc;
//				mint=i;
//			}
//		}
//		if(minn>=0) break;
//		tn=a[mint-1]+a[mint+1]-a[mint];
//		sqs+=-a[mint]*a[mint]+tn*tn;
//		s+=tn-a[mint];
//		a[mint]=tn;
//	}
	printf("%lld",ans);
}
/*
4
1 2 4 6
*/
