#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back

using namespace std;

const LL MOD=100000007;

LL n,a[10010],dp[17000][1500],b[10010],sm[20000],mp[20000],ans=1e18,seed=8429387;

LL myrand(){return seed=(seed*seed^seed)%MOD;}

void chmin(LL &x,LL y){if(x>y) x=y;}

void solveBF()
{
	rep(i,n-1) b[i]=a[i+1]-a[i];
	rep(i,n-1) sm[1<<i]=b[i],mp[1<<i]=i;
	rep(i,1<<(n-1)) if(__builtin_popcount(i)>1)
	{
		int lb=(i&(-i));
		sm[i]=sm[i^lb]+b[mp[lb]];
	}
	rep(i,(1<<(n-1))+5) rep(j,1495) dp[i][j]=1e18;
	dp[0][a[0]+600]=n*a[0]*a[0];
	rep(i,1<<(n-1)) rep(j,1490) if(dp[i][j]<1e18)
	{
		LL curs=sm[i]+a[0];
		rep(k,n-1) if((i&(1<<k))==0&&0<=j+curs+b[k]&&j+curs+b[k]<=1489)
			chmin(dp[i|(1<<k)][j+curs+b[k]],dp[i][j]+n*(curs+b[k])*(curs+b[k]));
	}
	rep(j,1490) if(dp[(1<<(n-1))-1][j]<1e18) chmin(ans,dp[(1<<(n-1))-1][j]-(LL)(j-600)*(LL)(j-600));
	cout<<ans<<endl;
}

LL pref[10010],sum,res;

void sa()
{
	double T=10000,mt=0.999992,eps=1e-9;
	rep(i,n-1) b[i]=a[i+1]-a[i];
	res=n*a[0]*a[0];sum=a[0];
	pref[0]=a[0];rep(i,n-1) pref[i+1]=pref[i]+b[i],res+=n*pref[i+1]*pref[i+1],sum+=pref[i+1];
	res-=sum*sum;ans=min(ans,res);
	while(T>eps)
	{
		LL id=myrand()%(n-2),nres=res+sum*sum;
		nres-=n*(pref[id+2]*pref[id+2]+pref[id+1]*pref[id+1]);
		nres+=n*((pref[id]+b[id+1])*(pref[id]+b[id+1])+(pref[id]+b[id+1]+b[id])*(pref[id]+b[id+1]+b[id]));
		LL nsum=sum-pref[id+1]-pref[id+2];
		nsum+=pref[id]+b[id+1]+pref[id]+b[id+1]+b[id];
		nres-=nsum*nsum;
		ans=min(ans,nres);
		bool ch=false;
		if(nres<res) ch=true;
		else
		{
			double d=(nres-res)*4;
			if(exp(T/d)>=(double)(myrand()%100000)/(double)100000) ch=true;
			//cout<<T/d<<endl;
		}
		//cout<<ans<<endl;
		if(ch)
		{
			res=nres;sum=nsum;
			swap(b[id],b[id+1]);
			pref[id+1]=pref[id]+b[id];pref[id+2]=pref[id+1]+b[id+1];
		}
		T*=mt;
	}
}

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	LL mx=0;
	rep(i,n) scanf("%lld",&a[i]),mx=max(mx,a[i]);
	if(n==1)
	{
		puts("0");
		return 0;
	}
	if(n==2)
	{
		cout<<n*a[0]*a[0]+n*a[1]*a[1]-(a[0]+a[1])*(a[0]+a[1])<<endl;
		return 0;
	}
	if(n<=15&&mx<=150)
	{
		solveBF();
		return 0;
	}
	sa();
	cout<<ans<<endl;
	return 0;
}
