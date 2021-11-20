#include <iostream>

using namespace std;

long long read() {
	long long x=0,f=1;
	char c;
	while(c=getchar(),c<'0'||c>'9')
		if(c=='-')
			f=-1;
	while(c>='0'&&c<='9')
		x=(x<<1)+(x<<3)+(c&15),c=getchar();
	return x*f;
}

void write(long long x) {
	if(x<0)
		putchar('-'),x=-x;
	if(x>9)
		write(x/10);
	putchar(x%10|48);
}

const long long mod=998244353;

long long n,m,k,v[101],a[31],oks=0;

long long sk() {
	long long ks=0,b[105] {};
	for(int i=1; i<=n; i++)
		b[a[i]]++;
	for(int i=0; i<105; i++) {
		if(b[i]&1)
			ks++;
		b[i+1]+=b[i]>>1;
	}
	return ks;
}

long long vv() {
	long long ss=1;
	for(int i=1; i<=n; i++)
		ss*=v[a[i]],ss%=mod;
	return ss;
}

void dfs(long long w) {
	if(w>n) {
		if(sk()<=k)
			oks+=vv(),oks%=mod;
		return;
	}
	for(long long i=0; i<=m; i++)
		a[w]=i,dfs(w+1);
}

int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=0; i<=m; i++)
		v[i]=read();
	dfs(1);
	write(oks%mod);
	return 0;
}
