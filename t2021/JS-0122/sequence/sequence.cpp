#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int inf=0x3f3f3f3f;
const ll mod=998244353;

int n,m,k;
ll v[110];

int read(){
	int f=1,x=0;char ch=getchar();
	while (ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0' && ch<='9'){x=x*10-'0'+ch;ch=getchar();}
	return f*x;
}

namespace subtask1{
	int a[35]={0};
	ll ans=0;
	
	int popcnt(int x){
		int cnt=0;
		while (x){
			cnt++;
			x-=x&(-x);
		}
		return cnt;
	}
	
	void ck(){
		ll x=0;
		for (int i=1;i<=n;i++){
			x+=(1ll<<a[i]);
		}
//		for (int i=1;i<=n;i++)cerr<<a[i]<<' ';cerr<<"sum:"<<x<<endl;
		if (popcnt(x)<=k){
			ll sum=1;
			for (int i=1;i<=n;i++)sum=(sum*v[a[i]])%mod;
			ans=(ans+sum)%mod;
		}
	}
	
	void solve(){
		while (a[0]==0){
			ck();
			int i=n; 
			while (a[i]==m){
				a[i]=0;
				i--;
			}
			a[i]++;
		}
		printf("%lld\n",ans);
	}
}

int main()
{
	freopen("sequence.in","r",stdin);
  freopen("sequence.out","w",stdout);
	n=read();m=read();k=read();
	for (int i=0;i<=m;i++)v[i]=read();
	if (n<=8 && m<=9){
		subtask1::solve();
	}

	return 0;
}

