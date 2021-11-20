#include <bits/stdc++.h>
#define ll long long 
#define pii pair<int,int>
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
const int mod=998244353;
inline void chadd(int &x,const int &b) {x+=b-mod;x+=(x>>31) & mod;}

template <typename T1,typename T2>
ostream & operator << (ostream &cout,const pair<T1,T2> &o)
{
	cout<<'('<<o.first<<','<<o.second<<')';
	return cout;
}

template <typename T>
ostream & operator << (ostream &cout,const vector<T> &v)
{
	cout<<'{';
	for(int i=0;i<(int)v.size();i++)
	{
		cout<<v[i];
		if(i!=(int)v.size()-1) cout<<',';
	}
	cout<<'}';
	return cout;
}
int dp[115][32][32][32];
int fac[55],ifac[55];
int w[115][35];
int n,m,k;
int v[115];

int fastpow(int x,int nn)
{
	int res=1;
	while(nn)
	{
		if(nn&1) res=1LL*res*x%mod;
		x=1LL*x*x%mod;
		nn>>=1;
	}
	return res;
}

int main()
{
	// freopen("input.txt","r",stdin);
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++) cin>>v[i];
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=1LL*fac[i-1]*i%mod;
	ifac[n]=fastpow(fac[n],mod-2);
	for(int i=n-1;i>=0;i--) ifac[i]=1LL*ifac[i+1]*(i+1)%mod;
	for(int i=0;i<=m;i++)
	{
		int pw=1;
		for(int j=0;j<=n;j++)
		{
			w[i][j]=1LL*pw*ifac[j]%mod;
			pw=1LL*pw*v[i]%mod;
		}
	}
	dp[m+10][0][0][n]=1;
	for(int i=m+1;i<=m+10;i++) w[i][0]=1;
	for(int i=m+10;i>0;i--)
	{
		int pos=i-1;
		for(int used=0;used<=k;used++)
		{
			for(int rm=0;rm<=n;rm++)
			{
				for(int l=rm;l<=n;l++)
				{
					int dv=dp[i][used][rm][l];
					if(!dv) continue;
					for(int ext=0;ext<2;ext++)
					{
						for(int pt=0;pt<=(pos<=m?rm+ext:0);pt++)
						{
							int nrm=(rm-pt+ext)*2;
							if(nrm>l-pt) continue;
							chadd(dp[i-1][used+ext][nrm][l-pt],1LL*dv*w[pos][pt]%mod);
						}
					}
				}
			}
		}
	}
	int res=0;
	for(int used=0;used<=k;used++) chadd(res,dp[0][used][0][0]);
	cout<<1LL*res*fac[n]%mod<<endl;
	return 0;
}