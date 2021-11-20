#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define dg() printf("114514\n")
LL read() {
	LL s=0,w=1; char ch=getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') w=-1; ch=getchar();}
	while(ch <= '9' && ch >= '0') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
const LL P=998244353;
LL v[110],a[110];
LL n,m,k;
LL ans;
bool check() {
	LL sum=0,num=0;
	for(int i=1;i<=n;i++) {
		sum+=(1 << a[i]);
	}
	while(sum) {
		if(sum & 1) num++;
		sum>>=1;
		if(num > k) return false;
	}
	return true;
}
void dfs(int x) {
	if(x == n+1) {
		if(!check()) return;
		LL val=1;
		for(int i=1;i<=n;i++) val=val*v[a[i]]%P;
		ans=(ans+val)%P;
		return; 
	} 
	for(int i=0;i<=m;i++) {
		a[x]=i;
		dfs(x+1);
	}
	return;
}
int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(); m=read(); k=read();
	for(int i=0;i<=m;i++) v[i]=read();
	//dg();
	dfs(1);
	//dg();
	printf("%lld\n",ans);
	return 0;
}
/*
5 1 1 
2 1
*/
