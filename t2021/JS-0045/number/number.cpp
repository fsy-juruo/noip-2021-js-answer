//rp++
/*
seive ?!
*/
#include<bits/stdc++.h>
using namespace std;

void fre() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef double db;

inline ll read() {
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void write(ll x) {
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
#define writesp(x) write(x),putchar(' ')
#define writeln(x) write(x),putchar('\n')

#define rep(x,l,r) for(int x=l;x<=r;x++)
#define per(x,r,l) for(int x=r;x>=l;x--)
#define rep0(x) while(x--)

#define psf push_front
#define psb push_back
#define ppf pop_front
#define ppb pop_back

#define fi first
#define se second

const int N=10001000,D=10000;

int n;
bool vis[N+D],tag[N+D];
int nxt[N+D];
//tag[i]==1 means i cannot be called
bool check(int x) {
	while(x) {
		if(x%10==7) return true;
		x/=10;
	}
	return false;
}
void seive() {
	rep(i,1,n) if(check(i)) tag[i]=1;
	
	vis[1]=1;
	rep(i,1,n) {
		if(!vis[i]) {
			rep(j,2,N/i) {
				vis[i*j]=1;
				tag[i*j]|=tag[i]|tag[j];
			}
		}
	}
	
	per(i,n,1) {
		if(!tag[i+1]) nxt[i]=i+1;
		else nxt[i]=nxt[i+1];
	}
}

int t;
int q[200200];

int main() {
	fre();
	
	//int st=clock();
	
	t=read();
	rep(i,1,t) q[i]=read(),n=max(n,q[i]);
	n+=D;
	if(n<=8000000) n=8000000;//?!?@@!?#
	//n=N;
	
	while(check(n)) n++;
	
	seive();
	rep(i,1,t) {
		if(tag[q[i]]) writeln(-1);
		else writeln(nxt[q[i]]);
	}
	
	//writeln(clock()-st);
	
	return 0;
}
