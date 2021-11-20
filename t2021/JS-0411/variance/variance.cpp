#include <bits/stdc++.h>
#define int long long
#define inf 200000000000000007
using namespace std;
const int maxl=10005;

int read(){
	int s=0,w=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-')  w=-w;ch=getchar();}
	while (ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^'0');ch=getchar();}
	return s*w;
}
int n,ans=inf,tmp;
int a[maxl],cf[maxl],p[maxl];

namespace Subtask_1{
	int bc[1048580];
	void init(){
		for (int i=1;i<=n;i++)  a[i]=read(),cf[i]=a[i]-a[i-1];
		
		n--;
		for (int i=1;i<=n;i++)  p[i]=i,cf[i]=cf[i+1];
		sort(cf+1,cf+n+1);
	}
	int calc(){
		int res=0,sumv=0;
		for (int i=1;i<=n;i++){
			sumv+=a[i]*i;
			res+=a[i]*(n-i+1)*sumv;
		}
		sumv=0;
		for (int i=n;i>=1;i--){
			res+=a[i]*i*sumv;
			sumv+=a[i]*(n-i+1);
		}
		return res;
	}
	void work(){
		for (int i=0;i<(1ll<<(min(20ll,n)));i++){
			bc[i]=(bc[i>>1ll])+(i&1ll);
			int head=bc[i],tail=bc[i]+1;
			for (int j=1;j<=n;j++){
				if (i&(1ll<<(j-1)))  a[head]=cf[j],head--;
				else a[tail]=cf[j],tail++;
			}
			ans=min(ans,calc());
		}
	}
	void solve(){
		init(),work();
		cout<<ans<<endl;
	}
}

signed main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	
	n=read();
	Subtask_1::solve();
	
	return 0;
}
