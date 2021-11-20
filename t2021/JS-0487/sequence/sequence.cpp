#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define inf 0x3f3f3f3f
#define djq 998244353
inline void file(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
}
inline int read(){
	int ret=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*f;
}
int n,m,k,a[35];
int V[105],ans;
inline int count(int x){
	int ret=0;
	while(x) x-=x&(-x),++ret;
	return ret;
}
void dfs(int x,int v,int vv){
	if(x==n+1){
		if(count(v)<=k) ans=(1ll*ans+vv)%djq;
		return ;
	}
	for(int i=0;i<=m;++i){
		a[x]=i;
		dfs(x+1,v+(1<<i),1ll*vv*V[i]%djq);
	}
}
signed main(){
	//system("fc number4.out number4.ans");
	file();
	n=read(),m=read(),k=read();
	for(int i=0;i<=m;++i) V[i]=read();
	dfs(1,0,1);
	printf("%d",ans);
	return 0;
}
