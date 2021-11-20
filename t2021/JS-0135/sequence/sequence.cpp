#include<bits/stdc++.h>
#define int long long
using namespace std;
inline void read(int &x){
	x=0;
	int y=1;
	char a;
	a=getchar();
	while(a<'0'||a>'9'){
		if(a=='-')y=-1;
		a=getchar();
	}
	while(a>='0'&&a<='9'){
		x=x*10+a-'0';
		a=getchar();
	}
	x*=y;
}
int n,m,k;
int fv[888];
int fz(int x){
	int fjg=0;
	while(x){
		if(x%2==1)++fjg;
		x/=2;
	}
	return fjg;
}
int fans;
int fzx[88];
int fjc[888],fny[888];
int fzfx;
int mod;
int ksm(int x,int p){
	int fjg=1;
	for(;p;p/=2,x=x*x%mod){
		if(p%2==1)fjg=fjg*x%mod;
	}
	return fjg;
}
int C(int nn,int mm){
	return fjc[nn]*fny[mm]%mod*fny[nn-mm]%mod;
}
bool dfsq(int x,int v,int num){
	if(v==x&&num==n){
		int nn=n;
		int fzans=1;
		for(int i=0;i<=m;++i){
			fzans*=C(nn,fzx[i]);
			fzans=fzans%mod;
			nn-=fzx[i];
			if(nn<=0)break;
		}
		int ffv=1;
		for(int i=0;i<=m;++i){
			ffv*=ksm(fv[i],fzx[i]);
			ffv=ffv%mod;
		}
		fans+=ffv*fzans%mod;
		fans=fans%mod;
		return false;
	}
	if(n-num+v>x)return true;
	if((n-num)*(1<<m)+v<x)return false;
	if(num==n)return false;
	if(v>=x)return false;
	for(int i=0;i<=m;++i){
		++fzx[i];
		if(dfsq(x,v+(1<<i),num+1))break;
		--fzx[i];
	}
}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	mod=998244353;
	fjc[0]=1;
	for(int i=1;i<=800;++i){
		fjc[i]=fjc[i-1]*i;
		fjc[i]=fjc[i]%mod;
	}
	fny[800]=ksm(fjc[800],mod-2);
	for(int i=799;i>=0;--i){
		fny[i]=fny[i+1]*(i+1)%mod;
	}
	read(n);read(m);read(k);
	for(int i=0;i<=m;++i){
		read(fv[i]);
	}
	for(int i=n;i<=n*(1<<m);++i){
		if(fz(i)<=k){
			memset(fzx,0,sizeof(fzx));
			dfsq(i,0,0);
		}
	}
	cout<<fans<<endl;
	return 0;
}


