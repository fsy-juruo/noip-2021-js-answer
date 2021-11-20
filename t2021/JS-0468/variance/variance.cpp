#include<bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<=c;++a)
#define per(a,b,c) for(int a=b;a>=c;--a)
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int MAXN=10010;
int a[MAXN],n;
ll ans=0,S=0,T=0;
bool flg=0;

inline bool check(int Las)
{
	rep(i,2,n-1)if(a[i]!=a[i-1]+a[i+1]-a[i])return true;
	return false;
}

inline ll getDelta(int pos,ll Del)
{
	return (ll)(n*(2*a[pos]*Del+Del*Del)-(2*S*Del+Del*Del));
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	srand(time(0));
	scanf("%d",&n);
	
	rep(i,1,n)
	{
		scanf("%d",&a[i]);
		S+=a[i],T+=a[i]*a[i];
	}
	ans=n*T-S*S;
	ll tans=ans;
	int Las=0;
	int Counter=0;
	while(Counter<=10000000)
	{
		ll mi=1e9;
		int pos=0;
		while(1)
		{
			pos=rand()%n+1;
			if(pos==1||pos==n)continue;
			if(a[pos]==a[pos+1]+a[pos-1]-a[pos])continue;
			mi=getDelta(pos,a[pos+1]+a[pos-1]-2*a[pos]);
			break;
		}
		ans=min(tans+mi,ans);
		tans+=mi;
		int tt=a[pos];
		a[pos]=a[pos+1]+a[pos-1]-a[pos];
		T+=a[pos]*a[pos]-tt*tt;
		S+=a[pos]-tt;
		Counter++;
	}	
	printf("%lld\n",ans);
	return 0;
}

