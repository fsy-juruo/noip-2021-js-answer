#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int read(){
	int sz=0,fh=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')fh=-1;ch=getchar();}
	while(isdigit(ch)){sz=sz*10+(ch-'0');ch=getchar();}
	return sz*fh;
}
const int N=110;
ll a[N],jc[N],vis[N],mod=998244353;
int n,m,k,lg;
ll s,ans,minn,maxn;
ll ny(ll tx){
	ll tm=mod-2,ts=1;
	while(tm!=0){
		if(tm&1)ts=(ts*tx)%mod;
		tx=(tx*tx)%mod;
		tm>>=1;
	}
	return ts;
}

void dfs(int dep,int las,ll sum,ll ts){
	if(dep>n){
		if(sum!=s)return;
		int add=jc[n];
		for(int i=0;i<=m;i++){
			if(vis[i])add=(add*ny(jc[vis[i]]))%mod;
		}
		ans=ans+(add*ts%mod);
		return;
	}
	if(sum>s)return;
	for(int i=las;i<=m;i++){
		vis[i]++;
		dfs(dep+1,i,sum+(1<<i),ts*a[i]%mod);
		vis[i]--;
	}
}
void dfs2(int dep,int tk,ll sum){
	if(dep>lg){
		if(sum<=minn||sum>=maxn||tk<k)return;
		s=sum;
		dfs(1,0,0,1);
		return;
	}
	if(tk<k)dfs2(dep+1,tk+1,sum+(1<<dep)); 
	dfs2(dep+1,tk,sum);
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=0;i<=m;i++)a[i]=read();
	jc[1]=1;
	for(int i=2;i<=n;i++)jc[i]=(jc[i-1]*i)%mod;
	minn=n,maxn=n*(1<<m);
	ll tmaxn=maxn;
	while(tmaxn>0){
		tmaxn/=2;
		lg++;
	}
	dfs2(1,0,0); 
	cout<<ans<<endl;
	return 0;
}

