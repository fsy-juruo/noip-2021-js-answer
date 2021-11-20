#include <bits/stdc++.h>
using namespace std;

const int maxn=120;
const long long MOD=998244353;

int n,m,k;
long long v[maxn],fac[maxn],ans;
set<vector<int> > st;

inline long long pwm(long long a,int x)
{
	long long ret=1;
	for(;x;x>>=1)
	{
		if(x&1) ret=ret*a%MOD;
		a=a*a%MOD;
	}
	
	return ret;
}

inline int cnt(vector<int> a)
{
	int ret=0;
	for(int i=0;i<(int)a.size();i++) ret+=a[i];
	return ret;
}

inline void calc(vector<int> a)
{
	long long bas=1,tim=0;
	for(int i=0;i<(int)a.size();i++) (bas*=pwm(v[i],a[i]))%=MOD;
	
	tim=fac[cnt(a)];
	for(int i=0;i<(int)a.size();i++) (tim*=pwm(fac[a[i]],MOD-2))%=MOD;
	
	(ans+=bas*tim%MOD)%=MOD;
}

inline void sol(vector<int> a)
{
	while(a.back()==0) a.pop_back();
	
	if(st.count(a)) return;
	st.insert(a);
	
	if(cnt(a)>n) return;
	if(cnt(a)==n&&(int)a.size()<=m+1)
	{
		calc(a);
		return;
	}
	
	for(int i=1;i<(int)a.size();i++)
	{
		if(a[i]==0) continue;
		
		a[i]--;
		a[i-1]+=2;
		
		sol(a);
		
		a[i]++;
		a[i-1]-=2;
	}
}

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout); 
	
	fac[0]=1;
	for(int i=1;i<=110;i++) fac[i]=fac[i-1]*i%MOD;
	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++) scanf("%lld",&v[i]);
	
	vector<int> a;
	for(int s=n;s<=pwm(2,m)*n;s++)
	{
		if(__builtin_popcount(s)>k) continue;
		
		a.clear();
		int t=s;
		
		for(;t;t>>=1) a.push_back(t&1);
		
		sol(a);
	}
	
	printf("%lld",ans);
	
	return 0; 
}
