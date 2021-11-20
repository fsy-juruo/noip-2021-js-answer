#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T&x){
	long long ff=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')ff=-1;
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	x*=ff;
}
template<typename T>inline void write(T x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+48);
}
template<typename T>inline void writeln(T x){
	write(x);putchar('\n');
}
const long long P=998244353;
long long n,m,k,V[40];
long long f[40][(1ll<<12)*30+10];
long long lowbit(long long x){
	return x&-x;
}
long long cnnt(long long S){
	long long res=0;
	while(S){
		S-=lowbit(S);res++;
	}
	return res;
}
void bf(){
	f[0][0]=1;
	for(long long i=1;i<=n;i++){
		for(long long S=0;S<=(1ll<<m)*n;S++){
			for(long long j=0;j<=m&&(1ll<<j)<=S;j++){
				f[i][S]=(f[i][S]+f[i-1][S-(1ll<<j)]*V[j]%P)%P;
			}
		}
	}
	long long ans=0;
	for(long long S=n;S<=(1ll<<m)*n;S++){
		if(cnnt(S)<=k){
			ans=(ans+f[n][S])%P;
		}
	}
	writeln(ans);
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	
	read(n);read(m);read(k);
	for(long long i=0;i<=m;i++)read(V[i]);
	bf();
	return 0;
}
/*
5 1 1
2 1

*/
