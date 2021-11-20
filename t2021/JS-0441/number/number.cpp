#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=(ch=='-'),ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
inline void write(int x){
	if(x>9)write(x/10);
	putchar(x%10|48);
}
inline void writeln(int x){
	write(x),putchar('\n');
}
int n=1e7+1;
bool f[10000005];
int p[6000005],c,d,r[10000005],g[1000005],x[200005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t=read(),ma=0;
	for(int i=1;i<=t;++i){
		x[i]=read();
		ma=max(ma,x[i]);
	}
	n=min(ma*2,n);
	for(int i=1;i<=n;++i){
		int tmp=i;
		while(tmp){
			if(tmp%10==7){
				f[i]=1;
				p[++c]=i;
				break;
			}
			tmp/=10;
		}
	}
	for(int i=2;i<=n;++i){
		for(int j=1;j<=c;++j){
			if(i*p[j]>n)break;
			f[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
		if(f[i]==0)g[++d]=i;
	}
	int w=n;
	for(int i=n;i>=1;--i){
		r[i]=w;
		if(f[i]==0)w=i;
	}
	for(int i=1;i<=t;++i){
		if(f[x[i]]){
			puts("-1");
			continue;
		}
		writeln(r[x[i]]);
	}
	return 0;
}
