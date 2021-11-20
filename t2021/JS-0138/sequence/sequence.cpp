
//1~10 50pts

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N=105,S=30*(1<<12)+5,mod=998244353;

inline int getint(){
	int x=0;
	char c=getchar();
	while(!isdigit(c))
		c=getchar();
	while(isdigit(c)){
		x=x*10+(c^48);
		c=getchar();
	}
	return x;
}

void putint(int x){
	if(x>9) putint(x/10);
	putchar(x%10+'0');
}

int n,m,k,maxs;
int v[N],cnt[S];
int f[N][S];

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=getint(),m=getint(),k=getint(),maxs=n*(1<<m);
	for(int i=0;i<=m;++i) v[i]=getint();
	for(int i=1;i<S;++i){ 
		cnt[i]=cnt[i>>1]+(i&1);
		//if(i<20) printf("%d %d\n",i,cnt[i]);
	}
	
	f[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int s=0;s<=maxs;++s)
			for(int j=0;j<=m;++j)
				if(s>=(1<<j)) f[i][s]=(f[i][s]+(LL)f[i-1][s-(1<<j)]*v[j])%mod;
	
	int ans=0;
	for(int i=n;i<=maxs;++i)
		if(cnt[i]<=k) (ans+=f[n][i])%=mod;
	putint(ans),putchar('\n');
	return 0;
}
