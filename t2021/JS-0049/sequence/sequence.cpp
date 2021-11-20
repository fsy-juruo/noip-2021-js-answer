#include<bits/stdc++.h>
#define LL long long
#define PB push_back
using namespace std;
void file(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
template <typename T>void read(T&x){
	x=0;int f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	x*=f;
}
#define mol 998244353
const int maxn=105;
int a[maxn];
int n,m,k;
int st[maxn];
LL jc[maxn],ny[maxn],tl[maxn][maxn];
LL ans;
bool check(int x){
	int t=0;
	while(x!=0)t++,x=(x-1)&x;
	return t<=k;
}
void dfs(int dep,LL x,LL vl,LL vl2,int tol){
	if(tol>n)return;
	if(dep==m+1){
		if(tol!=n)return ;
		if(check(x))
			ans=(ans+vl*vl2%mol*jc[n]%mol)%mol;
		return ;
	}
	for(int i=0;i<=n;i++)
		dfs(dep+1,x+(1<<dep)*i,vl*tl[dep][i]%mol,vl2*ny[i]%mol,tol+i);
}
LL fspower(LL x,int t){
	if(t==1)return x;
	if(t&1)return fspower(x*x%mol,t/2)*x%mol;
	return fspower(x*x%mol,t/2);
}
void init(){
	jc[1]=jc[0]=1;
	ny[1]=ny[0]=1;
	for(int i=2;i<=100;i++){
		jc[i]=(jc[i-1]*i)%mol;
		ny[i]=fspower(jc[i],mol-2);
	}
	for(int i=0;i<=m;i++){
		tl[i][0]=1;
		for(int j=1;j<=n;j++){
			tl[i][j]=(tl[i][j-1]*a[i])%mol;
		}
	}
}
int main(){
	file("sequence");
	read(n);
	read(m);
	read(k);
	for(int i=0;i<=m;i++){
		read(a[i]);
	}
	init();
	dfs(0,0,1,1,0);
	printf("%lld",ans);
	return 0;
}

