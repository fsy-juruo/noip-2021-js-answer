#include <bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x){
	x=0; T f=1; char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x*=f;
}

#define int long long
#define lowbit(n) n&(-n)
const int mod=998244353;
int ksm(int x,int p){
	int ans=1;
	for (;p;p>>=1){
		if (p&1) ans*=x,ans%=mod;
		x*=x; x%=mod;
	}
	return ans;
}

int v[110],n,m,k,ans,cnt,d[110],h[110];
int count1(int x){
	int s=0;
	while (x) s+=1&x,x>>=1;
	return s; 
}
int p[110];
void dfs(int nn,int s,int val,int last){
	if (nn==0){
		if (count1(s)<=k){
			int s=val*d[n]%mod;
			for (int i=0;i<=m;i++){
				s=s*ksm(d[h[i]],mod-2); s%=mod;
			}
			ans+=s;
			ans%=mod;
		}
		return;
	}
	for (int i=last;i<=m;i++){
		p[nn]=i;
		if (h[i]==0) cnt++; h[i]++;
		dfs(nn-1,s+(1<<i),val*v[i]%mod,i);
		if (h[i]>0) cnt--; h[i]--; 
	}
}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n); read(m); read(k);
	for (int i=0;i<=m;i++) read(v[i]);
	d[0]=1;
	for (int i=1;i<=n;i++) d[i]=d[i-1]*i;
	dfs(n,0,1,0);
	cout<<ans<<endl;
	return 0;
}

