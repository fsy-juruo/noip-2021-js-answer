#include<bits/stdc++.h>
using namespace std;
namespace IO{
	template <typename T>inline void read(T &x){
		x=0;int f=1;char c=getchar();
		for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
		for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
		x*=f;
	}
	template <typename T>inline void write(T x){
		if(x<0){putchar('-');x=-x;}
		if(x>9)write(x/10);
		putchar(x%10+'0');
	}
	template <typename T>inline void writeln(T x){
		write(x);putchar('\n');
	}
	template <typename T>inline void writesp(T x){
		write(x);putchar(' ');
	}
}
using namespace IO;
int n;
int a[10002];
long long pfh,sum,ans;
void dfs(int x,long long pfh,long long sum){
	if(x==n){
		ans=min(ans,n*pfh-sum*sum);
		return;
	}
	dfs(x+1,pfh+a[x]*a[x],sum+a[x]);
	int tmp=a[x];
	a[x]=a[x-1]+a[x+1]-a[x];
	dfs(x+1,pfh+a[x]*a[x],sum+a[x]);
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);

	read(n);
	for(int i=1;i<=n;++i){
		read(a[i]);
//		sum+=a[i];
//		pfh+=a[i]*a[i];
	}
	
//	ans=n*pfh-sum*sum;
	
	ans=9999999999999;
	dfs(2,a[1]*a[1]+a[n]*a[n],a[1]+a[n]);
	
	writeln(ans);
	return 0;
}

