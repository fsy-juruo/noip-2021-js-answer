#include<bits/stdc++.h>

using namespace std;

const int N=10010;

typedef long long LL;

LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

LL n;
LL a[N];
LL ans=1e9;

LL poww(LL a,int b){
	LL res=1;
	for(int i=1;i<=b;i++)
		res*=a;
	return res;
}

void dfs(int u){
	if(u==n-1){
		LL res1=0,res2=0;
		for(int i=1;i<=n;i++){
			res1+=pow(a[i],2);
			res2+=a[i];
		}
		ans=min(ans,n*res1-poww(res2,2));
		return;
	}
	for(int i=2;i<n;i++){
		dfs(u+1);
		a[i]=a[i+1]+a[i-1]-a[i];
		dfs(u+1);
		a[i]=a[i+1]+a[i-1]-a[i];
	}
}

int main(){
	
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	dfs(2);
	printf("%lld\n",ans);
	return 0;
}

