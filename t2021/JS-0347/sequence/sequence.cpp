#include<bits/stdc++.h>

using namespace std;

const int N=110,mod=998244353,M=1e7+10;

typedef long long LL;


LL n,m,k;
LL v[N];
LL a[N],ans;

LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void dfs(int u){
	if(u==n){
		int s=0;
		for(int i=1;i<=n;i++)
			s+=pow(2,a[i]);
		int cnt=0;
		while(s){
			if(s%2==1)cnt++;
			s>>=1;
		}
		if(cnt>k)return;
		else{
			LL res=1;
			for(int i=1;i<=n;i++)
				res=(res*v[a[i]])%mod;
			ans=(ans+res)%mod;
			return;
		}
	}
	for(int i=0;i<=m;i++){
		a[++u]=i;
		dfs(u);
		a[u]=0;
		u--;
	}
}

int main(){
	
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	
	n=read(),m=read(),k=read();
	for(int i=0;i<=m;i++)
		v[i]=read();
	dfs(0);
	printf("%lld\n",ans); 
	return 0;
}

