#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0;char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
inline void write(int x){
	if(x>9)write(x/10);
	putchar(x%10|48);
}
inline void writeln(int x){
	write(x),putchar('\n');
}
int n,ma=1e9,a[10005],b[10005],c[10005],w,d[10005],e[10005];
bool v[10005];
void dfs(int dep,int s,int t,int k){
	if(dep>=n){
		int tmp=n*s-k*k;
		if(tmp<ma)ma=tmp;
		return;
	}
	for(int i=1;i<n;++i){
		if(!v[i]){
			v[i]=1;
			c[dep]=b[i];
			dfs(dep+1,s+(t+b[i])*(t+b[i]),t+b[i],k+t+b[i]);
			v[i]=0;
		}
	}
}
void dfs2(int dep,int g,int la){
	if(g>w-1||n-dep<w-1-g)return;
	if(g==w-1){
		sort(c+1,c+g+1);
		int h=0,s=0,t=0,k=0;
		for(int i=2;i<n;++i)if(!v[i])d[++h]=b[i];
		sort(d+1,d+h+1);
		for(int i=1;i<w;++i)e[i]=c[g-i+1];
		e[w]=b[1];
		for(int i=w+1;i<n;++i)e[i]=d[i-w];
		for(int i=1;i<n;++i){
			t+=e[i];
			s+=t*t;
			k+=t;
		}
		ma=min(ma,n*s-k*k);
		return;
	}
	for(int i=la+1;i<n;++i){
		if(!v[i]){
			v[i]=1;
			c[g+1]=b[i];
			dfs2(dep+1,g+1,i);
			v[i]=0;
		}
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		b[i-1]=a[i]-a[i-1];
	}
	if(n<=10){
		dfs(1,0,0,0);
		writeln(ma);
		return 0;
	}
	sort(b+1,b+n);
	for(int i=1;i<n;++i){
		w=i;
		dfs2(2,0,1);
	}
	writeln(ma);
	return 0;
}
