#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans=1e9,a[10100],h[1000100];
const int MOD(1e6+7);
inline int read(){
	int FF=0,RR=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())
		if(ch=='-')
			RR=-1;
	for(;isdigit(ch);ch=getchar())
		FF=(FF<<1)+(FF<<3)+ch-48;
	return FF*RR;
}
int hsh(){
	int ret=0,p=127;
	for(int i=1;i<=n;i++){
		ret=(ret+p*a[i]%MOD)%MOD;
		p=p*127%MOD;
	}
	return ret;
}
int fangcha(){
	int fm=n,fz=0,ffz=0;
	for(int i=1;i<=n;i++)
		fz+=a[i];
	for(int i=1;i<=n;i++){
		int tmp=a[i]*fm-fz;
		ffz+=tmp*tmp;
	}
	return ffz/n;
}
void dfs(){
//	cerr<<ans<<'\n';
//	for(int i=1;i<=n;i++)
//		cout<<a[i]<<' ';
//	cout<<'\n';
	ans=min(ans,fangcha());
//	cerr<<ans<<'\n';
//	for(int i=1;i<=n;i++)
//		cout<<a[i]<<' ';
//	cout<<'\n';
	for(int i=2;i<n;i++)
		if(a[i-1]+a[i+1]-a[i]!=a[i]&&a[i-1]+a[i+1]-a[i]>=0){
			int tmp=a[i];
			a[i]=a[i-1]+a[i+1]-a[i];
			int hh=hsh();
//			cout<<i<<' ';
			if(!h[hh]){
				h[hh]=1;
				dfs();
			}
			a[i]=tmp;
		}
}
void dfs2(){
//	cerr<<ans<<'\n';
//	for(int i=1;i<=n;i++)
//		cout<<a[i]<<' ';
//	cout<<'\n';
	int x=fangcha();
	if(x>=ans)
		return;
	ans=x;
//	cerr<<ans<<'\n';
//	for(int i=1;i<=n;i++)
//		cout<<a[i]<<' ';
//	cout<<'\n';
	for(int i=2;i<n;i++)
		if(a[i-1]+a[i+1]-a[i]!=a[i]&&a[i-1]+a[i+1]-a[i]>=0){
			int tmp=a[i];
			a[i]=a[i-1]+a[i+1]-a[i];
			int hh=hsh();
//			cout<<i<<' ';
			if(!h[hh]){
				h[hh]=1;
				dfs();
			}
			a[i]=tmp;
		}
}
signed main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	h[hsh()]=1;
	if(n>=8)
		dfs2();
	else
		dfs();
	printf("%lld",ans);
	return 0;
}

